//使用单链表实现一元多项式的加，乘操作
#include <iostream>
using namespace std;

//定义一种x的几次方（单项式）的数据类型
typedef struct
{
	int coe;//系数 coefficient
	int index;//指数 index
}ElemType;

//建立单链表用来表示一个多项式
typedef struct LNode
{
	ElemType data; //结点的数据部分，每个data是一个单项式数据类型，是一个结构体噢~
	struct LNode *next;
}LinkList;

//初始化链表
void InitList(LinkList *&L)
{
	L=new LinkList;
	L->next=NULL;
}

//插入一个数据结点e到有序链表中
void InsertList(LinkList *&L,ElemType e)
{
	LinkList *r,*s;//r是循环用的结点指针，s是插入的新结点
	r=L;//每次循环开头指向头节点
	//寻找新插入结点的位置(注意这是循环步骤)
	while(r->next!=NULL&&e.index>r->next->data.index)//以指数的大小寻找位置-ps1
		r=r->next;            
	
	//判断下一个指数是否相等
	if(r->next!=NULL&&r->next->data.index==e.index)//若指数相同
		r->next->data.coe+=e.coe;//则系数相加
	else
	{
	s=new LinkList;
	s->data=e;//s->data.coe=e.coe;	s->data.index=e.index;//将e的值赋给s指针所指结点
	s->next = r->next;
	r->next = s;
	}
} 

//利用链表打印多项式---ps2
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while(p)
	{
		//特判系数为1，指数为0
		if(p->data.coe==1&&p->data.index==0)
			cout<<"1";
		//除了1和0其他都直接打，0忽略不打//普通系数打印
		if(p->data.coe!=0&&p->data.coe!=1)
			cout<<p->data.coe;
		//普通指数打印
		if(p->data.coe!=0)
		{
			if(p->data.index>1)
				cout<<"X^"<<p->data.index;
			else if(p->data.index<0)
				cout<<"X^("<<p->data.index<<")";
			else if(p->data.index==1)
				cout<<"X";
		}
		if(p->next!=NULL&&p->next->data.coe>0)//判断是否加+
			cout<<"+";
		p=p->next;   
	}
	cout<<endl;
}
//多项式加法
void AddList(LinkList *&L1,LinkList *L2)
{
	LinkList *b = L2->next;
	while(b != NULL)
	{
		InsertList(L1,b->data);//从L1表中取出每一个节点插入到L中
		b = b->next;
	}
}
//多项式乘法
void multiply(LinkList *L1,LinkList *L2,LinkList *&L3)
{
	LinkList *b,*a = L1->next;
	ElemType e;
	while(a != NULL)  //取L1表中的每一个节点
	{
		b = L2->next;  
		while(b != NULL)   //取L2表中的每一个节点
		{
			e.coe = a->data.coe * b->data.coe;    //系数相乘
			e.index = a->data.index + b->data.index;   //指数相加，得到节点相乘的值 
			InsertList(L3,e);  //再将该节点插入到L3中
			b = b->next;
		}
		a = a->next;
	}
	
}
int main()
{
	LinkList *L1;//初始化第一个多项式
	InitList(L1);
	LinkList *L2;//初始化第2个多项式
	InitList(L2);
	int a=0;ElemType F;//初始化一个单项式用于每次的接收
	while(a++<2){
	int i=0;
	do//
	{	
		cout<<"请输入第"<<a<<"个多项式的"<<i+1<<"项的系数:（按0视为该多项式结束项）";  cin>>F.coe;//先输入系数
		cout<<"请输入第"<<a<<"个多项式的"<<i+1<<"项的指数:";  cin>>F.index;//再输入指数
		i++; cout<<endl;
		if(F.coe!=0&&a==1)//coe为0直接忽略
			InsertList(L1,F);
		else if(F.coe!=0&&a==2)
			InsertList(L2,F);
	}while(F.coe!=0);
	}
	cout<<"第一个多项式F(X)=:     ";  DispList(L1);
	cout<<"第二个多项式G(X)=:     ";  DispList(L2);
	LinkList *L3;  InitList(L3);
	cout<<"多项式相乘为：     ";multiply(L1,L2,L3); DispList(L3);
	cout<<"多项式相加为：     ";AddList(L1,L2);DispList(L1);//其实也可以一个一个加
	return 0;
}

//浅浅的分析一下
//第一二个多项式需要不断输入各系数，而且由指数由小到大打印
//ps1：直到找到比自己大的停下，此时的位置即为自己的位置如果遇到相等也会停下
//ps2:打印的思路特判一下思路
//打印系数
//index=0，coe=1的情况，直接打印系数
//系数为1的情况，不打印1
//
//第三是加号的特判+

