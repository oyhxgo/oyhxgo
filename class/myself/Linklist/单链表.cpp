#include <iostream>
using namespace std;
typedef char ch;
typedef struct LNode {
	ch data;
	struct LNode*next;//指针域：存放下一个节点的地址
} LinkNode;
//初始化
void InitList(LinkNode *&L) {
	L = new LinkNode;
	L->next = NULL;
}
//插入（尾插法）
void Insertlist(LinkNode *&L, ch a[], int n) { //传入想插入的数组(1,2,3,4),则此法插完后亦是（1,2,3，4）
	LinkNode *s, *r; //创建两个指针
	r = L; //r指向首节点L
	for (int i = 0; i < n; i++) {
		s = new LinkNode; //创建空间
		s->data = a[i]; //数据存储（值得注意的是s是指针）
		r->next = s; //r->next表示L的next指针域，其实就是赋值，将s的地址（s本身就是地址）赋给L的next域，相当于是L--s
		r = s; //然后将r指向s
	}
	r->next = NULL; //最后r指向末节，指针域为NULL
}
//输出
void Displaylist(LinkNode *L) {
	LinkNode *p = L->next; //这里注意一下，其实首节点是没有数据的，直接指向下一个节点打印
	while (p != NULL) {
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl << endl;
}
//输出长度
int Listlength(LinkNode *L) {
	int n = 0;
	LinkNode *p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
//判断是否为空
bool emptyelem(LinkNode *L) {
	if (L->next == NULL)
		return false;
	else
		return true;
}
//取值
bool Getelem(LinkNode *L, int n, ch &e) {
	if (n <= 0)
		return false;
	LinkNode *p = L;
	int j = 0;
	while (j < n && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	e = p->data;
	return true;
}
//输出位置
int Locelem(LinkNode *L, ch e) {
	LinkNode *p = L->next;
	int j = 1;
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return 0;
	}

	return j;
}
//指定位置插入元素
bool insertlist(LinkNode *&L, int n, ch q) {
	if (n <= 0)
		return false;
	int j = 0;
	LinkNode *p = L, *s;
	while (j < n - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p==NULL||p->next == NULL)
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
	int j = 0;
	LinkNode *p = L, *q;
	while (j < n - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	q = p->next;
	if (q == NULL)
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

int main() {
	LinkNode *L1;
	InitList(L1);
	cout << "1.初始化单链表成功！！！" << endl << endl;
	//插入
	ch a[10] = {'a', 'b', 'c', 'd', 'e'};
	cout << "2.依次插入abcde." << "尾插法" << "    ";
	Insertlist(L1, a, 5);
	cout << "插入成功！！！" << endl << endl;
	//打印
	cout << "3.当前的单链表为：  ";
	Displaylist(L1);
	//输出长度
	int n = Listlength(L1);
	cout << "4.当前单链表的长度为：" << n << endl << endl;
	//判断链表是否为空
	cout << "5.当前链表";
	if (emptyelem(L1))
		cout << "不为空表" << endl << endl;
	else
		cout << "为空表" << endl << endl;
	//取值（输出元素）
	cout << "6.取值操作:";	int l;ch e;
	cout << "请输入您要取哪个位置的值：";cin >> l;
	if (Getelem(L1, l, e))
		cout << "取值成功！ " << "单链表第" << l << "位的元素是：" << e << endl << endl;
	else
		cout << "取值失败，您输入的位置" << l << "越界！！！" << endl << endl;
	//查找
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
	Displaylist(L1);
	cout << "10.删除操作：";int y;ch o;
	cout << "请您输入要删除的元素的序号：";cin >> y;
	if (!Delem(L1, y, o))
		cout << "对不起，您的输入的序号有误（越界），删除失败！" << endl << endl;
	else
		cout << "删除成功！成功删除第" << y << "个元素" << o << endl << endl;
	cout << "11.当前单链表的元素有：";Displaylist(L1);
	//释放
	cout << "12.销毁单链表：";Destroylist(L1);
	cout << "销毁成功！！！";
	return 0;
}
