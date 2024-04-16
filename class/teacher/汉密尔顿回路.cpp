#include <iostream>
#include <iomanip>  //setw函数需要,对齐格式用
using namespace std;

const int maxn=105;
int board[maxn][maxn]={0};//棋盘
int num=0;
int m,n;//棋盘大小
int startX,startY;//起点位置
//马的8种走法，用数组做一个记录,左上为0号方向，顺时针下来到7号方向。
int dx[8]={-2,-2,-1, 1, 2, 2, 1,-1};
int dy[8]={-1, 1, 2, 2, 1,-1,-2,-2};



//打印棋盘
void output()
{
	for(int i = 0;i<m;i++)
    {
		for(int j = 0;j<n;j++)
			cout<<setw(3)<<board[i][j]<<" ";
		cout<<endl;
	}
}


//判断下一步是否到达起始点
int toStart(int x,int y)
{
	for(int i = 0;i<8;i++)
		if(board[x+dx[i]][y+dy[i]]==1) //当前(x,y)的位置，8个方向中的其中一个位置能回到起点
			return 1;
	return 0;
}


//马走的函数
bool moveHorse(int x,int y,int num)
{
	if(num==m*n+1&&toStart(x,y))//达到终点并且走满棋盘
    {
		output();//输出棋盘
		return true;//找到路线
	}
	int xx=0,yy=0;
    for(int i = 0;i<8;i++)//对马可以跳的8个方向进行探测,顺时针进行探测
    {
        xx=x+dx[i],yy=y+dy[i];//下一步的坐标
        if((!board[xx][yy])&&(xx>=0&&xx<m&&yy>=0&&yy<n))
        {//下一步为空并且未越界
            board[xx][yy]=num;//在棋盘上记录马的步数
            if(moveHorse(xx,yy,num+1)) return true;
            board[xx][yy]=0;//清零以便下一次查找
        }
    }
    return false;
}


int main()
{
    //输入规模
    cout<<"输入规模；";
	cin>>m>>n;
	//输入起始位置
	cout<<"输入起始位置:" ;
	cin>>startX>>startY;
	board[startX][startY]=1;//将起始位置为1
	cout<<moveHorse(startX,startY,2);
	return 0;
}



