#include<iostream>
using namespace std;	
const int max_size = 100;


void merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[max_size], R[max_size];
	// sao chep vao mang tam
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[l+i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = a[m + 1 + j];
	}

	// tien hanh sap xep va tron mang 
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	// truong hop con phan tu du mot trong hai mang L va R

	while (i < n1)
	{
		a[k] = L[i];
		k++;
		i++;
	}

	while (j < n2)
	{
		a[k] = R[j];
		k++;
		j++;
	}
}
void merge_sort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, m, r);
	}
}
int main()
{
	int n;
	int a[max_size];
	cout << "Nhap n phan tu: ";
	cin >> n;
	system("cls");
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
	cout << "SAP XEP THEO MERGE SORT: " << endl;
	cout << "Mang truoc khi sap xep: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	merge_sort(a, 0, n - 1);
	cout << "Mang sau khi sap xep: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}