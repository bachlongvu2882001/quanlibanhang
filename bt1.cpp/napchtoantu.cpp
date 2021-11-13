//Bach Long Vu
//MSSV:6051071145
#include<iostream>
using namespace std;
class PS{
    private:
     float tu,mau;
    public:
     friend istream& operator>>(istream& is, PS& ps);
     friend ostream& operator<<(ostream& os, PS& ps);
    // friend PS operetor +(PS ps1, PS ps2);
    PS operator +(PS ps);
    PS operator -(PS ps);
    PS operator *(PS ps);
    PS operator /(PS ps);
    PS operator +=(PS ps);
    PS operator -=(PS ps);
    PS operator *=(PS ps);
    PS operator /=(PS ps);
    int operator >(PS ps);
    int operator <(PS ps);
    int operator ==(PS ps);
    PS operator++(int);
    PS operator++();

};
//Nhap
istream& operator>>(istream& is, PS& ps){
    cout<<"Nhap tu: ";
    is>>ps.tu;
    cout<<"Nhap mau: ";
    is>>ps.mau;
    return is;
}
//Xuat
ostream& operator<<(ostream &os,PS &temp){
    if(temp.tu==0){
    os<<0;
    }
    else if(temp.mau==0)
     {
         os<<"Khong xac dinh";
         }
     else
     os<<temp.tu<<"/"<<temp.mau;
     return os;
}
//dinh nghia toan tu +
PS PS:: operator+(PS ps){
     
    PS tong;
    if(this->tu==0){
        return ps;
    }
    else{
    tong.tu=(this->tu*ps.mau+this->mau*ps.tu);
    tong.mau=(this->mau*ps.mau);
    return tong;
    }
}
//dinh nghia toan tu -
PS PS:: operator-(PS ps){
     PS hieu;
    hieu.tu=(this->tu*ps.mau-this->mau*ps.tu);
    hieu.mau=(this->mau*ps.mau);
    return hieu;
    }
//dinh nghia toan tu *
PS PS:: operator *(PS ps){
     PS nhan;
    nhan.tu=(this->tu*ps.tu);
    nhan.mau=(this->mau*ps.mau);
    return nhan;
    }
//dinh nghia toan tu /
PS PS:: operator /(PS ps){
     PS chia;
    chia.tu=(this->tu*ps.mau);
    chia.mau=(this->mau*ps.tu);
    return chia;
    }

/*
//dinh nghia toan tu -=
PS PS:: operator-=(PS ps){
     PS hieu;
    hieu.tu=(this->tu*ps.mau-this->mau*ps.tu);
    hieu.mau=(this->mau*ps.mau);
    return hieu;
    }
//dinh nghia toan tu *=
PS PS:: operator *=(PS ps){
     PS nhan;
    nhan.tu=(this->tu*ps.tu);
    nhan.mau=(this->mau*ps.mau);
    return nhan;
    }
//dinh nghia toan tu /=
PS PS:: operator /=(PS ps){
     PS chia;
    chia.tu=(this->tu*ps.mau);
    chia.mau=(this->mau*ps.tu);
    return chia;
    }*/
//So sanh lon hon
int PS::operator>(PS ps){
    if((tu/mau)>(ps.tu/ps.mau))
    return 1;
    else return 0;
}
//so sanh ==
int PS::operator ==(PS ps){
if ((double(tu)/mau)==(double(ps.tu)/mau))
		return 1;
	return 0;
}
//So sanh be hon
int PS::operator<(PS ps){
    if((tu/mau)<(ps.tu/ps.mau))
    return 1;
    else return 0;
}
//++a
PS PS::operator++(){
    tu=tu+mau;
    return *this;
}
PS PS::operator++(int){
     tu=tu+mau;
    return *this;
}
int main(){
    PS a,b,c;
    cout<<"Nhap phan so a: ";
    cin>>a;
    cout<<"Nhap phan so b: ";
    cin>>b;
    cout<<"*******************************************"<<endl;
    c=a+b;
    cout<<"Tong phan so +: "<<c<<endl;
    c=a-b;
    cout<<"Hieu phan so -: "<<c<<endl;
    c=a*b;
    cout<<"Tich phan so *: "<<c<<endl;
    c=a/b;
    cout<<"Thuong phan so /: "<<c<<endl;
    cout<<"*******************************************"<<endl;
   /* a+=b;
    cout<<"Tong phan so +=: "<<c<<endl;
    a-=b;
    cout<<"Hieu phan so -=: "<<c<<endl;
    a*=b;
    cout<<"Tich phan so *=: "<<c<<endl;
    a/=b;
    cout<<"Thuong phan so /=: "<<c<<endl;
    cout<<"*******************************************"<<endl;*/
    if(a>b)
    cout<<"a lon hon"<<endl;
    else if(a==b)
    cout<<"a=b";
    else cout<<"a be hon"<<endl;
    cout<<"*******************************************"<<endl;
    system("pause");
}