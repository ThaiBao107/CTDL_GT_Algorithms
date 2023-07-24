#include<iostream>
using namespace std;


struct NODE
{
	int data;
	NODE* link;
};

struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};

void init_queue(QUEUE& e)
{
	e.pHead = NULL;
	e.pTail = NULL;
}

NODE* init_NODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}

bool IsEmpty(QUEUE e)
{
	if (e.pHead == NULL) return true;
	else
		return false;
}
void Push(QUEUE& e, NODE* p)
{
	if (IsEmpty(e))
	{
		e.pHead = e.pTail = p;
	}
	else
	{
		e.pTail->link = p;
		e.pTail = p;
	}
}

bool Pop(QUEUE& e, int& x)
{
	if (IsEmpty(e))
		return false;
	else
	{
		NODE* p = e.pHead;
		x = e.pHead->data;
		e.pHead = e.pHead->link;
		delete p;
		return true;
	}
}

bool Top(QUEUE e, int& x)
{
	if (IsEmpty(e))
		return false;
	else
	{
		x = e.pHead->data;
		return true;
	}
}

void duyet_DS(QUEUE e)
{
	if (IsEmpty(e))
		cout << "Chua co danh sach" << endl;
	else
	{
		cout << "DANH SACH" << endl << endl;
		while(IsEmpty(e) != true)
		{
			int x = 0;
			Pop(e, x);
			cout << "x: " << x << endl;
		}
	}
}

int main()
{
	int choose;
	QUEUE e;
	init_queue(e);
	do
	{
		cout << "----------------------MENU--------------------------" << endl;
		cout << "1. Push                                            " << endl;
		cout << "2. Pop                                             " << endl;
		cout << "3. Top                                             " << endl;
		cout << "4. Duyet danh sach                                 " << endl;
		cout << "5. EXIT                                           " << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 5) break;
			else
				cout << "Nhap sai, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Nhap node: ";
			cin >> x;
			NODE* p = init_NODE(x);
			Push(e, p);
			break;
		}
		case 2:
		{
			int x = 0;
			if (Pop(e, x))
			{
				cout << "Pop: " << x << endl;
			}
			else
				cout << "Chua co danh sach" << endl;
			break;
		}
		case 3:
		{
			int x = 0;
			if (Top(e, x))
			{
				cout << "Top: " << x << endl;
			}
			else
				cout << "Chua co danh sach" << endl;
			break;
		}
		case 4:
		{
			duyet_DS(e);
			break;
		}
		case 5:
		{
			if (IsEmpty(e))
				return 0;
			else
			{
				while (IsEmpty(e) == true)
				{
					int x;
					Pop(e, x);
				}
				cout << "THOAT" << endl;
				return 0;
			}

		}
		}
		system("pause");
		system("cls");
	} while (true);
}