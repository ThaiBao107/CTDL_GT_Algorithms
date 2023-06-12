#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;
int n=0;

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

void DanhSach(LIST &l);
NODE *KhoitaoNode(I thongtin, int x);
void Them_vao_dau(LIST &l, NODE *p);
void Them_Vao_Cuoi(LIST &l, NODE *p);
void xuatDS(LIST l);
void them_p_vaosau_q(LIST &l,NODE *p);
void them_p_vaotruoc_q(LIST &l, NODE * p);
void them_vao_VT_batki(LIST &l, NODE *p, int vt);
void xoa_dau(LIST &l);
void xoa_cuoi(LIST &l);
void DanhSach(LIST &l)
{
    l.pHead =NULL;
    l.pTail=NULL;
}


// Khoi tao NODE

NODE *KhoitaoNode(I thongtin, int x)
{
    NODE * p = new NODE;
    p->n =  x;
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
    
    I i;
    int x;
    cout<<"Nhap node q can them: ";
    cin >> x;
    NODE * q = KhoitaoNode(i,x);
    int count =0;
    // chạy for trước để tìm nốt q cần thêm vào 
    if( q->n == l.pHead->n && l.pHead->link == NULL)
    {
        Them_Vao_Cuoi(l,p);
    }
    else
    {
    for(NODE *k = l.pHead;k!=NULL;k=k->link)
    {
        if(q->n == k->n)
        {
            NODE *h = KhoitaoNode(p->thong_tin,p->n);
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


// them node p vao truoc node q
//---------------------------------------------------------
void them_p_vaotruoc_q(LIST &l, NODE * p)
{
    I i;
    int x;
    int count =0;
    cout<<"Nhap node q: ";
    cin >> x;
    NODE *q =KhoitaoNode(i,x);
    // kiem tra du lieu cua node q
    if(q->n == l.pHead->n && l.pHead->link == NULL)
    {
        Them_vao_dau(l,p);
    }
    else
    {
        NODE *g = new NODE;
        for(NODE *k = l.pHead;k!=NULL;k=k->link)
        {
            if(q->n == k->n)
            {
            NODE *h = KhoitaoNode(p->thong_tin,p->n); // sao chep du lieu tu p sang h
            h->link = k;
            g->link = h;
            count++;
            }
        g=k; // update lai vi tri cua node truoc q
        }   
    }

    if(count == 0)
    {
        cout<<"Khong co node q can them"<<endl;
    }
    else
    {
        cout<<"Them thanh cong"<<endl;
    }
}
// --------------------------------------------------------

// them vao vi tri bat ki
// --------------------------------------------------------
void them_vao_VT_batki(LIST &l, NODE *p, int vt)
{
    if(l.pHead == NULL || vt == 1)
    {
        Them_vao_dau(l,p);
    }
    else if(vt == n+1)
    {
        Them_Vao_Cuoi(l,p);
    }
    else
    {
        NODE *g= new NODE;
        int dem =0;
        for(NODE *k=l.pHead; k!=NULL;k=k->link)
        {
            dem++;
            if(dem == vt)
            {
                NODE *h = KhoitaoNode(p->thong_tin,p->n);
                h->link = k;
                g->link = h;
                break;
            }
            g=k;
        }
    }

}
//-------------------------------------------------------- 

// xoa dau danh sach
// -------------------------------------------------------
void xoa_dau(LIST &l)
{
    if(l.pHead == NULL) // chua co danh sach
    {
        return ;
    }
    else
    {
        NODE *p= l.pHead;
        l.pHead = l.pHead->link;
        delete p;
    }
}

void xoa_cuoi(LIST &l)
{
    if(l.pHead == NULL)
    {
        return ;
    }
    else if(l.pHead->link == NULL)
    {
        xoa_dau(l);
        return ;
    }
    else
    {
        for(NODE *k=l.pHead;k!=NULL;k=k->link)
        {
            if(k->link == l.pTail)
            {
                delete l.pTail;
                k->link = NULL; // dua con tro sat cuoi bang NULL 
                l.pTail = k;  // l.pTail luon la NULL khi o cuoi danh sach
            }

        }

    }
}
// -------------------------------------------------------


int main()
{
    LIST l;
    DanhSach(l);
    int m;
    do
    {
        cout<<"1. Tao 1 node"<<endl;
        cout<<"2. Xuat Danh sach"<<endl;
        cout<<"3. Them p vao truoc node q"<<endl;
        cout<<"4. Them p vao sau node q"<<endl;
        cout<<"5. Them vao vi tri bat ki"<<endl;
        cout<<"6. Xoa dau danh sach"<<endl;
        cout<<"7. Xoa cuoi danh sach"<<endl;
        cout<<"8. EXIT"<<endl; 
        cout<<"Choose: "; 
        while(true)
        {
            cin>> m;
            if(m > 0 && m<=8) break;
            else
                cout<<"Nhap sai: ";
        }
        system("cls");
        switch(m)
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

            case 3:
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
                them_p_vaotruoc_q(l,p);
                cout<<"-> Nhan enter de xem KQ: ";
                getch();
                system("cls");
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
                xuatDS(l);
                break;
            }

            case 5:
            {
                for(NODE *k=l.pHead; k!=NULL;k=k->link)
                    n++;
                
                cout << n<<endl; 
                I thong_tin;
                int x;
                int vt;
                cout<<"Nhap node p: "; cin >> x;
                cin.ignore();
                cout<<"Nhap MSSV: "; getline(cin,thong_tin.code);
                cout<<"Nhap name: "; getline(cin,thong_tin.name);
                cout<<"Nhap tuoi: "; cin >> thong_tin.tuoi;
                NODE *p = KhoitaoNode(thong_tin,x);
                system("cls");
                // ---------------------------------------------
                cout<<"Nhap vao vi tri can them: ";

                while(true)
                {
                    cin >> vt;
                    if(vt > 0 && vt <= n+1) break;
                    else
                        cout<<"Nhap sai, hoat dong trong [1,"<<n+1<<"]: ";
                }

                them_vao_VT_batki(l,p,vt);
                cout<<"Them vao thanh cong"<<endl;
                cout<<"-> Nhan enter de xem KQ: "; 
                getch();
                system("cls");
                // -------------------------------------
                xuatDS(l);
                break;
            }
            case 6:
                {
                    xoa_dau(l);
                    cout<<"Xoa thanh cong"<<endl;
                    cout<<"-> Nhan enter de xem KQ: ";
                    getch();
                    system("cls");
                    // ----------------------------------------
                    xuatDS(l);
                    break;
                }

            case 7:
                {
                    xoa_cuoi(l);
                    cout<<"Xoa thanh cong"<<endl;
                    cout<<"-> Nhan enter de xem KQ: ";
                    getch();
                    system("cls");
                    // ----------------------------------------
                    xuatDS(l);
                    break;
                }
                
            case 8:
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
    } while(true);
    
    return 0;
}