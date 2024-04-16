////递推爬楼梯
//#include<stdio.h>
//int oy(int n)
//{
//	if(n==1||n==2)
//		return 1;
//	if(n==3)
//		return 2;
//	else 
//		return oy(n-1)+oy(n-3);
//}
//int main()
//{
//	int a[1000],i=0;
//	while(scanf("%d",&a[i])!=EOF)
//	{
//		a[i]=oy(a[i]);
//		i++;
//	}
//	for(int j=0;j<i;j++)
//	{
//		printf("%d\n",a[j]);
//	}
//	return 0;
//}

////超级楼梯
//#include<stdio.h>
//int oy(int n)
//{
//	if(n==1)
//		return 1;
//	if(n==2)
//		return 1;
//	else
//		return oy(n-1)+oy(n-2);//同理的思维，以3（2和1），4（3和2）得出出口必须有1或2
//}
//int main()
//{
//	int i,a,b[10000];
//	scanf("%d",&a);
//	for(i=0;i<a;i++)
//	{
//		scanf("%d",&b[i]);
//		b[i]=oy(b[i]);
//	}
//	for(int j=0;j<i;j++)
//	{
//		printf("%d\n",b[j]);
//	}
//	return 0;
//}

////成群的奶牛
//#include<stdio.h>
//int a,b;
//int o=1;//o代表有几群奶牛
//void oy(int n)
//{
//	int p=(n-b)/2;
//	int l=(n+b)/2;//先定义两个分裂数出来
//	if(p+l!=n)
//		return;//不返回值(定义需为void)，用于跳出
//	o++;
//	if(p>b)
//		oy(p);
//	if(l>b)
//		oy(l);
//	
//}
//int main()
//{
//
//	scanf("%d %d",&a,&b);
//	oy(a);
//	printf("%d",o);
//	return 0;
//	
//}

//全排列
//#include<stdio.h>
//int oy(int n)
//{
//	if(n==1)
//		return 1;
//	else if(n==2)
//		return 2;
//	else
//		return n*oy(n-1);
//}
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	printf("%d",oy(a));
//	
//}

//#include<stdio.h>
//int p[10000]={0},l[1000]={0};
//int k;
//void oy(int n)//如果把这个排列看成盒子，那n就是你走到第几个盒子了
//{
//	if(n==k+1)//走到第k+1个盒子则立马结束，
//	{
//		for(int i=1;i<=k;i++)
//			printf("%d ",p[i]);//立马打印这一行
//		printf("\n");
//		return;//结束
//	}
//	for(int i=1;i<=k;i++)
//	{
//		if(l[i]==0)
//		{
//			p[n]=i;//将号码放到盒子里
//			l[i]=1;//标记他被使用了
//			oy(n+1);//走到下一个盒子，123或者132；然后走到最后一个盒子，return，之后1的排列结束，所有的数字变成都没被使用，继续2
//			l[i]=0;
//		}	
//	}
//	return;
//}
//int main()
//{
//	scanf("%d",&k);
//	oy(1);
//	return 0; 
//	
//}

////初级快速幂（分治或者递归思想）
//#include<bits/stdc++.h>//c++的头文件
//using namespace std;
//long long oy(long long a, long long n, long long b)//二分法递归快速幂（其实就是分治算法，但是我喜欢称之为递推）
//{//首先这是一个计算a的n次方的函数（记住哦）
//	if (n <= 1)				//递归出口设置为当指数为1
//							//当n被分解到1或者等于0(这里只考虑者两种情况)
//	{						//0去分解答案为1
//		if (n == 0)
//			return 1 % b;
//		else				//1答案为a的1次幂去%b
//			return a % b;
//	}						//理解这里的递推！！
//	long long half = n / 2;					//二分法开始了（一半赋给half）
//	long long  tem= oy(a, half, b);			//计算少一半次数的a的n/2次方==临时tem
//	if (n % 2 == 0)							//对指数操作：
//	{
//		return (tem * tem) % b;				//能被2整除即可以用tem*tem求出所有
//	}
//	else
//	{
//		return (tem * oy(a, half + 1, b)) % b;//不能的话就是乘多一项（int会砍掉小数，自然得到的tem是小的那一个）
//	}
//}
//int main()
//{
//	long long int a, n, b,i=0,o[100000];
//	while (scanf("%lld %lld %lld", &a, &n, &b) != EOF)
//	{
//		o[i]=oy(a,n,b);
//		i++;
//	}
//	for(int j=0;j<i;j++)
//	{
//		printf("%d\n",o[j]);
//	}
//	return 0;
//}
//
//#include<stdio.h>
//long long oy(int a,int n,int b)
//{
//	if(n<=1)
//	{
//		if(n==1)
//			return a%b;
//		if(n==0)
//			return 1%b;
//	}
//	int p=n/2;
//	long long tem=oy(a,p,b);
//	if(n%2==0)
//		return tem*tem%b;
//	if(n%2!=0)
//		return tem*tem*a%b;
//}
//
//int main()
//{
//	int a,b,c;
//	scanf("%d %d %d",&a,&b,&c);
//	long long k=oy(a,b,c);
//	printf("%lld",k);
//	
//}

//分型三角形
#include<bits/stdc++.h>
using namespace std;
string s[1024][2048];
int a[4] = { 1,2,2,4 };
int h = 2, l = 4;
void turn_right()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < l; j++)
			s[i][l + j] = s[i][j];
}
void turn_down()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < l; j++)
			s[h + i][l / 2 + j] = s[i][j];
}
int main()
{
	int n;
	for (int i = 0; i < 1024; i++)
		for (int j = 0; j < 2048; j++)
			s[i][j] = " ";
	cin >> n;
	n -= 1;
	s[0][0] = s[1][1] = "/";
	s[0][1] = s[0][2] = "_";
	s[0][3] = s[1][2] = "\\";
	for (int i = 0; i < n; i++)
	{
		turn_right();
		turn_down();
		h *= 2;
		l *= 2;
	}
	for (int i = h - 1; i >= 0; i--)
	{
		for (int j = 0; j < l; j++)
			cout << s[i][j];
		cout << endl;
	}
	return 0;
}

