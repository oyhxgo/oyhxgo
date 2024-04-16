#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct node
{
	ElemType data;
   	struct node *next;
} LinkList;   

void InitList(LinkList *&L)   
{
	L= new LinkList;       
    L->next=L;
}

/////////////////////////////////////////////////////////
//1.ͷ�巨����һ��ѭ������
void CreateListF(LinkList *&L,ElemType a[],int n)  
{
	LinkList *s;
	L = new LinkList;
	L->next = L;
	for (int i=0;i<n;i++)
	{
		s = new LinkList;
		s->data = a[i];
		s->next = L->next;
		L->next = s; 
	}	
}

/////////////////////////////////////////////////////////
//2.β�巨����һ��ѭ������
void CreateListR(LinkList *&L,ElemType a[],int n)  
{
	LinkList *s,*r;
	L = new LinkList;
	r = L;
	for (int i=0;i<n;i++)
	{
		s = new LinkList;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = L;
}

///////////////////////////////////////////////////////
//3.����ѭ������
void DestroyList(LinkList *&L)
{
	LinkList *pre=L->next,*p=pre->next;
	while (p != L)	//ͷ������ж�ѭ�����������Ա������������� 
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
	delete p;	// delete L;   Ч����һ���� 
}


////////////////////////////////////////////////////////
//4.�ж��Ƿ�Ϊ�ձ�
bool ListEmpty(LinkList *L)
{
	return (L->next==L);
}

///////////////////////////////////////////////////////
//4.��ѭ������ĳ���
int ListLength(LinkList *L)
{
	int count = 0;
	LinkList *p=L->next;
	while (p != L)
	{
		count ++;
		p = p->next;
	}
	return count;
}

///////////////////////////////////////////////////////
//5.���ѭ������
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
} 

///////////////////////////////////////////////////////
//6.��ĳ������Ԫ��ֵGetElem(L,i,e)
bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0; LinkList *p=L;
	while (j < i && p->next != L)
	{
		j ++;
		p = p->next;
	}
	if (i<1 || i>j)
		return false;
	e = p->data;
	return true;

}

//////////////////////////////////////////////////////////
//7.��Ԫ��ֵ����
int LocateElem(LinkList *L, ElemType e)
{
	LinkList *p=L->next;
	int i=1;
	while (p != L && p->data != e)
	{
		i ++;
		p = p->next;
	}
	if (p == L)
		return 0;
	else 
		return i;
}

//////////////////////////////////////////////////////////////
//8.��������Ԫ��
bool ListInsert(LinkList *&L,int i,ElemType e)
{
	if (i < 1) return false;
    int j=0; LinkList *p=L,*s;
    if (i==1)			//�Ե�һ�����ݽ����ж���Ĵ��� 
    {
    	s = new LinkList;
    	s->data = e;
   		s->next = p->next;
    	p->next = s;
    	return true; 
    }
    else 
    {
   		while (j < i-1 && p->next!=L)
   		{
    		j ++;
    		p = p->next;
    	}
   		if (i > j+1 || p==L)
   			return false;
    	s = new LinkList;
    	s->data = e;
    	s->next = p->next;
    	p->next = s;
   		return true;
    }
}


///////////////////////////////////////////////////////////////
//9.ɾ������Ԫ��
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
	if (i < 1) return false;
	
    int j=0; 
    LinkList *p=L,*q;
    if (i==1)
    {
    	q = p->next;
    	e = q->data;
    	p->next = q->next;
   		delete q;
    	return true;
    }
    else
    {
    	while (j < i-1 && p->next!=L)
    	{
    		j ++;
     		p = p->next;
    	}
    	if (p->next==L)
    		return false;
    	q = p->next;
    	e = q->data;
    	p->next = q->next;
    	delete q;
    	return true;
    }
}



/////////////////////////////////////////
//����Ϊ����������

int main()
{
	LinkList *L1;
	cout<<"1.��ʼ��ѭ������:"<<endl;InitList(L1);

	cout<<"\n2.β�巨����:"<<endl;
	ElemType a[5]={'A','B','C','D','E'};
    for(int i=0;i<5;i++)
		if(!ListInsert(L1,i+1,a[i]))
			cout<<"����ʧ��!";
	
	cout<<"\n3.ѭ�������Ԫ��Ϊ:";
	DispList(L1);

	cout<<"\n4.��ѭ������ĳ���Ϊ:"<<ListLength(L1)<<endl;

	cout<<"\n5.��ѭ������ ";
	if(ListEmpty(L1))
		cout<<"Ϊ��!"<<endl;
	else
		cout<<"��Ϊ��!"<<endl;

	cout<<"\n6.ȡԪ��..........."<<endl;
	ElemType temp;cout<<"������ȡ��λ��:";int k;cin>>k;
	if(GetElem(L1,k,temp))
		cout<<"ȡֵ�ɹ�����ѭ������ĵ�"<<k<<"��Ԫ�ص�ֵΪ:"<<temp<<endl;
	else
		cout<<"ȡֵʧ�ܣ��������λ��"<<k<<"Խ��:"<<endl;

	cout<<"\n7.����Ԫ��:"<<endl<<"���������Ԫ�ص�ֵ:";cin>>temp;
	if(LocateElem(L1,temp))
		cout<<"���Ԫ��'"<<temp<<"'��λ��Ϊ:"<<LocateElem(L1,temp)<<endl;
	else
		cout<<"Ԫ��'"<<temp<<"'������."<<endl;
  
	cout<<"\n8.��ѭ������ָ��λ�ò���Ԫ�� :"<<endl;
	cout<<"����������λ��:";cin>>k;
	cout<<"���������Ԫ�ص�ֵ:";cin>>temp;
	if(ListInsert(L1,k,temp))
		cout<<"����ɹ�"<<endl;
	else
		cout<<"����ʧ��!"<<endl;

	cout<<"\n9.���ѭ������"<<endl;
	DispList(L1);
	
	cout<<"\n10.ɾ��ѭ������ָ��λ�õ�Ԫ��"<<endl;
	cout<<"������ɾ����λ��:";cin>>k;
	if(ListDelete(L1,k,temp))
		cout<<"ɾ���ɹ���ɾ����Ԫ��Ϊ:"<<temp<<endl;
	else
		cout<<"ɾ��ʧ��!"<<endl;

	cout<<"\n11.���ѭ������"<<endl;
	DispList(L1);
	
	cout<<"\n12.�ͷ�ѭ������"<<endl;
	DestroyList(L1);
	
	
	return 0;
}
