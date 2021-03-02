#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Khoi_Tao(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

NODE* Khoi_Tao_NODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void Them_Cuoi(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void Them_Dau(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void Xuat_DS(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

void menu(LIST& l)
{
	int lc;
	while (true)
	{
		system("cls");
		cout << "\n\t\t ================== MENU ==================";
		cout << "\n\t\t 1. Them gia tri vao danh sach.";
		cout << "\n\t\t 2. Xuat danh sach lien ket don.";
		cout << "\n\t\t 0. Ket Thuc.";
		cout << "\n\t\t ================== END ==================";

		cout << "\n Nhap lua chon: ";
		cin >> lc;
		if (lc == 1)
		{
			int x;
			cout << "\n Nhap gia tri cua NODE: ";
			cin >> x;
			NODE* p = Khoi_Tao_NODE(x);
			Them_Cuoi(l, p);
		}
		else if (lc == 2)
		{
			cout << "\n Cac phan tu cua List: ";
			Xuat_DS(l);
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	LIST l;
	Khoi_Tao(l);
	menu(l);
	return 0;
}