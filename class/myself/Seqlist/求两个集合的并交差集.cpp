#include<iostream>
using namespace std;
#define MAX 100000
typedef char ch;
typedef struct
{
	ch data[MAX];
	int length;
}Sqlist;
//初始化 
void Initsqlist(Sqlist *&L)
{
	L=new Sqlist;
	L->length=0;
}
//插入 
bool Insertsqlist(Sqlist *&L,int i,ch e)
{
	if(i<1||i>L->length+1)//同样的地方不要跌倒两次 
		return false;
	i--;
	for(int j=L->length;j>i;j--)
	{
		L->data[j]=L->data[j-1];
	}
	L->data[i]=e;
	L->length++;
	return true;
} 
void Displaysqlist(Sqlist *L)
{
	for(int j=0;j<L->length;j++)
		cout<<L->data[j]<<"   ";
	cout<<endl<<endl;
}
//获取
bool Getelem(Sqlist *L,int i,ch &tmp)
{
	if(i<1||i>=L->length+1)
		return false;
	i--;
	tmp=L->data[i];
	return true;
}
//查找
int Findelem(Sqlist *L,ch e)
{
	int k=0;
	while(k<L->length&&L->data[k]!=e){
		k++;	
	}
	if(k>=L->length)
		return 0;
	else
		return k+1;
}
//删除
void deletesqlist(Sqlist *L,int i)
{
	i--; 
	for(int j=i;j<L->length-1;j++)
	{
		L->data[j]=L->data[j+1];
	} 
	L->length--;
}
//求并集
void unionList(Sqlist *L1,Sqlist *L2,Sqlist *&L3)
{
	ch e;
	for(int i=1;i<=L1->length;i++)//填充L3
	{
		Getelem(L1,i,e);
		Insertsqlist(L3,i,e);
	}
	int len=L1->length;
	for(int j=1;j<=L2->length;j++)
	{
		Getelem(L2,j,e);
		if(!Findelem(L1,e))
		{
			Insertsqlist(L3,++len,e);
		}
	}	
} 
//交集
void interList(Sqlist *L1,Sqlist *L2,Sqlist *&L3)
{
	ch e;
	int len=0;
	for(int j=1;j<=L2->length;j++)
	{
		Getelem(L2,j,e);
		if(Findelem(L1,e))
		{
			Insertsqlist(L3,++len,e);
		}
	}
}
//差集
void Differsqlist(Sqlist *L1,Sqlist *L2,Sqlist *&L3)
{
	ch e;int a=0;
	for(int i=1;i<=L1->length;i++)//填充L3
	{
		Getelem(L1,i,e);
		Insertsqlist(L3,i,e);
	}
	for(int j=1;j<=L2->length;j++)
	{
		Getelem(L2,j,e);
		a=Findelem(L3,e);
		if(a)
			deletesqlist(L3,a);
	}
	
}
void Destroysqlist(Sqlist *&L)
{
	delete L;
}
int main()
{
	ch A[5]={'A','B','C','D'};
	ch B[6]={'B','C','E','F','G'}; 
	Sqlist *L1,*L2,*L3;
	Initsqlist(L1);Initsqlist(L2);Initsqlist(L3);
	//插入
	for(int i=0;i<4;i++)
	{
		if(!Insertsqlist(L1,i+1,A[i]))
			cout<<"插入失败,检查插入代码"<<endl; 
	} 
	for(int i=0;i<5;i++)
	{
		if(!Insertsqlist(L2,i+1,B[i]))
			cout<<"插入失败,检查插入代码"<<endl; 
	}	 
	//输出两个顺序表
	cout<<"线性表A的元素为：";Displaysqlist(L1);
	cout<<"线性表B的元素为：";Displaysqlist(L2);
	//并集 ∪
	unionList(L1,L2,L3);
	cout<<"A∪B为：";Displaysqlist(L3);
	//交集∩
	Sqlist *L4;Initsqlist(L4);
	interList(L1,L2,L4); 
	cout<<"A ∩B为：";Displaysqlist(L4);
	//差集
	Sqlist *L5;Initsqlist(L5);
	Differsqlist(L1,L2,L5);
	cout<<"A-B为：";Displaysqlist(L5);
	
	Sqlist *L6;Initsqlist(L6);
	Differsqlist(L2,L1,L6);
	cout<<"B-A为：";Displaysqlist(L6);
	//释放
	Destroysqlist(L1);Destroysqlist(L2);Destroysqlist(L3);
	Destroysqlist(L4);Destroysqlist(L5);Destroysqlist(L6);
	return 0;
}
//求两个集合的交集，并集，差集
//分析所需函数
//1.输出顺序表
//0.插入 
//2.求并集:选择一个顺序表，然后遍历他，寻找另一个顺序表不同元素插入 
//3.求交集：寻找相同元素 
//4.求差集：1对2，寻找1中与2相同的元素，找到就删除1的 
