#include<iostream>
using namespace std;

#define MaxSize 40
typedef char ElemType;//定义ElemType类型
typedef struct			//定义顺序栈结构体
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitSqStack(SqStack *&L)		//初始化顺序栈 
{
	L=new SqStack;
	L->top=-1;
}


bool SqStackEmpty(SqStack *L)			//判断顺序栈是否为空栈 
{
	return(L->top==-1);
}


bool PushSqStack(SqStack *&L,ElemType e)		//判断元素e是否能进栈，若能则令栈顶指针指向元素e 
{
	if(L->top==MaxSize-1)
		return false;
	else 
	L->top++;
	L->data[L->top]=e;
		return true;
}


bool PopSqStack(SqStack *&L,ElemType &e)		//判断顺序栈栈顶元素是否存在，若存在则取栈顶元素，并让指针--
{
	if(L->top==-1)
		return false;
	else
	e=L->data[L->top];
	L->top--;
		return true;
}


void TenConversionN(SqStack *&L,ElemType b[],int N)	//进行10进制数转换为N进制数，并将与结果相反的值依次进栈
{
	ElemType d;						//定义字符变量d 
	int t=0,d1;						//定义整型变量t，d1 
	for(int i3=0;b[i3]!='\0';i3++)			//将用户输入的10进制数转化成整型，并用t保存 
		t=t*10+b[i3]-'0';
	for(int i4=0;;i4++)			//将10进制数依次处理 
	{
		d1=t%N;					//让d1保存10进制数对N的余数 
		if(d1>=0 && d1<=9)			//判断d1是否在0-9的区间 若是则转化为字符0-9 
			d=d1+48;
		else if(d1>9 && d1<36)		//判断d1是否在10-35的区间，若是则转化为字符A-Z 
			d=d1+65-10;
		t/=N;							//重置t为t/N 
		if(L->top==MaxSize-1)			//判断元素e是否能进栈，若能则令栈顶指针指向元素e 
			cout<<"进栈失败！"<<endl;
		else
		{
			L->top++;
			L->data[L->top]=d;
		}
		if(t==0)				//当t为0时跳出循环，避免死循环 
			break;
	}
}

void DestoryStack(SqStack *&L)		//销毁栈 
{
	delete (L);
}

//主函数 
int main()
{
	SqStack *L1;							//定义顺序栈 
	InitSqStack(L1);						//初始化顺序栈 
	
	
	cout<<"将顺序栈初始化后"<<endl;
	if(!SqStackEmpty(L1))					//判断顺序栈是否为空栈并输出结果 
		cout<<"该栈非空"<<endl;
	else
		cout<<"该栈为空"<<endl; 
	
	
	ElemType a[5]={'A','B','C','D','E'};		//定义字符数组a 
	for(int i1=0;i1<5;i1++)					//让数组a中元素依次进栈 
		if(!PushSqStack(L1,a[i1]))			//判断数组a中元素是否进栈成功，若失败则提示 
			cout<<"进栈失败！"<<endl;
			
	
	cout<<"将A,B,C,D,E依次进栈后"<<endl; 
	if(!SqStackEmpty(L1))					//判断顺序栈是否为空栈并输出结果 
		cout<<"该栈非空"<<endl;
	else
		cout<<"该栈为空"<<endl;
		
		
	ElemType c;							//定义字符变量c，利用c取出顺序栈内栈顶元素 
	for(int i2=0;i2<5;i2++)				//依次取出顺序栈内栈顶元素，若顺序栈为空栈提示出栈失败，此时需取出数组a中元素 
		if(!PopSqStack(L1,c))
			cout<<"出栈失败！"<<endl;
		else
			cout<<c<<' ';
	cout<<endl;
		
	
	cout<<"将顺序栈内元素出栈后"<<endl;
	if(!SqStackEmpty(L1))				//判断顺序栈是否为空栈并输出结果 
		cout<<"该栈非空"<<endl;
	else
		cout<<"该栈为空"<<endl;


	ElemType b[MaxSize];					//定义字符数组b保存用户输入的十进制数，字符变量d 
	int n;								//定义整型变量n 
	cin>>b>>n;							//让用户输入十进制数b，以及需要转换成的n进制 
	TenConversionN(L1,b,n);				//利用函数将十进制数转换为n进制数，并将与结果相反的值依次进顺序栈 
	for(int i2=0;L1->data[i2]!='\0';i2++)	//依次取出顺序栈内栈顶元素，若顺序栈为空栈提示出栈失败，此时需取出转化后的n进制数 
		if(!PopSqStack(L1,c))
			cout<<"出栈失败！"<<endl;
		else
			cout<<c;
	cout<<endl;
	
	
	DestoryStack(L1);					//销毁顺序栈 
	cout<<"已将顺序栈销毁"<<endl;
}
