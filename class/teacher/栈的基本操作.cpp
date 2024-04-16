#include<iostream>
using namespace std;

#define MaxSize 40
typedef char ElemType;//����ElemType����
typedef struct			//����˳��ջ�ṹ��
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitSqStack(SqStack *&L)		//��ʼ��˳��ջ 
{
	L=new SqStack;
	L->top=-1;
}


bool SqStackEmpty(SqStack *L)			//�ж�˳��ջ�Ƿ�Ϊ��ջ 
{
	return(L->top==-1);
}


bool PushSqStack(SqStack *&L,ElemType e)		//�ж�Ԫ��e�Ƿ��ܽ�ջ����������ջ��ָ��ָ��Ԫ��e 
{
	if(L->top==MaxSize-1)
		return false;
	else 
	L->top++;
	L->data[L->top]=e;
		return true;
}


bool PopSqStack(SqStack *&L,ElemType &e)		//�ж�˳��ջջ��Ԫ���Ƿ���ڣ���������ȡջ��Ԫ�أ�����ָ��--
{
	if(L->top==-1)
		return false;
	else
	e=L->data[L->top];
	L->top--;
		return true;
}


void TenConversionN(SqStack *&L,ElemType b[],int N)	//����10������ת��ΪN�����������������෴��ֵ���ν�ջ
{
	ElemType d;						//�����ַ�����d 
	int t=0,d1;						//�������ͱ���t��d1 
	for(int i3=0;b[i3]!='\0';i3++)			//���û������10������ת�������ͣ�����t���� 
		t=t*10+b[i3]-'0';
	for(int i4=0;;i4++)			//��10���������δ��� 
	{
		d1=t%N;					//��d1����10��������N������ 
		if(d1>=0 && d1<=9)			//�ж�d1�Ƿ���0-9������ ������ת��Ϊ�ַ�0-9 
			d=d1+48;
		else if(d1>9 && d1<36)		//�ж�d1�Ƿ���10-35�����䣬������ת��Ϊ�ַ�A-Z 
			d=d1+65-10;
		t/=N;							//����tΪt/N 
		if(L->top==MaxSize-1)			//�ж�Ԫ��e�Ƿ��ܽ�ջ����������ջ��ָ��ָ��Ԫ��e 
			cout<<"��ջʧ�ܣ�"<<endl;
		else
		{
			L->top++;
			L->data[L->top]=d;
		}
		if(t==0)				//��tΪ0ʱ����ѭ����������ѭ�� 
			break;
	}
}

void DestoryStack(SqStack *&L)		//����ջ 
{
	delete (L);
}

//������ 
int main()
{
	SqStack *L1;							//����˳��ջ 
	InitSqStack(L1);						//��ʼ��˳��ջ 
	
	
	cout<<"��˳��ջ��ʼ����"<<endl;
	if(!SqStackEmpty(L1))					//�ж�˳��ջ�Ƿ�Ϊ��ջ�������� 
		cout<<"��ջ�ǿ�"<<endl;
	else
		cout<<"��ջΪ��"<<endl; 
	
	
	ElemType a[5]={'A','B','C','D','E'};		//�����ַ�����a 
	for(int i1=0;i1<5;i1++)					//������a��Ԫ�����ν�ջ 
		if(!PushSqStack(L1,a[i1]))			//�ж�����a��Ԫ���Ƿ��ջ�ɹ�����ʧ������ʾ 
			cout<<"��ջʧ�ܣ�"<<endl;
			
	
	cout<<"��A,B,C,D,E���ν�ջ��"<<endl; 
	if(!SqStackEmpty(L1))					//�ж�˳��ջ�Ƿ�Ϊ��ջ�������� 
		cout<<"��ջ�ǿ�"<<endl;
	else
		cout<<"��ջΪ��"<<endl;
		
		
	ElemType c;							//�����ַ�����c������cȡ��˳��ջ��ջ��Ԫ�� 
	for(int i2=0;i2<5;i2++)				//����ȡ��˳��ջ��ջ��Ԫ�أ���˳��ջΪ��ջ��ʾ��ջʧ�ܣ���ʱ��ȡ������a��Ԫ�� 
		if(!PopSqStack(L1,c))
			cout<<"��ջʧ�ܣ�"<<endl;
		else
			cout<<c<<' ';
	cout<<endl;
		
	
	cout<<"��˳��ջ��Ԫ�س�ջ��"<<endl;
	if(!SqStackEmpty(L1))				//�ж�˳��ջ�Ƿ�Ϊ��ջ�������� 
		cout<<"��ջ�ǿ�"<<endl;
	else
		cout<<"��ջΪ��"<<endl;


	ElemType b[MaxSize];					//�����ַ�����b�����û������ʮ���������ַ�����d 
	int n;								//�������ͱ���n 
	cin>>b>>n;							//���û�����ʮ������b���Լ���Ҫת���ɵ�n���� 
	TenConversionN(L1,b,n);				//���ú�����ʮ������ת��Ϊn�����������������෴��ֵ���ν�˳��ջ 
	for(int i2=0;L1->data[i2]!='\0';i2++)	//����ȡ��˳��ջ��ջ��Ԫ�أ���˳��ջΪ��ջ��ʾ��ջʧ�ܣ���ʱ��ȡ��ת�����n������ 
		if(!PopSqStack(L1,c))
			cout<<"��ջʧ�ܣ�"<<endl;
		else
			cout<<c;
	cout<<endl;
	
	
	DestoryStack(L1);					//����˳��ջ 
	cout<<"�ѽ�˳��ջ����"<<endl;
}
