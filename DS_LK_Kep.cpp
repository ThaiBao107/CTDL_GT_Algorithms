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

void init_LIST(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *init_NODE(int x)
{
	NODE* p = new NODE;
	p->value = x;
	p->link = NULL;
	p->previous = NULL;
	return p;
}
void add_last(LIST& l, NODE* p);
void add_fisrt(LIST& l, NODE* p);
NODE* init_NODE(int x);
void giai_phong(LIST& l);
void add_node_p_vaosau_node_q(LIST& l, NODE* p);
void init_LIST(LIST& l);
void show_LIST(LIST l);
void delete_first(LIST& l);
void delete_last(LIST& l);
void show_last(LIST l);
void delete_node_p_after_node_q(LIST& l);
void delete_vt_bk(LIST& l, NODE* vt);
int n = 0;

void add_fisrt(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->link = l.pHead;
		l.pHead->previous = p;
		l.pHead = p;
	}
}

void add_last(LIST& l, NODE* p)
{
	if (l.pTail == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->previous = l.pTail;
		l.pTail->link = p;
		l.pTail = p;
	}
}

void giai_phong(LIST &l)
{
	NODE* g;
	while (l.pHead != NULL)
	{
		g = l.pHead;
		l.pHead = l.pHead->link;
		delete g;

	}
}

void show_LIST(LIST l)
{
	int i = 0;
	cout << "DANH SACH" << endl << endl;
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		cout << "NODE thu " << i + 1 << ": " << endl;
		cout << k->value << endl;
		i++;
		cout << endl;
	}
		
}

void add_node_p_vaosau_node_q(LIST& l, NODE* p)
{
	int x;
	cout << "Nhap node q can them vao sau: "; cin >> x;
	NODE* q = init_NODE(x);
	if (q->value == l.pHead->value && l.pHead->link == NULL)
	{
		add_fisrt(l, p);
	}
	else
	{
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			if (k->value == q->value)
			{
				p->previous = k;
				p->link = k->link;
				k->link = p;
				k->link->previous = p;
			}
		}
	}
}

void add_node_p_vao_truoc_q(LIST& l, NODE* p)
{
	int x;
	cout << "Nhap node q: ";
	cin >> x;
	NODE* q = init_NODE(x);
	if (l.pHead == NULL)
	{
		add_fisrt(l, p);
		return;
	}
	if (q->value == l.pHead->value && l.pHead->link == NULL)
	{
		add_fisrt(l, p);
	}
	else
	{
		NODE* g = new NODE;
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			if (q->value == k->value)
			{
				NODE* h = init_NODE(p->value);
				h->link = k;
				h->previous = g;
				g->link = h;
				k->previous = h;
			}
			g = k;
		}
	}
}

void them_nodep_vao_vt_batky(LIST& l, NODE *p, int vt)
{

	if (l.pHead == NULL || vt == 1)
	{
		add_fisrt(l, p);
	}
	else if (vt == n + 1)
	{
		add_last(l, p);
	}
	else
	{
		NODE* g = new NODE;
		int dem = 0;
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			dem++;
			if (dem == vt)
			{
				NODE* h = init_NODE(p->value);
				h->link = k;
				h->previous = g;
				g->link = h;
				k->previous = h;
			}
			g = k;
		}
	}
}

void delete_first(LIST& l)
{
	if (l.pHead == NULL) return;  // danh sach rong
	else if (l.pHead->link == NULL)   // danh sach chi co mot phan tu 
	{
		NODE* g = l.pHead;
		l.pHead = l.pTail = NULL;
		delete g;
	}
	else
	{
		NODE* g = l.pHead;
		l.pHead = l.pHead->link;
		l.pHead->previous = NULL;
		delete g;
	}
}
//---------------------------------------------------
// xoa cuoi
//---------------------------------------------------
void delete_last(LIST& l)
{
	if (l.pHead == NULL) return;
	else if (l.pHead->link == NULL)
		delete_first(l);
	else
	{
		NODE* p = l.pTail;
		l.pTail = l.pTail->previous;
		l.pTail->link = NULL;
		delete p;
	}
}
//---------------------------------------------------

void show_last(LIST l)
{
	int i = 0;
	for (NODE* k = l.pTail; k != NULL; k = k->previous)
	{
		cout << "Node thu " << i + 1 << endl;
		cout << k->value << endl;
		i++;
	}
}

// xoa node p sau node q 
//-----------------------------------------------------
void delete_node_p_after_node_q(LIST& l)      // can coi lai
{
	int x;
	cout << "Nhap node q can xoa sau: ";
	cin >> x;
	NODE* q = init_NODE(x);
	if (l.pHead == NULL) // chua co danh sach
	{
		cout << "Chua co danh sach khong the xoa dc" << endl;
		return;
	}
	else if (l.pHead->link == NULL && q->value == 1)  // danh sach chi co mot phan tu
	{
		delete_first(l);
		return;
	}
	else
	{
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			if (q->value == k->value)
			{
				NODE* h = k->link;
				k->link = h->link;
				if (k->link == NULL)
				{
					l.pTail = k;
					delete h;
					return;
				}
				k->link->previous = h->previous;
				delete h;
			}
		}
	}
}
//-----------------------------------------------------
// xoa node do nguoi dung nhap
//-----------------------------------------------------
void delete_vt_bk(LIST& l, int vt)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co danh sach khong the xoa" << endl;
		return;
	}
	else if (l.pHead->value == vt)
	{
		delete_first(l);
		return;
	}
	else if (l.pTail->value == vt)
	{
		delete_last(l);
		return;
	}
	else
	{
		NODE* g = new NODE;
		for (NODE* k = l.pHead; k != NULL; k = k->link)
		{
			if (k->value == vt)
			{
				g->link = k->link;
				k->link->previous = g;
				delete k;
				return;
			}
			g = k;
		}
	}
	n = 0;
}
//-----------------------------------------------------


int main()
{
	LIST l;
	init_LIST(l);
	int choose;
	do
	{
		cout << "---------------------MENU----------------------" << endl;
		cout << "1. Nhap mot node                               " << endl;
		cout << "2. Danh sach                                   " << endl;
		cout << "3. Them node vao dau danh sach                 " << endl;
		cout << "4. Them vao cuoi danh sach                     " << endl;
		cout << "5. Them node p vao sau node q                  " << endl;
		cout << "6. Them node p vao truoc node q                " << endl;
		cout << "7. Them node p vao vi tri bat ki               " << endl;
		cout << "8. Xoa dau danh sach lien kep                   " << endl;
		cout << "9. Xoa cuoi danh sach                         " << endl;
		cout << "10. Xoa node p sau node q                       " << endl;
		cout << "11. Xoa vi tri do nguoi dung nhap               " << endl;
		cout << "12. EXIT                                        " << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 12) break;
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
			add_last(l,p);
			break;
		}
		case 2:
		{
			show_LIST(l);
			break;
		}
		case 3:
		{
			int x;
			cout << "Nhap node: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_fisrt(l,p);
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap node: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_last(l, p);
			break;
		}
		
		case 5:
		{
			int x;
			cout << "Nhap node: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_node_p_vaosau_node_q(l, p);
			break;
		}
		case 6:
		{
			int x;
			cout << "Nhap node: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_node_p_vao_truoc_q(l, p);
			break;
		}
		case 7:
		{	
			for (NODE* k = l.pHead; k != NULL; k = k->link)
				n++;

			int a;
			cout << "Nhap Nope p: "; 
			cin >> a;
			NODE* p = init_NODE(a);
			//------------------------------------------------------
			int vt;
			cout << "Nhap vi tri trong khoang [1," << n + 1 << "]: ";
			while (true)
			{
				cin >> vt;
				if (vt > 0 && vt <= n+1) break;
				else
					cout << "Nhap sai, nhap lai: ";
			}
			them_nodep_vao_vt_batky(l, p, vt);
			n = 0;
			break;
		}
		case 8:
		{
			delete_first(l);
			cout << "Xoa thanh cong" << endl;
			system("pause");
			system("cls");
			show_LIST(l);
			break;
		}
		case 9:
		{
			delete_last(l);
			cout << "Xoa thanh cong" << endl;
			system("pause");
			system("cls");
			show_last(l);
			break;
		}
		case 10:
		{
			delete_node_p_after_node_q(l);
			cout << "Xoa thanh cong" << endl;
			system("pause");
			system("cls");
			show_last(l);
			break;
		}
		case 11:
		{
			for (NODE* k = l.pHead; k != NULL; k = k->link) n++;
			int x;
			cout << "Nhap vi tri can xoa trong khoang [1," << n<<"]: ";
			while (true)
			{
				cin >> x;
				if (x > 0 && x <= n) break;
				else
					cout << "Vi tri nhap sai hoac khong co vi tri do, nhap lai: ";
			}
			delete_vt_bk(l, x);
			system("pause");
			system("cls");
			show_last(l);
			break;
		}
		case 12:
		{
			if (l.pHead == NULL) return 0;
			else
			{
				giai_phong(l);
				cout << "THOAT" << endl;
				return 0;
			}
		}
		}
		system("pause");
		system("cls");
	} while (true);
}
