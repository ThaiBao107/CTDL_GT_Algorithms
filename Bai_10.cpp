#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* link;
};

struct stack
{
	NODE* sTop;
};

NODE* init_NODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}

void init_Stack(stack& s)
{
	s.sTop = NULL;
}

bool IsEmpty(stack s)
{
	if (s.sTop == NULL) return true;
	return false;
}

void Push(stack& s, NODE* p)
{
	if (IsEmpty(s))
		s.sTop = p;
	else
	{
		p->link = s.sTop;
		s.sTop = p;
	}
}

void Pop(stack& s, int option)
{
	if (option == 16)
	{
		while (s.sTop != NULL)
		{
			NODE* g = s.sTop;
			s.sTop = s.sTop->link;
			switch (g->data)
			{
			case 10:
			{
				cout << "A" << " ";
				break;
			}
			case 11:
			{
				cout << "B" << " ";
				break;
			}
			case 12:
			{
				cout << "C" << " ";
				break;
			}
			case 13:
			{
				cout << "D" << " ";
				break;
			}
			case 14:
			{
				cout << "E" << " ";
				break;
			}
			case 15:
			{
				cout << "F" << " ";
				break;
			}
			default:
				cout << g->data << " ";
			}
			delete g;
		}
		return;
	}
	while (s.sTop != NULL)
	{
		NODE* g = s.sTop;
		s.sTop = s.sTop->link;
		cout << g->data << " ";
		delete g;
	}
}

// change
void change(stack& s, int x, int option)
{
	while (x != 0)
	{
		int temp = x % option;
		NODE* p = init_NODE(temp);
		Push(s, p);
		x /= option;
	}
}



int main()
{
	int x, option;
	stack s;
	init_Stack(s);
	cout << "Nhap so can doi: "; cin >> x;
	cout << "Nhap he so can doi: "; cin >> option;
	change(s, x, option);
	cout << "So sau khi doi: "; Pop(s, option);
	return 0;
}