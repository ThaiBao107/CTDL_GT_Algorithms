#include<iostream>
using namespace std;
const int MAX_S = 100;

void init_da_thuc(int a[], int& n)
{
	cout << "Nhap da thuc: ";
	while (true)
	{
		cin >> n;
		if (n > 0 && n <= MAX_S) break;
		else
			cout << "Nhap sai, nhap lai: ";
	}
	n++;
	system("cls");
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap he so x" << i << ": ";
		cin >> a[i];
	}
	cout << "Init success" << endl;
}

void show_da_thuc(int a[], int n)
{
	cout << "Da thuc: ";
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			cout << a[i] << endl;
		}
		else
		{
			cout << a[i] << "x^" << i << "+";
		}
	}
}

void sum_da_thuc(int a[],int b[], int kq[], int n, int m, int &tam)
{
	cout << "CONG DA THUC<" << endl;
		int min;
		if (n > m)
		{
			tam = n;
			min = m;
		}
		else if (n < m)
		{
			tam = m;
			min = n;
		}
		else tam = min = n;
		int dem = 0;
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < min; j++)
			{
				if (i == j)
				{
					kq[i] = a[i] + b[j];
					dem++;
				}
			}
		}
		while (dem < tam)
		{
			if (n > m) {
				kq[dem] = a[dem];
				dem++;
			}
			else
			{
				kq[dem] = b[dem];
				dem++;
			}
		}
		
	cout << "Thuc hien phep tinh thanh cong" << endl;
}


void tru_da_thuc(int a[], int b[], int kq[], int n, int m, int &tam)
{
	int min;
	if (n > m)
	{
		tam = n;
		min = m;
	}
	else if (n < m)
	{
		tam = m;
		min = n;
	}
	else tam = min = n;
	int dem = 0;
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < min; j++)
		{
			if (i == j)
			{
				kq[i] = a[i] - b[j];
				dem++;
			}
		}
	}
	while (dem < tam)
	{
		if (n > m) {
			kq[dem] = a[dem];
			dem++;
		}
		else
		{
			kq[dem] = b[dem];
			dem++;
		}
	}
	cout << "Thuc hien phep tinh thanh cong" << endl;

}
int main()
{
	int a[MAX_S];
	int n = 0;
	int arr[MAX_S];
	int m = 0;
	int choose;
	bool flag = false;
	do
	{
		cout << "----MENU---------" << endl;
		cout << "1. Nhap hai da thuc can tinh" << endl;
		cout << "2. Xuat hai da thuc          " << endl;
		cout << "3. Cong hai da thuc           " << endl;
		cout << "4. Tru hai da thuc" << endl;
		cout << "5. Nhan hai da thuc" << endl;
		cout << "6. Chia hai da thuc " << endl;
		cout << "7. EXIT" << endl;
		cout << "Choose: ";
		while (1)
		{
			cin >> choose;
			if (choose > 0 && choose <= 7) break;
			else
			{
				cout << "Nhap sai option, nhap lai or nhan e de thoat: ";
				char exit;
				cin >> exit;
				if (exit == 'e') return 0;
			}
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			cout << "Da thuc thu nhat" << endl;
			init_da_thuc(a, n);
			cout << "Da thuc thu hai" << endl;
			init_da_thuc(arr, m);
			flag = true;
			break;
		}
		case 2:
		{
			if (flag == true)
			{
				show_da_thuc(a, n);
				show_da_thuc(arr, m);
			}
			else
			{
				cout << "Chua co da thuc" << endl;
			}
			break;
		}
		case 3:
		{
			if (flag == true)
			{
				int kq[MAX_S];
				int k = 0;
				sum_da_thuc(a, arr, kq, n, m, k);
				system("pause");
				system("cls");
				show_da_thuc(kq, k);
			}
			else
			{
				cout << "Chua co da thuc" << endl;
			}
			break;
		}
		case 4:
		{
			if (flag == true)
			{
				int kq[MAX_S];
				int k = 0;
				tru_da_thuc(a, arr, kq, n, m, k);
				system("pause");
				system("cls");
				show_da_thuc(kq, k);
			}
			else
			{
				cout << "Chua co da thuc" << endl;
			}
			break;
		}
		case 5:
		{
			if (flag == true)
			{
				cout << "Chau lam" << endl;
			}
			else
			{
				cout << "Chua co da thuc" << endl;
			}
			break;
		}
		case 6:
		{
			if (flag == true)
			{
				cout << "Chua lam" << endl;
			}
			else
			{
				cout << "Chua co da thuc" << endl;
			}
			break;
		}
		case 7:
		{
			cout << "Thoat" << endl;
			return 0;
		}
		}
		system("pause");
		system("cls");
	} while (true);
}