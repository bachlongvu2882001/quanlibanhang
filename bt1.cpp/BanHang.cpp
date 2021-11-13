//Bach Long Vũ - 6051071145
#include<iostream>
#include<string>
using namespace std;
class MatHang{
    private:
        string tenmh;
        int sl;
        float dg;
        float tien;
    public:
        void Nhap();
        void Xuat();    
        float Tien();   
};
class HoaDon:public MatHang{
    private:
        string tenhd;
        string dsmh;
        int slmh;
        float tt=0;
    public:
        void Nhap();
        void Xuat();   
        float TongTien();    
        string TenHD();
        void TimKiem(HoaDon *a, int n);
};
//Lay ten hoa don
string HoaDon::TenHD(){
    return tenhd;
}
//Lay so tien cua mot mat hang
float MatHang::Tien(){
    return tien;
}
//Lay so tien cua cac mat hang trong mot hoa don
float HoaDon::TongTien(){
   return tt;
      }
//Nhap cho Mat Hang
void MatHang::Nhap(){
    cout<<"\nNhap ten mat hang =  ";
    cin.ignore(1);
    getline(cin,tenmh);
    cout<<"\nNhap so luong =  ";
    cin>>sl;
    cout<<"\nNhap don gia =  ";
    cin>>dg;
    tien=sl*dg;
}
//Xuat cho Mat Hang
void MatHang::Xuat(){
    cout<<"\nTen mat hang  =  "<<tenmh<<endl;
    cout<<"\nSo luong =  "<<sl<<endl;
    cout<<"\nDon gia =  "<<dg<<endl;
}
//Nhap cho Hoa Don
void HoaDon::Nhap(){
    cout<<"\nNhap ten hoa don =  ";
    cin.ignore(1);
    getline(cin,tenhd);
    cout<<"\nNhap danh sach mat hang =  ";
    cin.ignore(1);
    getline(cin,dsmh);
    cout<<"\nNhap so luong mat hang=  ";
    cin>>slmh;
   for(int i=0;i<slmh;i++){
         MatHang::Nhap();
         tt+=Tien();
         cout<<"*****************"<<endl;
    }
}
//Xuat cho Mat Hang
void HoaDon::Xuat(){
    cout<<"\nTen hoa don  =  "<<tenhd<<endl;
    cout<<"\nDanh sach mat hang  =  "<<dsmh<<endl;
    cout<<"\nSo luong mat hang = "<<slmh<<endl;
    for(int i=0;i<slmh;i++){
         MatHang::Xuat();
          cout<<"*****************"<<endl;
    }
    cout<<"TOng tien: "<<TongTien();
}
//Nhap cho n hoa don
void Nhap(HoaDon *a, int n){
    for( int i=0; i<n; i++){
        cout<<"Nhap cho hoa don thu: "<<i+1<<endl;
        (a+i)->Nhap();
    }
}
//Xuat n hoa don 
void Xuat(HoaDon *a, int n){
    for( int i=0; i<n; i++){
        cout<<"Hoa don thu: "<<i+1<<endl;
        (a+i)->Xuat();
    }
    
}
//Tim hoa don co tong tien nho nhat
void min(HoaDon *a, int n){
   float min = (a+0)->TongTien();
   int temp=0;
      for(int i=0; i<n; i++){
            if(min>(a+i)->TongTien() ){
                min = (a+i)->TongTien();
            temp=i;
            }

      }
cout<<"Hoa don co tong tien be nhat la:"<<endl;
(a+temp)->Xuat();
cout<<endl;
}
//Tim hoa don co tong tien lon nhat
void max(HoaDon *a, int n){
   float min = (a+0)->TongTien();
   int temp=0;
      for(int i=0; i<n; i++){
            if(min<(a+i)->TongTien() ){
                min = (a+i)->TongTien();
            temp=i;
            }

      }
cout<<"Hoa don co tong tien lon nhat la:"<<endl;
(a+temp)->Xuat();
cout<<endl;
}
//TIm ten hoa don 
void TimKiem(HoaDon *a, int n){
    string b;
    int temp=0;
	cout<<"\nNhap ten hoa don cua can tim:  ";
	cin.ignore(1);
	getline(cin,b);
    for(int i=0;i<n; i++){
        if((a+i)->TenHD()==b){
            temp=i;
        }
        (a+temp)->Xuat();
    }

}
int main(){
    HoaDon *a;
    int  n;
    do{
         system("cls");
        cout<<"\n================MENU=================";
        cout<<"\n 1.Nhap cho hoa don.";
        cout<<"\n 2.Xuat danh sach.";
        cout<<"\n 3.Hoa don co tong tien be nhat.";
        cout<<"\n 4.Hoa don co tong tien lon nhat.";
        cout<<"\n 5.Tim ten hoa don .";
        cout<<"\n 6.Thoat."<<endl;
         cout<<"\n Nhap su lua chon =  ";
        int c;
        cin>>c;
       
        switch(c){
            case 1:
                    cout<<"\nNhap so luong hoa don =  ";
                    cin>>n;
                    a=new HoaDon[n];
                    Nhap(a,n);
                    break;

            case 2:
                    Xuat(a,n);
                    break;

            case 3:
                   min(a,n);
                   break;
            case 4:
                   max(a,n);
                   break;          
            case 5:
                   TimKiem(a,n); 

            case 6:
                    exit(1);
            }
            system("pause");
    }while(1);
    system("pause");
    delete a;
    return 0;
}