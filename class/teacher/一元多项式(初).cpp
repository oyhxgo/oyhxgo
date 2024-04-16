#include <iostream>
using namespace std;

typedef struct
{
	int xi;//ϵ��
	int zhi;//ָ��
}ElemType;

typedef struct LNode
{
	ElemType data; //�������ݲ���
	struct LNode *next;
} LinkList;

//��ʼ������
void InitList(LinkList *&L)
{
	L=new LinkList;
	L->next=NULL;
}



//����һ�����ݽ��e������������
void InsertList(LinkList *&L,ElemType e)
{
	LinkList *r,*s;//r��ѭ���õĽ��ָ�룬s�ǲ�����½��
	r=L;
	//Ѱ���²������λ��
	while(r->next!=NULL&&e.zhi>r->next->data.zhi)
		r=r->next;

	s=new LinkList;
	s->data=e;//s->data.xi=e.xi;	s->data.zhi=e.zhi;
	//��e��ֵ����sָ����ָ���
	s->next=r->next;
	r->next=s;
}//������û�п���ָ����ͬ���������Ҫ���� 

//��������ʽ���
//void AddList(LinkList *&L,LinkList *Lc)

//��������ʽ��� 

//�������Ա�
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



//�����򲿷�
int main()
{
	LinkList *La;
	InitList(La);
	int i=0;ElemType k;
	do
	{		
		cout<<"�������"<<i+1<<"���ϵ��:";
		cin>>k.xi;
		cout<<"�������"<<i+1<<"���ָ��:";
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
