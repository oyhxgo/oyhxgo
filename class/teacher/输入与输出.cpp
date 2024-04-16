//输入两个整数，输出它们的和
//#include <stdio.h>
#include <iostream>    //输入输出流 
using namespace std;

typedef double ElemType;
int main()
{
	//int a,b;
	ElemType a,b;
	//printf("请输入第一个整数：");
	cout<<"请输入第一个整数：";
	//scanf("%d",&a);
	cin>>a;
	//printf("请输入第二个整数：");
	cout<<"请输入第二个整数：";
	//scanf("%d",&b);
	cin>>b;
	
	//printf("它们的和为：%d\n",a+b);
	cout<<"它们的和为："<<a+b<<endl; 
	return 0;
 } 
