//欢迎来到打地鼠的游戏
#include<bits/stdc++.h>
using namespace std; 
int b[6][6];//创建棋盘
int dx[5]={0,-1,0,1,0};int dy[5]={0,0,1,0,-1};//存储四个方位
//对于队列嘛，我们知道是用来存储答案的，仿照迷宫每个格子都有自己的属性
//而且每打一次，地图变一次，所以我们可以设立一下结构体

struct node//敲击节点 
{
	int now[6][6];//为什么要count，主要是要算出最短的
	int count;//记录敲了多少只老鼠，哦不，地鼠
	int row[20];//行///存储每次敲击的那只老鼠，最后输出这个答案
	int col[20];//列/其实我们最多也尝试到10
}bg,temp,ans;


//使用BFS广度优先搜索
void Whack(int x,int y)//x,y表示初始位置，就是敲哪只老鼠，哦不，地鼠
{
	queue<node> q;//创建队列，偷懒开始，不过这个队列的作用和迷宫作用相同
	//首敲定义
	bg.count=1;//第一次敲击
	bg.row[bg.count]=x;bg.col[bg.count]=y;//导入第一次敲的老鼠位置
	for(int i=1;i<=4;i++)	
		for(int j=1;j<=4;j++)
			bg.now[i][j]=b[i][j];	//导入敲前的地图
	for(int i=0;i<5;i++)//包括他本身我们也一起处理
		if(x+dx[i]<=4&&x+dx[i]>0&&y+dy[i]<=4&&y+dy[i]>0)//不越界
			bg.now[x+dx[i]][y+dy[i]]=1-b[x+dx[i]][y+dy[i]];//开始敲 ，执行反处理
	q.push(bg);//推入第一个敲击路线，开始搜索
	
	
	//每次全排列返回位置
	while(!q.empty()){//这里其实就是永远的1
		//读者注意，这里的bg现在是当前路线的意思
		bg=q.front();			//取出当前全排列中未完成路线
		q.pop();				//取完就删，否则占我内存
		int flag=1;	//成功否，成功为1，不成功为0
	//判断游戏成功了吗？
		for(int j=1;j<=4;j++)//遍历
		{
			for(int k=1;k<=4;k++)	
				if(bg.now[j][k])	//还没成功 
				{
					flag=0;			//判断标志变为0 
					break;		
				}
			if(!flag)		//跳出二重循环
				break;
		}
	//成功，寻找最优解
	if(flag)				
	{						
		if(ans.count>bg.count)		//看看是不是更短
		{
			for(int y=1;y<=bg.count;y++)	//导入这个较短路线的解法 
			{
				ans.row[y]=bg.row[y];
				ans.col[y]=bg.col[y];
			}
			ans.count=bg.count;
		}
		return;
	}
	if(bg.count>=10)		//样例中没有一个路线超过8的，所以这里保险一点，也偷懒一下，只选到10
		continue;
	//不成功，继续开始`敲击	
	for(int j=1;j<=4;j++){//
		for(int k=1;k<=4;k++)
		{
			if(bg.now[j][k])		//遍历当前的地图，看看哪只老鼠没下地 
			{
				temp.count=bg.count+1;	//，找到，开敲，敲地鼠次数加1//此时全排列进行到的支路 
				for(int m=1;m<=4;m++)
					for(int n=1;n<=4;n++)
						temp.now[m][n]=bg.now[m][n];	//将敲前的地图存储到新结构体中 	
				for(int o=0;o<5;o++)
				{
					if(j+dx[o]<=4&&j+dx[o]>=1&&k+dy[o]<=4&&k+dy[o]>=1)	//找图内的点 
						temp.now[j+dx[o]][k+dy[o]]=1-temp.now[j+dx[o]][k+dy[o]];//将所敲地鼠及其周围四格状态进行改变 ,
				}//早就想单独把这个做成函数了，但是二维数组，我不会
					
				for(int l=1;l<=bg.count;l++)	//存储之前每次敲的位置 
				{
					temp.row[l]=bg.row[l];
					temp.col[l]=bg.col[l];
				}
				temp.row[temp.count]=j;
				temp.col[temp.count]=k;		//存储这次敲的位置 
				q.push(temp);//导入队列//对于第一次而言，第一次敲完展开，得到全排列
			}
			}
		}	
	}
}


void print()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{	
			if(b[i][j]==1)
				cout<<"●";//直接cv（扶额苦笑）
			else if(b[i][j]==0)
				cout<<"○";
		}
		cout<<endl;
	}
}

void gj(int x,int y)
{
	for(int i=0;i<5;i++)
		if(x+dx[i]<=4&&x+dx[i]>0&&y+dy[i]<=4&&y+dy[i]>0)
			b[x+dx[i]][y+dy[i]]=1-b[x+dx[i]][y+dy[i]];
}
void zuobiao(int p,int &x,int&y)
{
	if(p>0&&p<=16){
		if(p%4==0)
		{
			x=5-p/4;y=4;
		}
		else{
			x=4-p/4;
			y=p%4;
		}
}
}

int main(){
	ans.count=50;
	int a[6][6],o=1,p=1,x,y;
	cout<<"//////////////欢迎来到打地鼠游戏！//////////////"<<endl;
	cout<<"接下来您将会看到一个四乘四的棋盘，其大致坐标方位如下："<<endl;
	for(int i=4;i>=1;i--)//样例棋盘
	{		for(int j=1;j<=4;j++)
		{
			a[i][j]=o;
			o++;
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
			cout<<setw(3)<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"在接下来的测试数据中，请您给出初始状态下哪些位置会出现地鼠（当输入0时代表结束）："<<endl;
	for(int i=1;i<=4;i++)//初始化原本棋盘
		for(int j=1;j<=4;j++)
			b[i][j]=0;
	while(p){//这里本来的思路是为了防止两边越界，第一个元素设为（1,1）
		cin>>p;//后面想想，好像也没必要（0,0）的算法其实也不影响
		if(p>0&&p<=16){
		if(p%4==0)
		{
			x=5-p/4;y=4;
		}
		else{
		x=4-p/4;
		y=p%4;
		}
		b[x][y]=1;
		}
	}
	cout<<"分析数据成功！初始转态如下："<<endl;	cout<<"(ps:●代表有地鼠，○代表洞)"<<endl<<endl;
	print();cout<<endl;
	for(int i=1;i<=4;i++)    //bfs遍历 第一次锤地鼠的格子 
	{
		for(int j=1;j<=4;j++)
		{
			if(b[i][j])
			{
				Whack(i,j);
			}
		}
	}
	if(ans.count<=9&&ans.count>0)	//步数小于等于10说明有至少一个解 
	{
		cout<<"分析成功！现在为您演习最短路径（这个操作后世称为挂机）"<<endl<<endl;
		for(int i=1;i<=ans.count;i++)
		{
			int x,y;
			cout<<"敲击"<<4*(4-ans.row[i])+ans.col[i]<<"号位"<<endl;
			zuobiao(4*(4-ans.row[i])+ans.col[i],x,y);
			gj(x,y);
			print();
			cout<<endl;
		}
		cout<<"综上，最短路径为：";
		for(int i=1;i<=ans.count;i++)
			cout<<4*(4-ans.row[i])+ans.col[i]<<" ";	//将坐标转换为序号输出 
		cout<<endl<<endl;
		double shijian = clock() / CLOCKS_PER_SEC;
		cout << "本解法耗时" << shijian << "秒" << endl;
	}
	else
		cout<<"此题在你现在的电脑配置下无解！"<<endl;
	return 0;
}



//思路分析：
//其实本质敲地鼠就是是三个阶段
//敲部分：寻找还在地上的地鼠，敲他，count+1，然后存储敲前的地图，变化敲后的地图，存储敲击线路
//判断是否成功
//判断是不是最优解
//敲，判断游戏成功了吗？判断是不是最优解
