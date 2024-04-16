#include <iostream>
using namespace std;
#define MaxSize 100

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];		//�����˳����е�Ԫ��
	int length;					//��ĳ��� 
} SqList;

//1.˳����ʼ��
void InitList(SqList *&L)
{
	L=new SqList;				//L=(SqList *)malloc(sizeof(SqList));  �ø������Ҫ����ͷ�ļ�   #include <malloc.h> 
}

//3.�жϱ��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList *L)
{
	return (0==L->length);
} 
//4.��˳���ĳ���
int ListLength(SqList *L)
{
	return L->length;
} 
//5.���˳���
void DispList(SqList *L) 
{
	for(int i=0;i<L->length;i++)
		cout<<L->data[i]<<"  ";		
}

//6.�����ȡֵ
bool GetElem(SqList *L,int i,ElemType &e)
{
	if(i<1 || i>L->length)
		return false;
	e=L->data[i-1];
	return true;
} 
//8.���뺯��
bool ListInsert(SqList *&L,int i,ElemType e)		//��ָ��λ��i֮ǰ����Ԫ��e
{
	if(i<1 || i>L->length+1)
		return false;
	i--;						//���߼�λ�򻻳�����λ��
	for(int j=L->length;j>i;j--)		//�Ӻ���ǰ�����ƶ����ݣ��ճ�����λ�� 
		L->data[j]=L->data[j-1];
	L->data[i]=e; 				//��Ԫ��e�����µ�λ�� 
	L->length++;
	return true;
} 

 
int main()
{
	SqList *L1;InitList(L1);
	cout<<"1.��ʼ��˳���."<<endl<<endl;
	
	ElemType a[5]={'A','B','C','D','E'};
	cout<<"2.���β���Ԫ��ABCDE."<<endl<<endl;
	for(int i=0;i<5;i++)
		if(!ListInsert(L1,i+1,a[i]))
			cout<<"����ʧ��!";
	
	cout<<"3.˳����е�Ԫ��Ϊ:";DispList(L1);cout<<endl<<endl;
	
	cout<<"4.˳���ĳ���Ϊ:"<<ListLength(L1)<<endl<<endl;
	
	cout<<"5.˳���";
	if(ListEmpty(L1))
		cout<<"Ϊ�ձ�."<<endl<<endl;
	else
		cout<<"��Ϊ�ձ�."<<endl<<endl;
	
	cout<<"6.ȡֵ����.";
	int loc;cout<<endl<<"������ȡֵλ��:";cin>>loc;
	ElemType temp;
	if(GetElem(L1,loc,temp))
	{
		cout<<"ȡֵ�ɹ���˳���ĵ�"<<loc<<"Ԫ��ֵΪ:"<<temp<<endl<<endl;
	}
	else
		cout<<"ȡֵʧ�ܣ��������λ��"<<loc<<"Խ��!"<<endl<<endl;
	return 0;
}
