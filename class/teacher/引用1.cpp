#include <iostream>    //输入输出流 
using namespace std;

int main()
{
	int a=3;
	int &b=a;	//变量b是变量a的引用
	cout<<"a="<<a<<"  b="<<b<<endl; 
	
	a=5;
	cout<<"a="<<a<<"  b="<<b<<endl; 
	
	b=1;
	cout<<"a="<<a<<"  b="<<b<<endl; 
	
	cout<<"a="<<&a<<"  b="<<&b<<endl; 
	return 0;
}
