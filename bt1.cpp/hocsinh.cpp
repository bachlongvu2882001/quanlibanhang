//Bạch Long Vũ
//6051071145
#include<iostream>
#include<string>
using namespace std;
class HocSinh{
    private:
        string hoten;
        float van,toan;
    public:
        HocSinh(string hoten, float van, float toan);
        HocSinh(const HocSinh &x);
        HocSinh(string hoten);      
        ~HocSinh();
        float DTB();
		friend istream &operator>>(istream &is, HocSinh &hs);
		friend ostream &operator<<(ostream &os, const HocSinh &hs);
		bool operator>(HocSinh hs);
		bool operator<(HocSinh hs);
		bool operator==(HocSinh hs);
        bool operator>=(HocSinh hs);
		bool operator<=(HocSinh hs);
		bool operator!=(HocSinh hs);
       void operator=(const HocSinh &hs);
       int DemSTT();
};
int HocSinh::DemSTT()
{
    static int stt{ 0 };
    return stt;
}
HocSinh::HocSinh(string hoten, float van, float toan){
    this->hoten = hoten;
    this->van = van;
    this->toan = toan;
}
HocSinh::HocSinh(const HocSinh &x){
    hoten=x.hoten;
    van = x.van;
    toan = x.toan;
}
HocSinh::HocSinh(string hoten){
    this->hoten = hoten;
    this->van = 0.0;
    this->toan = 0.0;
}
HocSinh::~HocSinh(){

}
//Toan tu nhap
istream &operator>>(istream &is, HocSinh &hs){
	cout<<"Nhap ho va ten: ";
	cin.ignore();
	getline(is,hs.hoten);
	cout<<"Nhap diem toan: ";
	is>>hs.toan;
	cout<<"Nhap diem van: ";
	is>>hs.van;
	return is;
}
//Toan tu xuat
ostream &operator<<(ostream &os, const HocSinh &hs){
	cout<<"\tHo ten: "<<hs.hoten<<endl;
	cout<<"\tDiem toan: "<<hs.toan<<endl;
	cout<<"\tDiem van: "<<hs.van<<endl;
	return os;
}
//Toan tu so sanh >
bool HocSinh::operator>(HocSinh hs){
	if(DTB()>hs.DTB())
	return 1;
	return 0;
	
}
//Toan tu so sanh <
bool HocSinh::operator<(HocSinh hs){
	if(DTB()<hs.DTB())
	return 1;
	return 0;
}
//Toan tu so sanh ==
bool HocSinh::operator==(HocSinh hs){
	if(DTB()==hs.DTB())
	return 1;
	return 0;
}
//Toan tu so sanh >=
bool HocSinh::operator>=(HocSinh hs){
	if(DTB()>=hs.DTB())
	return 1;
	return 0;
	
}
//Toan tu so sanh <=
bool HocSinh::operator<=(HocSinh hs){
	if(DTB()<=hs.DTB())
	return 1;
	return 0;
}
//Toan tu so sanh !=
bool HocSinh::operator!=(HocSinh hs){
	if(DTB()!=hs.DTB())
	return 1;
	return 0;
}
//Ham lay diem trung binh
float HocSinh::DTB(){
	return (toan+van)/2;
}
//Toan tu gan =
void HocSinh::operator=(const HocSinh &hs){
   hoten=hs.hoten;
    van = hs.van;
    toan = hs.toan;
}
int main(){
    HocSinh a(),b(); 
    cout<<"Thong tin hoc sinh la:"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<"***************************\n";
    cout<<"Toan tu so sanh >,<,== "<<endl;
    if(a>b)
        cout<<"Diem tb a cao hon"<<endl;
    else if(a<b)
        cout<<"Diem tb a be hon b"<<endl;
    else if(a==b)
         cout<<"a=b"<<endl;
    else
         cout<<"khong xac dinh"<<endl;
    cout<<"***************************\n";
    cout<<"Toan tu so sanh >= <=, != "<<endl;
    if(a>=b)
    cout<<"Diem tb a lon hon hoac bang b"<<endl;
    if(a<=b)
    cout<<"Diem tb a be hon hoac bang b"<<endl;
    if(a!=b)
    cout<<"a!=b"<<endl;
    system("pause");
    return 0;
}