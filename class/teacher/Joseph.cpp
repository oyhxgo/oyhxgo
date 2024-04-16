#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	LNode* next;
} LinkNode;

// 1. ��ʼ��ͷ�ڵ�
void InitNode (LinkNode*& L) {
	L = new LinkNode;
	L-> next = L;
}

// 2. ��β�巨����ѭ�������� ͬʱ�ı�ʵ���е�βָ��
void CreateListByRear (LinkNode*& L, LinkNode*& r, ElemType arr[], int n) {
	r = L;     				// βָ�벢ָ��ͷ�ڵ�
	L->data = arr[0];       // ͷ�ڵ��data��ֵ
	
	for (int i = 1; i < n; ++i) {       // �½��ڵ㲢��������
		LinkNode* s = new LinkNode;
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	r->next = L;                     // ��Ȧ
}

// 3.�����Ȧ˳��
// count -> �������ͳ�Ȧ      move ->�ӵ�i����ʼ, ���ƶ�i-1���ڵ�
// ʹ��������ָ��ʵʱ�ı�ʵ���е�ͷβָ��, ʹ֮�����߼�
void out(LinkNode*& p, LinkNode*& pre, int count, int move) {
	int i = 1;
	
//  �ƶ��ڵ㣬����ʼ���Ǹ���
	while (--move) {
		p = p->next;
		pre = pre->next;
	}
	
//  ��Ȧ��Ϊ1����ʱ��ѭ����Ȧ
	while (p->next != p) {
		
		if (i == count) {       // ����ĳ�������ͳ�Ȧ
			i = 1;
			cout << p->data << " ";
			
			pre->next = p->next;    // ɾ����Ȧ�ڵ�
			delete p;
			p = pre->next;
			
		} else {
			pre = pre->next;        // ���û����ָ���������ͼ����ƶ�����ͳ��
			p = p->next;
			++i;
		}
	}
	cout << p->data << endl;        // ���Ȧ�����һ����
}

int main() {
// 1. ����ͷβ�ڵ�ָ��, ��ʼ��ͷ�ڵ�ָ��
	LinkNode* head; InitNode(head);
	LinkNode* rear;
	
// 2.����, ������Ҫ�Ĳ���; ��ʼ�����鲢��ֵ
	int n, m, from;
	cout << "������Ԫ�ظ���: "; cin >> n;
	cout << "�ӵڼ����˿�ʼ? "; cin >> from;
	cout << "�ڼ����˳�Ȧ? "; cin >> m;
	int* a = new int[n];        // ������̬����

	for (int i = 0; i < n; ++i) {   // ��Ԫ�ز��뵽������
		a[i] = i + 1;
	}
	
//  3. β�巨����ѭ���������õ�βָ��
	CreateListByRear(head, rear, a, n);
	
//  4. ��Ȧ�����
    cout << "��Ȧ˳��Ϊ: ";
	out(head, rear, m, from);
	
//  5. ��Ȧ���ʣͷ�ڵ㣬�ͷ�ͷ�ڵ�ָ����ָ�ռ伴��
	delete head;
	
	return 0;
}