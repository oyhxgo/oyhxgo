//#include<stdio.h>
//#include<string.h>
//int max(int a,int b)
//{
//	if(a>b)
//		return a;
//	else
//		return b;
//}
//int main()
//{
//	char arr1[10000],arr2[10000];//用来接收的数组
//	int a[10000],b[10000],c[10000];//ab都是加数，c是ans用来接收答案
//	scanf("%s",arr1);
//	scanf("%s",arr2);
//	int sz1=strlen(arr1);//计算位数
//	int sz2=strlen(arr2);
//	int sz3=max(sz1,sz2)+1;//进位的计算
//	for(int i=0;i<sz1;i++)//转化，转化为数字
//	{
//		a[sz1-i]=arr1[i]-'0';
//	}
//	for(int i=0;i<sz2;i++)
//	{
//		b[sz2-i]=arr2[i]-'0';
//	}
//	//高精度加法的主体本质上是模拟计算985+211，可以体会体会，我的建议熟记于心
//	for(int i=0;i<=sz3;i++)
//	{
//		c[i]=c[i]+a[i]+b[i];
//		c[i+1]=c[i]/10;
//		c[i]%=10;
//	}
//	if(c[sz3]==0&&sz3>0)	sz3--;
//	for(int i=sz3;i>0;i--)
//	{
//		printf("%d",c[i]);
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//int compare(char a[10090],char b[10090],int s1,int s2)//创建一个函数比较大小,以1为正，0为负//至于为什么不先转化为数值是因为现在是正序
//{	
//	if(s1>s2)	return 1;//比较位数
//	else if(s1<s2)	return 0;
//	else //再逐个比较
//	{
//		for(int i=0;i<s1;i++){
//			if(a[i]>b[i])	return 1;
//			else if(a[i]<b[i])	return 0;
//			else continue;
//		}
//	}
//}
//int main()
//{
//	char a[10090],b[10090];//1
//	int a1[10090],a2[10090],ans[10090];//2
//	int s1,s2;//3
//	cin>>a;cin>>b;
//	s1=strlen(a);s2=strlen(b);//3
//
//	int p=compare(a,b,s1,s2);
//	
//	if(p==0)
//	{
//		char q[10090]="123";
//		strcpy(q,a);
//		strcpy(a,b);
//		strcpy(b,q);
//		cout<<'-';
//	}
//	int s3=strlen(a);
//	int s4=strlen(b);
//	for(int i=0;i<s3;i++)//4
//		a1[s3-i]=a[i]-'0';
//	for(int i=0;i<s4;i++)
//		a2[s4-i]=b[i]-'0';
//	for(int i=1;i<=s3;i++)
//	{
//		if(a1[i]<a2[i])
//		{
//			a1[i+1]--;
//			a1[i]+=10;
//		}
//		ans[i]=a1[i]-a2[i];
//	}
//	
//	while(s3>0&&ans[s3]==0)	s3--;//5
//	for(int i=s3;i>0;i--)//6
//		cout<<ans[i];
//	return 0;
//}
//高精度乘法
//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char a[100000],b[100000];
//	int c[10000],d[10000],ans[10000];
//	cin>>a;cin>>b;
//	int s1=strlen(a);int s2=strlen(b);
//	for(int i=0;i<=s1;i++)
//		c[s1-i]=a[i]-'0';
//	for(int i=0;i<s2;i++)
//		d[s1-i]=b[i]-'0';
//	for(int i=1;i<=s2;i++)
//		for(int j=1;j<=s1;j++ )
//			ans[i+j-1]+=c[j]*d[i];
//	for(int i=1;i<s1+s2;i++)
//	{
//		if(ans[i]>9)
//		{
//			ans[i+1]+=ans[i]/10;
//			ans[i]%=10;
//		}
//	}
//	int s3=s1+s2;
//	while(ans[s3]==0&&s3>1)	s3--;
//	for(int i=s3;i>=1;i--)
//		cout<<ans[i];
//	return 0;
//}
//
//
////P1067 [NOIP2009 普及组] 多项式输出
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int n,a;
//	cin>>a;//如果a为0，循环一次
//	for(int i=a;i>=0;i--)//值得注意，输出a+1项
//	{
//		cin>>n;
//		if(n)//首先自己为0，不用输出
//		{
//			//第一步，判断在前面是否输出+
//			if(i!=a&&n>0)//第一项不输出和负数不输出
//				cout<<'+';
//			if(abs(n)>1||i==0)//不是0，负数直接输出，或者是常数项直接输出
//				cout<<n;
//			//输出-1（但-1不能是常）
//			if(n==-1&&i)
//				cout<<"-";
//			//开始判断输出x，分常数项(已判)，1次项和其他项
//			if(i==1)//一次项
//				cout<<'x';
//			if(i>1) 
//				cout<<"x^"<<i;//其他项
//			
//		}	
//		
//	}
//		
//	
//}
//


//模拟乒乓球
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int f[5]={11,21};//两种赛制
	char a;
	int b[25*2500+10],n=0;
	while(1)//学习套路
	{
		cin>>a;
		if(a=='E')  break;
		else if(a=='W')  b[n++]=1;
		else if(a=='L')	 b[n++]=0;
	}
	for(int i=0;i<2;i++)//循环2次
	{
		int w=0,l=0;
		for(int j=0;j<n;j++)
		{
			w+=b[j];  l+=1-b[j];
			if(max(w,l)>=f[i]&&abs(w-l)>=2){
				cout<<w<<':'<<l<<endl;
				w=0;l=0;
			}
			
		}
		cout<<w<<':'<<l<<endl<<endl;
	}
	return 0;
}
