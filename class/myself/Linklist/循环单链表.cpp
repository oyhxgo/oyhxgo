//ѭ�������� 
#include<iostream>
using namespace std;
typedef char ch;
typedef struct LNode
{
	ch data;
	struct LNode *next;
}LinkNode;
//��ʼ�� 
void Initlinknode(LinkNode *&L)
{
	L=new LinkNode;
	L->next=NULL;
}
//β�巨����
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
//���
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
//����
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
//�ж��Ƿ�Ϊ��
bool emptyelem(LinkNode *L)
{
	if (L->next == NULL)
		return false;
	else
		return true;
} 
//ȡֵ
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
//���λ��
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
//ָ��λ�ò���Ԫ��
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
//ɾ��ָ��Ԫ��
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
//�ͷ�
void Destroylist(LinkNode *&L) {
	delete L;
}
int main()
{
	LinkNode *L1;
	Initlinknode(L1);	
	cout << "1.��ʼ��ѭ��������ɹ�������" << endl << endl;
	cout << "2.���β���abcde." << "β�巨" << "    ";
	ch a[10]={'A','B','C','D','E'};
	Endinsert(L1,a,5);displaylinknode(L1);
	cout << "����ɹ�������" << endl << endl;
	int l=Linknodelength(L1);
	cout<<"��ǰѭ��������ĳ���Ϊ��"<<l<<endl<<endl; 
	cout << "5.��ǰѭ��������";
	if (emptyelem(L1))
		cout << "��Ϊ�ձ�" << endl << endl;
	else
		cout << "Ϊ�ձ�" << endl << endl;
	cout << "6.ȡֵ����:";	int m;ch e;
	cout << "��������Ҫȡ�ĸ�λ�õ�ֵ��";cin >> m;
	if (Getelem(L1, m, e))
		cout << "ȡֵ�ɹ��� " << "�������" << m << "λ��Ԫ���ǣ�" << e << endl << endl;
	else
		cout << "ȡֵʧ�ܣ��������λ��" << m << "Խ�磡����" << endl << endl;
	cout << "7.���Ҳ�����";ch find;
	cout << "��������Ҫ���ҵ�Ԫ�أ�  ";
	cin >> find;
	if (Locelem(L1, find) == 0)
		cout << "�Բ��𣬵�ǰ��������û�������ҵ�Ԫ�أ���" ;
	else
		cout << "���ҳɹ����������ҵ�Ԫ��" << find << "�ڵ�ǰ������ĵ�" << Locelem(L1, find) << "λ" ;
	cout<<endl<<endl;
	cout << "8.���������";int k;ch q;
	cout << "��������һ�����ֺ�һ���ַ��������ڵڼ�λ����һ���ַ���";cin >> k;cin >> q;
	if (!insertlist(L1, k, q))
		cout << "Warning:�������Խ�磬����ʧ�ܣ�����" << endl;
	else
		cout << "����ɹ�������" << endl << endl;
	cout << "9.��ǰ�������Ԫ���У�";
	displaylinknode(L1);
	cout << "10.ɾ��������";int y;ch o;
	cout << "��������Ҫɾ����Ԫ�ص���ţ�";cin >> y;
	if (!Delem(L1, y, o))
		cout << "�Բ�������������������Խ�磩��ɾ��ʧ�ܣ�" << endl << endl;
	else
		cout << "ɾ���ɹ����ɹ�ɾ����" << y << "��Ԫ��" << o << endl << endl;
	cout << "11.��ǰ�������Ԫ���У�";displaylinknode(L1);
	//�ͷ�
	cout << "12.���ٵ�����";Destroylist(L1);
	cout << "���ٳɹ�������";
	return 0;
}
 
