#include <iostream>
using namespace std;
#define Maxsize 100 

//�洢��ǰ����Ľṹ�� 
typedef struct
{
	int i;
	int j;
	int di;
}Box;

//ջ�ṹ�� 
typedef struct
{
	int top;
	Box date[Maxsize];
}StType;

//��ʼ�� 
void InitStack(StType *& S)
{
	S=new StType;
	S->top=-1;
}

//���� 
void Destroy(StType *&S)
{
	delete S;
}

//�ж�ջ�Ƿ�� 
bool EmptyStack(StType *S)
{
	return S->top==-1;
}

//��ջ 
bool PushStack(StType *&S,Box e)
{
	if(S->top==Maxsize-1)	return false;
	S->top++;
	S->date[S->top]=e;
	return true;
}

//��ջ 
bool PopStack(StType *&S,Box &e)
{
	if(S->top==-1)	return false;
	e=S->date[S->top];
	S->top--;
	return true;
}

//ȡջ��Ԫ�� 
bool GetTop(StType *S,Box &e)
{
	if(S->top==-1)	return false;
	e=S->date[S->top];
	return true;
}
//����ջ
void CopySqStack(StType *&New,StType *Old)
{ 
	int i;
	for(i=0;i<=Old->top;i++)
		New->date[i]=Old->date[i];
	New->top=Old->top;
}


 //����һ:�ŵ㣺��������⡣ȱ�㣺�Ƚ��鷳��Ҫϸ�ļ�飬��ֹ����Խ�������
int n,m,sx,sy;//�趨Ϊȫ�ֱ��� 
void MaPath(int xi,int yi,int m,int n)
{
	//�������� //////////////////////////////////////////////////// 
	int ma[m+4][n+4];//��Χ��Ȧ�Ǳ߽磨��Ϊ�������2�����һ�����Ա߽�Ӧ������4�� 
	for(int i=0;i<m+4;i++)
	{
		for(int j=0;j<n+4;j++)
		{
			if(i==0 ||i==1||j==0||j==1||j==n+2||j==n+3||i==m+3||i==m+2) //�ѱ߽縳ֵ1�����ߵĲ�����Ϊ0 
				ma[i][j]=1;
			else 
				ma[i][j]=0;
		}
	}
	////////////////////////////////////////////////////////////////
	
	int i,j,di,i1,j1;
	StType *s1,*result;//s1����Ҫ��ջ,result�Ǹ��������ջ���������ϸ���ͣ� 
	InitStack(s1); 
	InitStack(result);          
	Box e;                               //����һ��Box���͵Ľṹ��e��ŵ�ǰi��j��di 
	
	e.i=xi; e.j=yi;	e.di=0;              //�ṹ��e��ʼ������� 
	PushStack(s1,e);                     //����ջ 
	ma[xi][yi]=1;                        //���ֵΪ1.�����ظ��� 
	int num=1;                           //��¼��ջ���� 
	int flag=1;                          //�ж�����Ƿ񵽴���� 
	while(!EmptyStack(s1))
	{                      
		GetTop(s1,e);                     //ȡջ������
		i=e.i;j=e.j; di=e.di;             //��ǰ����Ϊջ������ 
		
		bool find;
		find=false;                       //�жϿ��߷�λ�ı�־ 
		while(di<8 && !find)
		{
			di++;
			switch(di)                    //ѡ�����ƶ���λ 
			{
				case 1: i1=i-2; j1=j+1;break;
				case 2: i1=i-1; j1=j+2;break;
				case 3: i1=i+1; j1=j+2;break;
				case 4: i1=i+2; j1=j+1;break;
				case 5: i1=i+2; j1=j-1;break;
				case 6: i1=i+1; j1=j-2;break;
				case 7: i1=i-1; j1=j-2;break;
				case 8: i1=i-2; j1=j-1;break;
			}
			
			if(ma[i1][j1]==0)	find=true;       //�ҵ��ߵķ�λ�˳�ѭ�� 
			else if(i1==xi&&j1==yi && num==n*m)  //����ҵ����λ�ò���ջ�����������ָ��� 
			{   
				CopySqStack(result,s1); 
				int cout=n*m;                    //·������ 
				while(!EmptyStack(result))
				{
					PopStack(result,e);              //���յ㿪ʼ��ջȡ���� 
					ma[e.i][e.j]=cout--;         //���յ��ȥ��㸳ֵ 
				} 	
				flag=0;                          //flag�յ�ص����ı�־ 
			}
		}
		
		if(flag==0)		break;
		//����ֱ��ѡ��break����Ϊ·������̫���ˣ��������ֱ���ҵ�һ��·�����˳��� 
		if(find)
		{
			s1->date[s1->top].di=di;            //�޸�ԭջ����di 
			e.i=i1;  e.j=j1;  e.di=0;           //���ҵ��ķ�λ��di��ʼ��Ϊ0 
			PushStack(s1,e);                    //���ߵķ�λ��ջ
			num++;                              //��ջ������1 
			ma[i1][j1]=1;                      //���ߵķ�λ��Ϊ1�������ظ� 
		}
		else                                    //�˸���λ�������� 
		{
			PopStack(s1,e);                     //��ջ 
			num--;                              //ջ������1 
			ma[e.i][e.j]=0;                     //��ջ�����ؿ��߷��� 
		} 
	
	}	
	//���/////////////////////////////////////////////////////
	for(int i=2;i<m+2;i++)                       
	{
		for(int j=2;j<n+2;j++)
		{
			cout<<ma[i][j]<<"	";
		}
		cout<<endl;
	}
	 
	//////////////////////////////////////////////////////////// 
	Destroy(s1);
}


//�������ݹ�(��ν����������������ŵ�:������,ȱ��:����ʱ���ȷ���һ��
bool Chess[20][20];//��¼ÿ������û���߹���(Ĭ�϶���false)
int dx[8]={-1,1,2,2,1,-1,-2,-2};//��������������ʵ������ж� 
int dy[8]={2,2,1,-1,-2,-2,-1,1};	
StType *result;//����һ�����������ջ(һ��Ҫ�������棬�䵱ȫ��) 
int sum=0;//��¼·������ 
int Play[20][20];//����������������
void dfs(StType *&s2,int x,int y,int num)
{
	Box e; //����һ��Box���͵Ľṹ��e��ŵ�ǰi��j��di 
	if(!Chess[x][y])//���û�߹�����,��֮��� 
	{
		Chess[x][y]=true;
		e.i=x;
		e.j=y;
		PushStack(s2,e);//û�߹��ĵ�ֱ����ջ 
	} 
	
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];//ģ��һ�¾Ϳ���ʵ������ж�(�е�߼���Ҫʱ����⣩
		if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&(!Chess[nx][ny]))//�߽����⿼���Լ���֤���ߵ���һ����û�߹� 
		{
			dfs(s2,nx,ny,num+1);//����+1,Ȼ����µĵ�����ݹ� 
			PopStack(s2,e);//���ݹ����֮��һ��Ҫ��ջ(���ݷ��� 
			Chess[nx][ny]=false;//�ǵ�ҲҪ�ѱ�Ǹ�Ϊfalse,������������Ѱ�� 
		} 
		else if(num==n*m&&sx==nx&&sy==ny)//�����Ѿ������ˣ����ҿ����жϵ����һ�����Ե��յ�
		{
				sum++;
				if(sum==1)//��Ϊֻ��Ҫһ��������sum==1����� 
				{
					CopySqStack(result,s2);//����һ���µ�ջ��Ϊ�˲��ı��¼·����ջ,��Ȼ�޷��ظ�ִ�У��ҵ����ϵ�����·�� 
					int z=num;
					while(PopStack(result,e))
						Play[e.i][e.j]=z--;
					for(int i=1;i<=m;i++)
					{
						for(int j=1;j<=n;j++)
							cout<<Play[i][j]<<"   ";
						cout<<endl;
					}
				}
					PopStack(s2,e);
					return;
		}
	} 
	return;
}

int main()
{
	cout<<"ʹ�÷���һ"<<endl; 
	cout<<"�������ģ��";cin>>m>>n;
	cout<<"��������ʼλ��(���õ�һ�����0,0��ʼ����";cin>>sx>>sy; 
	MaPath(sx+2,sy+2,m,n);//����ڣ�2��2������������������Ҫ��2 
	cout<<"����ʹ�÷��������ݹ飩" ;
	cout<<"�������ģ��";cin>>m>>n;
	cout<<"��������ʼλ��(�����˵�һ�����1,1��ʼ����";cin>>sx>>sy; 
	StType *s;
	InitStack(s);//��Ϊ�ݹ��ǲ��ϵ��ú���������Ҫ�ȴ���ջ 
	InitStack(result);
	dfs(s,sx,sy,1);//һ��ʼ����Ϊ1; 
	cout<<"������������Ĳ���(�����е�ã�";
	cout<<sum; 
	
	
	return 0;
}
