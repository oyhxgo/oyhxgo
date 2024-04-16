#include <iostream>
using namespace std;

typedef struct
{
	int xi;//系数
	int zhi;//指数
}ElemType;

typedef struct LNode
{
	ElemType data; //结点的数据部分
	struct LNode *next;
} LinkList;

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
	r=L;
	//寻找新插入结点的位置
	while(r->next!=NULL&&e.zhi>r->next->data.zhi)
		r=r->next;

	s=new LinkList;
	s->data=e;//s->data.xi=e.xi;	s->data.zhi=e.zhi;
	//将e的值赋给s指针所指结点
	s->next=r->next;
	r->next=s;
}//本代码没有考虑指数相同的情况，需要完善 

//两个多项式相加
//void AddList(LinkList *&L,LinkList *Lc)

//两个多项式相乘 

//遍历线性表
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while(p)
	{
		cout<<p->data.xi<<"X^"<<p->data.zhi;
		if(p->next!=NULL&&p->next->data.xi>0)
			cout<<"+";
		p=p->next;   
	}
	cout<<endl;
}



//主程序部分
int main()
{
	LinkList *La;
	InitList(La);
	int i=0;ElemType k;
	do
	{		
		cout<<"请输入第"<<i+1<<"项的系数:";
		cin>>k.xi;
		cout<<"请输入第"<<i+1<<"项的指数:";
		cin>>k.zhi;
		i++;
		cout<<endl;
		if(k.xi!=0)
			InsertList(La,k);
	}while(k.xi!=0);
	cout<<"F(X)=";
	DispList(La);
	return 0;

}
