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
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else
	{
		l.pTail->link = p;
		l.pTail = p;
	}
}

void duyet_LIST(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->link)
	{
		cout << k->data << " ";
	}

}

void tap_hop(LIST l1, LIST l2, LIST &kq)
{
	for (NODE* k = l1.pHead; k != NULL; k = k->link)
	{
		add_NODE(kq, k);
	}

	for (NODE* h = l2.pHead; h != NULL; h = h->link)
	{
		add_NODE(kq, h);
	}
}

void tap_giao(LIST l1, LIST l2, LIST &kq)
{
	for (NODE* k = l1.pHead; k != NULL; k = k->link)
	{
		for (NODE* h = l2.pHead; h != NULL; h = h->link)
			if (k->data == h->data)
			{
				NODE *i = init_NODE(k->data);
				add_NODE(kq, i);
			}
	}
}


bool check_number(int value, LIST l2)
{
	for (NODE* k = l2.pHead; k != NULL; k = k->link)
	{
		if (k->data == value) return true;
	}
	return false;
}

void phan_bu(LIST l1, LIST l2, LIST& kq)
{
	for (NODE* k = l1.pHead; k != NULL; k = k->link)
	{
		if (check_number(k->data, l2) == false)
			add_NODE(kq, k);
	}
}



int main()
{
	LIST l1;
	LIST l2;
	LIST hop;
	LIST giao;
	LIST bu;
	init_LIST(l1);
	init_LIST(l2);
	init_LIST(hop);
	init_LIST(giao);
	init_LIST(bu);

	for (int i = 0; i < 5; i++)
	{
		int n;
		cout << "Nhap gia tri: ";
		cin >> n;
		NODE* p = init_NODE(n);
		add_NODE(l1, p);
	}
	system("cls");

	for (int i = 0; i < 5; i++)
	{
		int n;
		cout << "Nhap gia tri: ";
		cin >> n;
		NODE* p = init_NODE(n);
		add_NODE(l2, p);
	}
	system("cls");
	tap_hop(l1, l2, hop);
	tap_giao(l1, l2, giao);
	phan_bu(l1, l2, bu);
	cout << "Tap hop: "; duyet_LIST(hop);
	cout << endl;
	cout << "Tap giao: "; duyet_LIST(giao);
	cout << endl;
	cout << "Phan bu: "; duyet_LIST(bu);
	return 0;


}