//Hamilton回路 	迷宫的做法 
#include<bits/stdc++.h>//解决间隔第一种做法是C++自带的函数setw(头文件为iomanip)
using namespace std;//第二种为直接使用c语言printf（“%3d”）
#define MAX 105
int m,n,a,b;//妙用全局变量，写在这里我们就不必要给函数一直传这几个参数了

//创造棋盘
int board[MAX][MAX]={0};//初始化为0

//存放八个方向
int dx[8]={-2,-2,-1,1,2,2,1,-1};
int dy[8]={-1,1,2,2,1,-1,-2,-2};
//全部写完后看这里
//思考为何答案和图片不同，更改数据,我们注意从4到5这一步
//勇敢猜一下4为基点，5（-2，-1）是第一个搜索点
//很好，猜对了，所以呀，漫漫人生路，总能对几步

bool finish(int x,int y)//结束条件为下一部能否回到起点
{
	for(int i=0;i<=7;i++)
		if(board[x+dx[i]][y+dy[i]]==1)
			return true;
	return false; 
}
//打印棋盘
void print(int m,int n)
{
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			printf("%3d ",board[i][j]);
		cout<<endl;
	}
}
bool Housepath(int a,int b,int num)//采用迷宫思想，分别搜索棋盘中可以走的路线
{//直到找到一个解为止，其实就是dfs深度优先搜索
	//由于本质上还是个递归，
	if(num==m*n+1&&finish(a,b)){//找到一解退出条件
		print(m,n);
		return true;
	}
	//从当前位置开始深搜
	int x1,y1;
	for(int i=0;i<=7;i++)
	{
		x1=a+dx[i];y1=b+dy[i];
		if((board[x1][y1]==0)&&(x1>=0&&x1<m&&y1>=0&&y1<n))//下一空可走且不越界棋盘
		{
			board[x1][y1]=num;//开始填充棋盘
			if(Housepath(x1,y1,num+1))//ps1//dfs开始，这个点可以就一直探索，值得注意，结束标志在最上面的那个if
				return true;//如果最终找到了，返回true，这里相当于一直退出所有之前的递归，不过真正能打印的只有终点的那一次递归
			board[x1][y1]=0;//如果这不是解，则会被return false，然后不满足每一点都被赋值为0，直到有一点满足Housepath
		}
	}
	return false;
}
int main()
{

	cout<<"请输入您想创建的棋盘规模：";
	cin>>m>>n;
	cout<<"请输入初始位置坐标：";
	cin>>a>>b;
	cout<<"为您找到一条可解的路线："<<endl;
	board[a][b]=1;//初始坐标赋值
	Housepath(a,b,2);
	return 0;
}


//ps1
//为什么num+1不能是++num
//因为回溯回来的时候num也要跟着回溯



//就在昨天的明天也就是今天我突然发现了一个很破防的事情
//#include<iomanip>中有一个setbase函数可以把十进制数转化为任意进制，只需要
//cout<< setbase(8) << 255 << endl;
//这么写就可以把255的十进制转化为8进制
//我.....不过，没事，你没努力过，又怎么能知道放弃的快乐呢


 
