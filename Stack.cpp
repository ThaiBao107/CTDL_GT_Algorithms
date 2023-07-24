#include<iostream>
using namespace std;

// stack hoat dong theo LIFO( LAST IN FISRT OUT) vvao sau ra truoc
// Push them vao trong stack 
// Pop lay thong cua stack dau, tra ve gia tri trong stack va huy di
// IsEmpty : kiem tra stack co rong khong tra ve bool
// Top : Xem thong tin cua dau stack , lay gia tri, va KHONG HUY NO

struct NODE
{
	int data;
	NODE* link;
};

struct STACK
{
	NODE* pTop;   // dung con tro de quan ly dau stack
};

void init_stack(STACK& s)  // init stack
{
	s.pTop = NULL;
}

NODE* init_node(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}
 
bool IsEmpty(STACK s)  // kiem tra xem stack co rong khong
{
	if (s.pTop == NULL)
		return true;
	else
		return false;
}

void Push(STACK &s, NODE * p)
{
	if (IsEmpty(s)==true)
		s.pTop = p;
	else
	{
		p->link = s.pTop;
		s.pTop = p;
	}
}

bool Pop(STACK& s, int& x)  // x de lay gia tri tu dau stack
{
	if (IsEmpty(s))
	{
		return false;
	}
	else
	{
		NODE* h = s.pTop;
		x = h->data;            // lay du lieu tu dau stack ta
		s.pTop = s.pTop->link;
		delete h;
	}
	return true;
}


bool Top(STACK s, int& x)
{
	if (IsEmpty(s))
	{
		return false;
	}
	else
	{
		x = s.pTop->data;
		return true;
	}
}


void show_STACK(STACK &s)   // coi lai phan show
{
	if (IsEmpty(s))
	{
		cout << "DS DANG RONG" << endl;
	}
	else
	{
		while(IsEmpty(s) != true)
		{
			int x;
			Pop(s, x);
			cout << x << " ";
		}
	}
}




int main()
{
	STACK s;
	init_stack(s);
	int choose;
	do
	{
		cout << "-----------------------MENU------------------------" << endl;
		cout << "1. Them node vao stack                             " << endl;
		cout << "2. Pop stack                                       " << endl;
		cout << "3. Top stack                                      " << endl;
		cout << "4. Duyet danh sach                                " << endl;
		cout << "5. EXIT                                            " << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 5) break;
			else
			{
				char x;
				cout << "Nhap sai hoac nhan e de thoai CT, nhap lai: ";
				cin >> x;
				if (x == 'e') return 0;
			}
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Nhap node: ";
			cin >> x;
			NODE* p = init_node(x);
			Push(s, p);
			break;
		}
		case 2: // Pop
		{
			int x;
			if (Pop(s, x))
			{
				cout << "Pop: " << x << endl;
			}
			else
				cout << "DANH SACH DANG TRONG" << endl;
			break;
		}
		case 3:    //  Top
		{
			int x = 0;
			if (Top(s, x))
			{
				cout << "Top: " << x << endl;
			}
			else
				cout << "DANH SACH DANG RONG" << endl;
			break;
		}
		case 4:
		{
			show_STACK(s);
			break;
		}
		case 5:
		{
			if (IsEmpty(s)) return 0;
			else
			{
				while (IsEmpty(s) != true)
				{
					int x;
					Pop(s, x);
				}
				return 0;
			}
		}
		}
		system("pause");
		system("cls");
	} while (true);
}