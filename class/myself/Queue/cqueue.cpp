//For fun，we use English to annotation
#include<iostream>
#include<stack>//we can also use this head file
using namespace std;
#define MAX 40
typedef char ch;//define our elemtype

//our old friend struct
typedef struct
{
	ch data[MAX]; //存放队列的elem,actually,queue is also 一维array 
	int front,rear;	//存放首尾指针
}cq;

//Initialition our cirle queue which named cq
void Initqueue(cq *&q)
{
	q=new cq;
	q->front=q->rear=0;//初始状态下，两个指针重合，都指向环形队列的一号位置
} 
//delete our queue
void deletequeue(cq *&q)
{
	delete q;
}
//is the queue empty?(Chinlish)
bool queueisempty(cq *q)
{
	return (q->front==q->rear);//队列为空，就是两个指针相等的时间	
}
//进队push our elem
bool Intoqueue(cq *&q,ch e)
{
	if((q->rear+1)%MAX==q->front)//when front and rear meet again
		return false;
	q->rear=(q->rear+1)%MAX;//防止假溢出
	q->data[q->rear]=e;
	return true;
}
//出队out our elem出列元素本质没被删除，只是在未被判断为队会被替代
bool Outqueue(cq *&q,ch &e)
{
	if(queueisempty(q))//when the queue is empty，懂？不懂也懂！
		return false;
	q->front=(q->front+1)%MAX;
	e=q->data[q->front];
	return true; 
}
void tentoany(stack<ch>&q,int n,int m)//整数部分m表示转换为多少进制，m为要转化的数
{
	int p;
	while(m)
	{
		p=m%n;
		if(p>10)
			q.push(p+55);
		else
			q.push(p+48);
		m/=n;
	}
	return;
	
}
//函数
void Tentoany(cq *&q,int n,double m)
{
	double a;int b;
	a=(int)m;
	a=m-a;
	for(int i=1;i<=8;i++){//保留八位小数
		a=a*n;
		b=(int)a;
		if(b>10)
			Intoqueue(q,b+55);
		else
			Intoqueue(q,b+48);
		a=a-b;
	}
}
void Destroyqueue(cq *&q)
{
	delete q;
}

int main()
{
	cq *q;ch e;stack<ch>q1;
	Initqueue(q);
	cout<<"1.初始化环形队列，Now you have a circular queue："<<endl<<endl;
	if(queueisempty(q))
		cout<<"2.您的环形队列是空的"<<endl<<endl;
	else
		cout<<"2.您的环形队列不为空！"<<endl<<endl;
	///插入a,b,c
	ch p[MAX]={'a','b','c'};//The maximum space is MAX
	cout<<"3.现在令a b c 进队："<<endl<<endl;
	for(int i=0;i<3;i++)
		if(!Intoqueue(q,p[i]))
			cout<<"您的"<<p[i]<<"进队失败"<<endl<<endl;
	cout<<"GOOD，a b c进队成功！！！"<<endl<<endl;
	//出队一个元素
	cout<<"4.现在出队一个元素，他是：";
	Outqueue(q,e);cout<<e<<endl<<endl;
	ch k[MAX]={'d','e','f'};//值得注意，使用MAX=4会爆，应该是5个元素了现在
	cout<<"5.现在令d e f进队："<<endl<<endl;
	for(int i=0;i<3;i++)
		if(!Intoqueue(q,k[i]))
			cout<<"您的"<<k[i]<<"进队失败"<<endl<<endl;
	cout<<"GOOD，d e f进队成功！！！"<<endl<<endl;
	//出队
	cout<<"6.出列序列为：";
	while(!queueisempty(q)){
		Outqueue(q,e);
		cout<<e<<" ";
	}
	cout<<endl<<endl;
	//转化为二进制
	double m;int n,flag=0;
	cout<<"请输入一个十进制的数字";cin>>m;
	cout<<"这个数的二进制表示为（小数点后最多保留8位）：";tentoany(q1,2,m);Tentoany(q,2,m);
	while(!q1.empty()){
		flag=1;
		e=q1.top();q1.pop();
		cout<<e;
	}
	if(flag)
		cout<<".";
	else 
		cout<<"0.";
	while(!queueisempty(q)){
		Outqueue(q,e);
		cout<<e;
	}
	cout<<endl<<endl;
	//转化为任意进制,m
	flag=0;
	cout<<"请输入一个十进制的数字（小数点后最多保留8位）";cin>>m;cout<<endl;
	cout<<"请输入要转化的进制：(2-36)";cin>>n;cout<<endl;
	tentoany(q1,n,m);Tentoany(q,n,m);
	cout<<m<<"的"<<n<<"进制表示为:";
	while(!q1.empty()){
		flag=1;
		e=q1.top();q1.pop();
		cout<<e;
	}
	if(flag)
		cout<<".";
	else 
		cout<<"0.";
	while(!queueisempty(q)){
		Outqueue(q,e);
		cout<<e;
	}
	cout<<endl<<endl;
	//销毁
	Destroyqueue(q);
	cout<<"7.销毁队列成功!!!";
	return 0;
}



//几点注意
//本质上，是rear和front两个指针在动，进队rear动，出队front动。队空和队满其实两个指针重合
//为了防止重合条件，牺牲一个空间，是对空对满条件不重合
//对空是两个指针相遇（重合），队满则是rear下一个是front则队满
//看队满，rear动，看对空，front动
//出队其实元素并不是消失了，其实还在，但是根据结构特性，其实这里是认为是空的，等待下一个元素去代替
//利用这个，其实可以做点溯源
