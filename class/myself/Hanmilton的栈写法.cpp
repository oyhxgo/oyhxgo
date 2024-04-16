//Hamilton回路 	迷宫的做法 
#include<bits/stdc++.h>
using namespace std;
#define MAX 105
int board[MAX][MAX]={0};//初始化为0
int dx[8]={-2,-2,-1,1,2,2,1,-1};
int dy[8]={-1,1,2,2,1,-1,-2,-2};
int m,n,a,b;
int PATH[MAX][MAX]={0};
//这个是每个格子的属性表 
typedef struct
{
	int row;	//行 row
	int col;	//列 column
	int loc;  //走到下一个邻方位号 	
}BOX;
//这是个栈，我们知道栈的本质是一维数组，本质存储着数据只能一维打印
typedef struct 
{
	BOX data[MAX];//10*10的话设立为105妥当，用于存放最终路线 
	int top; 
}ST;//顺序栈类型

void Initsqstack(ST *&s)
{
	s=new ST;
	s->top=-1;//置为空表 
}
//判断是否为空,空返回真 
bool emptystack(ST *s)
{
	return (s->top==-1);
} 
void Push(ST *&s,BOX a)//实现功能插入abcde  
{
	s->top++;
	s->data[s->top]=a;
}
bool Housepath(int a,int b,int xe,int ye)
{
	BOX e;
	e.row=a;e.col=b;
	ST *end;
	Push(end,e);
	
	
	
	
	
}
int main()
{
	
	
	
	
	for(int i=0;i<=0;i++){
		//TODO
	}
	
	
	return 0;
}
