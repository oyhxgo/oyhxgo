//��1+2+...+n�ĺͣ��ú���ʵ�� 
#include <iostream>    //��������� 
using namespace std;

void qh(int n,int &s)		//������û�з���ֵ��ͨ���βΰѽ�����з��� 
{
	s=0;
	for(int i=1;i<=n;i++)
		s=s+i;
}

int main()
{
	int sum,k;
	cin>>k;
	qh(k,sum);  	//���ù��̣����������˴���     n=k ,&s=sum
	cout<<sum;
	return 0;
}
