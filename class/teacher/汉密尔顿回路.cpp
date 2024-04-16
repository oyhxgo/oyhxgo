#include <iostream>
#include <iomanip>  //setw������Ҫ,�����ʽ��
using namespace std;

const int maxn=105;
int board[maxn][maxn]={0};//����
int num=0;
int m,n;//���̴�С
int startX,startY;//���λ��
//���8���߷�����������һ����¼,����Ϊ0�ŷ���˳ʱ��������7�ŷ���
int dx[8]={-2,-2,-1, 1, 2, 2, 1,-1};
int dy[8]={-1, 1, 2, 2, 1,-1,-2,-2};



//��ӡ����
void output()
{
	for(int i = 0;i<m;i++)
    {
		for(int j = 0;j<n;j++)
			cout<<setw(3)<<board[i][j]<<" ";
		cout<<endl;
	}
}


//�ж���һ���Ƿ񵽴���ʼ��
int toStart(int x,int y)
{
	for(int i = 0;i<8;i++)
		if(board[x+dx[i]][y+dy[i]]==1) //��ǰ(x,y)��λ�ã�8�������е�����һ��λ���ܻص����
			return 1;
	return 0;
}


//���ߵĺ���
bool moveHorse(int x,int y,int num)
{
	if(num==m*n+1&&toStart(x,y))//�ﵽ�յ㲢����������
    {
		output();//�������
		return true;//�ҵ�·��
	}
	int xx=0,yy=0;
    for(int i = 0;i<8;i++)//�����������8���������̽��,˳ʱ�����̽��
    {
        xx=x+dx[i],yy=y+dy[i];//��һ��������
        if((!board[xx][yy])&&(xx>=0&&xx<m&&yy>=0&&yy<n))
        {//��һ��Ϊ�ղ���δԽ��
            board[xx][yy]=num;//�������ϼ�¼��Ĳ���
            if(moveHorse(xx,yy,num+1)) return true;
            board[xx][yy]=0;//�����Ա���һ�β���
        }
    }
    return false;
}


int main()
{
    //�����ģ
    cout<<"�����ģ��";
	cin>>m>>n;
	//������ʼλ��
	cout<<"������ʼλ��:" ;
	cin>>startX>>startY;
	board[startX][startY]=1;//����ʼλ��Ϊ1
	cout<<moveHorse(startX,startY,2);
	return 0;
}



