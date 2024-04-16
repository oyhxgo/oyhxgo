////1煎饼：寻找规律
//#include<stdio.h>
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	if(a==1)
//		printf("2");
//	else 
//		printf("%d",a);
//	return 0;
//	
//	
//}
//二叉树



//植物大战僵尸（找最大值）
//#include<stdio.h>
//int main()
//{
//	int a,b[100002],max;
//	scanf("%d",&a);
//	for(int i=1;i<=5;i++)
//	{
//		scanf("%d",&b[0]);
//		max=b[0];
//		for(int j=1;j<a;j++)
//		{
//			scanf("%d",&b[j]);
//			if(j==a-1&&b[j]>max)
//			{
//				continue;
//			}
//			if(b[j]>max)
//				max=b[j];
//		}
//		printf("%d\n",max);
//	}
//}

//异或和
//#include<stdio.h>
//int main()
//{
//	int a,b[100002],ans;
//	scanf("%d",&a);
//	getchar();
//	scanf("%d",&b[0]);
//	ans=b[0];
//	for(int i=1;i<a;i++)
//	{
//		scanf("%d",&b[i]);
//		ans=ans^b[i];
//	}
//	if(ans!=0)
//		printf("YES");
//	else
//		printf("NO");
//	
//	return 0;
//}


#include <stdio.h>

int main() {
	int N, Q, i, operation, x;
	scanf("%d %d", &N, &Q);
	
	int sequence[N];
	
	// 读取序列
	for(i = 0; i < N; i++) {
		scanf("%d", &sequence[i]);
	}
	
	// 执行查询操作
	for(i = 0; i < Q; i++) {
		scanf("%d %d", &operation, &x);
		if(operation == 0) {
			printf("%d\n", sequence[x-1]); // 假设输入的x是从1开始的序列索引
		} else {
			// 这里应该处理其它类型的操作，但没有足够的信息
		}
	}
	
	return 0;
}



