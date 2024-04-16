//P1563 [NOIP2016 提高组] 玩具谜题
#include<iostream>
#include<string>
using namespace std;
#define MAX 10000000
struct 
{
	int loc;
	char name[10];
}p[MAX];
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		cin>>p[i].loc;cin>>p[i].name;
	}
	int now=0;//用于定位等于0是因为我们是从0开始存的
	for(int i=1;i<=b;i++){
		cin>>x>>y;
		if(p[now].loc==x)//相等
			now=(now+a-y)%a;
		else //不等
			now=(now+y)%a;
	}
	cout<<p[now].name;
	
	return 0;
}
