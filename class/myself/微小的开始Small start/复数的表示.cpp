//复数的具体实现 
#include<iostream>
#include<cmath>
using namespace std;
typedef struct
{
	double num;
	double i;	
}Complex;
//初始化
void Initcomplex(Complex *&z)
{
	z=new Complex;
}
//构造
void assigncomplex(Complex *&z,double a,double b)
{
	Initcomplex(z);
	z->num=a;
	z->i=b;
}
//输出
void discomplex(Complex *z)
{
	if(z->i==0||z->num==0)//判断是否有0
	{
		if(z->i==0&&z->num!=0)//数字可以为1
		{
			cout<<z->num;
		}
		else if(z->i!=0&&z->num==0)//虚部排除1
		{
			if(z->i==1)	cout<<"i";
			else if(z->i==-1)	cout<<"-i";
			else	cout<<z->i;
		}
		else //都为0则为0
		{
			cout<<0;
		}
	}
	else if(z->i>0)//虚部大于0
	{
		if(z->i==1)
			cout<<z->num<<"+"<<"i"<<endl;
		else
			cout<<z->num<<"+"<<z->i<<"i"<<endl;
	}
	
	else//虚部小于一
	{
		if(z->i==-1)	
			cout<<z->num<<"-"<<"i"<<endl;
		else	
			cout<<z->num<<z->i<<"i"<<endl;
	}
} 
//加法
void Add(Complex *z1,Complex *z2,Complex *&s)
{
	s->num=z1->num+z2->num;
	s->i=z1->i+z2->i;
}
//减法
void dfr(Complex *z1,Complex *z2,Complex *&sub)
{
	sub->num=z1->num-z2->num; 
	sub->i=z1->i-z2->i;
}
//乘法
void product(Complex *z1,Complex *z2,Complex *&mul)
{
	double num,i;
	num=z1->num*z2->num-z1->i*z2->i;
	i=z1->i*z2->num+z1->num*z2->i;
	mul->num=num;mul->i=i;
	
}
//除法
void did(Complex *z1,Complex *z2,Complex *&dd)
{
	if(z2->num==0&&z2->i==0)
	{
		cout<<"Error:无法计算商，因为除数即第二个复数为0,无意义！！！"<<endl;
	}
	else{
	dd->num=(z1->num*z2->num+z1->i*z2->i)/(z2->num*z2->num+z2->i*z2->i);
	dd->i=(z1->i*z2->num-z1->num*z2->i)/(z2->num*z2->num+z2->i*z2->i);	
	}
}
//取模
void qumo(Complex *z1,double &mo)
{
	mo=sqrt(z1->num*z1->num+z1->i*z1->i);
	
}
//销毁（虽然我不知道为什么要专门再写一个函数啦）
void DestroyComplex(Complex*& z)
{
	delete z;
}
int main() 
{
	double a,b,c,d;
	cout<<"请输入第一个复数的实部";cin>>a;	
	cout <<"请输入第一个复数的虚部";cin>>b;
	Complex *z1;//定义一个指向结构体的z1,注意这时候他没有空间，准确来说，类似于指针，没有初始化；
	assigncomplex(z1,a,b);//值得一提，里面包含Initcomplex
	cout<<"第一个复数的表示为：";discomplex(z1);cout<<endl;
	cout<<"请输入第二个复数的实部";cin>>c;	
	cout <<"请输入第二个复数的虚部";cin>>d;
	Complex *z2;//2
	assigncomplex(z2,c,d);
	cout<<"第二个复数的表示为：";discomplex(z2);cout<<endl;
	//加
	Complex *s;Initcomplex(s);//3
	Add(z1,z2,s);
	cout<<"他们的和为：";discomplex(s);cout<<endl;
	//减
	Complex *sub;Initcomplex(sub);//subtract(sub)//4
	dfr(z1,z2,sub);
	cout<<"他们的差为：";discomplex(sub);cout<<endl;
	//乘
	Complex *mul;Initcomplex(mul);//multiply(mul)//5
	product(z1,z2,mul);
	cout<<"他们的乘积为：";discomplex(mul);cout<<endl;
	//除法
	Complex *dd;Initcomplex(dd);//divide(dd)//6
	did(z1,z2,dd);
	
	if(z2->num!=0||z2->i!=0){
		cout<<"他们的商为：";
		discomplex(dd);cout<<endl;
	}
	//取模
	double mo;
	qumo(z1,mo);
	cout<<"第一个复数的模是："<<mo<<endl;
	qumo(z2,mo);	cout<<"第二个复数的模是："<<mo;
	//销毁：可以知道需要消灭7个new分配的空间，类型是结构体
	DestroyComplex(z1);
	DestroyComplex(z2);
	DestroyComplex(sub);
	DestroyComplex(mul);
	DestroyComplex(dd);
	return 0;
}
