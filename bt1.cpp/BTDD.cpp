#include<iostream>
using namespace std;
class A{
    private:
       int x,y;
    public:
        A();
        A(int x1, int y1);
        A(const A &a);
        ~A(); 
        int operator>(A a);
        A operator+(A a);
        friend istream& operator >> (istream &is, A &a);
        friend ostream& operator << (ostream &os,const A a);
};
A::A()
{
    x=0;
    y=0;
}
A::A(int x1, int y1)
{
    x=x1;
    y=y1;
}
A::A(const A &a)
{
    x=a.x;
    y=a.y;
}
A::~A()
{

}
istream& operator >> (istream &is, A &a){
    cout<<"\nNhap x: "<<endl;
    is>>a.x;
    cout<<"\nNhap y: "<<endl;
    is>>a.y;
	return is;
}
ostream& operator << (ostream &os,const A a){
    cout<<"\nX: ";
    os<<a.x;
    cout<<"\nY: ";
    os<<a.y;
	return os;
}
int A::operator>(A a)
{
    if((x+y) > (a.x + a.y))
     return 1;
    else
      return 0;
}
A A::operator+(A a)
{
    A a2;
    a2.x= x+a.x;
    a2.y= y+a.y;
    return a2;
}
class B:public A
{
    private:
        int z;
    public:
        B();
        B(int z);
        B(const B &b);
        ~B(); 
        int operator>(B b);
        B operator+(B b);
        friend istream& operator >> (istream &is, B &b);
        friend ostream& operator << (ostream &os,const B b);
};
istream& operator >> (istream &is, B &b){
    cout<<"\nNhap z: "<<endl;
    is>>b.z;
	return is;
}
ostream& operator << (ostream &os,const B b){
    cout<<"\nZ:= ";
    os<<b.z;
	return os;
}
B::B()
{
    z=0;
}
B::B(int z1)
{
    z=z1;
}
B::B(const B &b)
{
    z=b.z;
}
B::~B()
{

}
int B::operator>(B b)
{
    if((z) > (b.z))
     return 1;
    else
      return 0;
}   
B B::operator+(B b)
{
    B b2;
    b2.z= z+b.z;
    return b2;
}
int main()
{
    A a(11,8);
    cout<<a<<endl;
    A b(a);
    cout<<b;
    cin>>a;
    cout<<a;
}