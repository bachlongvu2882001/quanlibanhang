#include <iostream>
#include<conio.h>
#include<string>
using namespace std;
class person{
    protected:
        string name,add;
        int age;
        void input();
        void output();
        string getname();
};
class student : public person{
    private:
       float score;
       string id;
    public:
       void input();
       void output();
       void rank();
};
class teacher:public person{
      void teach();
};
void teacher::teach(){
    if(getname()=="Mien"||getname()=="mien"){
        cout<<"Day CSDL";
    }
    else if(getname()=="Dung"||getname()=="dung"){
        cout<<"Day OOP";
    }
    else if(getname()=="Minh"||getname()=="minh"){
        cout<<"Day Tin hoc dai cuong";
    }
    else{
        cout<<"Day Phan tich thuat toan";
    }
}
/////////////////////////////////////////////
////////////////////////////////////////////
string person::getname(){
    return this->name;
}
void person::input(){
    cin.ignore();
    cout<<"Nhap ho va ten: ";
	getline(cin,name);
    cout<<"Nhap dia chi: ";
	getline(cin,add);
    cout<<"Nhap tuoi: ";
    cin>>age;
}
void person::output(){
    cout<<"Ho va ten: "<<name<<endl;
    cout<<"Dia chi: "<<add<<endl;
    cout<<"Tuoi: "<<age<<endl;
}
//////////////////////////////////////////////////
/////////////////////////////////////////////////
void student::input(){
    cin.ignore();
    cout<<"Nhap ma so sinh vien: ";	
	getline(cin,id);
    cout<<"Nhap ho va ten: ";
	getline(cin,name);
    cout<<"Nhap dia chi: ";
	getline(cin,add);
    cout<<"Nhap tuoi: ";
    cin>>age;
    cout<<"Nhap diem: ";
    cin>>score;
}
void student::output(){
    cout<<"Ho va ten: "<<name<<endl;
    cout<<"Dia chi: "<<add<<endl;
    cout<<"Tuoi: "<<age<<endl;
    cout<<"Diem: "<<score<<endl;
}
void student::rank(){
    if(score>=8){
      cout<<"Loai gioi";}
    else if(6.5<=score<8)
      {cout<<"Loai kha";}
    else if(5<=score<6.5)
      {cout<<"Loai TB";}
    else  
      {cout<<"Loai yeu";}
}
int main(){
    student *a;
    person *p;
    teacher *c;
    int n,u,m;
     do
            {

                cout<<"1: Nhap cho sinh vien \n";
                cout<<"2: Nhap cho giang vien";
                cout<<"3: Xuat sinh vien\n";
                cout<<"4: Xep loai\n";
                cout<<"5: Mon giang vien day\n";
                cout<<"6: Xuat giang vien\n";	
                cout<<"7: Thoat\n";			
	            cin>>u;
                system("cls");
                switch (u)
                {
                    case 1:  
                        cout<<"Nhap so luong sinh vien: \n";
                        cin>>n;                                   
                        a=new student[n];
                        for(int i=0;i<n;i++){
                            cout<<"Nhap cho sinh vien thu: "<<i+1<<endl;
                            (a+i)->input();
                        }
                        break;
                    case 2:  
                        cout<<"Nhap so luong giang vien: \n";
                        cin>>n;                                   
                        p=new student[m];
                        for(int i=0;i<m;i++){
                            cout<<"Nhap cho giang vien thu: "<<i+1<<endl;
                            (a+i)->input();
                        }
                        break;
                    case 3:
                        for(int i=0;i<n;i++){
                            cout<<"Thong tin sinh vien thu: "<<i+1<<endl;
                            (a+i)->output();
                      }
                        break;
                    case 4:
                        {
                        for(int i=0;i<n;i++){
                            cout<<"Xep sinh vien thu: "<<i+1<<endl;
                            (a+i)->rank();
                            cout<<endl;
                        }
                        break;
                        }
                     case 5:
                    {
                        for(int i=0;i<m;i++){
                            cout<<"Giang vien ten: "<<(p+i)->getname()<<endl;
                            (p+i)->teach();
                            cout<<endl;
                    }
                     case 6:
                        for(int i=0;i<m;i++){
                            cout<<"Thong tin giang vien thu: "<<i+1<<endl;
                            (p+i)->output();
                      }
                        break;
                    case 7:
                    {
                        exit(1);
                        break;
                    }
				getch();
            }
            } while (1);
    getch();
    delete a;
    delete p;
    return 0;
}