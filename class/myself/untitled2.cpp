#include <iostream>
#include <cassert>
using namespace std;
#define MAXSIZE 40
typedef char ElemType;
struct SqQueue
{
	ElemType data[MAXSIZE];
	int front, rear;
};
void InitSqQueue(SqQueue*& q)
{
	q = new SqQueue;
	q->front = q->rear = 0;
}
void DestroySqQueue(SqQueue*& q)
{
	delete q;
}
bool QueueEmpty(SqQueue* q)
{
	return q->front == q->rear;
}
bool enQueue(SqQueue*& q, ElemType e)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return false;
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (QueueEmpty(q))
		return false;
	q->front = (q->front + 1) % MAXSIZE;
	e = q->data[q->front];
	return true;
}
void change1(SqQueue*& q, double m,int n)//m为测试数据,n为保留的位数
{
	for (int i = 1; i <= n; i++)
	{
		m = m * 2;
		if (m > 1)
		{
			if (!enQueue(q, 1))
				cout << "插入失败";
			m = m - 1;
		}
		else if (m < 1)
		{
			if (!enQueue(q, 0))
				cout << "插入失败";
		}
		else if (m == 1)
		{
			if (!enQueue(q, 1))
				cout << "插入失败";
			break;
		}
	}
}
void change2(SqQueue*& q,double m, double n)//m为测试数据，n为转换的进制
{
	for (int i = 1; i <= 10;i++)//保留十位小数；
	{
		int a;
		m = m * n;
		if (m > 10)
		{
			a = (int)m + 55;//a的最小值为65，A的ASCII码为65；
			if (!enQueue(q,a))
				cout << "插入失败";
			m = m - (int)m;
		}
		else
		{
			a=(int)m + 48;//a的最小值为0，'0'的ASCII码为48；
			if (!enQueue(q,a))
				cout << "插入失败";
			m = m - (int)m;
		}
	}
}
int main()
{
	SqQueue *Q;
	ElemType e;
	ElemType a[MAXSIZE] = { 'a','b','c' };
	ElemType b[MAXSIZE] = { 'd','e','f' };
	
	cout << "1.初始化队列q" << endl;
	InitSqQueue(Q);
	
	cout << "2.判断队列q是否非空" << endl;
	if (!QueueEmpty(Q))
		cout << "队列q不为空" << endl;
	else
		cout << "队列q为空" << endl;
	
	cout << "3.依次进队元素a、b、c" << endl;
	for (int i = 0; i < 3; i++)
		if (!enQueue(Q,a[i]))
			cout << "插入失败" << endl;
	
	cout << "4.出队一个元素,输出该元素" << endl;
	if (deQueue(Q, e))
		cout << "出队的元素为" << (char)e << endl;
	
	cout << "5.依次进队元素d、e、f" << endl;
	for (int i = 0; i < 3; i++)
		if (!enQueue(Q, b[i]))
			cout << "插入失败" << endl;
	
	cout << "6.输出出队序列" << endl;
	while (!QueueEmpty(Q))
	{
		if (deQueue(Q, e))
			cout << (char)e << '\t';
	}
	cout << endl;
	
	cout << "7.释放队列" << endl;
	DestroySqQueue(Q);
	
	cout << "函数1的实现" << endl;
	SqQueue* L1;
	InitSqQueue(L1);
	change1(L1, 0.635, 8);
	cout << "0.";
	while (!QueueEmpty(L1))
	{
		if (deQueue(L1, e))
			cout << e;
	}
	DestroySqQueue(L1);
	cout << endl;
	
	cout << "函数2的实现" << endl;
	SqQueue* L2;
	InitSqQueue(L2);
	cout << "请输入测试数据:"; double k; cin >> k;
	cout << "请输入转换的进制:"; double j; cin >> j;
	change2(L2,k,j);
	cout << "0.";
	while (!QueueEmpty(L2))
	{
		if (deQueue(L2, e))
			cout << (char)e;
	}
	DestroySqQueue(L2);
}
