//栈的基本操作 
#include<iostream>
using namespace std;
#define MAX 40
typedef char ch;
//老样子，先建立栈的结构体 
typedef struct
{
	ch data[MAX];//存储栈的数据元素，其大小为栈的总大小，在这里我们可以看到栈的本质，一个一维数组 
	int top;//存储栈的栈顶,在data中的下标 
}Sqstack; 
//初始化栈s
void Initsqstack(Sqstack *&s)
{
	s=new Sqstack;
	s->top=-1;//置为空表 
}
//判断是否为空,空返回真 
bool emptystack(Sqstack *s)
{
	return (s->top==-1);
} 
//插入
bool Push(Sqstack *&s,ch a)//实现功能插入abcde  
{
	if(s->top==MAX-1)//栈满的情况 
		return false;
	s->top++;
	s->data[s->top]=a;
	return true;
}
//出栈 (外加判断能否出栈)
bool Pop(Sqstack *s,ch &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true; 
}
//函数1十进制转任意进制
void Tentoanybase(Sqstack *s,ch *b,int any)//用一个数组来存储所输入的数字，57就是5和7存入，t表示要转化什么进制
{
	ch e;
	int p=0,y;//p用于存储十进制的数，y是取余后的数
	//由于接收的字符，所以得先转化成整型
	for(int i=0;b[i]!='\0';i++){
		p=p*10+b[i]-'0';
	}
	while(p)//不知道是哪个进制，我们先让他循环再说吧
	{
		y=p%any;//取余
		if(y>=0&&y<=9){//判断是否需要字母
			e=y+48;//转化为0-9字符型0=45
		}
		else if(y>9&&y<36)
			e=y+55;//A=65
		p=p/any;
		if(!Push(s,e))
			cout<<"元素"<<e<<"进栈失败！";
	}
}
 
//释放 
void Destroystack(Sqstack *&s)
{
	delete (s);
}
int main()
{
	Sqstack *s1;Initsqstack(s1);
	cout<<"初始化栈s成功，您现在拥有一个栈"<<endl<<endl;
	if(emptystack(s1)) 
		cout<<"当前的顺序栈为空"<<endl<<endl;
	else 
		cout<<"当前的顺序栈不为空"<<endl<<endl;
	ch a[6]={'A','B','C','D','E'};
	for(int i=0;i<=4;i++)//为了发挥bool的作用，我们给个插入错误的tip 
	{
		if(!Push(s1,a[i]))
			cout<<"元素"<<a[i]<<"进栈失败！"<<endl<<endl;
	}
	cout<<"插入ABCDE成功！！！"<<endl<<endl; 
	if(emptystack(s1)) 
		cout<<"当前的顺序栈为空"<<endl<<endl;
	else 
		cout<<"当前的顺序栈不为空"<<endl<<endl;
	//出栈
	cout<<"元素出栈：";
	ch r;
	for(int i=0;i<=4;i++)
	{
		if(!Pop(s1,r))
			cout<<"出栈失败！！！"<<endl<<endl;
		else
			cout<<r<<"  "; 
	}
	cout<<endl<<endl;
	if(emptystack(s1)) 
		cout<<"当前的顺序栈为空"<<endl<<endl;
	else 
		cout<<"当前的顺序栈不为空"<<endl<<endl;
	//外加的函数1
	ch p[MAX];int any;
	cout<<"函数1：请您分别输入想转换的十进制数字和2，以空格隔开：";
	cin>>p;	cin>>any;
	Tentoanybase(s1,p,any);
	cout<<endl;
	cout<<"转换成功！"<<p<<"的"<<"二进制为：";
	while(s1->top!=-1){
		cout<<s1->data[s1->top];
		s1->top--;
	}
	cout<<endl<<endl;
	if(emptystack(s1)) 
		cout<<"当前的顺序栈为空"<<endl<<endl;
	else 
		cout<<"当前的顺序栈不为空"<<endl<<endl;
	cout<<"函数2：请您分别输入想转换的十进制数字和想要转换的进制，以空格隔开：";
	cin>>p;	cin>>any;
	Tentoanybase(s1,p,any);
	cout<<endl;
	cout<<"转换成功！"<<p<<"的"<<any<<"进制为：";
	while(s1->top!=-1){
		cout<<s1->data[s1->top];
		s1->top--;
	}
	cout<<endl<<endl;
	Destroystack(s1);
	cout<<"销毁栈成功！！您现在一无所有！！！！"<<endl<<endl; 
	return 0;
}



//浅浅分析一下，先看十进制转二进制，短除法告诉我们对10取余2，短除，然后将所有数字
//倒序输出，没错先进后出，这不就是栈
//思想的实现
//while (number != 0 && number != 1) {
//	flag = number % 2;//取余
//	num[i++] = flag;//存储
//	number = number / 2;//短除
//}
//num[i++] = number;
//printf("该十进制数的二进制数是：");
//for (int j = i - 1; j >=0 ; j--)//倒序输出这一步和存储可以用栈代替
//	printf("%d", num[j]);

//那么我们发现了，任意进制我们就取余对应数就可以了，要求我们36进制以内，emm
//我们知道十六进制用到了F，所以36嘛用到了0-Z，所以分两种情况打印即可
//所以还是蛮简单的嘛，嘻嘻，学废了！！！
//对了，关于改成进栈，直接用上面的函数，让每次的得到的数字存在
//















