#include <iostream>
#include <time.h>
using namespace std;
#define Max 100
#define N 6
#define M 6

typedef struct			//�����ṹ��洢�����꣬�������ѡ���� 
{
	int hang;			// ������ 
	int lie;			// ������ 
	int xz;				// ѡ���� 
}Wei;


typedef struct			//����ջ 
{
	Wei data[Max];		// �洢ÿһ�������� 
	int top;
}Sqstack;


void ChuSqack(Sqstack*& L)		// ��ʼ��ջ 
{
	L = new Sqstack;
	L->top = -1;
}


bool KongStack(Sqstack* L)		//�ж�ջ�Ƿ�Ϊ�� 
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


bool Push(Sqstack*& L, Wei x)	//��ջ 
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


bool Pop(Sqstack*& L, Wei& e)	//��ջ 
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


bool GetStack(Sqstack* L, Wei& e)	// ȡջ��Ԫ�� 
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



void XiaoStack(Sqstack*& L)	 	//����˳��ջ 
{
	delete(L);
}


void InitiArray(int array[N + 4][M + 4])		//�������� 
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
{							//��ӡ����
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


bool Pan(int x1, int y1, int x, int y)		// �ж����һ�������ܷ�ص�ԭ�� 
{											// ���˸����� 
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


bool Hmedhl(Sqstack*& L, int x, int y)		// ���ܶ��ٺ��� 
{
	int ass[N + 4][M + 4];
	InitiArray(ass);
	Wei arr[Max], e;										// �洢ÿһ���Ľ�� 
	int hang, lie, xz, h1, l1, zhi = 1;

	bool ban;

	e.hang = x;						// �Ƚ���ʼ�������ջ 
	e.lie = y;
	e.xz = -1;
	Push(L, e);
	ass[x][y] = 1;

	while (KongStack(L))				// ջ��Ϊ��ʱѭ�� 
	{
		GetStack(L, e);				// ȡջ��Ԫ�� 
		hang = e.hang;
		lie = e.lie;
		xz = e.xz;
		if (zhi == 36 && Pan(hang, lie, x, y))			// �ж����Ƿ��������̣��Ǿ���� 
		{
			cout << "����·��Ϊ��" << endl;
			int i = 0;

			while (KongStack(L))						// ��ջ��Ԫ�ش�������У�ջ��Ԫ���������һ�� 
			{
				Pop(L, e);
				arr[i++] = e;
			}

			while (i >= 1)								// �������е�Ԫ��������� ��������� 
			{
				i--;
				cout << " " << arr[i].hang << "," << arr[i].lie << "  ";
				if (i % 6 == 0)
				{
					cout << endl;
				}
			}
			cout << endl << endl;
			cout << "����Ϊ��" << endl;				// ��ӡ���̣�������� 
			Print(ass);
			cout << endl;
			XiaoStack(L);							//����ջ 
			return true;
		}

		ban = false;
		while (xz < 8 && !ban)				// ѭ����ѡ�����ǰ������ 
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
			if (ass[h1][l1] == 0)				// ����Ϊ0ʱ���˳�ѭ����������һ�� 
			{
				ban = true;
			}
		}

		if (ban)
		{
			L->data[L->top].xz = xz;			// ����һ����ѡ�����¼����һ������ 
			e.hang = h1;
			e.lie = l1;
			e.xz = -1;
			Push(L, e);							// ��ǰ�����ջ 
			zhi++;
			ass[h1][l1] = zhi;					// �ı����� 

		}
		else
		{
			Pop(L, e);							// �޷�ǰ�У���ջ 
			ass[e.hang][e.lie] = 0;				// ����ָ�0 

			zhi--;								// �������ָֻ� 
		}
	}
	XiaoStack(L);							//����ջ 
	return false;
}


int main()
{

	int chu, shi;
	Sqstack* L1;
	ChuSqack(L1);

	cout << endl;
	cout << "�����뿪ʼ��������(2~7)��";
	cin >> chu;
	cout << "�����뿪ʼ��������(2~7)��";
	cin >> shi;

	if (chu < 2 || shi < 2 || chu > 2 + N || shi > M + 2)
	{
		cout << "�����겻�������ϣ�" << endl;
	}
	else
	{
		if (!Hmedhl(L1, chu, shi))
		{
			cout << "û��·��!";
		}
	}

	double shijian = clock() / CLOCKS_PER_SEC;
	cout << "��������ʱ��Ϊ��" << shijian << "��" << endl;
}