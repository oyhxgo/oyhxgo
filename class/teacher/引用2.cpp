//求1+2+...+n的和，用函数实现 
#include <iostream>    //输入输出流 
using namespace std;

void qh(int n,int &s)		//函数是没有返回值，通过形参把结果进行返回 
{
	s=0;
	for(int i=1;i<=n;i++)
		s=s+i;
}

int main()
{
	int sum,k;
	cin>>k;
	qh(k,sum);  	//调用过程，参数进行了传递     n=k ,&s=sum
	cout<<sum;
	return 0;
}
