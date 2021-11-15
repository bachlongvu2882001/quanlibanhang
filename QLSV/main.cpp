#include<iostream>
#include<iomanip>
#include<string>
#include <vector>
using namespace std;
//**************TAO CLASS SINH VIEN*****************
//**************************************************
//**************************************************
class SV{  
    protected:
        string hoten;
        string namsinh;
        string gioitinh;
        string lop;
        int khoa;
        int msv;
        bool loaiSV;
    public:
        virtual void Nhap()=0; 
        virtual void Xuat()=0; 
        int getMSV();
        string HOTEN();
        void setLoai(bool l);
        bool getLoai();
        virtual float getTD();
        virtual float DTB();
        virtual float TOAN();
        virtual float LI();
        virtual float HOA();
};
//Nhap cho class sinh vien
void SV::Nhap()
 {
    cout<<"\nMa sinh vien: ";
    cin>>msv;
    cin.ignore();
    cout<<"\nHo Va Ten: ";
    getline(cin,hoten);
    cout<<"\nNgay Thang Nam Sinh: ";
    getline(cin,namsinh);
    cout<<"\nGioi tinh: ";
    getline(cin,gioitinh);
    
 }
 //Xuat cho class sinh vien
 void SV::Xuat()
{
    cout<<"\nMa sinh vien: "<<msv;
    cout<<"\nHo Va Ten:  "<<hoten;
    cout<<"\nNgay Thang Nam Sinh:  "<<namsinh;
    cout<<"\nGioi tinh: "<<gioitinh;
}
int SV::getMSV(){
    return this->msv;
}
void SV::setLoai(bool l){
    loaiSV=l;
}
bool SV::getLoai(){
    return loaiSV;
}
 float SV::getTD(){
    return 0;
}
 float SV::DTB(){
    return 0;
        }
float SV::TOAN(){
       return 0;
   }
float SV::LI(){
       return 0;
   }
float SV::HOA(){
       return 0;
   }
//**************TAO CLASS MON HOC**************
//*********************************************
///////////////////////////////////////////////
class Mon{
    protected:
      string to_mmh;
      string l_mmh;
      string h_mmh;
      string td_mmh;
      float toan,li,hoa,td;
       int to_tclt,l_tclt,h_tclt,td_tclt;
       int to_tcth,l_tcth,h_tcth,td_tcth;
       
    public:
        void Nhap();
        void Xuat(); 
};
//Nhap cho class mon hoc
void Mon::Nhap()
{
    cout<<"\nNhap diem toan = ";
    cin>>toan;
    cout<<"\nNhap diem li = ";
    cin>>li;
    cout<<"\nNhap diem hoa = ";
    cin>>hoa;
    cout<<"\nNhap diem thi the duc= ";
    cin>>td;
}
//Xuat cho class mon hoc
void Mon::Xuat(){
    cout<<"\nMa mon hoc_TOAN: "<<to_mmh;
    cout<<"\nDiem toan=  "<<toan<<" Tin chi li thuyet: "<<to_tclt<<" Tin chi thuc hanh: "<<to_tcth;
    cout<<"\nMa mon hoc_LI: "<<l_mmh;
    cout<<"\nDiem li=  "<<li<<" Tin chi li thuyet: "<<l_tclt<<" Tin chi thuc hanh: "<<l_tcth;
    cout<<"\nMa mon hoc_HOA=  "<<h_mmh;
    cout<<"\nDiem hoa=  "<<hoa<<" Tin chi li thuyet: "<<h_tclt<<" Tin chi thuc hanh: "<<h_tcth;
    cout<<"\nMa mon hoc_THE_DUC=  "<<td_mmh;
    cout<<"\nDiem the duc =  "<<td<<" Tin chi li thuyet: "<<td_tclt<<" Tin chi thuc hanh: "<<td_tcth;
}
//************TAO CLASS LOP CHINH QUY************
//***********************************************
//***********************************************
class LopCQ:public Mon,public SV{ 
    protected:
        string MaLop;
        string TenLop;
        int Khoa;
    public:
        void Nhap();
        void Xuat();
};
//Nhap cho lop chinh quy
void LopCQ::Nhap(){
    cout<<"\nKhoa: ";
    cin>>Khoa;
    SV::Nhap();
    Mon::Nhap();
}
//Xuat cho lop chinh quy
void LopCQ::Xuat(){
    cout<<"\nMa Lop: "<< MaLop << endl <<"Ten Lop: "<<TenLop<<endl<<"Khoa: "<<Khoa<<endl;
    SV::Xuat();
    Mon::Xuat();
    //cout<<"\nDiem trung binh cua ban la:  "<<DTB();
}
//**********TAO CLASS LOP VUA HOC VUA LAM************
//***************************************************
//***************************************************
class LopVHVL:public Mon,public SV{ 
    private:
        string MaLop;
        string TenLop;
        int Khoa;

    public:
        void Nhap();
        void Xuat();
};
//Nhap cho lop vua hoc vua lam
void LopVHVL::Nhap(){
    cout<<"\nKhoa: ";
    cin>>Khoa;
    SV::Nhap();
    Mon::Nhap();
}
//Xuat cho lop vua hoc vua lam
void LopVHVL::Xuat(){
    cout<<"\nMa Lop: "<< MaLop << endl <<"Ten Lop: "<<TenLop<<endl<<"Khoa: "<<Khoa<<endl;
    SV::Xuat();
    Mon::Xuat();
    //cout<<"\nDiem trung binh cua ban la:  "<<DTB();
}
//***********TAO CLASS KE THUA**********************
//**************************************************
//**************************************************
class TongHop:public LopCQ,public LopVHVL{
    protected:
            vector <SV *> TH;
    public:
        void Nhap();
        void Xuat();
};
int main()
{
    system("pause");
    return 0;
}
