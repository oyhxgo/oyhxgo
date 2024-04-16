#include <iostream>
using namespace std;

typedef struct
{
	int xi;//ϵ��
	int zhi;//ָ��
}unit;

typedef struct LNode
{
	unit data; //�������ݲ���
	struct LNode* next;
} LinkList;

//��ʼ������
void InitList(LinkList*& L)
{
	L = new LinkList;
	L->next = NULL;
}



//����һ�����ݽ��e������������
void InsertList(LinkList*& L, unit e)
{
	LinkList* r, * s;//r��ѭ���õĽ��ָ�룬s�ǲ�����½��
	r = L;
	//Ѱ���²������λ��
	while (r->next != NULL && e.zhi > r->next->data.zhi)//��ָ�����������λ��
		r = r->next;
	if (r->next != NULL && e.zhi == r->next->data.zhi)//ָ�����
	{
		r->next->data.xi += e.xi;  //ϵ�����
		if (r->next->data.xi == 0)  //����ϵ��Ϊ0����� 
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
		//��e��ֵ����sָ����ָ���
		s->next = r->next;
		r->next = s;
	}
}

//��������ʽ���
void AddList(LinkList*& L, LinkList* Lc)
{
	LinkList* b = Lc->next;
	while (b != NULL)
	{
		InsertList(L, b->data);//��Lc����ȡ��ÿһ���ڵ���뵽L��
		b = b->next;
	}
}

void Cheng(LinkList*& La, LinkList*& Lb, LinkList* Lc)
{
	LinkList* b, * c = Lc->next;
	unit e;
	while (c != NULL)  //ȡLc���е�ÿһ���ڵ�
	{
		b = Lb->next;
		while (b != NULL)   //ȡLb���е�ÿһ���ڵ�
		{
			e.xi = c->data.xi * b->data.xi;    //ϵ�����
			e.zhi = c->data.zhi + b->data.zhi;   //ָ����ӣ��õ��ڵ���˵�ֵ 
			InsertList(La, e);  //�ٽ��ýڵ���뵽La��
			b = b->next;
		}
		c = c->next;
	}
}

//�������Ա�
void DispList(LinkList* L)
{
	LinkList* p = L->next;
	if (p==NULL)  //�������ݶ�û�� 
		cout << 0;
	while (p)
	{
		if (p->data.zhi == 0)
			//��ָ��Ϊ��ʱ
			cout << p->data.xi;
		else
		{//ָ����Ϊ��ʱ
			if (p->data.xi != 1 && p->data.xi != -1)
				//�ų�ϵ��1��-1���������
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


//�����򲿷�
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
			cout << "�������" << j << "������ʽ��" << ++i << "���ϵ������0�˳���:";
			cin >> k.xi;
			cout << "�������" << j << "������ʽ��" << i << "���ָ��:";
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
	cout << "��һ��һԪ����ʽΪ:F(X)="; DispList(La);
	cout << "�ڶ���һԪ����ʽΪ:G(X)="; DispList(Lb);
	cout << "����ʽ���Ϊ��";
	Cheng(L, La, Lb);
	DispList(L);
	cout << "����ʽ���Ϊ��";
	AddList(La, Lb);
	DispList(La);
	DestroyList(La);
	DestroyList(Lb);
	DestroyList(L);
}
