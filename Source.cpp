#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

struct SinhVien
{
	string maSV;
	string hoten;
	int namSinh;
	string diaChi;
	int gioiTinh;
	double diemTB;
};

struct NODE
{
	SinhVien sv;
	NODE* link;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void init_LIST(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}


NODE* init_data(SinhVien x)
{
	NODE* p = new NODE;
	p->sv.maSV = x.maSV;
	p->sv.hoten = x.hoten;
	p->sv.namSinh = x.namSinh;
	p->sv.diaChi = x.diaChi;
	p->sv.gioiTinh = x.gioiTinh;
	p->sv.diemTB = x.diemTB;
	p->link = NULL;
	return p;
}

void nhap_TT(SinhVien &sv)
{
	cout << "MSSV: ";
	getline(cin,sv.maSV);
	cout << "Nhap ho ten: ";
	getline(cin,sv.hoten);
	cout << "Nhap nam sinh: ";
	cin >> sv.namSinh;
	cin.ignore();
	cout << "Nhap dia chi: ";
	getline(cin,sv.diaChi);
	cout << "Gender(neu la nam thi nhap 1, nu nhap 0:)";
	cin >> sv.gioiTinh;
	cout << "Nhap diem TB: ";
	cin >> sv.diemTB;
	cin.ignore();
}


void add_NODE(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->link = p;
		l.pTail = p;
	}
}

void xuat_DS(LIST l)
{
	// maSV ----------Hoten-------Namsinh-----daichi--------Gioitinh--------Daichi------gender----diemTb--
	cout << "| " << setw(8) << left << "Ma SV" << "|" << setw(10) << left << "Ho ten" << "|" << setw(10) << left << "Nam sinh" << "|" << setw(10) << "Dia chi" << "|" << setw(8) << left << "Gender" << "|" << setw(8) << left << "Diem TB" << "|" << endl;
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		cout <<"|" << setw(8) << left << k->sv.maSV ;
		cout << "|" << setw(10) << left << k->sv.hoten ;
		cout << "|" << setw(10) << left << k->sv.namSinh  ;
		cout << "|" << setw(10) << left << k->sv.diaChi  ;
		if (k->sv.gioiTinh == 1)
			cout << "|" << setw(8) <<left << "Nam"  ;
		else
			cout << "|" << setw(8) << left << "Nu"  ;

		cout << "|" << setw(8) <<left << k->sv.diemTB << "|" << endl;
	}
}



int main()
{
	LIST l;
	init_LIST(l);
	int choose;
	do
	{
		cout << "---------------------------MENu---------------------------------" << endl;
		cout << "1. Nhap danh sach sinh vien                                    " << endl;
		cout << "2. Xuat danh sach sinh vien                                    " << endl;
		cout << "3. Nhap danh sach sinh vien tu file txt                         " << endl;
		cout << "4. Them mot 1 sinh vien vao DS                                 " << endl;
		cout << "5. Sap xep danh sach sinh vien theo tung du lieu               " << endl;
		cout << "6. Xoa 1 Sv ra khoi danh sach                                  " << endl;
		cout << "7. Ghi dnah sach sinh vine thoa DK ra file.txt                 " << endl;
		cout << "8. EXIT                                                      " << endl;
		cout << "Lua chon: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 8) break;
			else
				cout << "Nhap sai lua chon, nhap lai:";
		}
		cin.ignore();
		system("cls");
		switch (choose)
		{
		case 1:
		{
			SinhVien sv;
			nhap_TT(sv);
			NODE* p = init_data(sv);
			add_NODE(l, p);
			break;
		}
		case 2:
		{
			cout << "DANH SACH " << endl << endl;
			xuat_DS(l);
			break;
		}

		}
		system("pause");
		system("cls");
} while (true);
}