//BACH LONG VU - 6051071145
#include <iostream>
#include <conio.h>
using namespace std;

class PhanSo
{
    private:
        int TuSo;
        int MauSo;
    public:
        void Nhap();
        void Xuat();
        void Cong (PhanSo a, PhanSo b);
        void Tru (PhanSo a, PhanSo b);
        void Nhan (PhanSo a, PhanSo b);
        void Chia (PhanSo a, PhanSo b); 
        int UCLN(int a, int b); 
        void RutGon(PhanSo p);
};
 
 

void PhanSo::Nhap()
{   
    cout << "\tNhap tu So: "; cin >> TuSo;
    cout << "\tNhap mau so: "; cin >> MauSo;
}
 
void PhanSo::Xuat()
{
    cout << TuSo << "/" << MauSo << "\n";
   
}


//////////////////////////////////////////////////
void PhanSo::Cong(PhanSo a, PhanSo b)
{
    int tu,mau;
    tu=a.TuSo*b.MauSo+a.MauSo*b.TuSo;
    mau=a.MauSo*b.MauSo;
    cout<<"TOng hai ps: "<<tu<<"/"<<mau<<endl; 
}
/////////////////////////////////////////////////
void PhanSo::Tru(PhanSo a, PhanSo b)
{
    int tu,mau;
    tu=a.TuSo*b.MauSo-a.MauSo*b.TuSo;
    mau=a.MauSo*b.MauSo;
    cout<<"Hieu hai ps: "<<tu<<"/"<<mau<<endl; 
}
////////////////////////////////////////////////
void PhanSo::Nhan(PhanSo a, PhanSo b)
{
    int tu,mau;
    tu=a.TuSo*b.TuSo;
    mau=a.MauSo*b.MauSo;
    cout<<"Tich hai ps: "<<tu<<"/"<<mau<<endl; 
}
///////////////////////////////////////////////
void PhanSo::Chia(PhanSo a, PhanSo b)
{
    int tu,mau;
    tu=a.TuSo*b.MauSo;
    mau=a.MauSo*b.TuSo;
    cout<<"Thuong hai ps: "<<tu<<"/"<<mau<<endl; 
}
///////////////////////////////////////////////
int PhanSo::UCLN(int a, int b){
	while(a!=b){
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
//////////////////////////////////////////////
void PhanSo::RutGon(){
    int a,b;
    PhanSo ps;
    ps.TuSo=this->TuSo;
    ps.MauSo=this->MauSo;
//Hàm tìm UCLN thông thường
    a = abs(ps.TuSo);
    b = abs(ps.MauSo);
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    ps.TuSo=TuSo/a;
    ps.MauSo=MauSo/a;
    // Giá trị của this->TuSo và this->MauSo không hề thay đổi
    return ps; // Trả về giá trị của cái Class hiện tại
}
int  main()
{
    PhanSo ps1,ps2,ps3;
    
    cout << "Phan so 1: \n";
    ps1.Nhap();
    cout << "\tPhan so thu 1: ";
    ps1.Xuat();
/////////////////////////////////////////
    cout << "Phan so 2: \n";
    ps2.Nhap();
    cout << "\tPhan so thu 2: ";
    ps2.Xuat();
////////////////////////////////////////////
    ps3.Cong (ps1, ps2);  
    ps3.RutGon(ps3);    
////////////////////////////////////////////////////
     ps3.Tru (ps1, ps2); 
     ps3.RutGon(ps3);       
////////////////////////////////////////////////////
     ps1.Nhan (ps1, ps2); 
     ps3.RutGon(ps3);       
////////////////////////////////////////////////////
     ps1.Chia (ps1, ps2); 
     ps3.RutGon(ps3);     
 system("pause");
 	return 0;     
}