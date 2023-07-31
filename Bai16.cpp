#include<iostream>
using namespace std;
const int MAX = 100;
int hop[MAX];
int giao[MAX];
int temp = 0;
int k;
int bu[MAX];
int b = 0;


void init_array(int a[], int &n)
{
	cout << "Nhap so phan tu cua mang 1: ";
	while (true)
	{
		cin >> n;
		if (n > 0 && n < 100) break;
		else
			cout << "Nhap lai: ";
	}
	cout << "Nhap phan tu: ";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu cua phan tu " << i + 1 << ": ";
		cin >> a[i];
	}
}

void xuat_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}


void tap_hop(int a[], int a1[], int n, int m)
{
	if (n == 0 || m == 0) return;
	else
	{
		int min;
		k = n + m;
		int tam = 0;
		if (n < m)
		{
			min = n;
		}
		else if (n > m)
		{
			min = m;
		}
		else
		{
			min = m;
		}

		for (int i = 0; i < min; i++)
		{
			hop[i] = a[i];
		}

		for (int i = min; i < k; i++)
		{
			hop[i] = a1[tam++];
		}
	}
}

void tap_giao(int a[], int a1[], int n, int m)
{
	if (m == 0 || n == 0) return;
	else
	{
		int max;
		int min;
		if (n > m)
		{
			max = n;
			min = m;
		}
		else if (n < m) {
			max = m;
			min = n;
		}
		else
			max = min = n;

		for (int i = 0; i < max; i++)
		{
			for (int j = 0; j < min; j++)
				if (a[i] == a1[j])
					giao[temp++] = a[i];
		}
	}
}


bool check_number(int value, int m, int a1[])
{
	for (int i = 0; i < m; i++)
	{
		if (a1[i] == value)
		{
			return true;
		}
	}
	return false;
}
void phan_bu(int n, int m, int a[], int a1[])
{
	for (int i = 0; i < n; i++)
	{
		if (check_number(a[i], m, a1) == false)
			bu[b++] = a[i];
	}
}
int main()
{
	int n = 0, m = 0;
	int a[MAX];
	int a1[MAX];
	init_array(a, n);
	init_array(a1, m);
	tap_hop(a, a1, n, m);
	tap_giao(a, a1, n, m);
	phan_bu(n, m, a, a1);
	system("cls");
	cout << "Ket Qua: " << endl << endl;
	xuat_mang(hop, k);
	cout << endl;
	xuat_mang(giao, temp);
	cout << endl;
	xuat_mang(bu, b);
	return 0;
}