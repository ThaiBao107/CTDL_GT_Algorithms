#include<iostream>
using namespace std;

struct NODE
{
	int value;
	NODE* link;
	NODE* previous;
};

struct LIST 
{
	NODE* pHead;
	NODE* pTail;
};

typedef struct LIST DoubleLinked;
void init_LIST(DoubleLinked& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* init_NODE(int x)
{
	NODE* p = new NODE;
	p->value = x;
	p->link = NULL;
	p->previous = NULL;
	return p;
}

void show_LIST_link(DoubleLinked l)
{
	int dem = 0;
	cout << "DANH SACH" << endl;
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		dem++;
		cout << "NODE " << dem << ": " << k->value << endl;
	}
}

void show_LIST_previous(DoubleLinked l)
{
	int dem = 0;
	cout << "DANH SACH" << endl;
	for (NODE* k = l.pTail; k != NULL; k = k->previous)
	{
		dem++;
		cout << "NODE " << dem << ": " << k->value << endl;
	}
}

void add_fisrt(DoubleLinked& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->link = l.pHead;
		l.pHead->previous = p;
		l.pHead = p;
	}
}

void add_last(DoubleLinked& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->previous = l.pTail;
		l.pTail->link = p;
		l.pTail = p;
		
	}
}

void delete_first(DoubleLinked& l)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co danh sach" << endl;
		return;
	}
	else if (l.pHead->link == NULL)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else
	{
		NODE* h = l.pHead;
		l.pHead = l.pHead->link;
		l.pHead->previous = NULL;
		delete h;
		cout << "Xoa thanh cong" << endl;
	}
}

void delete_last(DoubleLinked& l)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co danh sach" << endl;
		return;
	}
	else if (l.pHead->link == NULL)
	{
		delete_first(l);
		cout << "Xoa thanh cong" << endl;
	}
	else
	{
		NODE* h = l.pTail;
		l.pTail = l.pTail->previous;
		l.pTail->link = NULL;
		delete h;
		cout << "Xoa thanh cong" << endl;
	}
}

void search_delete(DoubleLinked& l, int x)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co danh sach nen khong the xoa" << endl;
		return;
	}
	else if (l.pHead->link == NULL && l.pHead->value == x)
	{
		delete_first(l);
	}
	// khi danh sach co 1 phan tu
	else
	{
		NODE* p = l.pHead;
		NODE* preX = l.pHead;
		while (p != NULL)
		{
			// check dieu kien p la pHead
			if (p->value == x)
			{
				NODE* r = p; // node r luu vi tri can xoa turn;
				if (l.pHead == p)
				{
					l.pHead = l.pHead->link;
					p = l.pHead;
					preX = l.pHead;
					if (p != NULL)
						p->previous = NULL;
				}
				if (p->link == NULL)
				{
					l.pTail = l.pTail->previous;
					l.pTail->link = NULL;
					p = p->link;
				}
				else
				{
						/*if(p->link == NULL)
						{
							l.pTail = l.pTail->previous;
							l.pTail->link = NULL;
							p = p->link;
						}
						else
						{*/
							preX->link = p->link;
							p->link->previous = preX;
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


int main()
{
	int choose;
	DoubleLinked l;
	init_LIST(l);
	do
	{
		cout << "-------------DOUBLE LINKED LIST----------------" << endl;
		cout << "1. Them vao node vao danh sach                " << endl;
		cout << "2. Duyet danh sach                             " << endl;
		cout << "3. Them mot pt vao dau danh sach  " << endl;
		cout << "4.	Them mot pt vao cuoi danh sach" << endl;
		cout << "5. Xoa dau danh sach                           " << endl;
		cout << "6. Xoa cuoi danh sach                         " << endl;
		cout << "7. Search pt va xoa                           " << endl;
		cout << "8. ........                                    " << endl;
		cout << "9. EXIT                                        " << endl;
		cout << "Choose: ";
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
			int x;
			cout << "Nhap gia tri cua NODE: "; cin >> x;
			NODE* p = init_NODE(x);
			add_last(l, p);
			break;
		}
		case 2:
		{
			if (l.pHead == NULL)
				cout << "Chua co danh sach" << endl;
			else
			{
				cout << "Duyet bang link: " << endl;
				show_LIST_link(l);
				cout << endl << endl;
				cout << "Duyet bang previous: " << endl;
				show_LIST_previous(l);
			}
			break;
		}
		case 3:
		{
			int x;
			cout << "Nhap gia tri NODE: "; cin >> x;
			NODE* p = init_NODE(x);
			add_fisrt(l, p);
			cout << "Add first success" << endl;
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap gia tri NODE: "; cin >> x;
			NODE* p = init_NODE(x);
			add_last(l, p);
			cout << "Add first success" << endl;
			break;
		}
		case 5:
		{
			delete_first(l);
			break;
		}
		case 6:
		{
			delete_last(l);
			break;
		}
		case 7:
		{
			int x;
			cout << "Nhap phan tu can xoa: "; cin >> x;
			search_delete(l, x);
			break;
		}
		case 8:
		{
			cout << "Chua lam" << endl;
			break;
		}
		case 9:
		{
			if (l.pHead == NULL)
			{
				cout << "THOAT" << endl;
				return 0;
			}
			else
			{
				NODE* g;
				while (l.pHead != NULL)
				{
					g = l.pHead;
					l.pHead = l.pHead->link;
					delete g;
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