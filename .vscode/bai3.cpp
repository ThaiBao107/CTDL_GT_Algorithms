#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct ngaythangnam
{
	int date;
	int month;
	int year;
};

struct sinhvien
{
	int mssv;
	string ho;
	string ten;
	ngaythangnam namsinh;
	int gender;
	double dtb;
};

struct NODE
{
	sinhvien sv;
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

NODE* init_NODE(sinhvien SV)
{
	NODE* p = new NODE;
	p->sv.mssv = SV.mssv;
	p->sv.ho = SV.ho;
	p->sv.ten = SV.ten;
	p->sv.namsinh.date = SV.namsinh.date;
	p->sv.namsinh.month = SV.namsinh.month;
	p->sv.namsinh.year = SV.namsinh.year;
	p->sv.gender = SV.gender;
	p->sv.dtb = SV.dtb;
	p->link = NULL;
	return p;
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

void nhap_file(LIST l)
{
	ofstream outF;
	outF.open("Sinhvien.txt", ios_base::app);
	if (outF.is_open())
	{
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			cout << k->sv.mssv << '#' << k->sv.ho << '#' << k->sv.ten << '#' << k->sv.namsinh.date << '#' << k->sv.namsinh.month << '#' << k->sv.namsinh.year << '#' << k->sv.gender << '#' << k->sv.dtb << endl;
		}
		cout << "nhap file thanh cong" << endl;
		outF.close();
	}
	else
	{
		cout << "khong mo dc file" << endl;
	}

}

void nhap_ds(LIST& l)
{
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	system("cls");
	for (int i = 0; i < n; i++)
	{
		sinhvien SV;
		cout << "Nhap mssv: ";
		while (true)
		{
			int dem = 0;
			cin >> SV.mssv;
			for (NODE* k = l.pHead; k != NULL; k = k->link)
			{
				if (k->sv.mssv == SV.mssv)
				{
					dem++;
				}
			}
			if (dem == 0) break;
			else
			{
				cout << "MSSV da  bi trung, nhap lai: ";
			}
		}
		cout << "Nhap ho: "; cin >> SV.ho;
		cout << "Nhap ten: "; cin >> SV.ten;
		cout << "Nhap ngay sinh: "; cin >> SV.namsinh.date;
		cout << "Nhap thang sinh: "; cin >> SV.namsinh.month;
		cout << "Nhap nam sinh: "; cin >> SV.namsinh.year;
		cout << "Nam chon (0), Nu chon (1):";
		while (true)
		{
			cin >> SV.gender;
			if (SV.gender == 0 || SV.gender == 1) break;
			else
				cout << "Nhap sai, nhap lai:";
		}
		cout << "Nhap diem trung binh: "; cin >> SV.dtb;
		NODE* p = init_NODE(SV);
		add_NODE(l, p);
	}
	nhap_file(l);
}

void selection_sort_tang(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		if (k != l.pTail)
		{
			NODE* min_pos = k;
			for (NODE* h = k->link; h != NULL; h = h->link)
			{
				if (k->sv.mssv > h->sv.mssv)
					min_pos = h;
			}
			sinhvien temp = k->sv;
			k->sv = min_pos->sv;
			min_pos->sv = temp;
		}
	}
}


void selection_sort_giam(LIST &l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		if (k != l.pTail)
		{
			NODE* min_pos = k;
			for (NODE* h = k->link; h != NULL; h = h->link)
			{
				if (k->sv.mssv < h->sv.mssv)
					min_pos = h;
			}
			sinhvien temp = k->sv;
			k->sv = min_pos->sv;
			min_pos->sv = temp;
		}
	}
}

void duyet_ds(LIST& l)
{
	// mssv........ho ten..............dd/mm/yy....dtb.....
	cout <<"|" <<left << setw(12) << "MSSV" <<"|" << left << setw(25) << "Ho va ten" <<"|" << left<<setw(12)<<"dd/mm/yy"<<"|"<<left<<setw(10)<<"DTB"<<"|"
}

int main()
{

}