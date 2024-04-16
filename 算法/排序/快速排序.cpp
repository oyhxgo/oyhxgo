////快速排序
//#include<iostream>
//int a[1000000];
//using namespace std;
//void qsort(int *a,int begin,int end)//begin和end为寻找区间
//{
//	int i=begin,j=end,flag=a[(i+j)/2],tmp;//以数组中间的数为keyi
//	do{
//		while(a[i]<flag)	i++;//左边的遍历,找到大的数为止
//		while(a[j]>flag)	j--;//遍历右边，找到比keyi小的数为止
//		//执行到这一步其实就是找到了需要交换的两个数
//		if(i<=j)//只要不越界
//		{
//			tmp=a[i];a[i]=a[j];a[j]=tmp;
//			i++;j--;//再进一步
//		}	
//	}while(i<=j);//直到两者相遇
//	if(begin<j)	qsort(a,begin,j);//分治思想，进行递归，重要部分
//	if(end>i)	qsort(a,i,end);//
//}
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//		cin>>a[i];	
//	qsort(a,0,n-1);
//	for(int i=0;i<n;i++)
//		cout<<a[i]<<" ";
//	return 0;
//}

