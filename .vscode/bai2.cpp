#include<iostream>
using namespace std;
struct NODE
{
	int data;
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

NODE* init_NODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
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


void duyet_ds(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		cout << k->data << " ";
	}
}


void tang_dan(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		if (k != l.pTail)
			for (NODE* h = k->link; h != NULL; h = h->link)
				if (k->data > h->data)
				{
					int temp = k->data;
					k->data = h->data;
					h->data = temp;
				}
	}
}

void giam_dan(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		if (k != l.pTail)
			for (NODE* h = k->link; h != NULL; h = h->link)
			{
				if (k->data < h->data)
				{
					int temp = k->data;
					k->data = h->data;
					h->data = temp;
				}
			}
	}
}

void swap(NODE*& a, NODE*& b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void Selection_sort_tang(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		if (k != l.pTail)
		{
			NODE* pos_min = k;
			for (NODE* h = k->link; h != NULL; h = h->link)
			{
				if (k->data > h->data)
					pos_min = h;
			}
			swap(k, pos_min);
		}
	}
}

void Selection_sort_giam(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		if (k != l.pTail)
		{
			NODE* pos_min = k;
			for (NODE* h = k->link; h != NULL; h = h->link)
			{
				if (k->data < h->data)
					pos_min = h;
			}
			swap(k, pos_min);
		}
	}
}

int main()
{
	LIST l;
	init_LIST(l);
	int choose;
	do
	{
		cout << "------------------------------MENU------------------------------" << endl;
		cout << "1. Nhap npde trong danh sach                                    " << endl;
		cout << "2. Xuat danh sach                                               " << endl;
		cout << "3. Sap xep theo thuat taon interchange sort tang                   " << endl;
		cout << "4. Sap xep theo thuat toan interchange sort giam               " << endl;
		cout << "5. Sap xep theo thuat toan Selection sort tang                      " << endl;
		cout << "6. Sap xep theo thuat toan Selection sort giam                  " << endl;
		cout << "7. Sap xep theo thuat toan Insertion sort                       " << endl;
		cout << "8. EXIT                                                         " << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "Lua chon: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 8) break;
			else
				cout << "Nhap sai, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Nhap gia tri: "; cin >> x;
			NODE *p = init_NODE(x);
			add_NODE(l, p);
			break;
		}
		case 2:
		{
			if (l.pHead == NULL)
				cout << "Danh sach con trong";
			else
			{
				duyet_ds(l);
			}
			break;
		}
		case 3:
		{
			if (l.pHead == NULL)
				cout << "Danh sach con trong";
			else
			{
				cout << "interchange sort tang" << endl << endl;
				tang_dan(l);
				cout << "Sap xep thanh cong" << endl;
				system("cls");
				duyet_ds(l);
			}
			break;
		}
		case 4:
		{
			if (l.pHead == NULL)
				cout << "Danh sach con trong";
			else
			{
				cout << "interchange sort giam" << endl << endl;
				giam_dan(l);
				cout << "Sap xep thanh cong" << endl;
				system("cls");
				duyet_ds(l);
			}
			break;
		}
		case 5:
		{
			if (l.pHead == NULL)
				cout << "Danh sach con trong";
			else
			{
				cout << "selection sort tang" << endl;
				Selection_sort_tang(l);
				system("cls");
				duyet_ds(l);
			}
			break;
		}
		case 6:
		{
			if (l.pHead == NULL)
				cout << "Danh sach con trong";
			else
			{
				cout << "Selection sort giam" << endl;
				Selection_sort_giam(l);
				cout << "Sap xep thanh cong" << endl;
				system("cls");
				duyet_ds(l);
			}
			break;
		}
		case 7:
		{
			cout << "Chua lam" << endl;
			break;
		}
		case 8:
		{
			if (l.pHead == NULL)
			{
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
				return 0;
			}
		}
		}
		system("pause");
		system("cls");
	}while (true);
}