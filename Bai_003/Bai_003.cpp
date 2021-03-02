
#include<iostream>
using namespace std;
//	Khai báo biến toàn cục chứa số lượng phần tử trong danh sách.
int n = 0;

struct node
{
	int data;
	struct node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE *pHead;
	NODE *pTail;
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

void Them_Dau(LIST& l, NODE *p)
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

void Xuat_List(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

int Tim_MAX(LIST l)
{
	int lc = l.pHead->data;
	for (NODE* k = l.pHead->pNext; k != NULL; k = k->pNext)
	{
		if (k->data > lc)
		{
			lc = k->data;
		}
	}
	return lc;
}

//	Hàm thêm NODE p vào sau NODE q
void Them_p_sau_q(LIST& l, NODE *p)
{
	int x;
	cout << "\n Nhap gia tri cua Node q: ";
	cin >> x;
	NODE* q = Khoi_Tao_NODE(x);
	//	Nếu trong danh sách chỉ có một Node và giá trị của Node đó bằng node q thì như bài toán thêm Node vào đầu danh sách.
	if (l.pTail->data == q->data && l.pTail == NULL)
	{
		Them_Cuoi(l, p);
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE* h = Khoi_Tao_NODE(p->data);	//	Khởi tạo mới một con trỏ h để giữ giá trị của p để nó cập nhật lai =
			h->pNext = k->pNext;	//  Hiện tại con trỏ pNext của k đang giữ giá trị của Node đứng sau nó (Node đứng sau Node q). 
			k->pNext = h;
		}
	}
}

//	Hàm thêm NODE p vào trước NODE q
void Them_p_truoc_q(LIST& l, NODE* p)
{
	int x;
	cout << "\n Nhap gia tri cua Node q: ";
	cin >> x;
	//	Khởi tạo một node mới chứa giá trị của Node cần biết để thêm Node mới vào sau nó.
	NODE* q = Khoi_Tao_NODE(x);
	//	Nếu trong list chỉ có một phần tử  và phần tử đó bằng Node p thì thêm trước này chính là thêm Node vào đầu danh sách.
	if (l.pHead->data == q->data && l.pHead == NULL)
	{
		Them_Dau(l, p);		//	Gọi hàm thêm Node vào đầu danh sách với đối số l và con trỏ p chứa giá trị cần thêm vào list.
	}
	NODE* g = new NODE;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)	//	Duyệt danh sách từ đầu đến cuối để tìm ra Node đứng trước Node được thêm vào.
	{
		if (k->data == q->data)		//	Nếu giá trị của Node hiện ttai trong vòng lặp bằng với gái trị của Node p
		{
			//	Nếu LIST chứa nhiều ptu và phần tử thêm vào đứng trước phần tử đàu tiên trong danh sách
			if ( k== l.pHead)
			{
				Them_Dau(l, p);
			}
			else
			{
				NODE* h = Khoi_Tao_NODE(p->data);
				h->pNext = k;
				g->pNext = h;
			}
		}
		g = k;	//	Sử dụng NODE g để lưu giá trị của NODE k cảu vòng lặp trước đó để tìm cái NODE mà NODE đó đứng trước NODE cần thêm vào.
	}
}

//	Hàm thêm một Node p vào vị trí bất kì trong List
void Them_Bat_Ki(LIST& l, NODE* p, int vt)
{
	//	Nếu danh sách rỗng thì vị trí thêm vào chính là thêm phần tử vào đầu danh sách.
	if (l.pHead == NULL || vt == 1)
	{
		Them_Dau(l, p);
	}
	//	Nếu phần tử thêm vào ở cuối danh sách thì vị trí đó chính là phần tử thứ n+1.
	else if(vt==n+1)
	{
		Them_Cuoi(l, p);
	}
	//	Nếu không thì tất cả các phần tử còn lại trong đoạn từ 1 đến n.
	else
	{
		//	Khởi tạo biến đếm để lưu giữu vị trí của Node cần thêm vào.	Node đầu tiên sẽ giữ vị trí và 1
		int dem = 1;
		//	Duyệt danh sách từ đầu đến cuối để tìm ra vị trí cần thêm vào.
		NODE* g = new NODE;
		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			//	Khởi tạo một NODE g để lưu giữ giá trị của Node trước Node muốn thêm vào
			//	Nếu biến duyệt vị trí(dem) bằng với vị trí cần thêm NODE vào thì tiến hành thêm Node p vào trước Node q 
			if (dem == vt)
			{
				//	Khởi tạo một NODE p mới sau mỗi vòng lặp để tạo mới địa chỉ(tạo mới NODE q) để không xảy ra lỗi mất dữ liệu khi thêm NODE
				NODE* h = Khoi_Tao_NODE(p->data);
				h->pNext = k;
				g->pNext = h;
				break;
			}
			//	Lưu NODE k của vòng lặp hiện tại để sử dụng cho vòng lap sau
			g = k;
			dem++;
		}
	}
}

//	Hàm xóa NODE đầu danh sách
void Xoa_Dau(LIST& l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	if (l.pHead->pNext == NULL)
	{
		delete l.pHead;
		l.pHead = NULL;
		return;
	}
	NODE* p = l.pHead;	//	Tạo NODE trung gian lưu giá trị của node đầu để xóa
	l.pHead = l.pHead->pNext;	//	Cập nhật lại NODE đầu là NODE kế tiếp
	delete p;
	p = NULL;
}

//	Hàm xóa NODE cuối danh sách
void Xoa_Cuoi(LIST& l)
{
	//	Nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		return;
	}
		//	Nếu danh sách chỉ có một phần tử
	if (l.pHead->pNext == NULL)	//	Cách biểu diễn trong danh sách chỉ có một phần tử (Giá trị mà NODE đầu trỏ đến là NULL -> Danh sách chỉ có một phần tử)
	{
		delete l.pHead;
		l.pHead = NULL;	//	Xóa con trỏ thì phải trả nó về giá trị NULL
		return;
	}
	//	Duyệt từ đầu đến cuối danh sách để tìm ra vị trí áp cuối của danh sách
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)	//	Cách để truy xuất đến NODE áp cuối...
		{
			delete l.pTail;	//	Xóa phần tử cuối trong danh sách
			k->pNext = NULL;	//	Giá trị mà con trỏ của Node áp cuối trỏ đến trả về giá trị NULL ki NODE cuối ko còn tồn tại
			l.pTail = k;	//	Cập nhật NODE cuối mới là NODE k
		}
	}
}

//	Hàm xóa một NODE đứng sau NODE q cho trước 
void Xoa_Sau_q(LIST& l, NODE *q)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE* g = k->pNext;	//	Tạo một NODE mới trung gian để lưu giá trị của NODE cần xóa (NODE cần xóa là k->pNext)
			k->pNext = g->pNext;	//	Khởi tạo mối liên kết của NODE k(NODE trước NODE cần xóa) với NODE sau NODE cần xóa(g->pNext)
			delete g; //	Xóa NODE g
		}
	}
	if (q == l.pTail)
	{
		return;
	}
}

//	Hàm xóa một phần tử trước NODE q trong danh sách.
void Xoa_Truoc_q(LIST& l, NODE* q)
{
	NODE* g = new NODE;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		//	Nếu giá trị của phần tử mà k đag trỏ tới (phần tử nằm kế tiếp liền sau k) bằng với dữ liệu của q cần xóa.
		if ((k->pNext)->data == q->data)
		{
			//if (k == l.pHead)	// Lúc k là pHead thì dữ liệu mà cn trỏ k đag trỏ tới đúng bằng dữ liệu q cần xóa.
			//{
			//	//	Gọi lại hàm xóa phần tử đầu tiên danh sách.
			//	Xoa_Dau(l);
			//	return;
			//}
			//else
			//{
			g->pNext = k->pNext;
			delete k;
			k = g;
			//}
		}  
		g = k;
	}
}

//	Hàm xóa phần tử tại vị trí bất kì trong danh sách
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
			k = g;	//	Sau khi xóa khóa k trong LIST thì khóa k hiện tại bị mất địa chỉ cần phải cập nhật lại. Sau khi cập nhật,
			//   khóa k sẽ là NODE trước nó. Không thể là NODE sau nó vì sau vòng lặp FOR hiện tại thì k cũng sẽ tăng lên một đơn vị -> NODE liền sau 
			//  khóa k cần xóa sẽ bị bỏ qua
		}
		g = k;
	}
}

void menu(LIST l)
{
	int lc;
	while (true)
	{
		system("cls");
		cout << "\n\t\t ================== MENU ==================";
		cout << "\n\t\t 1. Them gia tri vao danh sach."; 
		cout << "\n\t\t 2. Xuat danh sach lien ket don.";
		cout << "\n\t\t 3. Tim gia tri LON NHAT trong danh sach.";
		cout << "\n\t\t 4. Them Node p vao SAU Node q.";
		cout << "\n\t\t 5. Them Node p vao TRUOC Node q.";
		cout << "\n\t\t 6. Them Node p vao vi tri BAT KI trong danh sach.";
		cout << "\n\t\t 7. Xoa phan tu DAU TIEN trong danh sach.";
		cout << "\n\t\t 8. Xoa phan tu CUOI CUNG trong danh sach.";
		cout << "\n\t\t 9. Xoa phan tu Sau NODE q trong danh sach.";
		cout << "\n\t\t 10. Xoa phan tu Truoc NODE q trong danh sach.";
		cout << "\n\t\t 11. Xoa khoa k BAT KI trong danh sach.";
		cout << "\n\t\t 0. Ket thuc.";
		cout << "\n\t\t ================== END ==================";

		cout << "\n Nhap lua chon cua ban: ";
		cin >> lc;
		
		if (lc == 1)
		{
			int x;
			cout << "\n Nhap gia tri can them vao list: ";
			cin >> x;
			NODE* p = Khoi_Tao_NODE(x);
			Them_Cuoi(l, p);
		}
		else if (lc == 2)
		{
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			system("pause");
		}
		else if (lc == 3)
		{
			cout << "\n TIM GIA TRI LON NHAT TRONG DANH SACH. " << endl;
			cout << "\n Gia tri lon nhat cua list la: " << Tim_MAX(l);
			system("pause");
		}
		else if (lc == 4)
		{
			cout << "\n============== THEM NODE P SAU NODE Q VAO DANH SACH ================" << endl;
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			int x;
			cout << "\n Nhap gia tri x cua node p: ";
			cin >> x;
			NODE* p = Khoi_Tao_NODE(x);
			Them_p_sau_q(l, p);
		}
		else if (lc == 5)
		{
			cout << "\n============== THEM NODE P TRUOC NODE Q VAO DANH SACH ================" << endl;
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			int x;
			cout << "\n Nhap gia tri x cua node p: ";
			cin >> x;
			NODE* p = Khoi_Tao_NODE(x);
			Them_p_truoc_q(l, p);
		}
		else if (lc == 6)
		{
			cout << "\n============== THEM MOT PHAN TU BAT KI VAO DANH SACH ================" << endl;
			/*int n = 0;
			*
			//			===>   VÒNG LẶP LẤY SỐ LƯỢNG NODE TRONG DANH SÁCH   <===

			for (NODE* k = l.pHead; k != NULL; k = k->pNext)
			{
				n++;
			}*/

			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			int x, vt;
			//	Khởi tạo gái trị cho Node p cần thêm vào
			cout << "\n Nhap gia tri x cua node p: ";
			cin >> x;
			NODE* p = Khoi_Tao_NODE(x);
			//	Khởi tạo vị trí của NODE p
			do
			{
				cout << "\n Nhap vi tri cua NODE p can them vao danh sach: ";
				cin >> vt;
				if (vt < 1 || vt >(n + 1))
				{
					cout << "\n Vi tri can them phai nam trong doan [1:" << n + 1 << "]. " << endl;
					// system("pause");
				}
			} while (vt < 1 || vt >(n + 1));
			Them_Bat_Ki(l, p, vt);
		}
		else if (lc == 7)
		{
			cout << "\n============== XOA NODE DAU TIEN TRONG DANH SACH ================" << endl;
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			Xoa_Dau(l);
		}
		else if (lc == 8)
		{
			cout << "\n============== XOA PHAN TU CUOI CUNG TRONG DANH SACH ================" << endl;
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			Xoa_Cuoi(l);
		}
		//	Xóa NODE sau NODE q trong danh sách.
		else if (lc == 9)
		{
			cout << "\n============== XOA MOT PHAN TU SAU NODE Q TRONG DANH SACH ================" << endl;
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			int x;
			cout << "\n Nhap gia tri cua NODE q: ";
			cin >> x;
			NODE* q = Khoi_Tao_NODE(x);
			Xoa_Sau_q(l, q);
		}
		//	Xóa NODE trước NODE q trong danh sách.
		else if (lc == 10)
		{
			cout << "\n============== XOA MOT PHAN TU TRUOC NODE Q TRONG DANH SACH ================" << endl;
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			int x;
			cout << "\n Nhap gia tri cua NODE q: ";
			cin >> x;
			NODE* q = Khoi_Tao_NODE(x);
			Xoa_Truoc_q(l, q);
		}
		else if (lc == 11)
		{
			cout << "\n============== XOA MOT PHAN TU BAT KI TRONG DANH SACH ================" << endl;
			cout << "\n Cac phan tu trong list la: ";
			Xuat_List(l);
			int x;
			cout << "\n Nhap gia tri cua NODE q: ";
			cin >> x;
			Xoa_Bat_Ki(l, x);
		}
		else 
		{
			break;
		}
	}
}

void Giai_Phong(LIST& l)
{
	NODE* k = new NODE;
	while (l.pHead != NULL)
	{
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
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