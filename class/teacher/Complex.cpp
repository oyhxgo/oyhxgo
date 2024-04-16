#include <iostream>
using namespace std;
#include <math.h>


typedef struct
{
    double real;//������ʵ��
    double imag;//�������鲿
} Complex;



//������ʼ��
void InitComplex(Complex *&z)//������ָ��
{
    z=new Complex;  //��z������һ��洢�ռ�            z=(Complex *)malloc(sizeof(Complex))
}  



//�����ĸ�ֵ
void AssignComplex(Complex *&z,double v1,double v2)
{
    z->real=v1;   //��v1��ֵ����������ʵ��
    z->imag=v2;   //��v2��ֵ�����������鲿
}

//�������  �����������������ʽ�����磺0��3��3i,4+i,4-i..
void DispComplex(Complex *z)
{

    if(z->real)//ʵ����Ϊ0
    {
        if(z->imag==0)
            cout<<z->real;
        else if(z->imag==1)
            cout<<z->real<<"+i";
        else if(z->imag==-1)
            cout<<z->real<<"-i";
        else if(z->imag>0)
            cout<<z->real<<"+"<<z->imag<<"i";
        else
            cout<<z->real<<z->imag<<"i";
	}
    else  //ʵ��Ϊ0�����
    {

        if(z->imag==0)
            cout<<0;
        else if(z->imag==1)
            cout<<"i";
        else if(z->imag==-1)
            cout<<"-i";
        else 
            cout<<z->imag<<"i";
	}
}



//�����������ĺ�
void Add(Complex *z1,Complex *z2,Complex *&sum)
{
    sum->real=z1->real+z2->real;
    sum->imag=z1->imag+z2->imag;
}



//�����������Ļ�
void Product(Complex *z1,Complex *z2,Complex *&pro)
{
	pro->real=z1->real*z2->real-z1->imag*z2->imag;
	pro->imag=z1->imag*z2->real+z1->real*z2->imag;
}



//�����������Ĳ�
void Difference(Complex *z1,Complex *z2,Complex *&dif)
{
	dif->real=z1->real-z2->real;
	dif->imag=z1->imag-z2->imag;

}


//ȡģ
double Module(Complex *z1)
{
	return sqrt(z1->real*z1->real+z1->imag*z1->imag);
}

//(a+bi)/(c+di)=(a+bi)*(c-di)/(c*c+d*d);
//��������������
bool Quotient(Complex *z1,Complex *z2,Complex *&quo)
{
	if(z2->imag==0 && z2->real==0)  //��z2Ϊ0,���ܽ��г�������
	{
		return false;
	}
	else
	{
		quo->real=(z1->real*z2->real+z1->imag*z2->imag)/(z2->real*z2->real+z2->imag*z2->imag);
		quo->imag=(z1->imag*z2->real-z1->real*z2->imag)/(z2->real*z2->real+z2->imag*z2->imag);
		return true;
	}
}



//���ٸ���
void DestroyComplex(Complex *&z)
{
	delete z;  //�ͷ�z��ռ�Ĵ洢�ռ�
}



int main()
{
    double a,b;
    cout<<"�������һ��������ʵ��:";cin>>a;
    cout<<"�������һ���������鲿:";cin>>b;
    Complex *z1;  InitComplex(z1);

    AssignComplex(z1,a,b);
    cout<<"��һ������Ϊ:";DispComplex(z1);cout<<endl;
	cout<<"������ģΪ:"<<Module(z1)<<endl;



    cout<<"������ڶ���������ʵ��:";cin>>a;
    cout<<"������ڶ����������鲿:";cin>>b;
    Complex *z2;  InitComplex(z2);

    AssignComplex(z2,a,b);
    cout<<"�ڶ�������Ϊ:";DispComplex(z2);cout<<endl;

    Complex *sum;
    InitComplex(sum);
    Add(z1,z2,sum);
    cout<<"�����������ĺ�Ϊ��";DispComplex(sum);cout<<endl;

    Complex *diff;
    InitComplex(diff); 
    Difference(z1,z2,diff);
    cout<<"�����������Ĳ�Ϊ��";DispComplex(diff);cout<<endl;

    Complex *prod;
    InitComplex(prod);
    Product(z1,z2,prod);
    cout<<"�����������Ļ�Ϊ��";DispComplex(prod);cout<<endl;

    Complex *shang;
    InitComplex(shang);
    if(Quotient(z1,z2,shang))
    {  
		cout<<"��������������Ϊ��";DispComplex(shang);cout<<endl;
    }
	else
		cout<<"�������"<<endl;
	//�ݴ���

	cout<<"���ٸ���";DestroyComplex(z1);DestroyComplex(z2);
	DestroyComplex(sum);DestroyComplex(diff);DestroyComplex(prod);DestroyComplex(shang);

	return 0;
}

