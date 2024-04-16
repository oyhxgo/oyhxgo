#include <iostream>
#include <time.h>
using namespace std;
#define Max 100
#define N 6
#define M 6

typedef struct			//构建结构体存储横坐标，纵坐标和选择方向 
{
	int hang;			// 横坐标 
	int lie;			// 纵坐标 
	int xz;				// 选择方向 
}Wei;


typedef struct			//构建栈 
{
	Wei data[Max];		// 存储每一步的坐标 
	int top;
}Sqstack;


void ChuSqack(Sqstack*& L)		// 初始化栈 
{
	L = new Sqstack;
	L->top = -1;
}


bool KongStack(Sqstack* L)		//判断栈是否为空 
{
	if (L->top == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool Push(Sqstack*& L, Wei x)	//进栈 
{
	if (L->top == Max - 1)
	{
		return false;
	}
	else
	{
		L->top++;
		L->data[L->top] = x;
		return true;
	}
}


bool Pop(Sqstack*& L, Wei& e)	//出栈 
{
	if (L->top == -1)
	{
		return false;
	}
	else
	{
		e = L->data[L->top];
		L->top--;
		return true;
	}
}


bool GetStack(Sqstack* L, Wei& e)	// 取栈顶元素 
{
	if (L->top == -1)
	{
		return false;
	}
	else
	{
		e = L->data[L->top];
		return true;
	}
}



void XiaoStack(Sqstack*& L)	 	//销毁顺序栈 
{
	delete(L);
}


void InitiArray(int array[N + 4][M + 4])		//建立棋盘 
{
	for (int i = 0; i < N + 4; i++)
	{
		for (int j = 0; j < M + 4; j++)
		{
			array[i][j] = -1;
		}
	}

	for (int i = 2; i < N + 2; i++)
	{
		for (int j = 2; j < M + 2; j++)
		{
			array[i][j] = 0;
		}
	}
}


void Print(int Chess[N + 4][M + 4])
{							//打印棋盘
	int i, j;

	for (i = 2; i < N + 2; i++)
	{
		for (j = 2; j < M + 2; j++)
		{
			cout << " " << Chess[i][j] << '\t';
		}

		printf("\n");
	}
}


bool Pan(int x1, int y1, int x, int y)		// 判断最后一个步马能否回到原点 
{											// 共八个方向 
	if (x1 - 1 == x && y1 - 2 == y)
	{
		return true;
	}

	else if (x1 - 2 == x && y1 - 1 == y)
	{
		return true;
	}

	else if (x1 - 2 == x && y1 + 1 == y)
	{
		return true;
	}

	else if (x1 - 1 == x && y1 + 2 == y)
	{
		return true;
	}

	else if (x1 + 1 == x && y1 + 2 == y)
	{
		return true;
	}

	else if (x1 + 2 == x && y1 + 1 == y)
	{
		return true;
	}

	else if (x1 + 2 == x && y1 - 1 == y)
	{
		return true;
	}

	else if (x1 + 1 == x && y1 - 2 == y)
	{
		return true;
	}

	else
	{
		return false;
	}
}


bool Hmedhl(Sqstack*& L, int x, int y)		// 汉密尔顿函数 
{
	int ass[N + 4][M + 4];
	InitiArray(ass);
	Wei arr[Max], e;										// 存储每一步的结果 
	int hang, lie, xz, h1, l1, zhi = 1;

	bool ban;

	e.hang = x;						// 先将初始的坐标进栈 
	e.lie = y;
	e.xz = -1;
	Push(L, e);
	ass[x][y] = 1;

	while (KongStack(L))				// 栈不为空时循环 
	{
		GetStack(L, e);				// 取栈顶元素 
		hang = e.hang;
		lie = e.lie;
		xz = e.xz;
		if (zhi == 36 && Pan(hang, lie, x, y))			// 判断马是否跳完棋盘，是就输出 
		{
			cout << "坐标路径为：" << endl;
			int i = 0;

			while (KongStack(L))						// 将栈中元素存进数组中，栈顶元素在数组第一个 
			{
				Pop(L, e);
				arr[i++] = e;
			}

			while (i >= 1)								// 将数组中的元素逆向输出 ，坐标输出 
			{
				i--;
				cout << " " << arr[i].hang << "," << arr[i].lie << "  ";
				if (i % 6 == 0)
				{
					cout << endl;
				}
			}
			cout << endl << endl;
			cout << "棋盘为：" << endl;				// 打印棋盘，棋盘输出 
			Print(ass);
			cout << endl;
			XiaoStack(L);							//销毁栈 
			return true;
		}

		ban = false;
		while (xz < 8 && !ban)				// 循环，选择马的前进方向 
		{
			xz++;
			switch (xz)
			{
			case 0: h1 = hang - 1, l1 = lie - 2; break;
			case 1: h1 = hang - 2, l1 = lie - 1; break;
			case 2: h1 = hang - 2, l1 = lie + 1; break;
			case 3: h1 = hang - 1, l1 = lie + 2; break;
			case 4: h1 = hang + 1, l1 = lie + 2; break;
			case 5: h1 = hang + 2, l1 = lie + 1; break;
			case 6: h1 = hang + 2, l1 = lie - 1; break;
			case 7: h1 = hang + 1, l1 = lie - 2; break;
			}
			if (ass[h1][l1] == 0)				// 坐标为0时，退出循环，进行下一步 
			{
				ban = true;
			}
		}

		if (ban)
		{
			L->data[L->top].xz = xz;			// 将上一步的选择方向记录在上一个坐标 
			e.hang = h1;
			e.lie = l1;
			e.xz = -1;
			Push(L, e);							// 当前坐标进栈 
			zhi++;
			ass[h1][l1] = zhi;					// 改变棋盘 

		}
		else
		{
			Pop(L, e);							// 无法前行，出栈 
			ass[e.hang][e.lie] = 0;				// 坐标恢复0 

			zhi--;								// 棋盘数字恢复 
		}
	}
	XiaoStack(L);							//销毁栈 
	return false;
}


int main()
{

	int chu, shi;
	Sqstack* L1;
	ChuSqack(L1);

	cout << endl;
	cout << "请输入开始的行坐标(2~7)：";
	cin >> chu;
	cout << "请输入开始的纵坐标(2~7)：";
	cin >> shi;

	if (chu < 2 || shi < 2 || chu > 2 + N || shi > M + 2)
	{
		cout << "该坐标不在棋盘上！" << endl;
	}
	else
	{
		if (!Hmedhl(L1, chu, shi))
		{
			cout << "没有路径!";
		}
	}

	double shijian = clock() / CLOCKS_PER_SEC;
	cout << "本次运行时间为：" << shijian << "秒" << endl;
}