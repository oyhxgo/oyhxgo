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


///////����������
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


/////(1)��ʼ��������h��
void InitList(LinkList *&L)
{
	L=(LinkList * )malloc(sizeof(LinkList));
	L->next=NULL;
}


/////(2)����β�巨���β���Ԫ��a,b,c,d,e;
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


/////(3)���������h��
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


/////(4)���������h���ȣ�
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


////(5)�жϵ�����h�Ƿ�Ϊ�գ�
bool ListEmpty(LinkList *L)
{
	return(L->next==NULL);
}


/////(6)���������h�ĵ�3��Ԫ�أ�
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


/////(7)���Ԫ��a��λ�ã�
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


/////(8)�ڵ�4��Ԫ��λ���ϲ���Ԫ��f��
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


/////(10)ɾ��L�ĵ�3��Ԫ�أ�
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




/////(12)�ͷŵ�����h��
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
	cout<<"1.����������";

	cout<<"\n2.:"<<"��ʼ��������:";InitList(h1);
	ElemType a[5]={'A','B','C','D','E'},f='F';
    for(int i=0;i<5;i++)
		if(!ListInsert(h1,i+1,a[i]))
			cout<<"����ʧ��!";
	cout<<"\n3.�������Ԫ��Ϊ:";
	DispList(h1);


	cout<<"\n4.�õ�����ĳ���Ϊ:"<<ListLength(h1)<<endl;

	cout<<"\n5.�õ�����";
	if(ListEmpty(h1))
		cout<<"Ϊ��!"<<endl;
	else
		cout<<"��Ϊ��!"<<endl;


	cout<<"\n6.���������h�ĵ�3��Ԫ��";
	ElemType temp;cout<<"������ȡ��λ��:";int k;cin>>k;
	if(GetElem(h1,k,temp))
		cout<<"ȡֵ�ɹ����õ�����ĵ�"<<k<<"��Ԫ�ص�ֵΪ:"<<temp<<endl;
	else
		cout<<"ȡֵʧ�ܣ��������λ��"<<k<<"Խ��:"<<endl;

  
	if(LocateElem(h1,'A'))
		cout<<"(7)���Ԫ��'A'��λ��="<<LocateElem(h1,'A')<<endl;
	else
		cout<<"(7)Ԫ��'A'������."<<endl;
  
	cout<<"(8)�ڵ�4��Ԫ�ص�ǰ�����'f'Ԫ��"<<endl;
	if(ListInsert(h1,4,'f'))
		cout<<"����ɹ�";
	else
		cout<<"����ʧ��";

	cout<<"(9)���������h1"<<endl;
	DispList(h1);
	
	cout<<"(10)ɾ��h1�ĵ�3��Ԫ��"<<endl;
	if(ListDelete(h1,3,temp))
		cout<<"ɾ���ɹ���ɾ����Ԫ��Ϊ:"<<temp<<endl;
	else
		cout<<"ɾ��ʧ��!";
	

	cout<<"(11)���������h"<<endl;
	DispList(h1);
	cout<<"(12)�ͷŵ�����h"<<endl;
	DestroyList(h1);
}
