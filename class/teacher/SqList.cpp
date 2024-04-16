#include <iostream>
using namespace std;
#define MaxSize 100

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];		//存放在顺序表中的元素
	int length;					//表的长度 
} SqList;

//1.顺序表初始化
void InitList(SqList *&L)
{
	L=new SqList;				//L=(SqList *)malloc(sizeof(SqList));  用该语句需要包含头文件   #include <malloc.h> 
}

//3.判断表是否为空表
bool ListEmpty(SqList *L)
{
	return (0==L->length);
} 
//4.求顺序表的长度
int ListLength(SqList *L)
{
	return L->length;
} 
//5.输出顺序表
void DispList(SqList *L) 
{
	for(int i=0;i<L->length;i++)
		cout<<L->data[i]<<"  ";		
}

//6.按序号取值
bool GetElem(SqList *L,int i,ElemType &e)
{
	if(i<1 || i>L->length)
		return false;
	e=L->data[i-1];
	return true;
} 
//8.插入函数
bool ListInsert(SqList *&L,int i,ElemType e)		//在指定位置i之前插入元素e
{
	if(i<1 || i>L->length+1)
		return false;
	i--;						//将逻辑位序换成物理位序
	for(int j=L->length;j>i;j--)		//从后往前依次移动数据，空出插入位置 
		L->data[j]=L->data[j-1];
	L->data[i]=e; 				//将元素e插入新的位置 
	L->length++;
	return true;
} 

 
int main()
{
	SqList *L1;InitList(L1);
	cout<<"1.初始化顺序表."<<endl<<endl;
	
	ElemType a[5]={'A','B','C','D','E'};
	cout<<"2.依次插入元素ABCDE."<<endl<<endl;
	for(int i=0;i<5;i++)
		if(!ListInsert(L1,i+1,a[i]))
			cout<<"插入失败!";
	
	cout<<"3.顺序表中的元素为:";DispList(L1);cout<<endl<<endl;
	
	cout<<"4.顺序表的长度为:"<<ListLength(L1)<<endl<<endl;
	
	cout<<"5.顺序表";
	if(ListEmpty(L1))
		cout<<"为空表."<<endl<<endl;
	else
		cout<<"不为空表."<<endl<<endl;
	
	cout<<"6.取值操作.";
	int loc;cout<<endl<<"请输入取值位置:";cin>>loc;
	ElemType temp;
	if(GetElem(L1,loc,temp))
	{
		cout<<"取值成功！顺序表的第"<<loc<<"元素值为:"<<temp<<endl<<endl;
	}
	else
		cout<<"取值失败，您输入的位置"<<loc<<"越界!"<<endl<<endl;
	return 0;
}
