//Ho ten: Bach Long Vu
//MSSV:6051071145
#include<iostream>
#include<math.h>
using namespace std;
class DonThuc{
    private:
        float heso;
        float somu;
    public: 
        void Nhap();
        void Xuat();
        float Tinhx(int x);
        void SoSanh(DonThuc dt1);
        DonThuc DaoHamCap1();
        DonThuc DaoHamCapK( int x);
        float getHeso();
        float getSomu();
        DonThuc Thuong(DonThuc dt1);
        DonThuc Tich(DonThuc dt1);
        DonThuc Tong(DonThuc dt1);
        DonThuc Hieu(DonThuc dt1);

};
 void DonThuc::Nhap(){
     cout<<"Nhap he so: "; cin>> heso;
     cout<<"Nhap so mu: "; cin>> somu;
 }
 //////////////////////////////////////////////////////
 void DonThuc::Xuat(){
     cout<<"Don thuc la: "<<heso<<"x^"<<somu;
 }
 //Tinh x
 float DonThuc::Tinhx(int x){
     return heso*pow((double)x,somu);
 }
 //So sanh hai don thuc
 void DonThuc::SoSanh(DonThuc dt1){
    int x;
    cout<<"Nhap x: "; cin>>x;
    if(this->Tinhx(x)>dt1.Tinhx(x)){
        cout<<"Don thuc 1 lon hon don thuc 2 ";
    }
    else if(this->Tinhx(x)<dt1.Tinhx(x)){
        cout<<"Don thuc 1 be hon don thuc 2 ";
    }
    else{
        cout<<"Hai don thuc bang nhau";
    }

 }
 
 //get he so
 float DonThuc::getHeso(){
     return heso;
 }
 //get so mu
 float DonThuc::getSomu(){
     return somu;
 }
 //Dao ham cap 1
 DonThuc DonThuc::DaoHamCap1()
{
    DonThuc c;
    c.heso = somu * heso;
    c.somu = somu - 1;
    return c;
}
//Dao ham cap K
DonThuc DonThuc::DaoHamCapK(int x )
{
    cout<<"Nhap bac cua don thuc: ";cin>>x;
    DonThuc a;
    while (x!=0)
    {
        a = DaoHamCap1();
        x--;
    }
    return a;
}
//Chia don thuc
DonThuc DonThuc::Thuong(DonThuc dt1)
{
    DonThuc c;
    c.heso = heso / dt1.heso;
    c.somu = somu - dt1.somu;
    return c;
}
//Nhan don thuc
DonThuc DonThuc::Tich(DonThuc dt1)
{
    DonThuc c;
    c.heso = heso * dt1.heso;
    c.somu = somu + dt1.somu;
    return c;
}
//Tong hai don thuc
DonThuc DonThuc::Tong(DonThuc dt1){
    DonThuc c;
    c.heso=heso+dt1.heso;
    c.somu=somu;
    return c;
}
//Hieu hai don thuc
DonThuc DonThuc::Hieu(DonThuc dt1){
    DonThuc c;
    c.heso=heso-dt1.heso;
    c.somu=somu;
    return c;
}
int main(){
    DonThuc dt1,dt2,dt3;
    int x;
    cout<<"Nhap cho don thuc 1: ";
    dt1.Nhap();
    dt1.Xuat();
    cout<<endl;
    cout<<"Nhap cho don thuc 2: ";
    dt2.Nhap();
    dt2.Xuat();
    cout<<endl;
    ///////////////////////////////////////
    cout<<"Dao ham cua don thuc 1: ";
    dt3=dt1.DaoHamCapK(x);
    dt3.Xuat();
    cout<<endl;
    cout<<"Dao ham cua don thuc 2 : ";
    dt3=dt2.DaoHamCapK(x);
    dt3.Xuat();
    cout<<endl;
    ////////////////////////////////////////////
    cout<<"Thuong hai don thuc ";
    dt3=dt1.Thuong(dt2);
    dt3.Xuat();
    cout<<endl;
    ////////////////////////////////////////////
    cout<<"Tich hai don thuc ";
    dt3=dt1.Tich(dt2);
    dt3.Xuat();
    cout<<endl;
    ///////////////////////////////////////////
    cout<<"Tong hai don thuc ";
    dt3=dt1.Tong(dt2);
    dt3.Xuat();
    cout<<endl;
    ///////////////////////////////////////////
    cout<<"Hieu hai don thuc ";
    dt3=dt1.Hieu(dt2);
    dt3.Xuat();
    cout<<endl;
    system("pause");
}
