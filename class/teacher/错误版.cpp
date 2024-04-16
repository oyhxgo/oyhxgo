#include <stdio.h>
#include <iostream>
#include <malloc.h>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkList;


///////建立单链表
void CreateListF(LinkList *&L,ElemType a[],int n)
{
	 LinkList *s;
	 int i;
	 L=(LinkList *)malloc(sizeof( LinkList));
	 L->next=NULL;
	 for(i=0;i<n;i++)
	 {
		 s=(LinkList *)malloc(sizeof(LinkList));
		 s->data=a[i];
		 s->next=L->next;
		 L->next=s;
	 }
}


/////(1)初始化单链表h；
void InitList(LinkList *&L)
{
	L=(LinkList * )malloc(sizeof(LinkList));
	L->next=NULL;
}


/////(2)采用尾插法依次插入元素a,b,c,d,e;
void CreateListR(LinkList * &L,ElemType a[],int n)
{
	LinkList * s, *r;
	int i;
	L=(LinkList *)malloc(sizeof(LinkList));
	r=L;
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}


/////(3)输出单链表h；
void DispList(LinkList *L)
{
	LinkList * p=L->next;
	while(p!=NULL)
	{
		printf("%d,",p->data);
	    p=p->next;
	}
	printf("\n");
}


/////(4)输出单链表h长度；
int ListLength(LinkList * L)
{
	int n=0;
	LinkList * p=L;
	while(p->next!=NULL)
	{
		n++;
		p=p->next;
	}
	return(n);
}


////(5)判断单链表h是否为空；
bool ListEmpty(LinkList *L)
{
	return(L->next==NULL);
}


/////(6)输出单链表h的第3个元素；
int LocateElem(LinkList *L,ElemType e)
{
	int i=1;
	LinkList *p=L->next;
	while(p!=NULL && p->data!=e)
	{
		p=p->next;
	    i++;
}
if(p==NULL)
      return(0);
else
     return(i);
}


/////(7)输出元素a的位置；
bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L;
	while(j<i && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else
	{
		e=p->data;
		return true;
	}
}


/////(8)在第4个元素位置上插入元素f；
bool ListInsert(LinkList *&L,int i,ElemType e)
{
	int j=0;
	LinkList * p=L,* s;
	while(j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else
	{
		s=(LinkList * )malloc(sizeof(LinkList));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}


/////(10)删除L的第3个元素；
bool ListDelete(LinkList * &L,int i,ElemType &e)
{
	int j=0;
	LinkList * p=L,*q;
	while(j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else
	{
		q=p->next;
		if(q==NULL)
			return false;
		e=q->data;
		p->next=q->next;
		free(q);
		return true;
	}
}




/////(12)释放单链表h。
void DestroyList(LinkList *&L)
{
	LinkList *pre=L,*p=L->next;
	while (p!=NULL)
	{
		free(pre);
	    pre=p;
	    p=pre->next;
	}

    free(pre);
}



int main() 
{
	LinkList *h1;
	cout<<"1.建立单链表";

	cout<<"\n2.:"<<"初始化单链表:";InitList(h1);
	ElemType a[5]={'A','B','C','D','E'},f='F';
    for(int i=0;i<5;i++)
		if(!ListInsert(h1,i+1,a[i]))
			cout<<"插入失败!";
	cout<<"\n3.单链表的元素为:";
	DispList(h1);


	cout<<"\n4.该单链表的长度为:"<<ListLength(h1)<<endl;

	cout<<"\n5.该单链表";
	if(ListEmpty(h1))
		cout<<"为空!"<<endl;
	else
		cout<<"不为空!"<<endl;


	cout<<"\n6.输出单链表h的第3个元素";
	ElemType temp;cout<<"请输入取的位置:";int k;cin>>k;
	if(GetElem(h1,k,temp))
		cout<<"取值成功，该单链表的第"<<k<<"个元素的值为:"<<temp<<endl;
	else
		cout<<"取值失败，你输入的位置"<<k<<"越界:"<<endl;

  
	if(LocateElem(h1,'A'))
		cout<<"(7)输出元素'A'的位置="<<LocateElem(h1,'A')<<endl;
	else
		cout<<"(7)元素'A'不存在."<<endl;
  
	cout<<"(8)在第4个元素的前面插入'f'元素"<<endl;
	if(ListInsert(h1,4,'f'))
		cout<<"插入成功";
	else
		cout<<"插入失败";

	cout<<"(9)输出单链表h1"<<endl;
	DispList(h1);
	
	cout<<"(10)删除h1的第3个元素"<<endl;
	if(ListDelete(h1,3,temp))
		cout<<"删除成功，删除的元素为:"<<temp<<endl;
	else
		cout<<"删除失败!";
	

	cout<<"(11)输出单链表h"<<endl;
	DispList(h1);
	cout<<"(12)释放单链表h"<<endl;
	DestroyList(h1);
}
