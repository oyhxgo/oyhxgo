//循环单链表 
#include<iostream>
using namespace std;
typedef char ch;
typedef struct LNode
{
	ch data;
	struct LNode *next;
}LinkNode;
//初始化 
void Initlinknode(LinkNode *&L)
{
	L=new LinkNode;
	L->next=NULL;
}
//尾插法插入
void Endinsert(LinkNode *&L,ch a[],int n)
{
	LinkNode *p=L,*s;
	for(int i=0;i<n;i++)
	{
		s=new LinkNode;
		s->data=a[i];
		p->next=s;
		p=s;
	}
	p->next=L; 
} 
//输出
void displaylinknode(LinkNode *L)
{
	LinkNode *p=L->next;
	while(p!=NULL&&p!=L)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl<<endl;
} 
//长度
int Linknodelength(LinkNode *L)
{
	LinkNode *p=L->next;
	int j=0;
	while(p!=L)
	{
		j++;
		p=p->next;
	}
	return j;
} 
//判断是否为空
bool emptyelem(LinkNode *L)
{
	if (L->next == NULL)
		return false;
	else
		return true;
} 
//取值
bool Getelem(LinkNode *L, int n, ch &e) {
	if (n <= 0)
		return false;
	LinkNode *p = L->next;
	int j = 1;
	while (j < n && p != L) {
		j++;
		p = p->next;
	}
	if (p == L)
		return false;
	e = p->data;
	return true;
}
//输出位置
int Locelem(LinkNode *L, ch e) {
	LinkNode *p = L->next;
	int j = 1;
	while (p != L && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == L) {
		return 0;
	}
	
	return j;
}
//指定位置插入元素
bool insertlist(LinkNode *&L, int n, ch q) {
	if (n <= 0)
		return false;
	int j = 1;
	LinkNode *p = L, *s;
	if(n!=1)
		p=L->next;
	while (p != L &&j < n - 1 ) {
		j++;
		p = p->next;
	}
	if ((p==L||p->next == L)&&n!=1)
		return false;
	else {
		s = new LinkNode;
		s->data = q;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
//删除指定元素
bool Delem(LinkNode *&L, int n, ch &e) {
	if (n <= 0)
		return false;
	int j = 1;
	LinkNode *p = L, *q;
	if(n!=1)
		p=L->next;
	while ( p != L &&j < n - 1) {
		j++;
		p = p->next;
	}
	if (p == L&&n!=1)
		return false;
	q = p->next;
	if (q == L)
		return false;
	e = q->data;
	p->next = q->next;
	delete q;
	return true;
}
//释放
void Destroylist(LinkNode *&L) {
	delete L;
}
int main()
{
	LinkNode *L1;
	Initlinknode(L1);	
	cout << "1.初始化循环单链表成功！！！" << endl << endl;
	cout << "2.依次插入abcde." << "尾插法" << "    ";
	ch a[10]={'A','B','C','D','E'};
	Endinsert(L1,a,5);displaylinknode(L1);
	cout << "插入成功！！！" << endl << endl;
	int l=Linknodelength(L1);
	cout<<"当前循环单链表的长度为："<<l<<endl<<endl; 
	cout << "5.当前循环单链表";
	if (emptyelem(L1))
		cout << "不为空表" << endl << endl;
	else
		cout << "为空表" << endl << endl;
	cout << "6.取值操作:";	int m;ch e;
	cout << "请输入您要取哪个位置的值：";cin >> m;
	if (Getelem(L1, m, e))
		cout << "取值成功！ " << "单链表第" << m << "位的元素是：" << e << endl << endl;
	else
		cout << "取值失败，您输入的位置" << m << "越界！！！" << endl << endl;
	cout << "7.查找操作：";ch find;
	cout << "请输入您要查找的元素：  ";
	cin >> find;
	if (Locelem(L1, find) == 0)
		cout << "对不起，当前单链表中没有您查找的元素！！" ;
	else
		cout << "查找成功，您所查找的元素" << find << "在当前单链表的第" << Locelem(L1, find) << "位" ;
	cout<<endl<<endl;
	cout << "8.插入操作：";int k;ch q;
	cout << "请您输入一个数字和一个字符，代表在第几位插入一个字符：";cin >> k;cin >> q;
	if (!insertlist(L1, k, q))
		cout << "Warning:输入序号越界，插入失败！！！" << endl;
	else
		cout << "插入成功！！！" << endl << endl;
	cout << "9.当前单链表的元素有：";
	displaylinknode(L1);
	cout << "10.删除操作：";int y;ch o;
	cout << "请您输入要删除的元素的序号：";cin >> y;
	if (!Delem(L1, y, o))
		cout << "对不起，您的输入的序号有误（越界），删除失败！" << endl << endl;
	else
		cout << "删除成功！成功删除第" << y << "个元素" << o << endl << endl;
	cout << "11.当前单链表的元素有：";displaylinknode(L1);
	//释放
	cout << "12.销毁单链表：";Destroylist(L1);
	cout << "销毁成功！！！";
	return 0;
}
 
