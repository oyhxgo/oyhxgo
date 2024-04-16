#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct node
{
	ElemType data;
   	struct node *next;
} LinkList;   

void InitList(LinkList *&L)   
{
	L= new LinkList;       
    L->next=L;
}

/////////////////////////////////////////////////////////
//1.头插法建立一个循环链表
void CreateListF(LinkList *&L,ElemType a[],int n)  
{
	LinkList *s;
	L = new LinkList;
	L->next = L;
	for (int i=0;i<n;i++)
	{
		s = new LinkList;
		s->data = a[i];
		s->next = L->next;
		L->next = s; 
	}	
}

/////////////////////////////////////////////////////////
//2.尾插法建立一个循环链表
void CreateListR(LinkList *&L,ElemType a[],int n)  
{
	LinkList *s,*r;
	L = new LinkList;
	r = L;
	for (int i=0;i<n;i++)
	{
		s = new LinkList;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = L;
}

///////////////////////////////////////////////////////
//3.销毁循环链表
void DestroyList(LinkList *&L)
{
	LinkList *pre=L->next,*p=pre->next;
	while (p != L)	//头结点是判断循环条件，所以必须最后才能销毁 
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
	delete p;	// delete L;   效果是一样的 
}


////////////////////////////////////////////////////////
//4.判定是否为空表
bool ListEmpty(LinkList *L)
{
	return (L->next==L);
}

///////////////////////////////////////////////////////
//4.求循环链表的长度
int ListLength(LinkList *L)
{
	int count = 0;
	LinkList *p=L->next;
	while (p != L)
	{
		count ++;
		p = p->next;
	}
	return count;
}

///////////////////////////////////////////////////////
//5.输出循环链表
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
} 

///////////////////////////////////////////////////////
//6.求某个数据元素值GetElem(L,i,e)
bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0; LinkList *p=L;
	while (j < i && p->next != L)
	{
		j ++;
		p = p->next;
	}
	if (i<1 || i>j)
		return false;
	e = p->data;
	return true;

}

//////////////////////////////////////////////////////////
//7.按元素值查找
int LocateElem(LinkList *L, ElemType e)
{
	LinkList *p=L->next;
	int i=1;
	while (p != L && p->data != e)
	{
		i ++;
		p = p->next;
	}
	if (p == L)
		return 0;
	else 
		return i;
}

//////////////////////////////////////////////////////////////
//8.插入数据元素
bool ListInsert(LinkList *&L,int i,ElemType e)
{
	if (i < 1) return false;
    int j=0; LinkList *p=L,*s;
    if (i==1)			//对第一个数据结点进行额外的处理 
    {
    	s = new LinkList;
    	s->data = e;
   		s->next = p->next;
    	p->next = s;
    	return true; 
    }
    else 
    {
   		while (j < i-1 && p->next!=L)
   		{
    		j ++;
    		p = p->next;
    	}
   		if (i > j+1 || p==L)
   			return false;
    	s = new LinkList;
    	s->data = e;
    	s->next = p->next;
    	p->next = s;
   		return true;
    }
}


///////////////////////////////////////////////////////////////
//9.删除数据元素
bool ListDelete(LinkList *&L,int i,ElemType &e)
{
	if (i < 1) return false;
	
    int j=0; 
    LinkList *p=L,*q;
    if (i==1)
    {
    	q = p->next;
    	e = q->data;
    	p->next = q->next;
   		delete q;
    	return true;
    }
    else
    {
    	while (j < i-1 && p->next!=L)
    	{
    		j ++;
     		p = p->next;
    	}
    	if (p->next==L)
    		return false;
    	q = p->next;
    	e = q->data;
    	p->next = q->next;
    	delete q;
    	return true;
    }
}



/////////////////////////////////////////
//以下为主函数部分

int main()
{
	LinkList *L1;
	cout<<"1.初始化循环链表:"<<endl;InitList(L1);

	cout<<"\n2.尾插法建表:"<<endl;
	ElemType a[5]={'A','B','C','D','E'};
    for(int i=0;i<5;i++)
		if(!ListInsert(L1,i+1,a[i]))
			cout<<"插入失败!";
	
	cout<<"\n3.循环链表的元素为:";
	DispList(L1);

	cout<<"\n4.该循环链表的长度为:"<<ListLength(L1)<<endl;

	cout<<"\n5.该循环链表 ";
	if(ListEmpty(L1))
		cout<<"为空!"<<endl;
	else
		cout<<"不为空!"<<endl;

	cout<<"\n6.取元素..........."<<endl;
	ElemType temp;cout<<"请输入取的位置:";int k;cin>>k;
	if(GetElem(L1,k,temp))
		cout<<"取值成功，该循环链表的第"<<k<<"个元素的值为:"<<temp<<endl;
	else
		cout<<"取值失败，你输入的位置"<<k<<"越界:"<<endl;

	cout<<"\n7.查找元素:"<<endl<<"请输入查找元素的值:";cin>>temp;
	if(LocateElem(L1,temp))
		cout<<"输出元素'"<<temp<<"'的位置为:"<<LocateElem(L1,temp)<<endl;
	else
		cout<<"元素'"<<temp<<"'不存在."<<endl;
  
	cout<<"\n8.在循环链表指定位置插入元素 :"<<endl;
	cout<<"请输入插入的位置:";cin>>k;
	cout<<"请输入插入元素的值:";cin>>temp;
	if(ListInsert(L1,k,temp))
		cout<<"插入成功"<<endl;
	else
		cout<<"插入失败!"<<endl;

	cout<<"\n9.输出循环链表"<<endl;
	DispList(L1);
	
	cout<<"\n10.删除循环链表指定位置的元素"<<endl;
	cout<<"请输入删除的位置:";cin>>k;
	if(ListDelete(L1,k,temp))
		cout<<"删除成功，删除的元素为:"<<temp<<endl;
	else
		cout<<"删除失败!"<<endl;

	cout<<"\n11.输出循环链表"<<endl;
	DispList(L1);
	
	cout<<"\n12.释放循环链表"<<endl;
	DestroyList(L1);
	
	
	return 0;
}
