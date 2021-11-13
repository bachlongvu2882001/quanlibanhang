#include <iostream>
#include <conio.h>
using namespace std;

class PhanSo
{
    private:
        int TuSo;
        int MauSo;
        
 
    public:
		int UCLN(int a, int b);
        PhanSo();
        PhanSo(int Tu, int Mau);
        void Nhap();
        void Xuat();
        void RutGon();   
		void Nghichdao ();
        PhanSo Cong (const PhanSo &);
        PhanSo Tru (const PhanSo &);
        PhanSo Nhan (const PhanSo &);
        PhanSo Chia (const PhanSo &);

        ~PhanSo();      
};
 
 
PhanSo::PhanSo()
{
    TuSo = 0;
    MauSo = 1;
}
 
PhanSo::PhanSo(int Tu, int Mau)
{
TuSo = Tu;
    if (Mau != 0)
    {
        MauSo = Mau;
    }
    else
    {
        MauSo = 1;
    }
}
 
void PhanSo::Nhap()
{
    cout << "\tNhap tu So: "; cin >> TuSo;
    cout << "\tNhap mau so: "; cin >> MauSo;
}
 
void PhanSo::Xuat()
{
    cout << TuSo << "/" << MauSo << "\n";
}

int PhanSo::UCLN(int a, int b) { 
	if (a==0 ||b==0) 
		return a+b; 
while (a !=b) { 
	if(a>b)
                    a=a-b;
                else
                    b=b-a;
            }
      return a;
       
}
void PhanSo::RutGon()
{
    int iUCLN = UCLN(TuSo, MauSo);
    TuSo = TuSo / iUCLN;
    MauSo = MauSo / iUCLN;
}
void PhanSo::Nghichdao(){
	int a;
	if (MauSo != 0)
		
		a = TuSo;
		TuSo = MauSo;
		MauSo= a; 
}
PhanSo PhanSo::Cong(const PhanSo &b)
{
    return PhanSo((TuSo*b.MauSo) + (MauSo*b.TuSo),MauSo*b.MauSo);
}
 
PhanSo PhanSo::Tru(const PhanSo &b)
{
      return PhanSo((TuSo*b.MauSo) - (MauSo*b.TuSo),MauSo*b.MauSo);
}
 
PhanSo PhanSo::Nhan(const PhanSo &b) 
{
     return PhanSo(this->TuSo*b.TuSo,this->MauSo*b.MauSo);
}
 
PhanSo PhanSo::Chia(const PhanSo &b)
{
    return PhanSo(this->TuSo*b.MauSo,this->MauSo*b.TuSo);
}
 

 
PhanSo::~PhanSo()
{
    cout << "\nHam huy";      
}

 
int  main()
{
    PhanSo ps1,ps2;
    PhanSo *ps;
    
    cout << "Phan so 1: \n";
    ps1.Nhap();
    cout << "\tPhan so thu 1: ";
    ps1.Xuat();
    ps1.RutGon();
    cout << "\tRut gon so thu 1: ";
    ps1.Xuat();
    cout<<"\tNghich dao phan so thu 1: ";
    ps1.Nghichdao();
    ps1.Xuat();
 
    cout << "Phan so 2: \n";
    ps2.Nhap();
    cout << "\tPhan so thu 2: ";
    ps2.Xuat();
    ps2.RutGon();
    cout << "\tRut gon so thu 2: ";
    ps2.Xuat();
    cout<<"\tNghich dao phan so thu 2: ";
 	ps2.Nghichdao();
 	ps2.Xuat(); 
 	
    PhanSo psTong = ps1.Cong(ps2);
    cout << "\nTong hai phan so: ";
    psTong.RutGon();
    psTong.Xuat();
 
    PhanSo psTich = ps1.Nhan(ps2);
    cout << "\nTich hai phan so: ";
    psTich.RutGon();
    psTich.Xuat();
 
    PhanSo psThuong = ps1.Chia(ps2);
    cout << "\nThuong hai phan so: ";
    psThuong.RutGon();
    psThuong.Xuat();
 	
	PhanSo psHieu = ps1.Tru(ps2);
    cout << "\nHieu hai so: ";
    psHieu.RutGon();
    psHieu.Xuat();
     
	int n ;
    cout<<"Nhap so phan so can nhap: ";
    cin>>n;
     ps=new PhanSo[n];
    for(int i=0; i<n; i++){
     cout << "Phan so thu: "<<i+1<<endl;
    (ps+i)->Nhap();
    
    }
    cout<<endl;
    system("pause");
 	return 0;    
 
     
}
