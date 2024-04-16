#include<iostream>
using namespace std;

#define Max 100000
typedef char ch;//将数据类型改成ch，方便代码修改 
typedef struct //创建一个自己想要的关键字，这是结构体
{//这里补充：由于我们创建的是一个顺序表，定义了关键字后，结构体的内容就应该为顺序表中我们想实现的功能 
	ch data[Max];//存储字母 
	int lth;//length长度 
}Sqlist;//关键字的名称叫做Sqlist，因为我们要做一个顺序表 

//初始化顺序表
void Initsqlist(Sqlist *&L)//内容包括开辟空间，定义长度 
{
	L=new Sqlist;
	L->lth=0;
} 
//释放顺序表
void destroysqlist(Sqlist *&L)
{
	delete L;
}

//插入元素 
bool Insertsqlist(Sqlist *&L,int i,ch e)//感想：为什么要用bool，因为要两种不同的回答
{ 
	if(i<1||i>L->lth+1)//逻辑，逻辑序号判断 
		return false;
	i--;//更改为物理序号 
	for(int j=L->lth;j>i;j--)
	{
		L->data[j]=L->data[j-1];
	} 
	L->data[i]=e;
	L->lth++;
	return true;
} 
//删除元素
bool delem(Sqlist *&L,int i,ch &o)
{ 
	if(i<1||i>=L->lth+1) 
		return false;
	i--; 
	o=L->data[i];
	for(int j=i;j<L->lth-1;j++)
	{
		L->data[j]=L->data[j+1];
	} 
	L->lth--;
	return true;
} 

//输出顺序表
void displaysqlist(Sqlist *L)
{
	for(int i=0;i<L->lth;i++)
		cout<<L->data[i]<<"   ";
} 
//输出顺序表的长度
int displaylength(Sqlist *L)
{
	return L->lth;
}
//判断顺序表是否为空
bool listempty(Sqlist *L)
{

	return (0==L->lth);
	
}
//输出某个元素（判断可不可取）
bool getlist(Sqlist *L,int i,ch &tmp)//感想：这种三个参数的好处就在于既可以判断，还可以直接锁定输出
{
	if(i<1||i>=L->lth+1)
		return false;
	i--;
	tmp=L->data[i];
	return true;
}
//输出元素的位置（判断存不存在）
int locelem(Sqlist *L,ch tmp)
{
	int k=0;//物理序号从0开始
	while(k<=L->lth-1&&L->data[k]!=tmp){
		k++;
	}
	if(k>=L->lth)
		return 0;
	else 
		return k+1;//返回逻辑序号
}

int main()
{
	Sqlist *L1;Initsqlist(L1);
	cout<<"1.初始化顺序表成功！！！"<<endl<<endl;
	
	int h=1;
	ch a[10]={'A','B','C','D','E'};	
	cout<<"2.依次插入ABCDE."<<"    "; 
	for(int i=0;i<5;i++)
	{
		if(!Insertsqlist(L1,i+1,a[i]))//这里注意我们所输入的参数是逻辑序号，在第一位插入 
			{
				cout<<"Warning:插入失败！！！请重试"<<endl;
				h=0;
			}
	}
	if(h)
		cout<<"插入成功！！！"<<endl<<endl; 
	//输出顺序表	
	cout<<"3.当前顺序表的元素有：";displaysqlist(L1);cout<<endl<<endl;
	//输出长度
	cout<<"4.当前顺序表的长度为："<<displaylength(L1)<<endl<<endl;
	//空表
	cout<<"5.当前顺序表";
	if(listempty(L1))
		cout<<"为空表"<<endl<<endl;
	else
		cout<<"不为空表"<<endl<<endl;
	//取值（输出元素）
	cout<<"6.取值操作:";
	ch temp;int p;
	cout<<"请输入您要取哪个位置的值：";cin>>p;
	if(getlist(L1,p,temp))
		cout<<"取值成功！ "<<"顺序表第"<<p<<"位的元素是："<<temp<<endl<<endl;
	else
		cout<<"取值失败，您输入的位置"<<p<<"越界！！！"<<endl<<endl;
	cout<<"7.查找操作：";
	ch find;
	cout<<"请输入您要查找的元素：  ";cin>>find;
	if(locelem(L1,find)==0)
		cout<<"对不起，当前顺序表中没有您查找的元素！！"<<endl<<endl;
	else
		cout<<"查找成功，您所查找的元素"<<find<<"在当前顺序表的第"<<locelem(L1,find)<<"位"<<endl<<endl;
	
	cout<<"8.插入操作：";
	int k;ch q;
	cout<<"请您输入一个数字和一个字符，代表在第几位插入一个字符：";cin>>k>>q;
;	if(!Insertsqlist(L1,k,q))
		cout<<"Warning:输入序号越界，插入失败！！！"<<endl;
	else
		cout<<"插入成功！！！"<<endl<<endl; 
	cout<<"9.当前顺序表的元素有：";displaysqlist(L1);cout<<endl<<endl;
	//删除元素
	cout<<"10.删除操作：";
	int y;ch o;
	cout<<"请您输入要删除的元素的序号：";cin>>y;
	if(!delem(L1,y,o))
		cout<<"对不起，您的输入的序号有误（越界），删除失败！"<<endl<<endl;
	else
		cout<<"删除成功！成功删除第"<<y<<"个元素"<<o<<endl<<endl;
	cout<<"11.当前顺序表的元素有：";displaysqlist(L1);cout<<endl<<endl;
	//释放顺序表
	cout<<"12.销毁顺序表：";
	destroysqlist(L1);
	cout<<"销毁成功！！！";
	return 0;
}

//值得注意
//1.顺序表的长度是逻辑序号
//我们查找插入所输入的序号也是逻辑序号
