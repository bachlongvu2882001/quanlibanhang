#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#include<Windows.h>
#pragma warning(disable:4996)
using namespace std;
//**************TAO CLASS SINH VIEN*****************
//**************************************************
//**************************************************
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// HÃƒÂ m tÃƒÂ´ mÃƒÂ u.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// HÃƒÂ m dÃ¡Â»â€¹ch chuyÃ¡Â»Æ’n con trÃ¡Â»Â Ã„â€˜Ã¡ÂºÂ¿n tÃ¡Â»Âa Ã„â€˜Ã¡Â»â„¢ x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// HÃƒÂ m xÃƒÂ³a mÃƒÂ n hÃƒÂ¬nh.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// HÃƒÂ m lÃ¡ÂºÂ¥y Key tÃ¡Â»Â« bÃƒÂ n phÃƒÂ­m
/* GetAsyncKeyState(VK_ESCAPE) => bÃ¡ÂºÂ¯t sÃ¡Â»Â± kiÃ¡Â»â€¡n phÃƒÂ­m Esc */ 

// HÃƒÂ m tÃ¡Â»Â± viÃ¡ÂºÂ¿t
void ToMau(int x, int y, char *a, int color) // x, y lÃƒÂ  tÃ¡Â»Âa Ã„â€˜Ã¡Â»â„¢ con trÃ¡Â»Â cÃ¡ÂºÂ§n nhÃ¡ÂºÂ£y Ã„â€˜Ã¡ÂºÂ¿n Ã„â€˜Ã¡Â»Æ’ viÃ¡ÂºÂ¿t, a lÃƒÂ  chuÃ¡Â»â€”i cÃ¡ÂºÂ§n truyÃ¡Â»Ân vÃƒÂ o, color lÃƒÂ  mÃƒÂ u truyÃ¡Â»Ân vÃƒÂ o.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
class SV{  
    protected:
		string hoten;
		string namsinh;
		string gioitinh;
		string lop;
		string khoa;
		string msv;
		bool loaiSV;
	public:
		virtual void Nhap(); 
		virtual void Xuat(); 
        string getMSV();
		string HOTEN();
		void setLoai(bool l);
		bool getLoai();
		virtual float getTD();
		virtual float DTB();
		virtual float TOAN();
		virtual float LI();
		virtual float HOA();
		
};
//NHAP CHO CLASS SINH VIEN
void SV::Nhap()
 {
 	cout<<"\nMa sinh vien: ";
 	cin>>msv;
	cin.ignore();
 	cout<<"\nHo Va Ten: ";
 	getline(cin,hoten);
 	cout<<"\nNgay Thang Nam Sinh: ";
 	getline(cin,namsinh);
 	cout<<"\nGioi tinh: ";
 	getline(cin,gioitinh);
 	
 }
//XUAT CHO CLASS SINH VIEN

void SV::Xuat()
{   
	cout<<"\nKhoa: "<<khoa;
    cout<<"\nMa sinh vien: "<<msv;
 	cout<<"\nHo Va Ten:  "<<hoten;
 	cout<<"\nNgay Thang Nam Sinh:  "<<namsinh;
 	cout<<"\nGioi tinh: "<<gioitinh;
}
string SV::HOTEN(){
    return this->hoten;
}
string SV::getMSV(){
    return this->msv;
}
void SV::setLoai(bool l){
	loaiSV=l;
}
bool SV::getLoai(){
	return loaiSV;
}
float SV::getTD(){
	return 0;
}
float SV::DTB(){
	return 0;
		}
float SV::TOAN(){
	   return 0;
   }
float SV::LI(){
	   return 0;
   }
float SV::HOA(){
	   return 0;
   }
//**************TAO CLASS MON HOC**************
//*********************************************
///////////////////////////////////////////////
class Mon{
	protected:
	  string to_mmh;
	  string l_mmh;
	  string h_mmh;
	  string td_mmh;
	  float toan,li,hoa,td;
	   int to_tclt,l_tclt,h_tclt,td_tclt;
	   int to_tcth,l_tcth,h_tcth,td_tcth;
       
	public:
		Mon();
		~Mon();
	    void Nhap();
	    void Xuat(); 
	    float getTD();
	    float TOAN();
	    float LI();
		float HOA();
        float DTB();
		
};


//HAM TAO VA HAM HUY
Mon::Mon(){
	//toan - ma mon - tin chi li thuyet - tin chi thuc hanh
	to_mmh = "TIT1";
	to_tclt = 3;
	to_tcth = 0;
	//li- ma mon - tin chi li thuyet - tin chi thuc hanh
	l_mmh = "LIT1";
	l_tclt = 3;
	l_tcth = 1;
	//Hoa - ma mon - tin chi li thuyet - tin chi thuc hanh
	h_mmh = "HIT1";
	h_tclt = 2;
	h_tcth = 1;	
	//The duc - ma mon - tin chi li thuyet - tin chi thuc hanh
	td_mmh = "TDIT1";
	td_tclt = 0;
	td_tcth = 1;	
}
Mon::~Mon(){
}
//NHAP CHO CLASS MON HOC
void Mon::Nhap()
{
	cout<<"\nNhap diem toan = ";
	cin>>toan;
	cout<<"\nNhap diem li = ";
	cin>>li;
    cout<<"\nNhap diem hoa = ";
	cin>>hoa;
	cout<<"\nNhap diem thi the duc= ";
	cin>>td;
}
//XUAT CHO CLASS MON HOC
void Mon::Xuat(){
  cout<<"\nMa mon hoc_TOAN: "<<to_mmh;
	cout<<"\nDiem toan=  "<<toan<<" Tin chi li thuyet: "<<to_tclt<<" Tin chi thuc hanh: "<<to_tcth;
	cout<<"\nMa mon hoc_LI: "<<l_mmh;
	cout<<"\nDiem li=  "<<li<<" Tin chi li thuyet: "<<l_tclt<<" Tin chi thuc hanh: "<<l_tcth;
	cout<<"\nMa mon hoc_HOA=  "<<h_mmh;
	cout<<"\nDiem hoa=  "<<hoa<<" Tin chi li thuyet: "<<h_tclt<<" Tin chi thuc hanh: "<<h_tcth;
	cout<<"\nMa mon hoc_THE_DUC=  "<<td_mmh;
	cout<<"\nDiem the duc =  "<<td<<" Tin chi li thuyet: "<<td_tclt<<" Tin chi thuc hanh: "<<td_tcth;
}
float Mon::TOAN(){
	   return 0;
   }
float Mon::LI(){
	   return 0;
   }
float Mon::HOA(){
	   return 0;
   }
float Mon::getTD(){
	  return 0;}
float Mon::DTB(){
	  return 0;
		}  
//************TAO CLASS LOP CHINH QUY************
//***********************************************
//***********************************************
class LopCQ:public Mon,public SV{ //lop chinh quy
	protected:
    	string MaLop;
    	string TenLop;
    	string Khoa;
    public:
		LopCQ();
		~LopCQ();
		void Nhap();
        void Xuat();
		void QuanLiMonHoc(int n);
		float getTD();
		float DTB();
		float TOAN();
	     float LI();
		 float HOA();
		 void TimKiemTenSV();
		 void TimKiemMSSV();
		 void Xoa();
         void Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, LopCQ &cq);
         void Doc_File(ifstream &filein, vector< LopCQ > &ds_sinhvien);
         void Test(vector<LopCQ> ds);
};
void LopCQ::Xoa(){
	ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienCQ.txt", ios_base::in); 
	vector< LopCQ> cq;
	LopCQ::Doc_File(filein, cq);
    int vitri=0,a=0;
	string b;
	cout<<"\nNhap ma so sinh vien cua ban:  ";
	cin>>b;
	for(int i=0;i<cq.size();i++){
			 if(stricmp(cq[i].getMSV().c_str(), b.c_str()) == 0){
				vitri=i;
				a++;
				cout<<"\n================================";
				}
				
		    }
	if(a==0)
	  {
	  cout<<"\nKhong co sinh vien can xoa";
	  }
	  if(a!=0){
      cq.erase(cq.begin()+vitri);
	  cout<<"\nXoa thanh cong";
	  }
	filein.close();
}
void LopCQ::TimKiemMSSV(){
	ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//HIHI//SinhVienCQ.txt", ios_base::in); 
	vector< LopCQ> cq;
	LopCQ::Doc_File(filein, cq);
    int a = 0;
	string b;
	cout<<"\nNhap ma sinh vien can tim:  ";
	cin.ignore(1);
	getline(cin,b);
	for(int i=0;i<cq.size();i++){
			 if(stricmp(cq[i].getMSV().c_str(), b.c_str()) == 0){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				cq[i].Xuat();
				if(cq[i].DTB()>=8 && cq[i].getTD()>=6.5 && cq[i].HOA()>=6.5 && cq[i].TOAN()>=6.5 && cq[i].LI()>=6.5)
						  {cout<<"\nHoc luc gioi";}
						else if(cq[i].DTB()>=6.5 && cq[i].getTD()>=5 && cq[i].HOA()>=5 && cq[i].TOAN()>=5 && cq[i].LI()>=5){
							cout<<"\nHoc luc kha";
						}
						else if(cq[i].DTB()>=5 && cq[i].getTD()>=3.5 && cq[i].HOA()>=3.5 && cq[i].TOAN()>=3.5 && cq[i].LI()>=3.5){
							cout<<"\nHoc luc trung binh";
						}
						else
						{
							cout<<"\nHoc luc yeu";
						}
				a++;
				cout<<"\n================================";
				}
	}filein.close();
	if(a==0){
		cout<<"\nKhong co ten sinh vien can tim";
	}

///////////////////////////////////////////////////////////
}
void LopCQ::TimKiemTenSV(){
    ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienCQ.txt", ios_base::in); 
	vector< LopCQ> cq;
	Doc_File(filein, cq);
    int a = 0;
	string b;
	cout<<"\nNhap ten sinh vien can tim:  ";
	cin.ignore(1);
	getline(cin,b);
	for(int i=0;i<cq.size()-1;i++){
			 if(stricmp(cq[i].HOTEN().c_str(), b.c_str()) == 0){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				cq[i].Xuat();
				if(cq[i].DTB()>=8 && cq[i].getTD()>=6.5 && cq[i].HOA()>=6.5 && cq[i].TOAN()>=6.5 && cq[i].LI()>=6.5)
						  {cout<<"\nHoc luc gioi";}
						else if(cq[i].DTB()>=6.5 && cq[i].getTD()>=5 && cq[i].HOA()>=5 && cq[i].TOAN()>=5 && cq[i].LI()>=5){
							cout<<"\nHoc luc kha";
						}
						else if(cq[i].DTB()>=5 && cq[i].getTD()>=3.5 && cq[i].HOA()>=3.5 && cq[i].TOAN()>=3.5 && cq[i].LI()>=3.5){
							cout<<"\nHoc luc trung binh";
						}
						else
						{
							cout<<"\nHoc luc yeu";
						}
				a++;
				cout<<"\n================================";
				}
	}
	if(a==0){
		cout<<"\nKhong co ten sinh vien can tim";
	}
filein.close();
}
void LopCQ:: Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, LopCQ &cq)
{
	string temp;
	getline(filein, cq.khoa); 
	filein.ignore(0);
	getline(filein, cq.msv); 
	filein.ignore(0);
	getline(filein, cq.hoten);
	filein.ignore(0);
	getline(filein, cq.namsinh);
	filein.ignore(0);
	getline(filein, cq.gioitinh);
	filein.ignore(0);
    filein>>cq.toan;
    filein>>cq.li;
    filein>>cq.hoa;
    filein>>cq.td;	
	getline(filein, temp);
}
void LopCQ::Doc_File(ifstream &filein, vector< LopCQ > &ds_sinhvien)
{
	while (filein.eof() == false)
	{
		LopCQ cq; 
		LopCQ::Doc_File_Thong_Tin_Sinh_Vien(filein, cq);
		ds_sinhvien.push_back(cq); // thÃƒÂªm sinh viÃƒÂªn vÃƒÂ o cuÃ¡Â»â€˜i mÃ¡ÂºÂ£ng
		
	}
}
void LopCQ::Test(vector<LopCQ> ds)
{
	cout<<"    __________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"   |   Khoa   |     MaSV     |        Ho Ten         |  Ngay/Thang/Nam Sinh  |  Gioi Tinh  |    Toan    |    Li     |    Hoa     |  The Duc   |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl;
	for (int i = 0; i < ds.size()-1; i++)
	{
		ds[i].Xuat();
	}
}
//HAM TAO HAM HUY
LopCQ::LopCQ(){ 
	this->MaLop = "IT1";
	this->TenLop="Cong Nghe Thong Tin";	
}
LopCQ::~LopCQ(){
}
//NHAP CHO LOP CHINH QUY
void LopCQ::Nhap(){
  char data[100];
	ofstream FileOut;
	FileOut.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienCQ.txt", ios::app);
	resizeConsole(1110,550);
	textcolor(10);
	cout<<"    __________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"   |   Khoa   |     MaSV     |        Ho Ten         |  Ngay/Thang/Nam Sinh  |  Gioi Tinh  |    Toan    |    Li     |    Hoa     |  The Duc   |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl; 
    int z;
    gotoxy(7,4);	
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(17,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(33,4);
	 cin.ignore();
 	 cin.getline(data, 100);
    FileOut<<data<<endl;
	gotoxy(58,4);
	cin.getline(data, 100);
 	FileOut<<data<<endl;
	gotoxy(80,4);
	cin.getline(data, 100);
 	FileOut<<data<<endl;
	gotoxy(95,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(109,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(120,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(133,4);
	cin>>data;
 	FileOut<<data<<endl;
    FileOut.close(); 
	cout<<"\n\n\n\n\n";
}
//XUAT CHO LOP CHINH QUY
void LopCQ::Xuat(){
    /*cout<<"\nMa Lop: "<< MaLop << endl <<"Ten Lop: "<<TenLop<<endl;
    SV::Xuat();
    Mon::Xuat();
	cout<<"\nDiem trung binh cua ban la:  "<<DTB();*/	
cout <<"\t"<< setw(5) << left << Khoa << "\t" << setw(7) << left << msv << "\t" << setw(20) << left << hoten<< "\t" << setw(20) << left << namsinh 
<< "\t" << setw(5) << left << gioitinh<< "\t" << setw(8) << left << toan<< "\t" << setw(7) << left << li
<< "\t" << setw(8) << left << hoa<< "\t" << setw(5) << left << td<< endl;
}

float LopCQ::TOAN(){
	   return this->toan;
   }
float LopCQ::LI(){
	   return this->li;
   }
float LopCQ::HOA(){
	   return this->hoa;
   }
float LopCQ::getTD(){
	return this->td;
}
float LopCQ::DTB(){
	return (toan+li+hoa)/3;
		}  
void LopCQ::QuanLiMonHoc(int n){
	
	if(n==1){
		cout<<"\nMon hoc chi co li thuyet : ";
		cout<<"\nMa mon hoc_TOAN: "<<to_mmh;
		cout<<" Tin chi li thuyet: "<<to_tclt<<" Tin chi thuc hanh: "<<to_tcth;
	}
	else if(n==2){
		cout<<"\nMonhoc chi co thuc hanh: ";
		cout<<"\nMa mon hoc_THE_DUC=  "<<td_mmh;
	    cout<<" Tin chi li thuyet: "<<td_tclt<<" Tin chi thuc hanh: "<<td_tcth;
}
    else{
		cout<<"\nMon hoc co ca li thuyet va thuc hanh: ";
		cout<<"\nMa mon hoc_LI: "<<l_mmh;
	    cout<<" Tin chi li thuyet: "<<l_tclt<<" Tin chi thuc hanh: "<<l_tcth;
		cout<<"\n==========================================================================";
		cout<<"\nMa mon hoc_HOA=  "<<h_mmh;
	    cout<<"\nTin chi li thuyet: "<<h_tclt<<" Tin chi thuc hanh: "<<h_tcth;
	}
	
}
//**********TAO CLASS LOP VUA HOC VUA LAM************
//***************************************************
//***************************************************
class LopVHVL:public Mon,public SV{ 
	private:
    	string MaLop;
    	string TenLop;
    	int Khoa;

	public:
		LopVHVL();
		~LopVHVL();
		void Nhap();
		void Xuat();
		float getTD();
		float DTB();
		float TOAN();
	    float LI();
		float HOA();
		void TimKiemTenSV();
		void TimKiemMSSV();
		void Xoa();
		void  Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, LopVHVL &cq);
		void Doc_File(ifstream &filein, vector< LopVHVL > &ds_sinhvien);
		void Test(vector<LopVHVL> ds);
};
void LopVHVL::Xoa(){
	ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienVHVL.txt", ios_base::in); 
	vector< LopVHVL> cq;
	LopVHVL::Doc_File(filein, cq);
    int vitri=0,a=0;
	string b;
	cout<<"\nNhap ma so sinh vien cua ban:  ";
	cin>>b;
	for(int i=0;i<cq.size();i++){
			 if(stricmp(cq[i].getMSV().c_str(), b.c_str()) == 0){
				vitri=i;
				a++;
				cout<<"\n================================";
				}
				
		    }
	if(a==0)
	  {
	  cout<<"\nKhong co sinh vien can xoa";
	  }
	  if(a!=0){
      cq.erase(cq.begin()+vitri);
	  cout<<"\nXoa thanh cong";
	  }
	filein.close();
}
void LopVHVL::TimKiemMSSV(){
	ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienVHVL.txt", ios_base::in); 
	vector< LopVHVL > cq;
	Doc_File(filein, cq);
	cout << "\nDu lieu da doc thanh cong !";
    int a = 0;
	string b;
	cout<<"\nNhap MSSV can tim:  ";
	cin.ignore(1);
	getline(cin,b);
	for(int i=0;i<cq.size();i++){
			 if(stricmp(cq[i].msv.c_str(), b.c_str()) == 0){
				cout<<"\nSinh vien he VHVL: "<<endl;
				cq[i].Xuat();
				if(cq[i].DTB()>=8 && cq[i].getTD()>=6.5 && cq[i].HOA()>=6.5 && cq[i].TOAN()>=6.5 && cq[i].LI()>=6.5)
						  {cout<<"\nHoc luc gioi";}
						else if(cq[i].DTB()>=6.5 && cq[i].getTD()>=5 && cq[i].HOA()>=5 && cq[i].TOAN()>=5 && cq[i].LI()>=5){
							cout<<"\nHoc luc kha";
						}
						else if(cq[i].DTB()>=5 && cq[i].getTD()>=3.5 && cq[i].HOA()>=3.5 && cq[i].TOAN()>=3.5 && cq[i].LI()>=3.5){
							cout<<"\nHoc luc trung binh";
						}
						else
						{
							cout<<"\nHoc luc yeu";
						}
				a++;
				cout<<"\n================================";
				}
	}
	if(a==0){
		cout<<"\nKhong co ten sinh vien can tim";
	}
filein.close();
}
void LopVHVL::TimKiemTenSV(){
    ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienVHVL.txt", ios_base::in); 
	vector< LopVHVL > cq;
	Doc_File(filein, cq);
	cout << "\nDu lieu da doc thanh cong !";
    int a = 0;
	string b;
	cout<<"\nNhap ten sinh vien can tim:  ";
	cin.ignore(1);
	getline(cin,b);
	for(int i=0;i<cq.size()-1;i++){
			 if(stricmp(cq[i].HOTEN().c_str(), b.c_str()) == 0){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				cq[i].Xuat();
				if(cq[i].DTB()>=8 && cq[i].getTD()>=6.5 && cq[i].HOA()>=6.5 && cq[i].TOAN()>=6.5 && cq[i].LI()>=6.5)
						  {cout<<"\nHoc luc gioi";}
						else if(cq[i].DTB()>=6.5 && cq[i].getTD()>=5 && cq[i].HOA()>=5 && cq[i].TOAN()>=5 && cq[i].LI()>=5){
							cout<<"\nHoc luc kha";
						}
						else if(cq[i].DTB()>=5 && cq[i].getTD()>=3.5 && cq[i].HOA()>=3.5 && cq[i].TOAN()>=3.5 && cq[i].LI()>=3.5){
							cout<<"\nHoc luc trung binh";
						}
						else
						{
							cout<<"\nHoc luc yeu";
						}
				a++;
				cout<<"\n================================";
				}
	}
	if(a==0){
		cout<<"\nKhong co ten sinh vien can tim";
	}
filein.close();
}
void LopVHVL:: Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, LopVHVL &cq)
{
		string temp;
	//getline(filein, cq.khoa, ','); // Ã„â€˜Ã¡Â»Âc dÃ¡Â»Â¯ liÃ¡Â»â€¡u Ã„â€˜Ã¡ÂºÂ¿n dÃ¡ÂºÂ¥u ','
	getline(filein, cq.msv); // Ã„â€˜Ã¡Â»Âc dÃ¡Â»Â¯ liÃ¡Â»â€¡u Ã„â€˜Ã¡ÂºÂ¿n dÃ¡ÂºÂ¥u ','
	filein.ignore(0);
	getline(filein, cq.hoten);
	filein.ignore(0);
	getline(filein, cq.namsinh);
	filein.ignore(0);
	getline(filein, cq.gioitinh);
	filein.ignore(0);
    filein>>cq.toan;
    filein>>cq.li;
    filein>>cq.hoa;
    filein>>cq.td;	
	getline(filein, temp);
}
void LopVHVL::Doc_File(ifstream &filein, vector< LopVHVL > &ds_sinhvien)
{
	// vÃƒÂ²ng lÃ¡ÂºÂ·p lÃ¡ÂºÂ·p Ã„â€˜Ã¡ÂºÂ¿n cuÃ¡Â»â€˜i file thÃƒÂ¬ dÃ¡Â»Â«ng
	while (filein.eof() == false)
	{
		LopVHVL cq; 
		LopVHVL::Doc_File_Thong_Tin_Sinh_Vien(filein, cq);
		ds_sinhvien.push_back(cq); // thÃƒÂªm sinh viÃƒÂªn vÃƒÂ o cuÃ¡Â»â€˜i mÃ¡ÂºÂ£ng	
	}
}
void LopVHVL::Test(vector<LopVHVL> ds)
{
	cout<<"    __________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"   |   Khoa   |     MaSV     |        Ho Ten         |  Ngay/Thang/Nam Sinh  |  Gioi Tinh  |    Toan    |    Li     |    Hoa     |  The Duc   |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl;
	for (int i = 0; i < ds.size()-1; i++)
	{
		ds[i].Xuat();
	}
}
//HAM TAO VA HAM HUY
LopVHVL::LopVHVL(){
	MaLop = "IT2";
	TenLop="Cong Nghe Thong Tin 2";	
}
LopVHVL::~LopVHVL(){
}
//NHAP CHO LOP VUA HOC VUA LAM
void LopVHVL::Nhap(){
	char data[100];
	ofstream FileOut;
	FileOut.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienVHVL.txt", ios::app);
	resizeConsole(1110,550);
	textcolor(10);
	cout<<"    __________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"   |   Khoa   |     MaSV     |        Ho Ten         |  Ngay/Thang/Nam Sinh  |  Gioi Tinh  |    Toan    |    Li     |    Hoa     |  The Duc   |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl; 
    int z;
    gotoxy(7,4);	
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(17,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(33,4);
	 cin.ignore();
 	 cin.getline(data, 100);
    FileOut<<data<<endl;
	gotoxy(58,4);
	cin.getline(data, 100);
 	FileOut<<data<<endl;
	gotoxy(80,4);
	cin.getline(data, 100);
 	FileOut<<data<<endl;
	gotoxy(95,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(109,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(120,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(133,4);
	cin>>data;
 	FileOut<<data<<endl;
    FileOut.close(); 
	cout<<"\n\n\n\n\n";
}
//XUAT CHO LOP VUA HOC VUA LAM
void LopVHVL::Xuat(){
	cout <<"\t"<< setw(5) << left << Khoa << "\t" << setw(7) << left << msv << "\t" << setw(20) << left << hoten<< "\t" << setw(20) << left << namsinh 
<< "\t" << setw(5) << left << gioitinh<< "\t" << setw(8) << left << toan<< "\t" << setw(7) << left << li
<< "\t" << setw(8) << left << hoa<< "\t" << setw(5) << left << td<< endl;
}
float LopVHVL::TOAN(){
	return this->toan;
   }
float LopVHVL::LI(){
	return this->li;
   }
float LopVHVL::HOA(){
	return this->hoa;
   }
float LopVHVL::getTD(){
	return this->td;
           }
float LopVHVL::DTB(){
	return ((toan+li+hoa)/3);
		}  
//***********TAO CLASS KE THUA**********************
//**************************************************
//**************************************************
class TongHop:public LopCQ,public LopVHVL{
	protected:
			vector <SV *> TH;
    public:
	float TOAN();
	float LI();
	float HOA();
	void Nhap();
	void Xuat();
	float getTD();
	float getDTB();
	void HocBong();
	void TimKiemHB();
	void TimKiemMSSV();
	void TimKiemTenSV();
	void SapXep();
	void Xoa();
	void XuatCQ();
	void XuatVHVL();
	void DoHoa();
};

void TongHop::XuatCQ(){
	LopCQ *a;
    ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienCQ.txt", ios_base::in); 
	vector< LopCQ> cq;
	a->Doc_File(filein, cq);
	a->Test(cq);
	filein.close(); 
}
void TongHop::XuatVHVL(){
	LopVHVL *a;
    ifstream filein;
	filein.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienVHVL.txt", ios_base::in); 
	vector< LopVHVL> ds_sinhvien;
	a->Doc_File(filein, ds_sinhvien);
	a->Test(ds_sinhvien);
	filein.close(); 
}

void TongHop::Nhap(){
	int k,u;
	SV *a;
	resizeConsole(560,400);
   do{
	system("cls");
	textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"          HE THONG QUAN LY SINH VIEN";
	textcolor(13);
	cout<<"                 *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.NHAP VAO THONG TIN SINH VIEN ";textcolor(13);cout<<"                     *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.QUAN LI MON HOC ";textcolor(13);cout<<"                                  *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.QUAN LI SINH VIEN ";textcolor(13);cout<<"                                *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 4.QUAN LI DIEM ";textcolor(13);cout<<"                                     *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 5.QUAN LI HOC BONG ";textcolor(13);cout<<"                                 *";
	cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 6.THOAT ";textcolor(13);cout<<"                                            *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
    cin>>k;
    switch(k){
	case 1: 
			{int i=1;
			while(i){
				system("cls");
				resizeConsole(560,400);
				textcolor(13); 
				cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Nhap cho sinh vien chinh quy ";textcolor(13);cout<<"                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Nhap cho sinh vien vua hoc vua lam ";textcolor(13);cout<<"               *";
    cout<<"\n          *";textcolor(11);cout<<" 3.Thoat nhap ";textcolor(13);cout<<"                                       *";
	cout<<"\n          *                                                     *";
	cout<<"\n          *******************************************************";			
				cout<<"\n\t\tMoi lua chon: ";
				cin>>u;
				system("cls");
			switch(u){
					case 1:
						a=new LopCQ;
						a->Nhap();
						break;
					case 2:
						a=new LopVHVL;
						a->Nhap();
						break;
					case 3:
						i=0;
						break;
					default:
						cout<<"Nhap sai. Moi nhap lai"<<endl;
				}
			}}
			break;
    case 2:
		     do{
		     system("cls");
    		 textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"                 QUAN LI MON HOC";
	textcolor(13);
	cout<<"                      *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Hien thi mon hoc chi co li thuyet ";textcolor(13);cout<<"                *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Hien thi mon hoc chi co thuc hanh ";textcolor(13);cout<<"                *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.Hien thi mon hoc ca ca li thuyet va thuc hanh ";textcolor(13);cout<<"    *";
    cout<<"\n          *                                                     *"; 
	cout<<"\n          *";textcolor(11);cout<<" 4.Quay lai ";textcolor(13);cout<<"                                         *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
             cin>>u;
             system("cls");
           switch(u){
           	case 1:
           		LopCQ::QuanLiMonHoc(u);
				cin.get();
				break;		
           	case 2:
           		LopCQ::QuanLiMonHoc(u);
				cin.get();
           		break;
           	case 3:
           		LopCQ::QuanLiMonHoc(u);
           		cin.get();
           		break;
           	case 4:
				 break;}
			cout << endl;
			cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
			cin.get();	 	 
			}while(u!=4);
			 break;
	case 3:
	        do{
			 system("cls");
			 textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"                   QUAN LY SINH VIEN";
	textcolor(13);
	cout<<"                 *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Tim kiem theo ma so sinh vien ";textcolor(13);cout<<"                    *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Tim kiem theo ten sinh vien  ";textcolor(13);cout<<"                     *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.Danh sach sinh vien ";textcolor(13);cout<<"                              *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 4.Xoa ";textcolor(13);cout<<"                                              *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 5.Quay lai  ";textcolor(13);cout<<"                                        *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
		     cin>>u;
		     system("cls");
		     switch(u){
		     	case 1:
				
		     		TimKiemMSSV();                 
		     		cin.get();
		     		break;
		     	case 2:
		     		TimKiemTenSV();
		     		cin.get();   
		     		break;
		     	case 3:
		     		Xuat();
					cin.get();	
					break;
				case 4:
					Xoa();                                           
					cin.get();
					break;
				case 5:
					break;
		           	} 
						cout << endl;
						cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
						cin.get();
						}while(u!=5);
						break;
	case 4: // chuc nang ben trong quan ly diem
	       do{
			system("cls");
			 textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"                 QUAN LY DIEM ";
	textcolor(13);
	cout<<"                       *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Danh sach SV theo thu tu giam dan cua DTB ";textcolor(13);cout<<"        *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Tra cuu ket qua hoc tap cua sinh vien  ";textcolor(13);cout<<"           *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.Quay lai ";textcolor(13);cout<<"                                         *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
		    cin>>u;
		    system("cls");
		    switch(u){
		        case 1:
		            SapXep();
		        	cin.get();
		            break;
		        case 2:
		        	TimKiemMSSV();      
		        	cin.get();
		        	break;
		        case 3:
		        	break;
		        }
				cout << endl;
				cin.get();
			    }while(u!=3);
			    break;
	case 5: // chuc nang ben trong quan ly hoc bong
	        do{
			 system("cls");
			 textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"                QUAN LY HOC BONG ";
	textcolor(13);
	cout<<"                    *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Danh sach hoc bong ";textcolor(13);cout<<"                               *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Tim sinh vien trong danh sach hoc bong   ";textcolor(13);cout<<"         *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.Quay lai ";textcolor(13);cout<<"                                         *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
		     cin>>u;
		     system("cls");
		     switch(u){
		     	case 1: 
					  HocBong();     
		     	     cin.get();
		     	     break;
		        case 2:
		     	     TimKiemHB();
		     	     cin.get();
		     	     break;
		     	case 3:
		     		 break;} 
	        	 cout << endl;
			  	cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
				cin.get();
			 }while(u!=3);
			 break;
	case 6:// thong chuong trinh
		     exit(1);
}}while(1);
}
//XOA SINH VIEN THEO MA SO SINH VIEN
void TongHop::Xoa(){
    int u;
    do{
		     system("cls");
    		 cout<<"\n*******************************************************"; 
    		 cout<<"\n*              XOA SINH VIEN                          *";
    		 cout<<"\n*                                                      *";
    		 cout<<"\n*   1. Xoa sinh vien thuoc lop Chinh Quy             *";
			 cout<<"\n*   2. Xoa sinh vien thuoc lop VHVL              *";
			 cout<<"\n*   3. Quay lai                                        *";
			 cout<<"\n*                                                      *";
             cout<<"\n*******************************************************";
             cout<<"\nNhap vao lua chon cua ban: ";
             cin>>u;
             system("cls");
           switch(u){
           	case 1:
           		LopCQ::Xoa();
				cin.get();
				break;		
           	case 2:
           		LopVHVL::Xoa();
				cin.get();
           		break;
           	case 3:
				 break;}
			cout << endl;
			cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
			cin.get();	 	 
			}while(u!=3);
	 
}
//SAP XEP SINH VIEN THEO THU TU GIAM DAN CUA DIEM TRUNG BINH
void TongHop::SapXep(){
	for(int i=0;i<TH.size();i++){ // thuat toan sap xep noi bot
		for(int j=i+1;j<TH.size();j++){
			if(TH[i]->DTB() < TH[j]->DTB() && TH[i]->DTB() != TH [j]->DTB()){
				swap(TH[i],TH[j]);
			}
		}
	}
	Xuat();
}
//TIM KIEM THEO TEN SINH VIEN
void TongHop::TimKiemTenSV(){
	int u;
    do{
		     system("cls");
    		 textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"           TIM KIEM BANG TEN SINH VIEN ";
	textcolor(13);
	cout<<"              *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Tim kiem ten sinh vien cua lop chinh quy ";textcolor(13);cout<<"         *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Tim sinh ten sinh vien cua lop vua hoc vua lam   ";textcolor(13);cout<<" *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.Quay lai ";textcolor(13);cout<<"                                         *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
             cin>>u;
             system("cls");
           switch(u){
           	case 1:
           		LopCQ::TimKiemTenSV();
				cin.get();
				break;		
           	case 2:
           		LopVHVL::TimKiemTenSV();
				cin.get();
           		break;
           	case 3:
				 break;}
			cout << endl;
			cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
			cin.get();	 	 
			}while(u!=3);
}
//TIM KIEM THEO MA SO SINH VIEN
 void TongHop::TimKiemMSSV(){
    int u;
    do{
		     system("cls");
    		 textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"           TIM KIEM BANG MS SINH VIEN ";
	textcolor(13);
	cout<<"              *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Tim kiem MS sinh vien cua lop chinh quy ";textcolor(13);cout<<"          *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Tim sinh MS sinh vien cua lop vua hoc vua lam   ";textcolor(13);cout<<"  *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.Quay lai ";textcolor(13);cout<<"                                         *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
             cin>>u;
             system("cls");
           switch(u){
           	case 1:
           		LopCQ::TimKiemMSSV();
				cin.get();
				break;		
           	case 2:
           		LopVHVL::TimKiemMSSV();
				cin.get();
           		break;
           	case 3:
				 break;}
			cout << endl;
			cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
			cin.get();	 	 
			}while(u!=3);
 }
 //DANH SACH SINH VIEN CO HOC BONG
void TongHop::HocBong(){
	int a = 0;
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			 if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
				
		    }
		else{
			if(TH[i]->getLoai()==false&&TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5){
				cout<<"\nSinh vien he vua hoc vua lam: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
		}
	}
	if(a==0){
		cout<<"\nKhong co sinh vien nao co hoc bong";
	}
	}
    //TIM KIEM SINH VIEN CO HOC BONG THEO MA SO SINH VIEN
void TongHop::TimKiemHB(){
	int a = 0;
	string b;
	cout<<"\nNhap ma so sinh vien cua ban:  ";
	cin>>b;
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			 if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && (TH[i]->getMSV()==b)){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
				
		    }
		else{
			if(TH[i]->getLoai()==false && TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && (TH[i]->getMSV()==b)){
				cout<<"\nSinh vien he vua hoc vua lam: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
		}
	}
	if(a==0){
		cout<<"\nKhong co sinh vien nao co hoc bong";
	}
	}
//XUAT TAT CA CAC CLASS 		                
void TongHop::Xuat(){
	int u;
	do{
						system("cls");
						textcolor(13);
	cout<<"\n          *******************************************************";
    cout<<"\n          *";textcolor(10);         cout<<"                 DANH SACH SINH VIEN";
	textcolor(13);
	cout<<"             *";  
	cout<<"\n          *******************************************************";
    cout<<"\n          *                                                     *";
	cout<<"\n          *";textcolor(11);cout<<" 1.Danh sach sinh vien lop Chinh Quy ";textcolor(13);cout<<"                *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 2.Danh sach sinh vien lop Vua Hoc Vua Lam  ";textcolor(13);cout<<"         *";
    cout<<"\n          *                                                     *"; 
    cout<<"\n          *";textcolor(11);cout<<" 3.Danh sach sinh vien thuoc ca hai lop ";textcolor(13);cout<<"             *";
    cout<<"\n          *                                                     *";
    cout<<"\n          *";textcolor(11);cout<<" 4.Quay lai  ";textcolor(13);cout<<"                                        *";
	cout<<"\n          *                                                     *";
    cout<<"\n          *******************************************************";
	textcolor(10);   
    cout<<"\n\t\tNHAP LUA CHON CUA BAN: ";
						cin>>u;
						system("cls");
					switch(u){
						case 1:
							XuatCQ();
							cin.get();
							break;		
						case 2:
							XuatVHVL();
							cin.get();
							break;
						case 3:
							cout<<"\nDanh sach sinh vien thuoc he chinh quy";
							cout<<"\n****************************************";
							XuatCQ();
							cout<<"\nDanh sach sinh vien thuoc he VHVL";
							cout<<"\n****************************************";
							XuatVHVL();
							cin.get();
							break;
						case 4:
							break;}
						cout << endl;
						cin.get();	 	 
						}while(u!=4);
} 
float TongHop::getTD(){
	return 0;
}
    float DTB(){
	return 0;
		}  
 float TongHop::TOAN(){
	   return 0;
   }
	float TongHop::LI(){
	   return 0;
   }
    float TongHop::HOA(){
	   return 0;
   }
void TongHop::DoHoa(){
	char data[100];
	ofstream FileOut;
	FileOut.open("E://OOP//QLSV//quanlisinhvien//QLSV//SinhVienCQ.txt", ios::app);
	resizeConsole(1110,550);
	textcolor(10);
	cout<<"    __________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"   |   Khoa   |     MaSV     |        Ho Ten         |  Ngay/Thang/Nam Sinh  |  Gioi Tinh  |    Toan    |    Li     |    Hoa     |  The Duc   |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl;
    cout<<"   |          |              |                       |                       |             |            |           |            |            |"<<endl;
	cout<<"   |__________|______________|_______________________|_______________________|_____________|____________|___________|____________|____________|"<<endl; 
    int z;
    gotoxy(7,4);	
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(17,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(33,4);
	 cin.ignore();
 	 cin.getline(data, 100);
    FileOut<<data<<endl;
	gotoxy(58,4);
	cin.getline(data, 100);
 	FileOut<<data<<endl;
	gotoxy(80,4);
	cin.getline(data, 100);
 	FileOut<<data<<endl;
	gotoxy(95,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(109,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(120,4);
	cin>>data;
 	FileOut<<data<<endl;
	gotoxy(133,4);
	cin>>data;
 	FileOut<<data<<endl;
    FileOut.close(); 
}
int main()
{
    
TongHop *a=new TongHop;
a->Nhap();
delete a;
system("pause");
return 0;
}