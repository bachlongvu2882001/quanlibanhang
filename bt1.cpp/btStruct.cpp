//BACH LONG VU
//MSSV:6051071145
#include <iostream>
#include<conio.h>
#include<string>
using namespace std;
typedef struct CONGNHAN
{
	string ten;
	int ns;
    float gio;
}CN;

void Nhap(CN *a,int n)
{
    cout<<"Nhap so luong CN";
    cin>> n;
    for (int i=1; i<=n; i++){
    cout<<"Nhap CN thu :"<<i<<endl;
    cout<<"Nhap ten CN: ";
    cin.ignore(1);
    getline(cin,(a+i)->ten);
   // cin>>(a+i)->ten;
    cout<<"Nhap nam sinh CN: ";
    cin>>(a+i)->ns;
    cout<<"Nhap so gio lam: ";
    cin>>(a+i)->gio;
    }
}
void Xuat(CN *a,int n)
{
    for (int i=1; i<=n; i++){
    cout<<"CN thu: "<<i<<endl;
    cout<<"Ten CN: "<<(a+i)->ten<<endl;
    cout<<"Nam sinh CN: "<<(a+i)->ns<<endl;
    cout<<"So gio lam: "<<(a+i)->gio<<endl;
    }
}

void SapXep(CN *a,int n){
       CN tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((a+i) < (a+j)){
                // Hoan vi 2 so a[i] va a[j]
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
    }
int main(){
    int n,u;
    CN *a;
    do
            {

                cout<<"1: Nhap \n";
                cout<<"2: Xuat\n";
                cout<<"3: Sap Xeo\n";
                cout<<"4: Thoat\n";				
	            cin>>u;
                system("cls");
                switch (u)
                {
                    case 1:                      
                        a=new CN[n];
                        Nhap(a,n);
                        break;
                    case 2:
                      
                        Xuat(a,n);
                        break;
                    case 3:
                        {
                       SapXep(a,n);
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
    return 0;
}

