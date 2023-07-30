#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int sl = 0;

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

void init_LIST(LIST& l)
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

void nhap_TT(SinhVien& sv)
{
	cout << "MSSV: ";
	getline(cin, sv.maSV);
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoten);
	cout << "Nhap nam sinh: ";
	cin >> sv.namSinh;
	cin.ignore();
	cout << "Nhap dia chi: ";
	getline(cin, sv.diaChi);
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


void delete_NODE(LIST& l, string s)  //xoa theo maSV
{	
	if (l.pHead == NULL)
		return;
	else
	{
		NODE* p = l.pHead;
		NODE* preX = l.pHead;
		while (p != NULL)
		{
			if (p->sv.maSV == s)
			{
				NODE* r = p;
				if (l.pHead == p)
				{
					l.pHead = l.pHead->link;
					p = l.pHead;
					preX = l.pHead;
				}
				else
				{
					preX->link = p->link;
					p = p->link;
				}
				delete r;
			}
			else
			{
				preX = p;
				p = p->link;
			}
		}
		cout << "Xoa thanh cong" << endl;
	}
}

void xuat_DS(LIST l)
{
	// maSV ----------Hoten-------Namsinh-----daichi--------Gioitinh--------Daichi------gender----diemTb--
	cout << "| " << setw(8) << left << "Ma SV" << "|" << setw(10) << left << "Ho ten" << "|" << setw(10) << left << "Nam sinh" << "|" << setw(10) << "Dia chi" << "|" << setw(8) << left << "Gender" << "|" << setw(8) << left << "Diem TB" << "|" << endl;
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		cout << "|" << setw(8) << left << k->sv.maSV << " |";
		cout << setw(10) << left << k->sv.hoten << "|";
		cout << setw(10) << left << k->sv.namSinh << "|";
		cout << setw(10) << left << k->sv.diaChi << "|";
		if (k->sv.gioiTinh == 1)
			cout << setw(8) << left << "Nam" << "|";
		else
			cout << setw(8) << left << "Nu" << "|";

		cout  << setw(8) << left << k->sv.diemTB << "|" << endl;
	}
}


void doc_data(LIST& l)
{
	ifstream inFile;
	inFile.open("Source.txt", ios::in);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			SinhVien sv;
			getline(inFile, sv.maSV,'#');
			getline(inFile, sv.hoten,'#');
			inFile >> sv.namSinh;
			inFile.ignore();
			getline(inFile, sv.diaChi,'#');
			inFile >> sv.gioiTinh;
			inFile.ignore();
			inFile >> sv.diemTB;
			inFile.ignore();
			NODE* p = init_data(sv);
			add_NODE(l, p);
		}
		inFile.close();
	}
	else
		cout << "khong mo duoc file" << endl;
}


void loc_ds(LIST l)
{
	int choose;
	do
	{	
		cout << "1. Loc theo ten " << endl;
		cout << "2. Loc nam sinh  " << endl;
		cout << "3. Loc maSV      " << endl;
		cout << "4. Loc diem TB " << endl;
		cout << "5. Thoat        " << endl;
		cout << "Lua chon: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 5) break;
			else
				cout << "Lua chon khong co, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			cout << "LOC THEO TEN" << endl;
			for (NODE* k = l.pHead; k != NULL; k = k->link)
			{
				cout << k->sv.hoten << " ";
			}
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "LOC THEO NAM SINH" << endl;
			for (NODE* k = l.pHead; k != NULL; k = k->link)
			{
				cout << k->sv.namSinh << " ";
			}
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "LOC THEO MA SV" << endl;
			for (NODE* k = l.pHead; k != NULL; k = k->link)
			{
				cout << k->sv.maSV << " ";
			}
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "LOC THEO DIEM" << endl;
			for (NODE* k = l.pHead; k != NULL; k = k->link)
			{
				cout << k->sv.diemTB << " ";
			}
			cout << endl;
			break;
		}
		case 5:
		{
			return;
		}
		}
		system("pause");
		system("cls");
	} while (true);
}

void dem_sl()
{
	ifstream inF;
	inF.open("Source.txt", ios::in);
	if (inF.is_open())
	{
		string s; 
		while (inF >> s)
		{
			sl++;
		}
		inF.close();
	}
	else
		cout << "Khong mo duoc file" << endl;
}

void write_data(LIST& l)
{
	ofstream outF;
	outF.open("Source1.txt", ios::app);
	if (outF.is_open())
	{
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			outF << k->sv.maSV << '#' << k->sv.hoten << '#' << k->sv.namSinh << '#' << k->sv.diaChi << '#' << k->sv.gioiTinh << '#' << k->sv.diemTB << endl;
		}
		outF.close();
		cout << "Nhap file thanh cong" << endl;
	}
	else
	{
		cout << "Khong mo duoc file" << endl;
	}
}
int main()
{
	LIST l;
	init_LIST(l);
	int choose;
	int flag_writ = 0;
	do
	{
		cout << "---------------------------MENu---------------------------------" << endl;
		cout << "1. Nhap danh sach sinh vien                                    " << endl;
		cout << "2. Xuat danh sach sinh vien                                    " << endl;
		cout << "3. Nhap danh sach sinh vien tu file txt                         " << endl;
		cout << "4. Loc danh sach                                                " << endl;
		cout << "5. Them mot 1 sinh vien vao DS                                 " << endl;
		cout << "6. Sap xep danh sach sinh vien theo tung du lieu               " << endl;
		cout << "7. Xoa 1 Sv ra khoi danh sach                                  " << endl;
		cout << "8. Ghi danh sach sinh vine thoa DK ra file.txt                 " << endl;
		cout << "9. EXIT                                                      " << endl;
		cout << "Lua chon: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 9) break;
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
		case 3:
		{
			dem_sl();
			if (sl != 0)
			{
				doc_data(l);
			}
			else
				cout << "Trong file trong co du lieu" << endl;
			break;
		}
		case 4:
		{
			loc_ds(l);
			break;
		}
		case 5:
		{
			SinhVien sv;
			nhap_TT(sv);
			NODE* p = init_data(sv);
			add_NODE(l, p);
			cout << "Them thanh cong" << endl;
			break;
		}
		case 6:
		{
			cout << "...." << endl;
			break;
		}
		case 7:
		{
			string s;
			cout << "Nhap ma SV de xoa: ";
			getline(cin, s);
			delete_NODE(l, s);
			break;
		}
		case 8:
		{
			if (l.pHead != NULL)
			{
				write_data(l);
			}
			else
				cout << "Chua co danh sach de them " << endl;
			break;
		}
		case 9:
		{
			if (l.pHead == NULL) return 0;
			else
			{
				NODE* g;
				while (l.pHead != NULL)
				{
					g = l.pHead;
					l.pHead = l.pHead->link;
					delete g;
				}
				return 0;
			}
		}

		}
		system("pause");
		system("cls");
	} while (true);
}