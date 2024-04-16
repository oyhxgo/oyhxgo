#include<iostream>
using namespace std;

#define Max 100000
typedef char ch;//���������͸ĳ�ch����������޸� 
typedef struct //����һ���Լ���Ҫ�Ĺؼ��֣����ǽṹ��
{//���ﲹ�䣺�������Ǵ�������һ��˳��������˹ؼ��ֺ󣬽ṹ������ݾ�Ӧ��Ϊ˳�����������ʵ�ֵĹ��� 
	ch data[Max];//�洢��ĸ 
	int lth;//length���� 
}Sqlist;//�ؼ��ֵ����ƽ���Sqlist����Ϊ����Ҫ��һ��˳��� 

//��ʼ��˳���
void Initsqlist(Sqlist *&L)//���ݰ������ٿռ䣬���峤�� 
{
	L=new Sqlist;
	L->lth=0;
} 
//�ͷ�˳���
void destroysqlist(Sqlist *&L)
{
	delete L;
}

//����Ԫ�� 
bool Insertsqlist(Sqlist *&L,int i,ch e)//���룺ΪʲôҪ��bool����ΪҪ���ֲ�ͬ�Ļش�
{ 
	if(i<1||i>L->lth+1)//�߼����߼�����ж� 
		return false;
	i--;//����Ϊ������� 
	for(int j=L->lth;j>i;j--)
	{
		L->data[j]=L->data[j-1];
	} 
	L->data[i]=e;
	L->lth++;
	return true;
} 
//ɾ��Ԫ��
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

//���˳���
void displaysqlist(Sqlist *L)
{
	for(int i=0;i<L->lth;i++)
		cout<<L->data[i]<<"   ";
} 
//���˳���ĳ���
int displaylength(Sqlist *L)
{
	return L->lth;
}
//�ж�˳����Ƿ�Ϊ��
bool listempty(Sqlist *L)
{

	return (0==L->lth);
	
}
//���ĳ��Ԫ�أ��жϿɲ���ȡ��
bool getlist(Sqlist *L,int i,ch &tmp)//���룺�������������ĺô������ڼȿ����жϣ�������ֱ���������
{
	if(i<1||i>=L->lth+1)
		return false;
	i--;
	tmp=L->data[i];
	return true;
}
//���Ԫ�ص�λ�ã��жϴ治���ڣ�
int locelem(Sqlist *L,ch tmp)
{
	int k=0;//������Ŵ�0��ʼ
	while(k<=L->lth-1&&L->data[k]!=tmp){
		k++;
	}
	if(k>=L->lth)
		return 0;
	else 
		return k+1;//�����߼����
}

int main()
{
	Sqlist *L1;Initsqlist(L1);
	cout<<"1.��ʼ��˳���ɹ�������"<<endl<<endl;
	
	int h=1;
	ch a[10]={'A','B','C','D','E'};	
	cout<<"2.���β���ABCDE."<<"    "; 
	for(int i=0;i<5;i++)
	{
		if(!Insertsqlist(L1,i+1,a[i]))//����ע������������Ĳ������߼���ţ��ڵ�һλ���� 
			{
				cout<<"Warning:����ʧ�ܣ�����������"<<endl;
				h=0;
			}
	}
	if(h)
		cout<<"����ɹ�������"<<endl<<endl; 
	//���˳���	
	cout<<"3.��ǰ˳����Ԫ���У�";displaysqlist(L1);cout<<endl<<endl;
	//�������
	cout<<"4.��ǰ˳���ĳ���Ϊ��"<<displaylength(L1)<<endl<<endl;
	//�ձ�
	cout<<"5.��ǰ˳���";
	if(listempty(L1))
		cout<<"Ϊ�ձ�"<<endl<<endl;
	else
		cout<<"��Ϊ�ձ�"<<endl<<endl;
	//ȡֵ�����Ԫ�أ�
	cout<<"6.ȡֵ����:";
	ch temp;int p;
	cout<<"��������Ҫȡ�ĸ�λ�õ�ֵ��";cin>>p;
	if(getlist(L1,p,temp))
		cout<<"ȡֵ�ɹ��� "<<"˳����"<<p<<"λ��Ԫ���ǣ�"<<temp<<endl<<endl;
	else
		cout<<"ȡֵʧ�ܣ��������λ��"<<p<<"Խ�磡����"<<endl<<endl;
	cout<<"7.���Ҳ�����";
	ch find;
	cout<<"��������Ҫ���ҵ�Ԫ�أ�  ";cin>>find;
	if(locelem(L1,find)==0)
		cout<<"�Բ��𣬵�ǰ˳�����û�������ҵ�Ԫ�أ���"<<endl<<endl;
	else
		cout<<"���ҳɹ����������ҵ�Ԫ��"<<find<<"�ڵ�ǰ˳���ĵ�"<<locelem(L1,find)<<"λ"<<endl<<endl;
	
	cout<<"8.���������";
	int k;ch q;
	cout<<"��������һ�����ֺ�һ���ַ��������ڵڼ�λ����һ���ַ���";cin>>k>>q;
;	if(!Insertsqlist(L1,k,q))
		cout<<"Warning:�������Խ�磬����ʧ�ܣ�����"<<endl;
	else
		cout<<"����ɹ�������"<<endl<<endl; 
	cout<<"9.��ǰ˳����Ԫ���У�";displaysqlist(L1);cout<<endl<<endl;
	//ɾ��Ԫ��
	cout<<"10.ɾ��������";
	int y;ch o;
	cout<<"��������Ҫɾ����Ԫ�ص���ţ�";cin>>y;
	if(!delem(L1,y,o))
		cout<<"�Բ�������������������Խ�磩��ɾ��ʧ�ܣ�"<<endl<<endl;
	else
		cout<<"ɾ���ɹ����ɹ�ɾ����"<<y<<"��Ԫ��"<<o<<endl<<endl;
	cout<<"11.��ǰ˳����Ԫ���У�";displaysqlist(L1);cout<<endl<<endl;
	//�ͷ�˳���
	cout<<"12.����˳���";
	destroysqlist(L1);
	cout<<"���ٳɹ�������";
	return 0;
}

//ֵ��ע��
//1.˳���ĳ������߼����
//���ǲ��Ҳ�������������Ҳ���߼����
