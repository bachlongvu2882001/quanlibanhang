#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <windows.h>
using namespace std;
//Tao Class Sinh Vien
class SinhVien {
protected:
	string HoTenSV;
	string LopSV;
	string MSsv;
public:
	string getMSsv();
	void Input(); //nhap thong tin sinh vien
	void Output();// xuat thong tin sinh vien
};
//Tao Class Diem
class Diem {
protected:
	string XepLoaiSV;
	float DiemCC, DiemBT, DiemGK, DiemCK;
public:
	void Input(); //nhap Diem
	void Output();// xuat Diem
	float TinhDiemTB();
	string XepLoai();

};

//Tao Class ALL thuc hien cac thao cua sinh vien va diem
class all :public SinhVien, public Diem {
public:
	void Nhap();
	void Xuat();
};
all arr[100];
int index = 0;
// Tao Class Lop chua thong tin cua tat ca sinh vien
class Lop {
public:
	void Menu();
	void ThongTinSV();
};
int main() {
	string f;
	Lop* l = new Lop;
	l->Menu();
	cin.get();
	//	l->TimKiemSV(f);
	delete l;
}
void Lop::ThongTinSV()
{
	cout << "\t \t 0.0.0===================  THONG TIN SINH VIEN  ===================0.0.0" << left << endl;
	cout << setw(12) << "MSSV" << setw(20) << "Ho Ten" << setw(20) << "Lop Hoc" << setw(10) << "Chuyen Can" << setw(10) << "Bai Tap"
		<< setw(10) << "Giua Ky" << setw(10) << "Cuoi Ky" << setw(10) << "TBM" << setw(10) << "Xep Loai" << endl;
}

// Class SinhVien
void SinhVien::Input() {
	cin.ignore();
	cout << "MSSV : ";
	getline(cin, MSsv);
	cout << "Ho Ten : ";
	getline(cin, HoTenSV);
	cout << "Lop Hoc : ";
	getline(cin, LopSV);
}
void SinhVien::Output() {
	cout << setw(12) << MSsv << setw(20) << HoTenSV << setw(20) << LopSV;
}
string SinhVien::getMSsv() {
	return MSsv;
}

// Class Diem
void Diem::Input() {
	cout << "Diem chuyen can : ";
	cin >> DiemCC;
	cout << "Diem bai tap : ";
	cin >> DiemBT;
	cout << "Diem giua ky : ";
	cin >> DiemGK;
	cout << "Diem cuoi ky : ";
	cin >> DiemCK;
}
float Diem::TinhDiemTB() {
	return  (DiemCC * 0.1 + DiemBT * 0.1 + DiemGK * 0.2 + DiemCC * 0.4);
}

string Diem::XepLoai()
{
	float a = TinhDiemTB();
	if (a >= 4.0 && a <= 5.4)
	{
		return XepLoaiSV = "D";
	}
	else if (a >= 5.5 && a <= 6.9)
	{
		return XepLoaiSV = "C";
	}
	else if (a >= 7.0 && a <= 8.4)
	{
		return XepLoaiSV = "B";
	}
	else if (a >= 8.5 && a <= 10)
	{
		return XepLoaiSV = "A";
	}
	else
	{
		return XepLoaiSV = "F";
	}
}
void Diem::Output() {
	cout << setw(10) << DiemCC << setw(10) << DiemBT << setw(10) << DiemGK << setw(10) << DiemCK << setw(10) << TinhDiemTB() << setw(10) << XepLoai() << endl;
}
// Class ALL
void all::Nhap() {
	SinhVien::Input();
	Diem::Input();

}
void all::Xuat() {
	SinhVien::Output();
	Diem::Output();
}
//hàm đồ họa
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void ve_tuong_tren() {
	int x = 10, y = 1;
	while (x <= 100) {
		gotoXY(x, y);
		cout << char(222);
		x++;
	}
}

void ve_tuong_duoi() {
	int x = 10, y = 19;
	while (x <= 100) {
		gotoXY(x, y);
		cout << char(222);
		x++;
	}
}

void ve_tuong_trai() {
	int x = 10, y = 1;
	while (y <= 19) {
		gotoXY(x, y);
		cout << char(222);
		y++;
	}
}

void ve_tuong_phai() {
	int x = 100, y = 1;
	while (y <= 19) {
		gotoXY(x, y);
		cout << char(222);
		y++;
	}
}

void ve_tuong() {
	ve_tuong_phai();
	ve_tuong_trai();
	ve_tuong_tren();
	ve_tuong_duoi();

}
// Class Lop
void Lop::Menu() {
	int luachon;
	int dem = 0;
	float tb;
	int sx;
	do {
		system("cls");
		system("color 5F");
		cout << "\n\n\t\t\t============ XIN MOI LUA CHON TINH NANG ============";
		cout << "\n\t\t1. Them Sinh Vien Vao Danh Sach." << endl;
		cout << "\n\t\t2. Hien Thi Danh Sach Sinh Vien." << endl;
		cout << "\n\t\t3. Tim Kiem Sinh Vien Co Trong Danh Sach." << endl;
		cout << "\n\t\t4. Xoa Sinh Vien." << endl;
		cout << "\n\t\t5. Tim Kiem Diem TB." << endl;
		cout << "\n\t\t6. Sap Xep Diem TB." << endl;
		cout << "\n\t\t7. Thoat Khoi Chuong Trinh." << endl;
		ve_tuong();
		cout << "\n\t\tTinh Nang Ban Chon La : ";
		cin >> luachon;
		system("cls");
		all* a;
		string f;
		switch (luachon) {
		case 1:
			int n;
			cout << "So luong sinh vien : ";
			cin >> n;
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				all sv;
				sv.Nhap();
				arr[index] = sv;
				index++;
				cout << endl;

			}
			break;
		case 2:
			cout << "\t \t 0.0.0===================  THONG TIN SINH VIEN  ===================0.0.0" << left << endl;
			cout << setw(12) << "MSSV" << setw(20) << "HoTen" << setw(20) << "LopHoc" << setw(10) << "ChuyenCan" << setw(10) << "BaiTap"
				<< setw(10) << "GiuaKy" << setw(10) << "CuoiKy" << setw(10) << "TBM" << setw(10) << "XepLoai" << left << endl;
			for (int i = 0; i < index; i++)
			{
				arr[i].Xuat();
			}
			break;
			break;
		case 3:
			cin.ignore();
			cout << "MSSV can tim kiem : ";
			getline(cin, f);
			for (int i = 0; i < index; i++) {
				if (f == arr[i].getMSsv()) {
					cout << "Co sinh vien trong danh sach." << endl;
					ThongTinSV();
					arr[i].Xuat();
					break;
				}
				else {
					cout << "Khong co sinh vien trong danh sach." << endl;
					break;
				}
			}
			break;
		case 4:
			int at;
			cout << "Nhap vi tri can xoa : ";
			cin >> at;
			at--;
			for (int i = 0; i < index; i++) {
				if (at == i) {
					for (int j = i; j < index; j++) {
						arr[j] = arr[j + 1];
					}
					dem++;
					--index;
					cout << "Xoa thanh cong";
				}
			}
			if (dem == 0) {
				cout << "Xoa khong hop le";
			}
			break;
		case 5:
			cin.ignore();
			cout << "TIM KIEM DIEM TB" << endl;
			cout << "1.Lon nhat" << endl;
			cout << "2.nho nhat" << endl;
			cout << "chon kieu tim kiem: ";;
			cin >> tb;
			if (tb == 1) {
				cout << "Sinh vien co diem TB cao nhat" << endl;
				float max = arr[0].TinhDiemTB();
				int t = 0;
				for (int i = 1; i < index; i++) {
					if (max < arr[i].TinhDiemTB()) {
						max = arr[i].TinhDiemTB();
						t = i;
					}
				}
				ThongTinSV();
				arr[t].Xuat();
			}
			else if (tb == 2) {
				cout << "Sinh vien co diem TB Thap nhat" << endl;
				float min = arr[0].TinhDiemTB();
				int t = 0;
				for (int i = 1; i < index; i++) {
					if (min > arr[i].TinhDiemTB()) {
						min = arr[i].TinhDiemTB();
						t = i;
					}
				}
				ThongTinSV();
				arr[t].Xuat();
			}
			else {
				cout << "Nhap khong hop le tro lai menu" << endl;
				break;
			}
			break;
		case 6:
			cout << "SAP XEP DIEM TB" << endl;
			cout << "1.Tang dan" << endl;
			cout << "2.Giam dan" << endl;
			cout << "chon kieu sap xep: ";
			cin >> sx;
			if (sx == 1) {
				for (int i = 0; i < index; i++) {
					for (int j = i + 1; j < index; j++) {
						if (arr[i].TinhDiemTB() > arr[j].TinhDiemTB()) {
							swap(arr[i], arr[j]);
							break;
						}
					}
				}
				cout << "Sap xep thanh cong" << endl;
			}
			else if (sx == 2) {
				for (int i = 0; i < index; i++) {
					for (int j = i + 1; j < index; j++) {
						if (arr[i].TinhDiemTB() < arr[j].TinhDiemTB()) {
							swap(arr[i], arr[j]);
							break;
						}
					}
				}
				cout << "Sap xep thanh cong" << endl;
			}
			else {
				cout << "Nhap khong hop le tro lai menu" << endl;
				break;
			}
			break;
		case 7:
			exit(0);
		default:
			cout << "Ban vui long nhap lai!" << endl;
		}
		cout << endl;
		system("pause");
	} while (luachon != 7);
}