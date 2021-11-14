#include<iostream>
#include<iomanip>
#include<string>
#include <vector>
using namespace std;
class Father{
    virtual void Nhap();
    virtual void Xuat();
};
//************CLASS SAN PHAM********************************
//**********************************************************
class SanPham:public Father{
    private:
        string tensp,masp,mancc,tenncc;
        int sl;
        float dg;
    public:
         void Nhap();
         void Xuat();
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
    private:
        string makh,tenkh,std,dc;
    public:
};
//************CLASS NHAN VIEN********************************
//**********************************************************
class NhanVien{
    private:
        string manv,tennv,sdt,dc;
    public:
           
};
//*************CLASS HOA DON********************************
//**********************************************************
class HoaDon:public SanPham,public KhachHang,public NhanVien{
    private:
        string mahd,makh,tenkh,manv,tennv;
    public:
          
};
//**********************MAIN********************************
//**********************************************************
int main()
{
   cout<<"hello world"<<endl;
    system("pause");
    return 0;
}