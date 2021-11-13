//Bach Long Vu
//6051071145
#include <iostream>
#include<conio.h>
#include<string>
using namespace std;
class TaiKhoan  {
  private:
         float  m_fSoDu = 0;
  public:
      float baoSoDu() {   
            return m_fSoDu; 
      }
void napTien(float fSoTien) {   
       m_fSoDu += fSoTien;  
}
void rutTien(float fSoTien)  {
   if (fSoTien <= m_fSoDu)
          m_fSoDu -= fSoTien;
  }  
};
class TaiKhoanTietKiem:public TaiKhoan{
    private:
       string kihangui,laisuat;
       float tien;
    public:
       void input();
       void output();
       float rutTien();
};
void TaiKhoanTietKiem::input(){
    cout<<"Nhap so tien can nap: ";
    cin>>tien;
    cout<<"Thoi han gui: ";
    cin>>kihangui;
    cout<<"Lai suat: ";
    cin>>laisuat;
    napTien(tien);
}
void TaiKhoanTietKiem::output(){
    cout<<"So tien hien co la: "<<baoSoDu()<<endl;
    cout<<"Thoi han gui la: "<<kihangui<<endl;
    cout<<"lai suat: "<<laisuat<<endl;    
}
float TaiKhoanTietKiem::rutTien(){
    cout<<"Nhap so tien can rut: ";
    cin>>tien;
    rutTien(tien);
}
int main(){
    TaiKhoanTietKiem *a;
    int thoigian,u;
     do
            {

                cout<<"1: Gui tien \n";
                cout<<"2: So du thoi diem hien tai";
                cout<<"3: Rut tien\n";
                cout<<"7: Thoat\n";			
	            cin>>u;
                system("cls");
                switch (u)
                {
                    case 1:  
                        a->input();
                        break;
                    case 2:  
                        cout<<"So du la: "<<a->baoSoDu();        
                        break;
                    case 3: 
                    a->rutTien(); 
                    cout<<"So du la: "<<a->baoSoDu();        
                    break;
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