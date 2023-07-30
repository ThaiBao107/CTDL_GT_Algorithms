#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* link;
};

struct stack
{
	NODE* pTop;
};

void init_STACK(stack &s)
{
	s.pTop = NULL;
}

NODE* init_NODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}

bool IsEmpty(stack s)
{
	if (s.pTop == NULL) return true;
	return false;
}


void Pop(stack& s)
{
	while (s.pTop != NULL)
	{
		NODE* g = s.pTop;
		s.pTop = s.pTop->link;
		cout << g->data << " ";
		delete g;
	}
}


void add_NODE(stack& s, NODE* p)
{
	if (IsEmpty(s))
	{
		s.pTop = p;
	}
	else
	{
		p->link = s.pTop;
		s.pTop = p;
	}
}

void doinhiphan(stack &s, int x)
{
	while (x != 0)
	{
		int temp = x % 2;
		NODE* p = init_NODE(temp);
		add_NODE(s, p);
		x /= 2;
	}
}



int main()
{
	int n;
	stack s;
	init_STACK(s);
	cout << "Nhap so thap phan: ";
	cin >> n;
	doinhiphan(s, n);
	cout << "So nhi phan sau doi: "; Pop(s);
	return 0;
}