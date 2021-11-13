#include <iostream>
#include<conio.h>
#include<string>
using namespace std;
class A{
   private:
       int x,y;
    public:
        A( int x, int y);
        A(const A &a);
        A();      
        ~A();
        friend istream &operator>>(istream &is, A &a);
		friend ostream &operator<<(ostream &os, const A &a);
         int operator>(A a);
         A operator+(A a);
       // bool operator >(int x, int y);
};
class B:public A{
   private:
       int z;
    public:
        B( int z);
        B(const B &b);
        B();      
        ~B();
        friend istream &operator>>(istream &is, B &b);
		friend ostream &operator<<(ostream &os, const B &b);
       int operator>(B b);
        B operator+(B b);
        

};
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
B::B(int z){
    this->z = z;
}
B::B(const B &b){
    z=b.z; 
}
B::B(){
    this->z = 0;
}
B::~B(){
}
istream &operator>>(istream &is, B &b){
    A a;
    cin>>a;
	cout<<"Nhap z: ";
	is>>b.z;
	return is;
}
ostream &operator<<(ostream &os, const B &b){
    A a;
    cout<<a;
	os<<"\tZ =  "<<b.z<<endl;
	return os;
}
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
A::A(int x, int y){
    this->x = x;
    this->y = y;
}
A::A(const A &a){
    x=a.x; y=a.y;
}
A::A(){
    this->x = 0;
    this->y = 0;
}
A::~A(){
}
istream &operator>>(istream &is, A &a){
	cout<<"Nhap a: ";
	is>>a.x;
	cout<<"Nhap b: ";
	is>>a.y;
	return is;
}
ostream &operator<<(ostream &os, const A &a){
	os<<"\tA =  "<<a.x<<endl;
	os<<"\tB =  "<<a.y<<endl;
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
int main(){
    B a;
    cin>>a;
    cout<<a;
    system("pause");
    return 0;
}