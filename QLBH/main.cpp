#include<iostream>
#include<iomanip>
#include<string>
#include <vector>
using namespace std;

//************CLASS SAN PHAM********************************
//**********************************************************
class SanPham{
    protected:
        string tensp,masp,mancc,tenncc;
        int sl;
        float dg;
    public:
         virtual void Nhap()=0;
         virtual void Xuat()=0;
};
//Nhap cho san pham
void SanPham::Nhap(){
    cout<<"\nMa san pham: ";
 	cin>>masp;
	cin.ignore();
 	cout<<"\nTen san pham: ";
 	getline(cin,tensp);
    cout<<"\nMa nha cung cap: ";
 	cin>>mancc;
 	cout<<"\nTen nha cung cap: ";
 	getline(cin,tenncc);
 	cout<<"\nSo luong: ";
 	cin>>sl;
    cout<<"\nDon gia: ";
 	cin>>dg;
}
//Xuat San san pham
void SanPham::Xuat(){
    cout<<"\nMa san pham: "<<masp;
 	cout<<"\nTen san pham:  "<<tensp;
    cout<<"\nMa nha cung cap: "<<mancc;
 	cout<<"\nTen nha cung cap:  "<<tenncc;
 	cout<<"\nSo luong:  "<<sl;
 	cout<<"\nDon gia: "<<dg;
}
//************CLASS KHACH HANG********************************
//**********************************************************
class KhachHang{
    protected:
        string makh,tenkh,sdt,dc;
    public:
        KhachHang(string makh,string tenkh,string sdt,string dc);
        virtual void Nhap()=0;
         virtual void Xuat()=0;
};
//Ham tao cho khach hang 
    KhachHang::KhachHang(string makh,string tenkh,string sdt,string dc){
    this->makh = " ";
    this->tenkh = " ";
    this->sdt = " ";
    this->dc = " ";
}
//Nhap cho khach hang
void KhachHang::Nhap(){
    cout<<"\nMa khach hang: ";
 	cin>>makh;
	cin.ignore();
 	cout<<"\nTen khach hang: ";
 	getline(cin,tenkh);
    cout<<"\nSo dien thoai: ";
 	cin>>sdt;
 	cout<<"\nDia chi: ";
 	cin>>dc;
}
//Xuat cho khach hang
void KhachHang::Xuat(){
    cout<<"\nMa khach hang: "<<makh;
 	cout<<"\nTen khach hang:  "<<tenkh;
    cout<<"\nSo dien thoai: "<<sdt;
 	cout<<"\nDia chi:  "<<dc;
}
//************CLASS NHAN VIEN********************************
//**********************************************************
class NhanVien{
    protected:
        string manv,tennv,sdt,dc;
    public:
        virtual void Nhap()=0;
        virtual void Xuat()=0; 
};
//Nhap cho khach hang
void NhanVien::Nhap(){
    cout<<"\nMa nhan vien: ";
 	cin>>manv;
	cin.ignore();
 	cout<<"\nTen nhan vien: ";
 	getline(cin,tennv);
    cout<<"\nSo dien thoai: ";
 	cin>>sdt;
 	cout<<"\nDia chi: ";
 	cin>>dc;
}
//Xuat cho khach hang
void NhanVien::Xuat(){
    cout<<"\nMa nhan vien: "<<manv;
 	cout<<"\nTen nhan vien: "<<tennv;
    cout<<"\nSo dien thoai: "<<sdt;
 	cout<<"\nDia chi:  "<<dc;
}
//*************CLASS HOA DON********************************
//**********************************************************
class HoaDon:public SanPham,public KhachHang,public NhanVien{
    private:
        string mahd;
    public:
        void Nhap();
        void Xuat(); 
};
//Nhap cho hoa don
void HoaDon::Nhap()
{
    bool temp=false;
    bool i=true;
    cout<<"\nMa hoa don: ";
 	cin>>mahd;
     cout<<"\nMa nhan vien ban hang: ";
 	cin>>manv;
	cin.ignore();
 	cout<<"\nTen nhan vien ban hang: ";
 	getline(cin,tennv);
	cin.ignore();
    cout<<"\nMa khach hang: ";
 	cin>>manv;
	cin.ignore();
 	cout<<"\nTen khach hang: ";
 	getline(cin,tennv);
     for(;i=temp;){
            cout<<"\nMa san pham: ";
            cin>>manv;
            cout<<"\nTen san pham: ";
            getline(cin,tensp);
            cout<<"1-Tiep tuc them san pham"<<endl;
            cout<<"2-Dung"<<endl;
            int luachon;
            cin>>luachon;
            switch(luachon){
                case 1: break;
                case 2: temp=true; break;                 
            }
     }
}
//Xuat cho hoa don
void HoaDon::Xuat(){
    cout<<"\nMa hoa don: "<<mahd;
 	cout<<"\nMa khach hang: "<<makh;
    cout<<"\nTen khach hang: "<<tenkh;
 	for(;;){
         cout<<"Ma san pham: "<<masp<<endl;
         cout<<"Ten san pham: "<<tensp<<endl;
     }
}
//**********************MAIN********************************
//**********************************************************
int main()
{
   cout<<"hello world"<<endl;
    system("pause");
    return 0;
}