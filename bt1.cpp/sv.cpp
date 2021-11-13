//Ho ten: Bach Long Vu
//MSSV:6051071145
#include <iostream>
#include<conio.h>
using namespace std;
class SinhVien{
    private:
        string hoten;
        float van,toan;
    public:
        void Nhap();
        void Xuat();
        string getHoten();
        float getVan();
        float getToan();
        float Diemtb();
        void XepLoai();
};
void SinhVien::Nhap(){
        cin.ignore();
        cout<<"\nHo Va Ten: ";
        getline(cin,hoten);
        cout<<"\nDiem Toan: ";
        cin>>toan;
        cout<<"\nDiem Van: ";
        cin>>van;
    
}
void SinhVien::Xuat()
{
 	cout<<"\nHo Va Ten:  "<<hoten<<endl;
 	cout<<"\nDiem Toan: "<<toan<<endl;
     cout<<"\nDiem Van:  "<<van<<endl;
}

//Lay ho ten sinh vien

string SinhVien::getHoten(){
    return hoten;
}

//Lay diem van sinh vien

float SinhVien::getVan(){
    return van;
}

//Lay diem toan sinh vien

float SinhVien::getToan(){
    return toan;
}

//Tinh diem trung binh

float SinhVien::Diemtb(){
  return (getVan()+getToan())/2;// hoac (van+toan)/2;
}

//Xep loai hoc luc

void SinhVien::XepLoai(){
    if(Diemtb()>=8)
      cout<<"Dat loai gioi"<<endl;
    else if(Diemtb()>=7 && Diemtb()<8)
      cout<<"Dat loai kha "<<endl;
    else if(Diemtb()>=5 && Diemtb()<7)
      cout<<"Dat loai trung binh"<<endl;
    else
      cout<<"Dat loai yeu"<<endl;
}
int main(){
    SinhVien *a;
    int n,u;
     do
            {

                cout<<"1: Nhap cho sinh vien \n";
                cout<<"2: Xuat sinh vien\n";
                cout<<"3: Diem trung binh va xep loai\n";
                cout<<"4: Thoat\n";				
	            cin>>u;
                system("cls");
                switch (u)
                {
                    case 1:  
                        cout<<"Nhap so luong sinh vien: \n";
                        cin>>n;                                   
                        a=new SinhVien[n];
                        for(int i=0;i<n;i++){
                            cout<<"Nhap cho sinh vien thu: "<<i+1<<endl;
                            (a+i)->Nhap();
                        }
                        break;
                    case 2:
                        for(int i=0;i<n;i++){
                            cout<<"Thong tin sinh vien thu: "<<i+1<<endl;
                            (a+i)->Xuat();
                      }
                        break;
                    case 3:
                        {
                        for(int i=0;i<n;i++){
                            cout<<"Diem trung binh cua sinh vien thu: "<<i+1<<endl;
                            cout<<"DiemTB = "<<(a+i)->Diemtb()<<endl;
                            (a+i)->XepLoai();
                        }
                        break;
                        }
                    case 4:
                    {
                        exit(1);
                        break;
                    }
				getch();
            }
            } while (1);
    getch();
    delete a;
    return 0;
}