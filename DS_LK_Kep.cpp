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
		cout << "8. EXIT                                        " << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Choose: ";
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