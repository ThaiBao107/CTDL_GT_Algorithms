#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;


struct information{
    string name;
    int tuoi;
    string code;
};

typedef struct information I;
struct Node
{
    int n;
    I thong_tin;
    Node *link;
};

typedef struct Node NODE;

struct list 
{
    NODE * pHead;
    NODE * pTail;
};

typedef struct list LIST;

void D(LIST &l)
{
    l.pHead =NULL;
    l.pTail=NULL;
}


// Khoi tao NODE

NODE *KhoitaoNode(I thongtin, int x)
{
    NODE * p = new NODE;
    p->n =x;
    p->thong_tin.name = thongtin.name;
    p->thong_tin.code = thongtin.code;
    p->thong_tin.tuoi = thongtin.tuoi;
    p->link =NULL;
    return p;
}

void Them_vao_dau(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->link = l.pHead;
        l.pHead = p;
    }
}

void Them_Vao_Cuoi(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead =l.pTail = p;
    }
    else
    {
        l.pTail->link = p;
        l.pTail = p;
    }
}


void xuatDS(LIST l)
{
    cout<<"| "<<setw(9)<<left<<"Ma code"<<" |"<<setw(17)<<left<<"NAME"<<" |"<<setw(4)<<left<<"TUOI"<<" |"<<endl;
    for(NODE *k = l.pHead; k!=NULL;k=k->link)
    {
        cout<<"| "<<setw(9)<<left<< k->thong_tin.code;
        cout<<" |"<<setw(17)<<left<< k->thong_tin.name;
        cout<<" |"<<setw(4)<<left<< k->thong_tin.tuoi<<" |";
        cout<<endl;
    }
}


// them p vao sau q   // xem lai
// ---------------------------------------------------------
void them_p_vaosau_q(LIST &l,NODE *p)
{
    I t;
    int x;
    cout<<"Nhap node q can them: ";
    cin >> x;
    NODE* q = KhoitaoNode(t,x);
    int count =0;
    // chạy for trước để tìm nốt q cần thêm vào 
    if( q->n == l.pHead->n && l.pHead == NULL)
    {
        Them_Vao_Cuoi(l,p);
    }
    else
    {
    for(NODE *k = l.pHead;k!=NULL;k=k->link)
    {
        if(q ->n == k->n)
        {
            NODE *h = KhoitaoNode(k->thong_tin,k->n);
            NODE *g = k->link;
            h->link = g;
            k->link = h;
            count++;
        }
    }
    }
    if(count != 0) cout<<"Them vao thanh cong"<<endl;
    else
        cout<<"Khong tim thay node q"<<endl;
}

// ---------------------------------------------------------
int main()
{
    LIST l;
    D(l);
    int n;
    do
    {
        cout<<"1. Tao 1 node"<<endl;
        cout<<"2. Xuat Danh sach"<<endl;
        cout<<"3. Them vao dau"<<endl;
        cout<<"4. Them vao p vao sau node q"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Choose: "; 
        while(true)
        {
            cin>> n;
            if(n > 0 && n<=4) break;
            else
                cout<<"Nhap sai: ";
        }
        system("cls");
        switch(n)
        {
            case 1:
                {
                int n;
                I thong_tin;
                cout<<"Nhap node: "; cin >> n;
                cin.ignore();
                cout<<"Nhap MSSV: "; getline(cin,thong_tin.code);
                cout<<"Nhap name: "; getline(cin,thong_tin.name);
                cout<<"Nhap tuoi: "; cin >> thong_tin.tuoi;
                NODE *p = KhoitaoNode(thong_tin,n);
                Them_Vao_Cuoi(l,p);
                break;
                }
            case 2:
                {
                cout<<"THONG TIN SINH VIEN"<<endl;
                // Ma code         NAME         Tuoi
                xuatDS(l);
                break;
                } 

            case 4:
            {
                I thong_tin;
                int n;
                cout<<"Nhap node p: "; cin >> n;
                cin.ignore();
                cout<<"Nhap MSSV: "; getline(cin,thong_tin.code);
                cout<<"Nhap name: "; getline(cin,thong_tin.name);
                cout<<"Nhap tuoi: "; cin >> thong_tin.tuoi;
                NODE *p = KhoitaoNode(thong_tin,n);
                system("cls");
                // ---------------------------------------------
                them_p_vaosau_q(l,p);
                cout<<"-> Nhan enter de xem KQ: ";
                getch();
                system("cls");
                D(l);
            }
            case 5:
                {
                cout<<"Thoat: "<<endl;
                for(NODE *k=l.pHead;k!=NULL;k=k->link)
                {
                    delete k;
                }
                return 0;
                }      
        }
        cout<<"-> Nhap enter de tro ve man hinh chinh: ";
        getch();
        system("cls");
    } while (true);
    
    return 0;
}