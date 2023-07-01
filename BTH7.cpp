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

void init_list(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *init_NODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}

void add_first(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else if (l.pHead->link == NULL)
	{
		p->link = l.pHead;
		l.pHead->link = p;
		l.pHead = p;
	}
	else
	{
		p->link = l.pHead;
		l.pTail->link = p;
		l.pHead = p;
	}
}

void add_last(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->link = p;
		l.pTail = p;
		p->link = l.pHead;
	}
}

void show_list(LIST l)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co danh sach" << endl;
	}
	else
	{
		NODE* p = l.pHead;
		int dem = 0;
		do
		{
			dem++;
			cout << "NODE " << dem << ": " << p->data << endl;
			if (p->link == NULL) break;
			p = p->link;
		} while (p != l.pHead);
	}
}

void delete_first(LIST& l)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co danh sach" << endl;
		return;
	}
	else
	{
		if (l.pHead->link == NULL)
		{
			delete l.pHead;
			l.pHead = l.pTail = NULL;
		}
		else
		{
			NODE* h = l.pHead;
			l.pHead = l.pHead->link;
			l.pTail->link = l.pHead;
			delete h;
		}
		cout << "Delete success" << endl;
	}
}


void delete_last(LIST& l)
{
	if (l.pHead == NULL)
	{
		cout << "Chua co dnah sach" << endl;
		return;
	}
	else if (l.pHead->link == NULL)
	{
		delete_first(l);
		cout << "Xoa thanh cong" << endl;
	}
	else
	{
		NODE* p = l.pHead->link;
		NODE* preX = l.pHead;
		while (p != l.pHead)
		{
			NODE* r = p;
			if (p == l.pTail)
			{
				preX->link = l.pHead;
				l.pTail = preX;
				p = p->link;
				delete r;
			}
			else
			{
				preX = p;
				p = p->link;
			}
		}

		cout << "Delete success" << endl;
	}
}

bool search_delete(LIST& l, int vt)
{
	if (l.pHead == NULL)
	{
		return false;
	}
	else if (l.pHead->link == NULL && l.pHead->data == vt)
	{
		delete_first(l);
		return true;
	}
	else   // cần xem lại 
	{
		NODE* p = l.pHead;
		NODE* preX = l.pHead;
		do
		{
			if (p->data == vt)
			{
				NODE* r = p;
				if (l.pHead == p)
				{
					l.pHead = l.pHead->link;
				}
			}
		} while (p != l.pHead);
		
		return true;
	}
}


int main()
{
	LIST l;
	init_list(l);
	int choose;
	do
	{
		cout << "--------------------Circular Linked List---------------------" << endl;
		cout << "1. Them Node                                                 " << endl;
		cout << "2. Duyet danh sach                                          " << endl;
		cout << "3. Them vao dau danh sach                                    " << endl;
		cout << "4. Them vao cuoi danh sach                                 " << endl;
		cout << "5. Xoa dau danh sach                                        " << endl;
		cout << "6. Xoa cuoi danh sach                                      " << endl;
		cout << "7. Tim va xoa phan tu                                       " << endl;
		cout << "8. EXIT                                                    " << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 8) break;
			else
				cout << "Nhap sai lua chon, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Nhap gia tri node: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_last(l, p);
			break;
		}
		case 2:
		{
			show_list(l);
			break;
		}
		case 3:
		{
			int x;
			cout << "Nhap gai tri NODE can them: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_first(l, p);
			cout << "Add success" << endl;
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap gia tri NODE can them: ";
			cin >> x;
			NODE* p = init_NODE(x);
			add_last(l, p);
			cout << "Add success" << endl;
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
			int value;
			cout << "Nhap gia tri can xoa: ";
			cin >> value;
			if (search_delete(l, value))
			{
				cout << "Delete success" << endl;
				system("pause");
				system("cls");
				show_list(l);
			}
			else
				cout << "Khong co danh sach" << endl;
			break;
		}
		case 8:
		{
			if (l.pHead == NULL)
				return 0;
			else
			{

				NODE* current = l.pHead;
				NODE* next = NULL;

					// Traverse the list and delete each node
				while (current != NULL)
				{
					next = current->link;
					delete current;
					current = next;

						// Break the circular link between tail and head when freeing memory
					if (current == l.pHead)
							break;
				}

					// Reset the pointers of the list to NULL
					l.pHead = NULL;
					l.pTail = NULL;

				return 0;
			}
		}
		}
		system("pause");
		system("cls");
	} while (true);

}