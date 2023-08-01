#include<iostream>
using namespace std;
const int MAX = 100;
int a[MAX];
int n = 0;

void nhap()
{
	cout << "Nhap so luong phan tu: ";
	while (true)
	{
		cin >> n;
		if (n > 0 && n < 100) break;
		else
			cout << "Nhap lai: ";
	}
	system("cls");
	for (int i = 0; i < n; i++)
	{
		cout << "Mhap pahn tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}

void xuat_mang()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Intersion_sort()
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		j = i - 1;
		while (j >= 0 && temp < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}


void selection_sort()
{
	for (int i = 0; i < n-1;i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min_pos] > a[j]) min_pos = j;
		}
		int temp = a[i];
		a[i] = a[min_pos];
		a[min_pos] = temp;
	}
}

void Interchange_sort()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1;j<n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


void Bubble_sort()
{
	for (int i = 0; i < n-1;i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] < a[j-1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}


bool tim_kiem(int value)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == value) return true;
	}
	return false;
}

bool search_binary(int value)
{
	int m, l, r;
	r = n - 1;
	l = 0;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (a[m] == value) return true;
		else if (a[m] > value) r = m - 1;
		else
			l = m + 1;
	}
	return false;
}

int main()
{
	int choose;
	int flag = 0;
	do
	{
		cout << "-------------------------------MENU-------------------------------" << endl;
		cout << "1. Nhap danh sach                                                " << endl;
		cout << "2. Xuat danh sach                                                 " << endl;
		cout << "3. Thuat toan Intertion sort                                     " << endl;
		cout << "4. Thuat toan Selection sort                                      " << endl;
		cout << "5. Thuat toan Interchange sort                                    " << endl;
		cout << "6. Thuat toan bubble sort                                          " << endl;
		cout << "7. Tim kiem tuan tu                                                " << endl;
		cout << "8. Tim kiem nhi phan                                              " << endl;
		cout << "9. EXIT                                                          " << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 9) break;
			else
				cout << "Nhap sai, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			nhap();
			break;
		}
		case 2:
		{
			if (n == 0) cout << "chua co danh sach" << endl;
			else
			{
				xuat_mang();
			}
			break;
		}
		case 3:
		{
			if (n == 0) cout << "Chua co danh sach" << endl;
			else
			{
				cout << "Sap xep theo Insertion sort" << endl;
				Intersion_sort();
				flag = 1;
				system("cls");
				xuat_mang();
			}
			break;
		}
		case 4:
		{
			if (n == 0) cout << "Chua co danh sach" << endl;
			else
			{
				cout << "Sap xep theo Selection sort" << endl;
				selection_sort();
				flag = 1;
				system("cls");
				xuat_mang();
			}
			break;
		}
		case 5:
		{
			if (n == 0) cout << "Chua co danh sach" << endl;
			else
			{
				cout << "Sap xep theo interchange sort" << endl;
				Interchange_sort();
				flag = 1;
				system("cls");
				xuat_mang();
			}
			break;
		}
		case 6:
		{
			if (n == 0) cout << "Chua co danh sach" << endl;
			else
			{
				cout << "Sap xep theo Bubble sort" << endl;
				Bubble_sort();
				flag = 1;
				system("cls");
				xuat_mang();
			}
			break;
		}

		case 7:
		{
			if (n == 0) cout << "Chua co danh sach" << endl;
			else
			{
				int value;
				cout << "Nhap value: ";
				cin >> value;
				if (tim_kiem(value))
					cout << "Value co trong mang" << endl;
				else
					cout << "Value khong co trong mang" << endl;
			}
			break;
		}
		case 8:
		{
			if (n == 0 || flag == 0) cout << "Chua co danh sach hoac chua sap xep" << endl;
			else
			{
				int value;
				cout << "Nhap value tim: "; cin >> value;
				if (search_binary(value))
				{
					cout << "Value can tim co trong mang" << endl;
				}
				else
					cout << "Value can tim khong co trong mang" << endl;
			}
			break;
		}
		default:
			return 0;
		}
		system("pause");
		system("cls");
	} while (1);
	return 0;
}