#include <iostream>
using namespace std;
#define Maxsize 100 

//存储当前坐标的结构体 
typedef struct
{
	int i;
	int j;
	int di;
}Box;

//栈结构体 
typedef struct
{
	int top;
	Box date[Maxsize];
}StType;

//初始化 
void InitStack(StType *& S)
{
	S=new StType;
	S->top=-1;
}

//销毁 
void Destroy(StType *&S)
{
	delete S;
}

//判断栈是否空 
bool EmptyStack(StType *S)
{
	return S->top==-1;
}

//进栈 
bool PushStack(StType *&S,Box e)
{
	if(S->top==Maxsize-1)	return false;
	S->top++;
	S->date[S->top]=e;
	return true;
}

//退栈 
bool PopStack(StType *&S,Box &e)
{
	if(S->top==-1)	return false;
	e=S->date[S->top];
	S->top--;
	return true;
}

//取栈顶元素 
bool GetTop(StType *S,Box &e)
{
	if(S->top==-1)	return false;
	e=S->date[S->top];
	return true;
}
//复制栈
void CopySqStack(StType *&New,StType *Old)
{ 
	int i;
	for(i=0;i<=Old->top;i++)
		New->date[i]=Old->date[i];
	New->top=Old->top;
}


 //方法一:优点：简单容易理解。缺点：比较麻烦需要细心检查，防止数组越界等问题
int n,m,sx,sy;//设定为全局变量 
void MaPath(int xi,int yi,int m,int n)
{
	//设置棋盘 //////////////////////////////////////////////////// 
	int ma[m+4][n+4];//外围两圈是边界（因为马可以走2格或者一格，所以边界应该扩大4） 
	for(int i=0;i<m+4;i++)
	{
		for(int j=0;j<n+4;j++)
		{
			if(i==0 ||i==1||j==0||j==1||j==n+2||j==n+3||i==m+3||i==m+2) //把边界赋值1，能走的部分设为0 
				ma[i][j]=1;
			else 
				ma[i][j]=0;
		}
	}
	////////////////////////////////////////////////////////////////
	
	int i,j,di,i1,j1;
	StType *s1,*result;//s1是主要的栈,result是负责输出的栈（下面会详细解释） 
	InitStack(s1); 
	InitStack(result);          
	Box e;                               //定义一个Box类型的结构体e存放当前i，j，di 
	
	e.i=xi; e.j=yi;	e.di=0;              //结构体e初始化在起点 
	PushStack(s1,e);                     //起点进栈 
	ma[xi][yi]=1;                        //起点值为1.避免重复走 
	int num=1;                           //记录进栈个数 
	int flag=1;                          //判断最后是否到达起点 
	while(!EmptyStack(s1))
	{                      
		GetTop(s1,e);                     //取栈顶坐标
		i=e.i;j=e.j; di=e.di;             //当前坐标为栈顶坐标 
		
		bool find;
		find=false;                       //判断可走方位的标志 
		while(di<8 && !find)
		{
			di++;
			switch(di)                    //选择马移动方位 
			{
				case 1: i1=i-2; j1=j+1;break;
				case 2: i1=i-1; j1=j+2;break;
				case 3: i1=i+1; j1=j+2;break;
				case 4: i1=i+2; j1=j+1;break;
				case 5: i1=i+2; j1=j-1;break;
				case 6: i1=i+1; j1=j-2;break;
				case 7: i1=i-1; j1=j-2;break;
				case 8: i1=i-2; j1=j-1;break;
			}
			
			if(ma[i1][j1]==0)	find=true;       //找到走的方位退出循环 
			else if(i1==xi&&j1==yi && num==n*m)  //最后找到起点位置并且栈数量等于数字个数 
			{   
				CopySqStack(result,s1); 
				int cout=n*m;                    //路径个数 
				while(!EmptyStack(result))
				{
					PopStack(result,e);              //从终点开始退栈取坐标 
					ma[e.i][e.j]=cout--;         //从终点回去起点赋值 
				} 	
				flag=0;                          //flag终点回到起点的标志 
			}
		}
		
		if(flag==0)		break;
		//这里直接选择break是因为路径个数太多了，在这里就直接找到一条路径就退出了 
		if(find)
		{
			s1->date[s1->top].di=di;            //修改原栈顶的di 
			e.i=i1;  e.j=j1;  e.di=0;           //现找到的方位的di初始化为0 
			PushStack(s1,e);                    //可走的方位进栈
			num++;                              //进栈个数加1 
			ma[i1][j1]=1;                      //可走的方位变为1，避免重复 
		}
		else                                    //八个方位都不可走 
		{
			PopStack(s1,e);                     //退栈 
			num--;                              //栈个数减1 
			ma[e.i][e.j]=0;                     //退栈方块变回可走方块 
		} 
	
	}	
	//输出/////////////////////////////////////////////////////
	for(int i=2;i<m+2;i++)                       
	{
		for(int j=2;j<n+2;j++)
		{
			cout<<ma[i][j]<<"	";
		}
		cout<<endl;
	}
	 
	//////////////////////////////////////////////////////////// 
	Destroy(s1);
}


//方法二递归(所谓的深度优先搜索）优点:代码简洁,缺点:运行时间会比方法一慢
bool Chess[20][20];//记录每个点有没有走过的(默认都是false)
int dx[8]={-1,1,2,2,1,-1,-2,-2};//利用两个数组来实现马的行动 
int dy[8]={2,2,1,-1,-2,-2,-1,1};	
StType *result;//定义一个用于输出的栈(一定要放在外面，充当全局) 
int sum=0;//记录路径个数 
int Play[20][20];//用于输出结果的数组
void dfs(StType *&s2,int x,int y,int num)
{
	Box e; //定义一个Box类型的结构体e存放当前i，j，di 
	if(!Chess[x][y])//如果没走过则真,反之则假 
	{
		Chess[x][y]=true;
		e.i=x;
		e.j=y;
		PushStack(s2,e);//没走过的点直接入栈 
	} 
	
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];//模拟一下就可以实现马的行动(有点高级需要时间理解）
		if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&(!Chess[nx][ny]))//边界问题考虑以及保证马走的下一个点没走过 
		{
			dfs(s2,nx,ny,num+1);//步数+1,然后对新的点继续递归 
			PopStack(s2,e);//当递归回来之后一定要出栈(回溯法） 
			Chess[nx][ny]=false;//记得也要把标记改为false,这样才能往后寻找 
		} 
		else if(num==n*m&&sx==nx&&sy==ny)//假如已经走完了，并且可以判断到最后一步可以到终点
		{
				sum++;
				if(sum==1)//因为只需要一个，所以sum==1就输出 
				{
					CopySqStack(result,s2);//复制一个新的栈是为了不改变记录路径的栈,不然无法重复执行，找到符合的所有路径 
					int z=num;
					while(PopStack(result,e))
						Play[e.i][e.j]=z--;
					for(int i=1;i<=m;i++)
					{
						for(int j=1;j<=n;j++)
							cout<<Play[i][j]<<"   ";
						cout<<endl;
					}
				}
					PopStack(s2,e);
					return;
		}
	} 
	return;
}

int main()
{
	cout<<"使用方法一"<<endl; 
	cout<<"请输入规模：";cin>>m>>n;
	cout<<"请输入起始位置(设置第一个点从0,0开始）：";cin>>sx>>sy; 
	MaPath(sx+2,sy+2,m,n);//起点在（2，2）所以输入后横纵坐标要加2 
	cout<<"现在使用方法二（递归）" ;
	cout<<"请输入规模：";cin>>m>>n;
	cout<<"请输入起始位置(设置了第一个点从1,1开始）：";cin>>sx>>sy; 
	StType *s;
	InitStack(s);//因为递归是不断调用函数，所以要先创建栈 
	InitStack(result);
	dfs(s,sx,sy,1);//一开始步数为1; 
	cout<<"输出满足条件的步数(可能有点久：";
	cout<<sum; 
	
	
	return 0;
}
