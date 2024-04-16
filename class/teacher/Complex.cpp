#include <iostream>
using namespace std;
#include <math.h>


typedef struct
{
    double real;//复数的实部
    double imag;//复数的虚部
} Complex;



//复数初始化
void InitComplex(Complex *&z)//引用型指针
{
    z=new Complex;  //给z分配了一块存储空间            z=(Complex *)malloc(sizeof(Complex))
}  



//复数的赋值
void AssignComplex(Complex *&z,double v1,double v2)
{
    z->real=v1;   //将v1的值赋给复数的实部
    z->imag=v2;   //将v2的值赋给复数的虚部
}

//输出复数  能输出复数的特殊形式，例如：0，3，3i,4+i,4-i..
void DispComplex(Complex *z)
{

    if(z->real)//实部不为0
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
    else  //实部为0的情况
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



//求两个复数的和
void Add(Complex *z1,Complex *z2,Complex *&sum)
{
    sum->real=z1->real+z2->real;
    sum->imag=z1->imag+z2->imag;
}



//求两个复数的积
void Product(Complex *z1,Complex *z2,Complex *&pro)
{
	pro->real=z1->real*z2->real-z1->imag*z2->imag;
	pro->imag=z1->imag*z2->real+z1->real*z2->imag;
}



//求两个复数的差
void Difference(Complex *z1,Complex *z2,Complex *&dif)
{
	dif->real=z1->real-z2->real;
	dif->imag=z1->imag-z2->imag;

}


//取模
double Module(Complex *z1)
{
	return sqrt(z1->real*z1->real+z1->imag*z1->imag);
}

//(a+bi)/(c+di)=(a+bi)*(c-di)/(c*c+d*d);
//求两个复数的商
bool Quotient(Complex *z1,Complex *z2,Complex *&quo)
{
	if(z2->imag==0 && z2->real==0)  //当z2为0,则不能进行除法运算
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



//销毁复数
void DestroyComplex(Complex *&z)
{
	delete z;  //释放z所占的存储空间
}



int main()
{
    double a,b;
    cout<<"请输入第一个复数的实部:";cin>>a;
    cout<<"请输入第一个复数的虚部:";cin>>b;
    Complex *z1;  InitComplex(z1);

    AssignComplex(z1,a,b);
    cout<<"第一个复数为:";DispComplex(z1);cout<<endl;
	cout<<"复数的模为:"<<Module(z1)<<endl;



    cout<<"请输入第二个复数的实部:";cin>>a;
    cout<<"请输入第二个复数的虚部:";cin>>b;
    Complex *z2;  InitComplex(z2);

    AssignComplex(z2,a,b);
    cout<<"第二个复数为:";DispComplex(z2);cout<<endl;

    Complex *sum;
    InitComplex(sum);
    Add(z1,z2,sum);
    cout<<"这两个复数的和为：";DispComplex(sum);cout<<endl;

    Complex *diff;
    InitComplex(diff); 
    Difference(z1,z2,diff);
    cout<<"这两个复数的差为：";DispComplex(diff);cout<<endl;

    Complex *prod;
    InitComplex(prod);
    Product(z1,z2,prod);
    cout<<"这两个复数的积为：";DispComplex(prod);cout<<endl;

    Complex *shang;
    InitComplex(shang);
    if(Quotient(z1,z2,shang))
    {  
		cout<<"这两个复数的商为：";DispComplex(shang);cout<<endl;
    }
	else
		cout<<"除零错误！"<<endl;
	//容错性

	cout<<"销毁复数";DestroyComplex(z1);DestroyComplex(z2);
	DestroyComplex(sum);DestroyComplex(diff);DestroyComplex(prod);DestroyComplex(shang);

	return 0;
}

