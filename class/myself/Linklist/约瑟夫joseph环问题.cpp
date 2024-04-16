//约瑟夫joseph环问题
#include<iostream>
using namespace std;

typedef struct Lnode
{
	int data;
	bool isvisit=false;//新增bool为了函数2
	struct Lnode *next;
}Joseph;
//初始化创建Joseph环,这时候还没闭环
void Initjoseph(Joseph *&L)
{
	L=new Joseph;
	L->next=NULL;
}

//插入,创造一个闭环
void Insertjoseph(Joseph *&L,int n)
{
	Joseph *s,*p=L;
	for(int i=1;i<=n;i++)//直接套循环单链模版
	{
		s=new Joseph;
		s->data=i;
		p->next=s;
		p=s;
	}
	p->next=L; 
}
bool emptyjoseph(Joseph *L)
{
	Joseph *p=L;
	if(p->next==L)
		return false;
	return true;
}
int Locelem(Joseph *L, int e) {
	Joseph *p = L->next;
	int j = 1;
	while (p->data != e&&p!=L) {
		p = p->next;
		j++;
	}
	return j;
}

void deletejoseph(Joseph *&L,int h,int &a)
{
	int j = 1;
	Joseph *p = L, *q;
	while (j <= h - 1) {
		j++;
		p = p->next;
	}
	q = p->next;
	a = q->data;
	p->next = q->next;
	delete q;
}

void goout(Joseph *L,int k,int m)
{
	int flag=1,a;
	Joseph *s=L;
	for(int i=1;i<=k;i++){
		s=s->next;
	}
	while(emptyjoseph(L)){//这里我想到可以做一个取出即删的方法
		while(flag<m)
		{
			s=s->next;
			if(s==L)	//傻了，试了好多次才试出来
				s=s->next;
			flag++;
		}
		int h=Locelem(L,s->data);
		s=s->next;
		if(s==L)
			s=s->next;
		deletejoseph(L,h,a);
		cout<<a<<"  ";
		flag=1;	
	}
}
//约瑟夫问题
void Josephquesion(Joseph *&L,int k)
{
	int m=0,n=1e5;
	Joseph *s=L; 
	for(int i=1;i<=k;i++){//找到开始位置
		s=s->next;
	}
	s->isvisit=true;//标记已经访问
	while(m<n){//当其还未超过最大位置
		int flag=0;
		while(flag<=m){//当还未到所需位置,思考当m=0时，也应该往下走一位
			s=s->next;
			if(s==L)
				s=s->next;
			flag++;
		}
		s->isvisit=true;
		m++;
	}
	
}
//函数1的输出
void displaylinknode(Joseph *L)
{
	Joseph *p=L->next;
	while(p!=NULL&&p!=L)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl<<endl;
} 
//函数2的输出
void displaylinknode2(Joseph *L)
{
	Joseph *p=L->next;
	while(p!=L)
	{
		if(p->isvisit==false)
			cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl<<endl;
}
int main()
{
	Joseph *L1;Initjoseph(L1);
	int n,k,m;//到n，从k开始，每次跳过m；
	cout<<"Question 1:输入环的元素总数以及从第几号开始，第几个出列： ";
	cin>>n>>k>>m;
	Insertjoseph(L1,n);cout<<endl;
	cout<<n<<"个元素，从"<<k<<"号开始，报到"<<m<<"元素出列。"<<"则出列顺序为：";
	goout(L1,k,m);cout<<endl<<endl;
	cout<<"样例2:输入环的元素总数以及从第几号开始，第几个出列： ";
	cin>>n>>k>>m;
	Insertjoseph(L1,n);cout<<endl;
	cout<<n<<"个元素，从"<<k<<"号开始，报到"<<m<<"元素出列。"<<"则出列顺序为：";
	goout(L1,k,m);cout<<endl<<endl;
	cout<<"样例3:输入环的元素总数以及从第几号开始，第几个出列： ";
	cin>>n>>k>>m;
	Insertjoseph(L1,n);cout<<endl;
	cout<<n<<"个元素，从"<<k<<"号开始，报到"<<m<<"元素出列。"<<"则出列顺序为：";
	goout(L1,k,m);cout<<endl<<endl<<endl;
	cout<<"Question 2:输入环的元素总数以及从第几号开始：(只展示1e5个位置的结果)：";
	cin>>n>>k;	Insertjoseph(L1,n);
	Josephquesion(L1,k);cout<<endl<<endl;
	cout<<"未访问的点有：";
	displaylinknode2(L1);
	return 0;
}

//老样子，浅浅分析一下
//初思路:读完题目，感觉有点像循环单链表耶，试试吧
//但是啊再次细品，出列又有点像栈，emm
//好了，经过无数次失败，我也不知道为什么错这么多次， 终于试出来了
//果然最后的代码很简单
//总结最后的思路就是
//笔者采取循环单链表的形式构建Joseph环，在寻找跳数m的时候，以s为指针，指向我们
//需要输出的位置，然后利用定位函数定位其位置（为了方便删除）
//后面利用删除函数删除，并输出被删除的数字，然后继续循环（使用链表是否为空作为终止条件，全部元素都被删除只剩下L即为空表）
//有趣的是，构成圆环的还有L，所以在循环过程中我们需要特判，跳过L这个东西，希望
//读者能够注意，因为笔者在这里浪费了一堆时间检查




//至于补充，我们还是有思路的，没错，一道经典的约瑟夫问题
//(比较傻的笔者竟然想成Joseph杀人问题，哭死)
//
