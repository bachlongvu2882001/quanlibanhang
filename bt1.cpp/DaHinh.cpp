//Bach LOng Vu
//6051071145
//Nhom 15
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class GiangVien{
	private:
		string HoTen,MaSo;
		int Tuoi;
		int Luong;
	public:
		virtual void Nhap(); //ham ao
		virtual void Xuat(); //ham ao
		virtual float TinhLuong() = 0; //ham thuan ao
		
};
void GiangVien::Nhap(){
    cout<<"Nhap ma so: ";
    cin>>MaSo;
	cout<<"\nNhap HoTen: ";
	cin.ignore(1);
	getline(cin,HoTen);
	cout<<"Nhap tuoi: ";
	cin>>Tuoi;
	cin.ignore(1);
	cout<<" Luong: ";
	cin>>Luong;
}
void GiangVien::Xuat(){
    cout<<"\tLuong= "<<Luong<<endl;
	cout<<"\tHo Ten=  "<<HoTen<<endl;
	cout<<"\tTuoi= "<<Tuoi<<endl;
	cout<<"\t Luong "<<Luong<<endl;	
}
float GiangVien::TinhLuong(){
    return 0;
}
//////////////////////////////////////////////
//////////////////////////////////////////////
class GiangVienCoHuu:public GiangVien{
	private:
		float HeSoLuong,ThamNien;
	public:
		void Nhap(); //ham ao
		void Xuat(); //ham ao
	    float TinhLuong() ; //ham thuan ao
		
};
void GiangVienCoHuu::Nhap(){
    Nhap();
    cout<<" He so luong: ";
	cin>>HeSoLuong;
    cout<<" Tham nien: ";
	cin>>ThamNien;
}
void GiangVienCoHuu::Xuat(){
    cout<<"\tHe so luong= "<<HeSoLuong<<endl;
	cout<<"\tTham Nien= "<<ThamNien<<endl;
	
}
float GiangVienCoHuu::TinhLuong(){
    return (HeSoLuong*1600+ThamNien*500);
}
///////////////////////////////////////////////
///////////////////////////////////////////////
class GiangVienThinhGiang:public GiangVien{
	private:
		int SoTiet;
        float DonGia;
	public:
		void Nhap(); //ham ao
		void Xuat(); //ham ao
		float TinhLuong() ; //ham thuan ao
		
};
void GiangVienThinhGiang::Nhap(){
    Nhap();
    cout<<" So tiet: ";
	cin>>SoTiet;
    cout<<" Don Gia: ";
	cin>>DonGia;
}
void GiangVienThinhGiang::Xuat(){
    Xuat();
    cout<<"\tSo tiet= "<<SoTiet<<endl;
	cout<<"\tDon Gia= "<<DonGia<<endl;
	
}
float GiangVienThinhGiang::TinhLuong(){
    return (SoTiet*DonGia);
}
////////////////////////////////////////////
//////////////////////////////////////////////
class QuanLyGiangVien{
    private:
		vector <GiangVien *> DSGV;
    public:
	    void Nhap(); 
		void Xuat(); 
		void SapXepTangDan();
        void LuongLonNhat();
        void TongLuongGiangVien();
};
void QuanLyGiangVien::Nhap(){
	int i=1,LuaChon;
	while(i){
		cout<<"\n1. Nhap Giang vien Co Huu."<<endl;
		cout<<"2. Nhap Giang vien thinh giang."<<endl;
		cout<<"3. Thoat nhap"<<endl;
		GiangVien *gv;
		cout<<"Moi lua chon: ";
		cin>>LuaChon;
		system("cls");
		switch(LuaChon){
			case 1:
				gv=new GiangVienCoHuu;
				gv->Nhap();
				DSGV.push_back(gv);
				break;
			case 2:
				gv=new GiangVienThinhGiang;
				gv->Nhap();
				DSGV.push_back(gv);
				break;
			case 3:
				i=0;
				break;
			default:
				cout<<"Nhap sai. Moi nhap lai"<<endl;
		}
	}
}
void QuanLyGiangVien::Xuat(){
	for(int i=0;i<DSGV.size();i++){
			cout<<"\nGiang Vien Co Huu: "<<endl;
			DSGV[i]->Xuat();
		}
		
		for(int i=0;i<DSGV.size();i++){
			cout<<"\nGiang Vien Thinh Giang: "<<endl;
			DSGV[i]->Xuat();
		}
}