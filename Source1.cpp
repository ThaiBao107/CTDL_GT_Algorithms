#include <iostream>
#include<iomanip>
using namespace std;
const int MAX_SIZE = 100;


void search(int a[], int &n);
void delete_pt(int a[], int& n, int vt);

void init_array(int a[], int &n)
{
	cout << "Nhap so luong phan tu cua mang: ";
	while (true)
	{
		cin >> n;
		if (n > 0 && n <= MAX_SIZE) break;
		else
			cout << "Nhap sai, nhap lai: ";
	}
	system("cls");
	for (int i = 0; i < n; i++)
	{
		cout << "PT thu " << i + 1 << ": "; 
		cin >> a[i];
	}
}

void show_array(int a[], int n)
{
	cout << "DANH SACH" << endl << endl;
	// Thu tu                      gia tri
	cout << "|" << setw(10) << left << "Thu tu" << " |" << setw(10) << left <<"Gia tri" <<"|" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(10) << left << i + 1 << " |" << setw(10) << left << a[i] <<"|" << endl;
	}
}

void add_array(int a[], int& n)
{
	int x;
	int vt;
	cout << "Nhap gia tri phan tu can them: "; cin >> x;
	cout << "Nhap vi tri can chen: ";
	while (true)
	{
		cin >> vt;
		if (vt > 0 && vt <= n) break;
		else
		{
			char i;
			cout << "Nhap sai hoac neu muon thoat nhap e, nhap lai: ";
			cin >> i;
			if (i == 'e') return;
		}
	}
	for (int i = n - 1; i >= vt - 1; i--)
		a[i + 1] = a[i];
	a[vt - 1] = x;
	n++; 
	cout << "Them vao thanh cong" << endl;
}
//-------------------------------------------------------

void search(int a[], int &n)
{
	int x;
	cout << "Nhap gia tri can xoa: ";
	cin >> x;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			delete_pt(a, n, i);
			dem++;
		}
	}
	if (dem == 0) cout << "Phan tu can tim khong co trong danh sach" << endl;
	else
		cout << "Xoa thanh cong" << endl;
}
void delete_pt(int a[], int& n, int vt)
{
	for (int i = vt; i < n-1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

//------------------------------------------------------

void gop_array(int a[], int n)
{
	int arr1[MAX_SIZE];
	int m = 0;
	system("cls");
	init_array(arr1, m);
	// gop mang
	int danhsach[MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		danhsach[i] = a[i];
	}
	int dem = 0;
	for (int i = n; i < m+n; i++)
	{
		danhsach[i] = arr1[dem++];
	}
	cout << "Mang sau khi gop: " << endl;
	show_array(danhsach, m + n);
}
int main()
{
	int arr[MAX_SIZE];
	int choose;
	bool flag = false;
	int n = 0;
	do
	{
		cout << "------------------MENU----------------------" << endl;
		cout << "1. Khoi tao mang                            " << endl;
		cout << "2. Show mang                                " << endl;
		cout << "3. Them vao mang                            " << endl;
		cout << "4. Xoa mot phan tu                          " << endl;
		cout << "5. Gop mang                                 " << endl;
		cout << "6. EXIT                                     " << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 6) break;
			else
				cout << "Nhap sai, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			init_array(arr, n);
			flag = true;
			break;
		}
		case 2:
		{
			if (flag == false)
			{
				cout << "Chua co danh sach" << endl;
			}
			else
			{
				show_array(arr, n);
			}
			break;
		}
		case 3:
		{
			if (flag == false) cout << "Chua co danh sach" << endl;
			else
			{
				add_array(arr, n);
			}
			break;
		}
		case 4:
		{
			if (flag == false) cout << "Chua co danh sach" << endl;
			else
			{
				search(arr, n);
				system("pause");
				system("cls");
				show_array(arr, n);
			}
			break;
		}
		case 5:
		{
			if (flag == false) cout << "Chua co danh sach" << endl;
			else
			{
				gop_array(arr, n);
			}
			break;
		}
		case 6:
		{NN
			cout << "EXIT" << endl;
			return 0;
		}
		}
		system("pause");
		system("cls");
	} while (true);
}