#include<stdio.h>
int main()
{
    int a,b,m,n;
    scanf("%d %d",&a,&b);
    m=a;
    n=b;
    int i=1;
    while(i)
    {
        i=m%n;
        m=n;
        n=i;
    }
    printf("%d",m);
    
}