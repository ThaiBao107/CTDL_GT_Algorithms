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
		if(k != l.pTail)
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

void Insertion_sort(LIST& l)
{

}

int main()
{

}