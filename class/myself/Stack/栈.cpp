//ջ�Ļ������� 
#include<iostream>
using namespace std;
#define MAX 40
typedef char ch;
//�����ӣ��Ƚ���ջ�Ľṹ�� 
typedef struct
{
	ch data[MAX];//�洢ջ������Ԫ�أ����СΪջ���ܴ�С�����������ǿ��Կ���ջ�ı��ʣ�һ��һά���� 
	int top;//�洢ջ��ջ��,��data�е��±� 
}Sqstack; 
//��ʼ��ջs
void Initsqstack(Sqstack *&s)
{
	s=new Sqstack;
	s->top=-1;//��Ϊ�ձ� 
}
//�ж��Ƿ�Ϊ��,�շ����� 
bool emptystack(Sqstack *s)
{
	return (s->top==-1);
} 
//����
bool Push(Sqstack *&s,ch a)//ʵ�ֹ��ܲ���abcde  
{
	if(s->top==MAX-1)//ջ������� 
		return false;
	s->top++;
	s->data[s->top]=a;
	return true;
}
//��ջ (����ж��ܷ��ջ)
bool Pop(Sqstack *s,ch &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true; 
}
//����1ʮ����ת�������
void Tentoanybase(Sqstack *s,ch *b,int any)//��һ���������洢����������֣�57����5��7���룬t��ʾҪת��ʲô����
{
	ch e;
	int p=0,y;//p���ڴ洢ʮ���Ƶ�����y��ȡ������
	//���ڽ��յ��ַ������Ե���ת��������
	for(int i=0;b[i]!='\0';i++){
		p=p*10+b[i]-'0';
	}
	while(p)//��֪�����ĸ����ƣ�����������ѭ����˵��
	{
		y=p%any;//ȡ��
		if(y>=0&&y<=9){//�ж��Ƿ���Ҫ��ĸ
			e=y+48;//ת��Ϊ0-9�ַ���0=45
		}
		else if(y>9&&y<36)
			e=y+55;//A=65
		p=p/any;
		if(!Push(s,e))
			cout<<"Ԫ��"<<e<<"��ջʧ�ܣ�";
	}
}
 
//�ͷ� 
void Destroystack(Sqstack *&s)
{
	delete (s);
}
int main()
{
	Sqstack *s1;Initsqstack(s1);
	cout<<"��ʼ��ջs�ɹ���������ӵ��һ��ջ"<<endl<<endl;
	if(emptystack(s1)) 
		cout<<"��ǰ��˳��ջΪ��"<<endl<<endl;
	else 
		cout<<"��ǰ��˳��ջ��Ϊ��"<<endl<<endl;
	ch a[6]={'A','B','C','D','E'};
	for(int i=0;i<=4;i++)//Ϊ�˷���bool�����ã����Ǹ�����������tip 
	{
		if(!Push(s1,a[i]))
			cout<<"Ԫ��"<<a[i]<<"��ջʧ�ܣ�"<<endl<<endl;
	}
	cout<<"����ABCDE�ɹ�������"<<endl<<endl; 
	if(emptystack(s1)) 
		cout<<"��ǰ��˳��ջΪ��"<<endl<<endl;
	else 
		cout<<"��ǰ��˳��ջ��Ϊ��"<<endl<<endl;
	//��ջ
	cout<<"Ԫ�س�ջ��";
	ch r;
	for(int i=0;i<=4;i++)
	{
		if(!Pop(s1,r))
			cout<<"��ջʧ�ܣ�����"<<endl<<endl;
		else
			cout<<r<<"  "; 
	}
	cout<<endl<<endl;
	if(emptystack(s1)) 
		cout<<"��ǰ��˳��ջΪ��"<<endl<<endl;
	else 
		cout<<"��ǰ��˳��ջ��Ϊ��"<<endl<<endl;
	//��ӵĺ���1
	ch p[MAX];int any;
	cout<<"����1�������ֱ�������ת����ʮ�������ֺ�2���Կո������";
	cin>>p;	cin>>any;
	Tentoanybase(s1,p,any);
	cout<<endl;
	cout<<"ת���ɹ���"<<p<<"��"<<"������Ϊ��";
	while(s1->top!=-1){
		cout<<s1->data[s1->top];
		s1->top--;
	}
	cout<<endl<<endl;
	if(emptystack(s1)) 
		cout<<"��ǰ��˳��ջΪ��"<<endl<<endl;
	else 
		cout<<"��ǰ��˳��ջ��Ϊ��"<<endl<<endl;
	cout<<"����2�������ֱ�������ת����ʮ�������ֺ���Ҫת���Ľ��ƣ��Կո������";
	cin>>p;	cin>>any;
	Tentoanybase(s1,p,any);
	cout<<endl;
	cout<<"ת���ɹ���"<<p<<"��"<<any<<"����Ϊ��";
	while(s1->top!=-1){
		cout<<s1->data[s1->top];
		s1->top--;
	}
	cout<<endl<<endl;
	Destroystack(s1);
	cout<<"����ջ�ɹ�����������һ�����У�������"<<endl<<endl; 
	return 0;
}



//ǳǳ����һ�£��ȿ�ʮ����ת�����ƣ��̳����������Ƕ�10ȡ��2���̳���Ȼ����������
//���������û���Ƚ�������ⲻ����ջ
//˼���ʵ��
//while (number != 0 && number != 1) {
//	flag = number % 2;//ȡ��
//	num[i++] = flag;//�洢
//	number = number / 2;//�̳�
//}
//num[i++] = number;
//printf("��ʮ�������Ķ��������ǣ�");
//for (int j = i - 1; j >=0 ; j--)//���������һ���ʹ洢������ջ����
//	printf("%d", num[j]);

//��ô���Ƿ����ˣ�����������Ǿ�ȡ���Ӧ���Ϳ����ˣ�Ҫ������36�������ڣ�emm
//����֪��ʮ�������õ���F������36���õ���0-Z�����Է����������ӡ����
//���Ի������򵥵��������ѧ���ˣ�����
//���ˣ����ڸĳɽ�ջ��ֱ��������ĺ�������ÿ�εĵõ������ִ���
//















