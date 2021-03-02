
/*Khởi tạo DSLKD các số nguyên. Viết chương trình xử lý: 
	Thêm phần tử cho danh sách
	Xuất danh sách
	Săp xếp danh sách giảm dần
	Xuất các phần tử là số đối xứng
	Xóa các phần tử có khóa k bất kì
*/

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
	l.pHead = NULL;
	l.pTail = NULL;
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

//	Hàm thêm phần tử vào sau danh sách
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

//	Hàm xuất danh sách LKD
void Xuat_DS(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

//	Hàm ĐỆ QUY ktra số đối xứng
int kt_Doi_Xung(int n, int dn)
{
	if (n == 0)
	{
		return dn;
	}
	dn = dn * 10 + n % 10;
	return kt_Doi_Xung(n / 10, dn);
}

void Goi_DX(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (kt_Doi_Xung(k->data, 0) == k->data)
		{
			cout << k->data << "   ";
		}
	}
}

//	Hàm hoán vị để sắp xếp danh sách
void Hoan_Vi(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

//	Hàm sắp xếp các phần tử trong danh sách giảm dần
void Giam_Dan(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		for (NODE* j = k->pNext; j != NULL; j = j->pNext)
		{
			if (j->data > k->data)
			{
				Hoan_Vi(j->data, k->data);
			}
		}
	}
}

//	Hàm xóa phần tử đầu tiên trong danh sách
void Xoa_Dau(LIST& l)
{
	NODE* k = l.pHead;
	l.pHead = l.pHead->pNext;
	delete k;
	k = NULL;
}

//	Hàm xóa phần tử cuối cùng trong danh sách
void Xoa_Cuoi(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
		}
	}
}

//	Hàm xóa một khóa k bất kì trong danh sách
void Xoa_Bat_Ki(LIST& l, int x)
{
	if (l.pHead == NULL)
	{
		return;
	}
	if (x == l.pHead->data)
	{
		Xoa_Dau(l);
		return;
	}
	if (x == l.pTail->data)
	{
		Xoa_Cuoi(l);
		return;
	}
	NODE* g = new NODE;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == x)
		{
			g->pNext = k->pNext;
			delete k;
			k = g;	//	Sau khi xóa khóa k trong LIST thì khóa k hiện tại bị mất địa chỉ cần phải cập nhật lại, sau khi cập nhật,
			//   khóa k sẽ là NODE trước nó. Không thể là NODE sau nó vì sau vòng lặp FOR hiện tại thì k cũng sẽ tăng lên một đơn vị -> NODE liền sau 
			//  khóa k cần xóa sẽ bị bỏ qua
		}
		g = k;
	}
}

void menu(LIST& l)
{
	int lc; 
	while (true)
	{
		system("cls");
		cout << "\n\t\t================ MENU ================";
		cout << "\n\t\t 1. Them phan tu vao danh sach.";
		cout << "\n\t\t 2. Xuat danh sach LIEN KET DON.";
		cout << "\n\t\t 3. Xuat cac phan tu la so doi xunng trong danh sach.";
		cout << "\n\t\t 4. Sap xep cac phan tu trong dnh sach giam dan.";
		cout << "\n\t\t 5. Xoa phan tu co khoa k (khoa k la data cua 1 NODE) bat ki.";
		cout << "\n\t\t 0. Ket thuc.";
		cout << "\n\t\t================ END ================";

		cout << "\n Nhap lua chon: ";
		cin >> lc;
		if (lc == 1)
		{
			int x;
			cout << "\n Nhap gia tri cua NODE: ";
			cin >> x;
			NODE* q = Khoi_Tao_NODE(x);
			Them_Cuoi(l, q);
		}
		else if (lc == 2)
		{
			cout << "\n Cac phan tu cua danh sach: ";
			Xuat_DS(l);
			system("pause");
		}
		else if (lc == 3)
		{
			cout << "\n Cac phan tu DOI XUNG cua danh sach: ";
			Goi_DX(l);
			system("pause");
		}
		else if(lc == 4)
		{
			cout << "\n Danh sach sau khi sap xep giam dan: ";
			Giam_Dan(l);
		}
		else if (lc == 5)
		{
			int k;
			cout << "\n Nhap khoa k can xoa: ";
			cin >> k;
			Xoa_Bat_Ki(l, k);
		}
		else
		{
			break;
		}
	}
}

// Hàm giải phóng vùng nhớ cho con trỏ
void Giai_Phong(LIST& l)
{
	NODE* n = NULL;
	while (l.pHead != NULL)
	{
		n = l.pHead;
		l.pHead = l.pHead->pNext;
		delete n;
		n = NULL;
	}
}

int main()
{
	LIST l;
	Khoi_Tao(l);
	menu(l);
	Giai_Phong(l);
	return 0;
}