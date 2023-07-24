#include<iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* left;
	NODE* right;
};

void tree_empty(NODE* &root)
{
	root = NULL;
}

NODE *search(NODE* root, int x)
{
	NODE* p = root;
	while (p != NULL)
	{
		if (p->data == x)
			return p;
		else if (x < p->data)
			p = p->left;
		else
		{
			p = p->right;
		}
	}
	return NULL;

}

void add_NODE(NODE*& root, int x)
{
	NODE* p = root;
	do
	{
		if (p == NULL)
		{
			p = new NODE;
			p->data = x;
			p->left = NULL;
			p->right = NULL;
		}
		else
		{
			if (x < p->data) p = p->left;
			else
				p = p->right;
		}
	} while (true);
}

void duyetDS(NODE* p)
{
	if (p != NULL)
	{
		duyetDS(p->left);
		cout << p->data << " ";
		duyetDS(p->right);
	}
}

void FreeBinaryTree(NODE *node) 
{
	if (node == nullptr) {
		return;
	}

	// Giải phóng các cây con bên trái và bên phải
	FreeBinaryTree(node->left);
	FreeBinaryTree(node->right);

	// Giải phóng nút hiện tại
	delete node;
}
int main()
{
	NODE* root;
	tree_empty(root);
	int choose;
	do
	{
		cout << "----------------------MENU--------------------------" << endl;
		cout << "1. Them node vao root                               " << endl;
		cout << "2. Tim kiem phan tu trong binary tree               " << endl;
		cout << "3. duyet danh sach                                  " << endl;
		cout << "4. EXIT                                             " << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 4) break;
			else
				cout << "nhap sai, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Nhap gia tri cua no: "; cin >> x;
			add_NODE(root, x);
			break;
		}
		case 2:
		{
			int x;
			cout << "Nhap gia tri can tim kiem: ";
			cin >> x;
			if (search(root, x) != NULL)
				cout << "Phan tu can tim co trong danh sach" << endl;
			else
				cout << "Phan tu can tim khong co trong danh sach" << endl;
			break;
		}
		case 3:
		{
			cout << "DUYET DANH SACH" << endl;
			duyetDS(root);
			cout << endl;
			break;
		}
		case 4:
		{
			if (root == NULL) return 0;
			else
			{
				FreeBinaryTree(root);
				return 0;
			}
		}
		}
		system("pause");
		system("cls");
	} while (true);
}