//Bach Long Vu
//MSSV: 6051071145
#include<iostream>
#include<string>
#include<conio.h>
#include <iomanip>
using namespace std;
class Sinhvien{
	private:
		int NS;
		string Hoten,MSV,Lop;
		float DTB;
	public:
		friend istream &operator>>(istream &is, Sinhvien &SV);
		friend ostream &operator<<(ostream &os, Sinhvien &SV);
		bool operator>(Sinhvien SV);
		bool operator<(Sinhvien SV);
		bool operator==(Sinhvien SV);
        float getDTB();
        int getNS();
};
//Nhap 
istream &operator>>(istream &is, Sinhvien &SV){
	cout<<"Nhap ma so sinh vien: ";
	cin.ignore();
	getline(is,SV.MSV);
	cout<<"Nhap ho va ten: ";
	cin.ignore();
	getline(is,SV.Hoten);
	cout<<"Nhap nam sinh: ";
	is>>SV.NS;
	cout<<"Nhap lop: ";
	cin.ignore();
	getline(is, SV.Lop);
	cout<<"Nhap diem trung binh: ";
	is>>SV.DTB;
	return is;
}
//Xuat
ostream &operator<<(ostream &os, Sinhvien &SV){
	cout<<setw(15)<<"\tMSSV: "<<SV.MSV<<endl;
	cout<<setw(20)<<"\tHo ten: "<<SV.Hoten<<endl;
	cout<<setw(10)<<"\tNam sinh: "<<SV.NS<<endl;
	cout<<setw(10)<<"\tLop: "<<SV.Lop<<endl;
	cout<<setw(10)<<"\tDiem trung binh: "<<SV.DTB<<endl;
	return os;
}
//Toan tu so sanh >
bool Sinhvien::operator>(Sinhvien SV){
	if(this->DTB>SV.DTB)
	return 1;
	return 0;
	//cach 2: return (this->DTB>SV.DTB?1:0);
}
//Toan tu so sanh <
bool Sinhvien:: operator<(Sinhvien SV){
	if(this->DTB<SV.DTB)
	return 1;
	return 0;
}
//Toan tu so sanh ==
bool Sinhvien:: operator==(Sinhvien SV){
	if(this->DTB==SV.DTB)
	return 1;
	return 0;
}
//Nhap n sinh vien 
void NhapDanhSachSV(int n, Sinhvien *SV){
	for(int i=0;i<n;i++){
		cin>>*(SV+i);
	}
}
//Xuat mot danh sach gom n sinh vien
void XuatDanhSachSV(int n, Sinhvien *SV){
	for(int i=0;i<n;i++){
		cout<<"************"<<endl;
		cout<<setw(5)<<"Stt: "<<i+1<<endl;
		cout<<*(SV+i);
	}
}
//Lay diem tb
float Sinhvien::getDTB(){
	return this->DTB;}
//Hoan doi vi tri sinh vien
void swap(Sinhvien *a,Sinhvien *b)
{
	Sinhvien c=*a;
	*a = *b;
	*b = c;
}

//Sap xep diem trung binh theo diem giam dan va dua ra man hinh
void SapxepDTB(int n,Sinhvien* SV)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if((SV+i)->getDTB()<(SV+j)->getDTB() )
				swap((SV+i),(SV+j));
	}
	XuatDanhSachSV(n,SV);
}
//Lay nam sinh cua sinh vien
int Sinhvien::getNS(){
    return this->NS;
}
//Sap xep Thu tu nam sinh tang dan va dua ra man hinh
void SapxepNS(int n,Sinhvien* SV)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if((SV+i)->getNS()>(SV+j)->getNS() )
				swap((SV+i),(SV+j));
	}
	XuatDanhSachSV(n,SV);
}
//Dem so sinh vien bi canh cao hoc vu (diemTB<1.0)
void ThongKe(int n, Sinhvien *SV){
	int soluongcanhcao = 0;
	for(int i=0;i<n;i++){
		float t = (SV+i)->getDTB();
		if(t < 1){
			soluongcanhcao++;
		}
	}
	cout<<"Tong so luong sinh vien canh cao: "<<soluongcanhcao<<endl;
}
int main(){
     Sinhvien *a;
    int n,u;
     do
            {

                cout<<"1: Nhap cho sinh vien \n";
                cout<<"2: Xuat sinh vien\n";
                cout<<"3: Sap xep sinh vien theo thu tu DTB giam dan\n";
                cout<<"4: Sap xep danh sach sinh vien theo thu tu nam sinh tang dan \n";	
                cout<<"5: Thong ke sinh vien canh cao hoc tap\n";
                cout<<"6: Thoat\n";			
	            cin>>u;
                system("cls");
                switch (u)
                {
                    case 1:  
                        cout<<"Nhap so luong sinh vien: \n";
                        cin>>n;                                   
                        a = new Sinhvien[n];
                        NhapDanhSachSV(n, a);
                        break;
                    case 2:
                        XuatDanhSachSV(n,a);
                        break;
                    case 3:
                        SapxepDTB(n,a);
                        break;
                        
                    case 4:
                    {
                       SapxepNS(n,a);
                        break;
                    }
                    case 5:
                      {
                       ThongKe(n,a);
                       break;
                      }
                    case 6:
                      exit(1);
                        break;
                }
				getch();
            } while (1);
    getch();
    delete a;
    return 0;
}
    
