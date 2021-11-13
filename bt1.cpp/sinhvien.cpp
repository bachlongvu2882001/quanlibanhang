#include <iostream>
#include<conio.h>
using namespace std;
class SinhVien{
        string hoten,gioitinh,ngaysinh;
        float diemtb;
    public:
        void Nhap();
        void Xuat();
        
};
void SinhVien::Nhap(){
    cout<<"Nhap ho ten: ";
    cin>>hoten;
    cout<<"Nhap gioi tinh: ";
    cin>>gioitinh;
    cout<<"Nhap ngay sinh: ";
    cin>>ngaysinh;
    cout<<"Nhap diem trung binh: ";
    cin>>diemtb;
}
void SinhVien::Xuat(){
    cout<<"Ho ten sinh vien la: "<<hoten<<endl;
    cout<<"Gioi tinh: "<<gioitinh<<endl;
    cout<<"Ngay sinh: "<<ngaysinh<<endl;
    cout<<"Diem trung binh: "<<diemtb<<endl;
}
int main(){
    SinhVien a;
    a.Nhap();
    a.Xuat();
    getch();
}