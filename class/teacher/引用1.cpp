#include <iostream>    //��������� 
using namespace std;

int main()
{
	int a=3;
	int &b=a;	//����b�Ǳ���a������
	cout<<"a="<<a<<"  b="<<b<<endl; 
	
	a=5;
	cout<<"a="<<a<<"  b="<<b<<endl; 
	
	b=1;
	cout<<"a="<<a<<"  b="<<b<<endl; 
	
	cout<<"a="<<&a<<"  b="<<&b<<endl; 
	return 0;
}
