

//1.A
#include<stdio.h>
int main()
{
	int a,c[10000]={0},ans=0;
	scanf("%d",&a);
	getchar();
	char b[a+1];
	gets(b);
	for(int i=1;i<=a;i++)
	{
		if(c[b[i]]=1)
			ans++;
		else
		{
			c[b[i]]=1;
			ans+=2;
		}
		
	}
	printf("%d",ans);
}
