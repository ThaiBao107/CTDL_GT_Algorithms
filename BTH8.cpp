#include<iostream>
#define MAX 100
int s[MAX];
int sp;
using namespace std;


void init_STACK(int s[], int &sp)
{
	sp = -1;
}

bool IsEmpty(int s[], int sp)
{
	if (sp == -1) return true;
	else
		return false;
}

bool IsPull(int s[], int sp)
{
	if (sp == MAX - 1)
		return true;
	else
		return false;
}

bool Push(int s[], int& sp, int n)
{
	if (sp <= MAX - 1)
	{
		s[++sp] = n;   // start = -1 / ++sp = 0
		return true;
	}
	return false;
}


bool Pop(int s[], int& sp, int &m)
{
	if (IsEmpty(s,sp))
		return false;
	else
	{
		m = s[sp--];
		return true;
	}
}


bool top(int s[], int sp, int &m)
{
	if (IsEmpty(s,sp))
		return false;
	else
	{
		m = s[sp];
		return true;
	}
}




int main()
{
	init_STACK(s, sp);
	int choose;
	do
	{
		cout << "-------------------MENU--------------------------" << endl;
		cout << "1. Check the stack empty                         " << endl;
		cout << "2. Check the stack full                         " << endl;
		cout << "3. Push                                         " << endl;
		cout << "4. Pop                                          " << endl;
		cout << "5. Top                                          " << endl;
		cout << "6. EXIT                                         " << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 6) break;
			else
			{
				cout << "Nhap sai, nhap lai: ";
			}
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			if (IsEmpty(s, sp))
				cout << "Danh sach dang trong" << endl;
			else
				cout << "Hien dang co mot danh sach" << endl;
			break;
		}
		case 2:
		{
			if (IsPull(s, sp))
				cout << "Danh sach da day" << endl;
			else
				cout << "Dang sach chua day" << endl;
			break;
		}
		case 3:
		{
			int n;
			cout << "Nhap n de them stack: ";
			cin >> n;
			if (Push(s, sp, n)) cout << "Them thanh cong" << endl;
			else
				cout << "Danh sach da day" << endl;
			break;
		}
		case 4:
		{
			int m = 0;
			if (Pop(s, sp, m) != true)
				cout << "Chua co danh sach" << endl;
			else
			{
				cout << "Pop: " << m << endl;
			}
			break;
		}
		case 5:
		{
			int m = 0;
			if (top(s, sp, m) != true)
				cout << "Chua co danh sach" << endl;
			else
			{
				cout << "Top: " << m << endl;
			}
			break;
		}
		case 6:
		{
			cout << "Thoat" << endl;
			return 0;
		}
		}
		system("pause");
		system("cls");
	} while (true);

}