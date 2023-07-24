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

NODE* init_NODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}

void init_list(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

bool search_NODE(LIST& l, int x)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		if (k->data == x) {
			return true;
		}
	}
	return false;
}

void show_list(LIST l)
{
	int dem = 0;
	cout << "DANH SACH HIEN CO" << endl;
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		dem++;
		cout << "NODE " << dem << ": " << k->data << endl;
	}
}

void add_fisrt_list(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->link = l.pHead;
		l.pHead = p;
	}
}

void delete_first_list(LIST& l)
{
	if (l.pHead == NULL) {
		cout << "Chua co danh sach" << endl;
		return;
	}
	else
	{
		NODE* h = l.pHead;
		l.pHead = l.pHead->link;
		delete h;
		cout << "Xoa thanh cong" << endl;
	}
}

void add_last_list(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->link = p;
		l.pTail = p;
	}
	cout << "Them thanh cong" << endl;
}

void delete_last_list(LIST& l)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co danh sach" << endl;
		return;
	}
	else
	{
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			if (k->link == l.pTail)
			{
				delete l.pTail;
				k->link = NULL;
				l.pTail = k;
			}
		}
		cout << "Delete success" << endl;
	}
}

int search_find_pt(LIST& l, int pt)
{
	int dem = 0;
	if (l.pHead == NULL) return dem;
	/*else if(l.pTail->data == pt)
	{
		delete_last_list(l);
		dem++;
	}*/
	else
	{
		NODE* preX = l.pHead;
		NODE* p = l.pHead;
		/*for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			if (k->data == pt)
			{

				g->link = k->link;
				delete k;
				dem++;
				continue;
			}
			g = k;
		}*/
		while (p != NULL)
		{
			if (p->data == pt)
			{
				NODE* r = p;

				if (l.pHead == p)
				{
					l.pHead = l.pHead->link;
					p = l.pHead;
					preX = l.pHead;
					dem++;
				}
				else
				{
					preX->link = p->link;
					p = p->link;
					dem++;
				}
				delete r;
			}
			else
			{
				preX = p;
				p = p->link;
			}
		}
	}
	return dem;
}

void swap(NODE*& a, NODE*& b)
{
	int tam = a->data;
	a->data = b->data;
	b->data = tam;
}

bool secletion_sort_list(LIST& l)
{
	if (l.pHead == NULL || l.pHead->link == NULL) return false;
	else
	{
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			NODE* min_pos = k;
			for (NODE* h = k->link; h != NULL; h = h->link)
			{
				if (k->data > h->data) min_pos = h;
			}
			swap(k, min_pos);
		}
		return true;
	}
}



int main()
{
	LIST l;
	init_list(l);
	int choose;
	bool flag = false;
	do
	{
		cout << "---------------------------MENU-------------------------" << endl;
		cout << "1. Them node vao danh sach                              " << endl;
		cout << "2. Duyet danh sach                                     " << endl;
		cout << "3. Search phan tu trong DS                             " << endl;
		cout << "4. Them mot phan tu vao dau danh sach                  " << endl;
		cout << "5. Xoa phan tu dau danh sach                           " << endl;
		cout << "6. Them phan tu vao cuoi danh sach                     " << endl;
		cout << "7. Xoa phan tu cuoi danh sach                          " << endl;
		cout << "8. Tim va xoa mot phan tu                               " << endl;
		cout << "9. Sap xep danh sach                                     " << endl;
		cout << "10. EXIT                                                  " << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 10) break;
			else
			{
				cout << "Nhap sai lua chon or nhap e de thoat: ";
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
			int x;
			cout << "Nhap value x: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_last_list(l, p);
			flag = true;
			break;
		}
		case 2:
		{
			if (flag)
			{
				show_list(l);
			}
			else
				cout << "Chua co danh sach" << endl;
			break;
		}
		case 3:
		{
			if (flag)
			{
				int x;
				cout << "Nhap phan tu can tim kiem: "; cin >> x;
				if (search_NODE(l, x))
					cout << "Phan tu can tim hien dang co trong danh sach" << endl;
				else
					cout << "Phan tu can tim khong co trong danh sach" << endl;
			}
			else
				cout << "Chua co danh sach" << endl;
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap gia tri NODE: "; cin >> x;
			NODE* p = init_NODE(x);
			add_fisrt_list(l, p);
			cout << "Add success" << endl;
			break;
		}
		case 5:
		{
			delete_first_list(l);
			system("pause");
			system("cls");
			show_list(l);
			break;
		}
		case 6:
		{
			int x;
			cout << "Nhap gia tri cua NODE: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_last_list(l, p);
			break;
		}
		case 7:
		{
			delete_last_list(l);
			system("pause");
			system("cls");
			show_list(l);
			break;
		}
		case 8:
		{
			int x;
			cout << "Nhap phan tu cann tim va xoa: "; cin >> x;
			if (search_find_pt(l, x) != 0)
			{
				cout << "Xoa thanh cong" << endl;
			}
			else
				cout << "Khong co phan tu can tim" << endl;
			break;
		}
		case 9:
		{
			if (secletion_sort_list(l))
			{
				cout << "Sort success" << endl;
			}
			else
				cout << "Danh sach chua co hoac danh sach chi co mot phan tu" << endl;
			break;
		}
		case 10:
		{
			if (l.pHead == NULL)
			{
				cout << "THOAT" << endl;
				return 0;
			}
			else
			{
				cout << "THOAT" << endl;
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
	} while (true);
}