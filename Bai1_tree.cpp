#include<iostream>
#include<cmath>
using namespace std;
int dem = 0;
int dem_TBC = 0;
int TBC = 0;
int tong = 0;

struct NODE
{
	int data;
	NODE* left;
	NODE* right;
};

void init_ROOT(NODE*& r)
{
	r = NULL;
}
void add_NODE(NODE*& r, int x)
{
	if (r == NULL)
	{
		r = new NODE;
		r->data = x;
		r->left = NULL;
		r->right = NULL;
	}
	else
	{
		if (r->data == x) return;
		else if (x > r->data) return add_NODE(r->right, x);
		else
			return add_NODE(r->left, x);
	}
}

NODE *search(NODE *r,int x)
{
	if (r != NULL)
	{
		if (r->data == x)
			return r;
		else
		{
			if (x > r->data) return search(r = r->right, x);
			else
		return search(r=r->left, x);
		}
	}
	return NULL;
}


void searchStandFor(NODE*& p, NODE*& q)
{
	if (q->left == NULL)
	{
		p->data == q->data;
		p = q;
		q = q->right;
	}
	else
	{
		searchStandFor(p, q->left);
	}
}
int delte_NODE(NODE *&r, int x)
{
	if (r == NULL) return 0;
	if (r->data == x)
	{
		NODE* p = r;
		if (r->left == NULL)
			r = r->right;
		else if (r->right == NULL)
			r = r->left;
		else
			searchStandFor(p, r->right);
		delete p;
		return 1;
	}
	if (r->data < x) return delte_NODE(r->right, x);
	if (r->data > x) return delte_NODE(r->left, x);
}


void duyet_NLR(NODE* r)
{
	if (r!= NULL)
	{
		cout << r->data << " ";
		duyet_NLR(r->left);
		duyet_NLR(r->right);
	}
}


void duyet_LNR(NODE *r)
{
	if (r != NULL)
	{
		duyet_LNR(r->left);
		cout << r->data << " ";
		duyet_LNR(r->right);
	}
}


void duyet_LRN(NODE* r)
{
	if (r != NULL)
	{
		duyet_LRN(r->left);
		duyet_LRN(r->right);
		cout << r->data << " ";
	}
}

void dem_pt(NODE *r)
{
	if (r != NULL)
	{
		dem_pt(r->left);
		dem_pt(r->right);
		dem++;
	}
}


void dem_tb(NODE *r)
{
	if (r != NULL)
	{
		dem_tb(r->left);
		dem_tb(r->right);
		dem_TBC++;
		tong += r->data;
	}
}

int dem_nt = 0;


bool check_nguyento(int x)
{
	if (x < 2) return false;
	else
	{
		for (int i = 2; i <= sqrt(x*1.0);i++)
		{
			if (x % i == 0) return false;
		}
	}
	return true;
}

void dem_nguyento(NODE *r)
{
	if (r != NULL)
	{
		dem_nguyento(r->left);
		dem_nguyento(r->right);
		if (check_nguyento(r->data) == true) dem_nt++;
	}
}

int main()
{
	NODE* root;
	init_ROOT(root);
	int choose;
	do
	{
		cout << "------------------------------MENU-----------------------------------" << endl;
		cout << "1. Them mot node vao cay                                            " << endl;
		cout << "2. Tim mot node                                                     " << endl;
		cout << "3 Xoa mot node                                                      " << endl;
		cout << "4 Duyet NLR                                                          " << endl;
		cout << "5 duyet LNR                                                         " << endl;
		cout << "6Duyet LRN                                                          " << endl;
		cout << "7 Dem so phan tu                                                    " << endl;
		cout << "8 TInh trung binh cong cac phan tu                                 " << endl;
		cout << "9 Tim gia tri lon nhat                                             " << endl;
		cout << "10Dem so nguyrn to trong cay                                      " << endl;
		cout << "11. EXIT                                                   " << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 11) break;
			else
				cout << "nhap sai, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			int n;
			cout << "Nhap gai tri NODE can them: "; cin >> n;
			add_NODE(root, n);
			break;
		}
		case 2:
		{
			if (root == NULL)
				cout << "Chua co phan tu trong cay" << endl;
			else
			{
				int x;
				cout << "Nhap so cna tim trong cay: " << endl;
				cin >> x;
				if (search(root, x) == NULL) cout << "NODE can tim khong co torng cay" << endl;
				else
				{
					cout << "NODE can tim cos trong cay" << endl;
				}
			}
			break;
		}
		case 3:
		{
			if (root == NULL) cout << "Chua co phan tu trong cay" << endl;
			else
			{
				int x;
				cout << "Nhap node can xoa: "; cin >> x;
				if (delte_NODE(root, x) == 0) cout << "NODE can xoa khong co trong cay" << endl;
				else
					cout << "xoa thanh cong" << endl;
			}
			break;
		}
		case 4:
		{
			if (root == NULL) cout << "Chua co phan tu trong cay" << endl;
			else
			{
				duyet_NLR(root);
			}
			break;
		}
		case 5:
		{
			if (root == NULL) cout << "Chua co phan tu trong cay" << endl;
			else
			{
				duyet_LNR(root);
			}
			break;
		}
		case 6:
		{
			if (root == NULL) cout << "Chua co phan tu trong cay" << endl;
			else
			{
				duyet_LRN(root);
			}
			break;
		}
		case 7:
		{
			if (root == NULL) cout << "Chua co phan tu trong cay" << endl;
			else
			{
				dem_pt(root);
				cout << "Sp phan tu trong cay: " << dem << endl;
				dem = 0;
			}
			break;
		}
		case 8:
		{
			if (root == NULL) cout << "Chua co phan tu trong cay" << endl;
			else
			{
				dem_tb(root);
				cout << "TBC: " << tong / dem_TBC << endl;
				tong = 0;
				dem_TBC = 0;
			}
			break;
		}
		case 9:
		{
			cout << "chua lam" << endl;
			break;
		}
		case 10:
		{
			if (root == NULL) cout << "Chua co phan tu trong cay" << endl;
			else
			{
				dem_nguyento(root);
				cout << "So luong snt trong cay: " << dem_nt << endl;
				dem_nt = 0;
			}
			break;
		}
		case 11:
		{
			return 0;
		}
		}
		system("pause");
		system("cls");
	} while (true);
}