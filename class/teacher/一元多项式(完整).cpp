#include <iostream>
using namespace std;

typedef struct
{
	int xi;//系数
	int zhi;//指数
}unit;

typedef struct LNode
{
	unit data; //结点的数据部分
	struct LNode* next;
} LinkList;

//初始化链表
void InitList(LinkList*& L)
{
	L = new LinkList;
	L->next = NULL;
}



//插入一个数据结点e到有序链表中
void InsertList(LinkList*& L, unit e)
{
	LinkList* r, * s;//r是循环用的结点指针，s是插入的新结点
	r = L;
	//寻找新插入结点的位置
	while (r->next != NULL && e.zhi > r->next->data.zhi)//以指数决定插入的位置
		r = r->next;
	if (r->next != NULL && e.zhi == r->next->data.zhi)//指数相等
	{
		r->next->data.xi += e.xi;  //系数相加
		if (r->next->data.xi == 0)  //处理系数为0的情况 
		{
			LinkList* q = r->next;
			r->next = q->next;
			delete q;
		}
	}

	else
	{
		s = new LinkList;
		s->data.xi = e.xi;	s->data.zhi = e.zhi;
		//将e的值赋给s指针所指结点
		s->next = r->next;
		r->next = s;
	}
}

//两个多项式相加
void AddList(LinkList*& L, LinkList* Lc)
{
	LinkList* b = Lc->next;
	while (b != NULL)
	{
		InsertList(L, b->data);//从Lc表中取出每一个节点插入到L中
		b = b->next;
	}
}

void Cheng(LinkList*& La, LinkList*& Lb, LinkList* Lc)
{
	LinkList* b, * c = Lc->next;
	unit e;
	while (c != NULL)  //取Lc表中的每一个节点
	{
		b = Lb->next;
		while (b != NULL)   //取Lb表中的每一个节点
		{
			e.xi = c->data.xi * b->data.xi;    //系数相乘
			e.zhi = c->data.zhi + b->data.zhi;   //指数相加，得到节点相乘的值 
			InsertList(La, e);  //再将该节点插入到La中
			b = b->next;
		}
		c = c->next;
	}
}

//遍历线性表
void DispList(LinkList* L)
{
	LinkList* p = L->next;
	if (p==NULL)  //所有数据都没有 
		cout << 0;
	while (p)
	{
		if (p->data.zhi == 0)
			//当指数为零时
			cout << p->data.xi;
		else
		{//指数不为零时
			if (p->data.xi != 1 && p->data.xi != -1)
				//排除系数1和-1的特殊情况
				cout << p->data.xi;
			else if (p->data.xi == -1)
				cout << "-";
			if (p->data.zhi > 1)
				cout << "X^" << p->data.zhi;
			else if (p->data.zhi < 0)
				cout << "X^(" << p->data.zhi << ')';
			else
				if (p->data.zhi == 1)
					cout << 'X';
		}
		if (p->next != NULL && p->next->data.xi > 0)
			cout << "+";
		p = p->next;
	}
	cout << endl;
}



void DestroyList(LinkList*& L)
{
	LinkList* pre, * p;
	pre = L, p = L->next;
	while (p != NULL)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}


//主程序部分
int main()
{
	LinkList* La, * Lb, * L;
	InitList(La); InitList(Lb); InitList(L);
	int i, j = 0;
	unit k;
	while (j++ < 2)
	{
		i = 0;
		do
		{
			cout << "请输入第" << j << "个多项式第" << ++i << "项的系数（按0退出）:";
			cin >> k.xi;
			cout << "请输入第" << j << "个多项式第" << i << "项的指数:";
			cin >> k.zhi;
			cout << endl;
			if (j == 1)
				if (k.xi != 0)
					InsertList(La, k);
			if (j == 2)
				if (k.xi != 0)
					InsertList(Lb, k);
		} while (k.xi != 0);
	}
	cout << "第一个一元多项式为:F(X)="; DispList(La);
	cout << "第二个一元多项式为:G(X)="; DispList(Lb);
	cout << "多项式相乘为：";
	Cheng(L, La, Lb);
	DispList(L);
	cout << "多项式相加为：";
	AddList(La, Lb);
	DispList(La);
	DestroyList(La);
	DestroyList(Lb);
	DestroyList(L);
}
