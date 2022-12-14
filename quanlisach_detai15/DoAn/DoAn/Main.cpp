#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>



// =============== KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN ===============
// Khai báo cấu trúc dữ liệu book
struct book
{
	int maSach;
	string tenSach;
	string tacGia;
	string nhaXuatBan;
	int namXuatBan;
	string theloai;
};
typedef struct book Book;

// Khai báo cấu trúc 1 node
struct bookNode
{
	Book data; // Dữ liệu chứa trong 1 node - 1 cuốn sách
	struct bookNode *pNext; // con trỏ dùng để liên kết các node với nhau
};
typedef struct bookNode BookNode;

// Khai báo cấu trúc danh sách liên kết đơn
struct listBook
{
	BookNode *pHead; // node quản lý đầu danh sách
	BookNode *pTail; // node quản lý cuối danh sách
};
typedef struct listBook ListBook;

// =============== KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN ===============
void khoiTao(ListBook &list) {
	list.pHead = NULL;
	list.pTail = NULL;
}

// Hàm khởi tạo 1 node
BookNode *khoiTaoBookNode(Book b) {
	BookNode *p = new BookNode; // cấp phát vùng nhớ cho node p
	p->data = b;
	p->pNext = NULL;
	return p;
}

// =============== TIỆN ÍCH ==================
// Hàm chuyển 1 string về chữ thường => để so sánh chuỗi không phân biệt hoa thường
string toLower(string s) {
	string str;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s.at(i);
		str.push_back(tolower(c));
	}
	return str;
}

// Hàm so sánh 2 chuỗi không phân biệt hoa thường
bool kiemTraChuoi(string s1, string s2) {
	string s3 = toLower(s1);
	string s4 = toLower(s2);
	if (s3.compare(s4) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Hàm kiểm tra chuỗi s1 có chứa chuỗi s2 không
bool checkStr(string s1, string s2) {
	string s3 = toLower(s1);
	string s4 = toLower(s2);
	if (strstr(s3.c_str(), s4.c_str()) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Hàm hiển thị tiêu đề
void showTieuDe() {
	string str = " -----------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout << setw(10) << "Ma sach" << setw(55) << "Ten sach" << setw(35) << "Tac gia" << setw(30) << "Nha xuat ban" << setw(10) << "NXB" << setw(25)<< "The loai" << endl;
	cout << str << endl;
}

// Hàm hiển thị 1 cuốn sách
void showBook(Book b) {
	string str = " ------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

		cout << setw(10) << b.maSach << setw(55) << b.tenSach << setw(35) << b.tacGia << setw(30) << b.nhaXuatBan << setw(10) << b.namXuatBan << setw(25)<<b.theloai << endl;
		cout << str << endl;
	
}

// =============== 2. THÊM 1 CUỐN SÁCH VÀO DANH SÁCH ===============
// Hàm kiểm tra mã có trùng hay không
bool checkMa(int ma, ListBook list) {
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext) {
		if (k->data.maSach == ma)
		{
			return true;
		}
	}
	return false;
}

// Hàm nhập giá trị 1 cuốn sách
BookNode *nhap(Book b, ListBook list) {
	do
	{
		cout << " Nhap ma sach: ";
		cin >> b.maSach;
	} while (checkMa(b.maSach, list) || b.maSach <= 0);
	cin.ignore();
	cout << " Nhap ten sach: ";
	getline(cin, b.tenSach);
	cout << " Nhap tac gia: ";
	getline(cin, b.tacGia);
	cout << " Nhap nha xuat ban: ";
	getline(cin, b.nhaXuatBan);
	cout << " Nhap nam xuat ban: ";
	cin >> b.namXuatBan;
	cin.ignore();
	cout << " Nhap the loai sach: ";
	getline(cin, b.theloai);
	BookNode *p = khoiTaoBookNode(b);
	return p;
}

// Hàm thêm 1 sách vào đầu danh sách
void InsertFirst(ListBook &list, BookNode *p) {
	// danh sách đang rỗng
	if (list.pHead == NULL)
	{
		list.pHead = list.pTail = p; // node đầu cũng là node cuối và là p
	}
	else
	{
		p->pNext = list.pHead;
		list.pHead = p;
	}
}

// Hàm thêm 1 sách vào cuối danh sách
void InsertLast(ListBook &list, BookNode *p) {
	// danh sách đang rỗng
	if (list.pHead == NULL)
	{
		list.pHead = list.pTail = p; // node đầu cũng là node cuối và là p
	}
	else
	{
		list.pTail->pNext = p;
		list.pTail = p;
	}
}

// Hàm thêm 1 sách vào sau 1 cuốn sách nào đó
void InsertAfter(ListBook &list, BookNode *p) {
	int ma;
	cout << "\n Ban muon them vao sau cuon sach nao? Nhap ma sach: ";
	cin >> ma;
	if (list.pHead == NULL)
	{
		list.pHead = list.pTail = p;
		return;
	}
	if (list.pHead->data.maSach == ma && list.pHead->pNext == NULL)
	{
		InsertLast(list, p);
	}
	else
	{
		for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.maSach == ma)
			{
				BookNode *g = k->pNext; // cho node g trỏ đến node nằm sau node q
				p->pNext = g;
				k->pNext = p;
			}
		}
	}
}

// =============== 1. KHỞI TẠO DANH SÁCH ===============
// Khởi tạo danh mục sách rỗng (chưa có sách)
// Đọc từ file: nhập vào tên file đã lưu danh mục sách ở lần làm việc trước đó
void docMotSach(ifstream &filein, Book &b) {
	string ma = to_string(b.maSach);
	getline(filein, ma, ';');
	b.maSach = atoi(ma.c_str());
	getline(filein, b.tenSach, ';');
	getline(filein, b.tacGia, ';');
	getline(filein, b.nhaXuatBan, ';');
	string nam = to_string(b.namXuatBan);
	getline(filein, nam, ';');
	b.namXuatBan = atoi(nam.c_str());
	getline(filein, b.theloai, ';');
	string temp1;
	getline(filein, temp1);


}

void docFile(ifstream &filein, ListBook &list) {
	while (!filein.eof())
	{
		Book b;
		docMotSach(filein, b);
		BookNode *p = khoiTaoBookNode(b);
		InsertLast(list, p);
	}
}

// Hàm kiểm tra file có tồn tại hay không
bool checkFile(string path) {
	ifstream isf(path);
	return isf.good();
}

// =============== 3. XOÁ 1 CUỐN SÁCH KHỎI DANH SÁCH ===============
// Xoá cuốn sách ở đầu danh sách
void deleteFirst(ListBook &list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	BookNode *p = list.pHead; // node p là node sẽ xoá
	list.pHead = list.pHead->pNext; // cập nhật lại pHead là phần tử kế tiếp (thứ 2)
	delete p;
	cout << " Xoa thanh cong!" << endl;
}

// Xoá cuốn sách ở cuối danh sách
void deleteLast(ListBook &list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	// trường hợp danh sách có 1 phần tử
	if (list.pHead->pNext == NULL)
	{
		deleteFirst(list);
		return;
	}
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		// nếu node k là phần tử kế cuối - thực hiện xoá
		if (k->pNext == list.pTail)
		{
			delete list.pTail; // xoá đi phần tử cuối danh sách
			k->pNext = NULL; // cho con trỏ của node kế cuối trỏ đến null
			list.pTail = k; // cập nhật lại pTail
			cout << " Xoa thanh cong!" << endl;
			return;
		}
	}
}

// Xoá cuốn sách ở sau cuốn sách có mã số nào đó
void deleteAfter(ListBook &list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	if (list.pHead->pNext == NULL)
	{
		cout << " Danh sach chi co 1 phan tu!" << endl;
		return;
	}
	int ma;
	cout << " Ban muon xoa sach o sau cuon sach nao? Nhap ma sach: ";
	cin >> ma;
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.maSach == ma)
		{
			BookNode *g = k->pNext; // node g là node nằm sau node k - xoá node g
			k->pNext = g->pNext; // cập nhật liên kết giữ node k với node sau node g
			delete g;
			cout << " Xoa thanh cong!" << endl;
			return;
		}
	}
}

// Xoá cuốn sách theo mã số
void deleteMa(ListBook &list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	int ma;
	cout << " Nhap ma sach can xoa: ";
	cin >> ma;
	// trường hợp mã sách nhập vào nằm đầu danh sách
	if (list.pHead->data.maSach == ma)
	{
		deleteFirst(list);
		return;
	}
	// trường hợp mã sách nhập vào nằm cuối danh sách
	if (list.pTail->data.maSach == ma)
	{
		deleteLast(list);
		return;
	}
	BookNode *g = new BookNode; // node g là node trỏ đến node nằm trước node cần xoá
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.maSach == ma)
		{
			g->pNext = k->pNext; // cập nhật liên kết giữ node g với node sau node k
			delete k;
			cout << " Xoa thanh cong!" << endl;
			return;
		}
		g = k; // cho node g trỏ đến node k
	}
	cout << " Ma ban nhap khong co trong danh sach!" << endl;
}

void deleteMa2(ListBook &list, int ma) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	// trường hợp mã sách nhập vào nằm đầu danh sách
	if (list.pHead->data.maSach == ma)
	{
		deleteFirst(list);
		return;
	}
	// trường hợp mã sách nhập vào nằm cuối danh sách
	if (list.pTail->data.maSach == ma)
	{
		deleteLast(list);
		return;
	}
	BookNode *g = new BookNode; // node g là node trỏ đến node nằm trước node cần xoá
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.maSach == ma)
		{
			g->pNext = k->pNext; // cập nhật liên kết giữ node g với node sau node k
			delete k;
			cout << " Xoa thanh cong!" << endl;
			return;
		}
		g = k; // cho node g trỏ đến node k
	}
	cout << " Ma ban nhap khong co trong danh sach!" << endl;
}

// Xoá cuốn sách theo tên sách
void deleteTenSach(ListBook &list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	cin.ignore();
	string tenSach;
	cout << " Nhap ten sach can xoa: ";
	getline(cin, tenSach);
	// trường hợp tên sách nhập vào nằm đầu danh sách
	if (kiemTraChuoi(list.pHead->data.tenSach, tenSach))
	{
		deleteFirst(list);
	}
	// trường hợp tên sách nhập vào nằm cuối danh sách
	if (kiemTraChuoi(list.pTail->data.tenSach, tenSach))
	{
		deleteLast(list);
	}
	int test = 0;
	BookNode *g = new BookNode; // node g là node trỏ đến node nằm trước node cần xoá
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (kiemTraChuoi(k->data.tenSach, tenSach))
		{
			test++;
			g->pNext = k->pNext; // cập nhật liên kết giữ node g với node sau node k
			delete k;
			k = g; // cập nhật lại k
		}
		g = k; // cho node g trỏ đến node k
	}
	if (test == 0) {
		cout << " Ten sach ban nhap khong co trong danh sach!" << endl;
	}
	else
	{
		cout << " Xoa thanh cong sach: " << tenSach << "!" << endl;
	}
}

// Xoá sách theo tên tác giả (Xoá tất cả)
void deleteTenTacGia(ListBook &list, string tenTacGia) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	// trường hợp tên sách nhập vào nằm đầu danh sách
	if (kiemTraChuoi(list.pHead->data.tacGia, tenTacGia))
	{
		deleteFirst(list);
	}
	// trường hợp tên sách nhập vào nằm cuối danh sách
	if (kiemTraChuoi(list.pTail->data.tacGia, tenTacGia))
	{
		deleteLast(list);
	}
	int test = 0;
	BookNode *g = new BookNode; // node g là node trỏ đến node nằm trước node cần xoá
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (kiemTraChuoi(k->data.tacGia, tenTacGia))
		{
			test++;
			g->pNext = k->pNext; // cập nhật liên kết giữ node g với node sau node k
			delete k;
			k = g; // cập nhật lại k
		}
		g = k; // cho node g trỏ đến node k
	}
	if (test == 0) {
		cout << " Ten tac gia ban nhap khong co trong danh sach!" << endl;
	}
	else {
		cout << " Xoa thanh cong tat ca sach cua tac gia: " << tenTacGia << "!" << endl;
	}
}

bool checkTacGia2(ListBook list, string tacGia) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return false;
	}
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (kiemTraChuoi(k->data.tacGia, tacGia))
		{
			return true;
		}
	}
	return false;
}

void showTacGia2(ListBook list, string tacGia) {
	if (checkTacGia2(list, tacGia) == true)
	{
		showTieuDe();
		for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
		{
			if (kiemTraChuoi(k->data.tacGia, tacGia))
			{
				showBook(k->data);
			}
		}
	}
}

// Xoá sách theo tên tác giả
void delTacGia(ListBook &list, string tacGia) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	int ma;
	cout << " Nhap ma sach can xoa cua tac gia " << tacGia << ": ";
	cin >> ma;
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (kiemTraChuoi(k->data.tacGia, tacGia) && k->data.maSach == ma)
		{
			deleteMa2(list, ma);
			return;
		}
	}
	cout << " Ma ban nhap khong co trong danh sach sach cua tac gia: " << tacGia << "!" << endl;
}

// ================= CHUC NANG HIEN THI DANH SACH =================

// Hàm hiển thị danh sách
void show(ListBook list) {

		showTieuDe();
		for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
		{
			showBook(k->data);
		}
	}
// =============== SẮP XẾP DANH SÁCH ===================
// Hàm hoán vị 2 phần tử trong danh sách liên kết
void swap(Book &b1, Book &b2) {
	Book b3;
	b3.maSach = b1.maSach;
	b3.tenSach = b1.tenSach;
	b3.tacGia = b1.tacGia;
	b3.nhaXuatBan = b1.nhaXuatBan;
	b3.namXuatBan = b1.namXuatBan;
	b3.theloai = b1.theloai;
	b1.maSach = b2.maSach;
	b1.tenSach = b2.tenSach;
	b1.tacGia = b2.tacGia;
	b1.nhaXuatBan = b2.nhaXuatBan;
	b1.namXuatBan = b2.namXuatBan;
	b1.theloai = b2.theloai;
	b2.maSach = b3.maSach;
	b2.tenSach = b3.tenSach;
	b2.tacGia = b3.tacGia;
	b2.nhaXuatBan = b3.nhaXuatBan;
	b2.namXuatBan = b3.namXuatBan;
	b2.theloai = b3.theloai;
}

// Hàm sắp xếp theo alphabet
void sortAlphaBet(ListBook list, int n) {
	for (BookNode *k = list.pHead; k != list.pTail; k = k->pNext) {
		for (BookNode *j = k->pNext; j != NULL; j = j->pNext) {
			string s1, s2;
			if (n == 1)
			{
				s1 = toLower(k->data.tenSach);
				s2 = toLower(j->data.tenSach);
			}
			else if (n == 2)
			{
				s1 = toLower(k->data.tacGia);
				s2 = toLower(j->data.tacGia);
			}
			else if( n == 3)
			{
				s1 = toLower(k->data.nhaXuatBan);
				s2 = toLower(j->data.nhaXuatBan);
			}
			else
			{
				s1 = toLower(k->data.theloai);
				s2 = toLower(j->data.theloai);
			}
			if (s1.compare(s2) > 0)
			{
				swap(k->data, j->data);
			}
		}
	}
}
// Hàm sắp xếp theo mã tang dần
void sortMaSach(ListBook list) {
	for (BookNode* k = list.pHead; k != list.pTail; k = k->pNext) {
		for (BookNode* j = k->pNext; j != NULL; j = j->pNext) {
			if (k->data.maSach > j->data.maSach)
			{
				swap(k->data, j->data);
			}
		}
	}
}
// Hàm sắp xếp theo mã ,theo thể loại(tăng dần)
void sortMaSach_theloai(ListBook list) {
	for (BookNode *k = list.pHead; k != list.pTail; k = k->pNext) {
		for (BookNode *j = k->pNext; j != NULL; j = j->pNext) {
			if (k->data.maSach > j->data.maSach)
			{
				swap(k->data.maSach, j->data.maSach);
			}
		}
	}
}

// Hàm sắp xếp theo năm (giảm dần)
void sortNamXuatBan(ListBook list) {
	for (BookNode *k = list.pHead; k != list.pTail; k = k->pNext) {
		for (BookNode *j = k->pNext; j != NULL; j = j->pNext) {
			if (k->data.namXuatBan < j->data.namXuatBan)
			{
				swap(k->data, j->data);
			}
		}
	}
}

// =============== 5. CHỨC NĂNG XEM DANH SÁCH ===============

// Hàm hiển thị danh sách theo alphabet của tên sách
void showAlphaBet(ListBook list, int n) {
	if (list.pHead != NULL)
	{
		if (n == 1)
		{
			sortAlphaBet(list, n);
			cout << " ========== DANH SACH BOOK THEO ALPHABET TEN SACH ==========" << endl;
			show(list);
		}
		else if (n == 2)
		{
			sortAlphaBet(list, n);
			cout << " ========== DANH SACH BOOK THEO ALPHABET TEN TAC GIA ==========" << endl;
			show(list);
		}
		else if ( n == 3)
		{
			sortAlphaBet(list, n);
			cout << " ========== DANH SACH BOOK THEO ALPHABET NHA XUAT BAN ==========" << endl;
			show(list);
		}
		else
		{

			sortAlphaBet(list, n);
			sortMaSach_theloai(list);
			cout << " ========== DANH SACH BOOK THEO ALPHABET THE LOAI ==========" << endl;
			show(list);
		}
	}
	else
	{
		cout << " Chua co du lieu!" << endl;
	}
}

// Hàm hiển thị danh sách sách được xuất bản mới nhất (theo năm)
void showNamXuatBan(ListBook list) {
	if (list.pHead != NULL)
	{
		sortNamXuatBan(list);
		cout << " ========== DANH SACH BOOK DUOC XUAT BAN MOI NHAT ==========" << endl;
		show(list);
	}
	else
	{
		cout << " Chua co du lieu!" << endl;
	}
}

// Hàm hiển thị danh sách sách theo mã sách tăng dần
void showMaSach(ListBook list) {
	if (list.pHead != NULL)
	{
		sortMaSach(list);
		cout << " ========== DANH SACH BOOK THEO MA TANG DAN ==========" << endl;
		show(list);
	}
	else
	{
		cout << " Chua co du lieu!" << endl;
	}
}

// =============== 4. TÌM KIẾM SÁCH ===============
void showSachTheoMa(ListBook list, int ma) {
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.maSach == ma)
		{
			cout << " ========== THONG TIN SACH ==========" << endl;
			showTieuDe();
			showBook(k->data);
		}
	}
}

// Tìm kiếm theo mã
int searchMaSach(ListBook list, int ma) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return 0;
	}
	int dem = 0;
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.maSach == ma)
		{
			return 1;
		}
	}
	return dem;
}

// Hàm tìm kiếm sách theo tên sách
void searchTenSach(ListBook list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	cin.ignore();
	string tenSach;
	cout << " Nhap ten sach can tim: ";
	getline(cin, tenSach);
	int dem = 1;
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (checkStr(k->data.tenSach, tenSach))
		{
			if (dem == 1)
			{
				cout << " ========== KET QUA TIM KIEM ==========" << endl;
				showTieuDe();
			}
			dem++;
			showBook(k->data);
		}
	}
	if (dem == 1)
	{
		cout << " Khong tim thay: " << tenSach << endl;
	}
}

// Hàm tìm kiếm sách theo tên tác giả
void searchTenTacGia(ListBook list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	cin.ignore();
	string tacGia;
	cout << " Nhap ten tac gia can tim: ";
	getline(cin, tacGia);
	int dem = 1;
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (checkStr(k->data.tacGia, tacGia))
		{
			if (dem == 1)
			{
				cout << " ========== KET QUA TIM KIEM ==========" << endl;
				showTieuDe();
			}
			dem++;
			showBook(k->data);
		}
	}
	if (dem == 1)
	{
		cout << " Khong tim thay: " << tacGia << endl;
	}
}

// Hàm tìm kiếm sách theo nhà xuất bản
void searchNhaXuatBan(ListBook list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	cin.ignore();
	string nhaXuatBan;
	cout << " Nhap nha xuat ban can tim: ";
	getline(cin, nhaXuatBan);
	int dem = 1;
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (checkStr(k->data.nhaXuatBan, nhaXuatBan))
		{
			if (dem == 1)
			{
				cout << " ========== KET QUA TIM KIEM ==========" << endl;
				showTieuDe();
			}
			dem++;
			showBook(k->data);
		}
	}
	if (dem == 1)
	{
		cout << " Khong tim thay: " << nhaXuatBan << endl;
	}
}
// Tìm kiếm chuỗi  "Lập Trình" 
bool kiemTraChuoiCon(string s1, string s2) {
	int pos = s1.find(s2);
	while(pos >= 0)
	{
		pos = s1.find(s2);
		return true;
	}
	return false;
}
void searchTenSachtheonsb(ListBook list) {
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	cin.ignore();
	string tenSach ="Lap trinh";
	int dem = 1;
	for (BookNode* k = list.pHead; k != NULL; k = k->pNext)
	{
			if (kiemTraChuoiCon(k->data.tenSach, tenSach))
			{
				if (k->data.nhaXuatBan == "NXB DHQG" || k->data.nhaXuatBan == "NXB KHKT")
				{

						if (dem == 1)
						{
							cout << " ========== KET QUA TIM KIEM ==========" << endl;
							showTieuDe();
						}
						dem++;
						
						showBook(k->data);
				}
			}
	}
	cout << "So sach: " << dem - 1 << endl;
	if (dem == 1)
	{
		cout << " Khong tim thay: " << tenSach << endl;
	}
}


// =============== 6. CHỈNH SỬA NỘI DUNG SÁCH ===============
void editSach(ListBook &list, int n, int ma) {
	string str;
	for (BookNode *k = list.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.maSach == ma)
		{
			cin.ignore();
			cout << " Nhap thong tin moi: ";
			getline(cin, str);
			if (n == 1)
			{
				k->data.tenSach = str;
			}
			else if (n == 2)
			{
				k->data.tacGia = str;
			}
			else if (n == 3)
			{
				k->data.nhaXuatBan = str;
			}
			else if( n == 4)
			{
				k->data.namXuatBan = atoi(str.c_str());
			}
			else
			{
				k->data.theloai = atoi(str.c_str());
			}
			cout << " Sua thanh cong!" << endl;
			cout << " ========== THONG TIN SACH SAU KHI CHINH SUA ==========" << endl;
			showTieuDe();
			showBook(k->data);
			return;
		}
	}
}
//=====================7.THỐNG KÊ SÁCH===================
 void showTieuDeThongKe() {
string str = " -----------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout << setw(30) <<"Ten tac gia" << setw(30)<<"So sach"<<setw(50)<< "Nha xuat ban" << endl;
	cout << str << endl;
}
 void swap(int a, int b)
 {
	 int c = a;
	 a = b;
	 b = c;
 }
//Hàm thống kê sách của trong từng NXB của mỗi tác giả
void book_statistics_TG(ListBook& list, Book &b)
{
	if (list.pHead == NULL)
	{
		cout << " Danh sach rong!" << endl;
		return;
	}
	cin.ignore();
	string tacGia;
	cout << " Nhap ten tac gia can tim: ";
	getline(cin, tacGia);
	int dem = 0;
	for (BookNode* k = list.pHead; k != NULL; k = k->pNext)
	{
	
		if (checkStr(k->data.tacGia, tacGia))
		{		
		}
		cout << " ========== KET QUA THONG KE ==========" << endl;
		showTieuDeThongKe();
		cout << setw(10) <<k->data.nhaXuatBan<< setw(30) << dem << endl;
	}
		
	if (dem == 0)
	{
		cout << " Khong tim thay tac gia: " << tacGia << endl;
	}
}
bool checkTen(string ten, ListBook list) {
	for (BookNode* k = list.pHead; k != NULL; k = k->pNext) {
		if (k->data.tacGia == ten)
		{
			return true;
		}
	}
	return false;
}
void intentg(ListBook list)
{
	string str = " ------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	showTieuDeThongKe();
	for (BookNode* k = list.pHead; k != NULL; k = k->pNext)
	{
		int dem = 0;
		for (BookNode* l = list.pHead; l != NULL; l = l->pNext)
		{
			if(k->data.tacGia == l->data.tacGia && k->data.nhaXuatBan == l->data.nhaXuatBan)
			{
				
				dem++;
			}
			
		}
		cout<<setw(30) << k->data.tacGia<<setw(30) << dem << setw(50) << k->data.nhaXuatBan<<setw(20) << endl;
		cout << str << endl;
	}
}
void tktheonam(ListBook list)
{
	string str = " ------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	showTieuDeThongKe();
	for (BookNode* k = list.pHead; k != NULL; k = k->pNext)
	{
		int dem = 0;
		for (BookNode* l = list.pHead; l != NULL; l = l->pNext)
		{
			
			if (k->data.namXuatBan == l->data.namXuatBan && k->data.nhaXuatBan == l->data.nhaXuatBan)
			{

				dem++;
			}

		}
		cout << setw(30) << k->data.namXuatBan << setw(30) << dem << setw(50) << k->data.nhaXuatBan << setw(20) << endl;
		cout << str << endl;
	}
}
//int largest_element(int arr[])
//{
//
//	int i, min_element;
//	min_element = arr[0];
//	for (i = 1; i < num; i++)
//		if (arr[i] > min_element)
//			min_element = arr[i];
//	return min_element;
//}

void minBook(ListBook &list)
{
	int min = 1000;
	for (BookNode* k = list.pHead; k != NULL; k = k->pNext)
	{
		int dem = 0;
		for (BookNode* l = list.pHead; l != NULL; l = l->pNext)
		{
			if (k->data.nhaXuatBan == l->data.nhaXuatBan)
			{
				dem++;
				/*showTieuDeThongKe();*/
			}
			
		}
		if (dem < min)
		{
			int temp = min;
			min = dem;
			dem = temp;
		
		}
	}
	for (BookNode* k = list.pHead; k != NULL; k = k->pNext)
	{
		int dem1 = 0;
		for (BookNode* l = list.pHead; l != NULL; l = l->pNext)
		{
			if (k->data.nhaXuatBan == l->data.nhaXuatBan)
			{
				dem1++;
				/*showTieuDeThongKe();*/
			}
		}
		if (dem1 == min)
		{
			/*cout << setw(30) << "Nha xuat ban" << setw(30) << "So sach" << endl;*/
			cout <<setw(30) << k->data.nhaXuatBan << setw(30) << dem1 << endl;
		}
	}
}

// Hàm giải phóng vùng nhớ cho danh sách liên kết đơn
void giaiPhongVungNho(ListBook &list) {
	BookNode *k = NULL;
	while (list.pHead != NULL)
	{
		k = list.pHead;
		list.pHead = list.pHead->pNext;
		delete k;
	}
}

// Menu
void menu(ListBook &list) {
	int luaChon;
	while (true)
	{
		system("cls");
		cout << "\n ============ CHUONG TRINH QUAN LY SACH ============";
		cout << "\n --0. Exit";
		cout << "\n --1. Khoi tao danh sach";
		cout << "\n --2. Them 1 cuon sach vao danh sach";
		cout << "\n --3. Xoa 1 cuon sach khoi danh sach";
		cout << "\n --4. Tim kiem sach";
		cout << "\n --5. Hien thi danh sach";
		cout << "\n --6. Chinh sua noi dung sach";
		cout << "\n --7. Thong ke";
		cout << "\n ===================== THE END =====================" << endl;

		cout << " Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 0)
		{
			cout << " Goodbye!" << endl;
			system("pause");
			break;
		}
		else if (luaChon == 1)
		{
			int luaChon1;
			while (true) {
				system("cls");
				cout << "\n ============ KHOI TAO DANH SACH ============";
				cout << "\n --0. Exit";
				cout << "\n --1. Khoi tao danh muc rong";
				cout << "\n --2. Doc tu file lam viec truoc do";
				cout << "\n ================= THE END ==================" << endl;

				cout << " Nhap lua chon: ";
				cin >> luaChon1;
				if (luaChon1 == 0) {
					break;
				}
				else if (luaChon1 == 1)
				{
					khoiTao(list);
					cout << " Khoi tao thanh cong!" << endl;
					system("pause");
				}
				else if (luaChon1 == 2)
				{
					khoiTao(list);
					cin.ignore();
					string tenFile="Text.txt";
					/*cout << " Nhap ten file: ";
					getline(cin, tenFile);*/
					if (checkFile(tenFile))
					{
						Book b;
						ifstream filein;
						filein.open(tenFile, ios_base::in);
						docFile(filein, list);
						show(list);
						cout << " Doc file thanh cong!" << endl;
						filein.close();
						
					}
					else
					{
						cout << " File ban nhap khong ton tai, vui long kiem tra lai!" << endl;
					}
					system("pause");
				}
				else
				{
					cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 2!" << endl;
					system("pause");
				}
			}
		}
		else if (luaChon == 2)
		{
			int luaChon2;
			while (true)
			{
				system("cls");
				cout << "\n ============ THEM 1 CUON SACH VAO DANH SACH ============";
				cout << "\n --0. Exit";
				cout << "\n --1. Them vao dau danh sach";
				cout << "\n --2. Them vao sau 1 cuon sach nao do";
				cout << "\n --3. Them vao cuoi danh sach";
				cout << "\n --4. Them vao danh sach theo the loai";
				cout << "\n ======================= THE END ========================" << endl;

				cout << " Nhap lua chon: ";
				cin >> luaChon2;
				if (luaChon2 == 0)
				{
					break;
				}
				else if (luaChon2 == 1)
				{
					cout << " ========= Nhap thong tin sach =========" << endl;
					Book b;
					BookNode *p = nhap(b, list);
					cout << " =======================================" << endl;
					InsertFirst(list, p);
					cout << " Them thanh cong!" << endl;
					system("pause");
				}
				else if (luaChon2 == 2)
				{
					cout << " ========= Nhap thong tin sach =========" << endl;
					Book b;
					BookNode *p = nhap(b, list);
					cout << " =======================================" << endl;
					InsertAfter(list, p);
					cout << " Them thanh cong!" << endl;
					system("pause");
				}
				else if (luaChon2 == 3)
				{
					cout << " ========= Nhap thong tin sach =========" << endl;
					Book b;
					BookNode *p = nhap(b, list);
					cout << " =======================================" << endl;
					InsertLast(list, p);

					cout << " Them thanh cong!" << endl;
					system("pause");
				}
				else if (luaChon2 == 4)
				{
					cout << " ========= Nhap thong tin sach =========" << endl;
					Book b;
					BookNode* p = nhap(b, list);
					cout << " =======================================" << endl;
					InsertLast(list, p);
					showAlphaBet(list,4);
					cout << " Them thanh cong!" << endl;
					system("pause");
				}
				else
				{
					cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 3!" << endl;
					system("pause");
				}
			}
		}
		else if (luaChon == 3)
		{
			int luachon3;
			while (true)
			{
				system("cls");
				cout << "\n ============ XOA 1 CUON SACH KHOI DANH SACH ============";
				cout << "\n --0. Exit";
				cout << "\n --1. Xoa theo ma so";
				cout << "\n --2. Xoa theo ten sach";
				cout << "\n --3. Xoa theo ten tac gia";
				cout << "\n --4. Xoa sach o dau danh sach";
				cout << "\n --5. Xoa sach o sau 1 cuon sach co ma so nao do";
				cout << "\n --6. Xoa sach o cuoi danh sach";
				cout << "\n ======================= THE END ========================" << endl;

				cout << " Nhap lua chon: ";
				cin >> luachon3;
				if (luachon3 == 0)
				{
					break;
				}
				else if (luachon3 == 1)
				{
					deleteMa(list);
					system("pause");
				}
				else if (luachon3 == 2)
				{
					deleteTenSach(list);
					system("pause");
				}
				else if (luachon3 == 3)
				{
					cin.ignore();
					string tenTacGia;
					cout << " Nhap ten tac gia can xoa: ";
					getline(cin, tenTacGia);
					while (true)
					{
						if (checkTacGia2(list, tenTacGia) == true)
						{
							system("cls");
							cout << " ========== XOA SACH THEO TEN TAC GIA: " << tenTacGia << " ==========" << endl;
							showTacGia2(list, tenTacGia);
							int traLoi;
							do
							{
								cout << " Ban co muon xoa tat ca sach cua tac gia do trong thu vien khong? (1: Co/0: Khong): ";
								cin >> traLoi;
							} while (traLoi != 0 && traLoi != 1);
							if (traLoi == 1)
							{
								deleteTenTacGia(list, tenTacGia);
								system("pause");
								break;
							}
							else
							{
								delTacGia(list, tenTacGia);
								int tiep;
								do
								{
									cout << " Ban co muon tiep tuc xoa sach cua tac gia '" << tenTacGia << "' trong thu vien khong? (1: Co/0: Khong): ";
									cin >> tiep;
								} while (tiep != 0 && tiep != 1);
								if (tiep == 1)
								{
									continue;
								}
								else
								{
									break;
								}
							}
						}
						else
						{
							cout << " Tac gia '" << tenTacGia << "' khong co sach trong thu vien!" << endl;
							system("pause");
							break;
						}
					}
				}
				else if (luachon3 == 4)
				{
					deleteFirst(list);
					system("pause");
				}
				else if (luachon3 == 5)
				{
					deleteAfter(list);
					system("pause");
				}
				else if (luachon3 == 6)
				{
					deleteLast(list);
					system("pause");
				}
				else
				{
					cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 6!" << endl;
					system("pause");
				}
			}
		}
		else if (luaChon == 4)
		{
			int luaChon4;
			while (true)
			{
				system("cls");
				cout << "\n ============ TIM KIEM SACH ============";
				cout << "\n --0. Exit";
				cout << "\n --1. Tim kiem theo ten sach";
				cout << "\n --2. Tim kiem theo ten tac gia";
				cout << "\n --3. Tim kiem theo nha xuat ban";
				cout << "\n --4. Tim kiem nha xuat ban có it sach nhat";
				cout << "\n --5. Tim kiem sach chua chuoi 'Lap trinh' do NXB DHQG va NXB KHKT";
				cout << "\n =============== THE END ===============" << endl;

				cout << " Nhap lua chon: ";
				cin >> luaChon4;
				if (luaChon4 == 0)
				{
					break;
				}
				else if (luaChon4 == 1)
				{
					searchTenSach(list);
					system("pause");
				}
				else if (luaChon4 == 2)
				{
					searchTenTacGia(list);
					system("pause");
				}
				else if (luaChon4 == 3)
				{
					searchNhaXuatBan(list);
					system("pause");
				}
				else if (luaChon4 == 4)
				{
					minBook(list);
					system("pause");
				}
				else if (luaChon4 == 5)
				{
					searchTenSachtheonsb(list);
					system("pause");
				}
				else
				{
					cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 3!" << endl;
					system("pause");
				}
			}
		}
		else if (luaChon == 5)
		{
			int luaChon5;
			while (true)
			{
				system("cls");
				cout << "\n ============ HIEN THI DANH SACH ============";
				cout << "\n --0. Exit";
				cout << "\n --1. Hien thi toan bo danh muc sach trong danh sach";
				cout << "\n --2. Hien thi sach theo thu tu";
				cout << "\n ================= THE END ==================" << endl;

				cout << " Nhap lua chon: ";
				cin >> luaChon5;
				if (luaChon5 == 0)
				{
					break;
				}
				else if (luaChon5 == 1)
				{
					cout << " ============ DANH SACH BOOK ============" << endl;
					show(list);
					system("pause");
				}
				else if (luaChon5 == 2)
				{
					int luaChon54;
					while (true)
					{
						system("cls");
						cout << "\n ============ HIEN THI DANH SACH THEO THU TU ============";
						cout << "\n --0. Exit";
						cout << "\n --1. Hien thi sach theo alphabet cua ten sach";
						cout << "\n --2. Hien thi sach theo alphabet cua ten tac gia";
						cout << "\n --3. Hien thi sach theo alphabet cua nha xuat ban";
						cout << "\n --4. Hien thi sach theo alphabet cua the loai";
						cout << "\n --5. Hien thi sach duoc xuat ban moi nhat (theo nam)";
						cout << "\n --6. Hien thi sach theo ma sach (tang dan)";
						cout << "\n ======================= THE END ========================" << endl;

						cout << " Nhap lua chon: ";
						cin >> luaChon54;
						if (luaChon54 == 0)
						{
							break;
						}
						else if (luaChon54 == 1)
						{

							showAlphaBet(list, 1);
							system("pause");
						}
						else if (luaChon54 == 2)
						{
							showAlphaBet(list, 2);
							system("pause");
						}
						else if (luaChon54 == 3)
						{
							showAlphaBet(list, 3);
							system("pause");
						}
						else if (luaChon54 == 4)
						{
							showAlphaBet(list, 4);
							system("pause");
						}
						else if (luaChon54 == 5)
						{
							showNamXuatBan(list);
							system("pause");
						}
						else if (luaChon54 == 6)
						{
							showMaSach(list);
							system("pause");
						}
						else
						{
							cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 6!" << endl;
							system("pause");
						}
					}
				}
				else
				{
					cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 2!" << endl;
					system("pause");
				}
			}
		}
		else if (luaChon == 6)
		{
			int ma;
			cout << " Nhap ma sach can sua: ";
			cin >> ma;
			int kq = searchMaSach(list, ma);
			if (kq != 0)
			{
				int luaChon7;
				while (true)
				{
					system("cls");
					showSachTheoMa(list, ma);
					cout << "\n ============ CHINH SUA NOI DUNG SACH ============";
					cout << "\n --0. Exit";
					cout << "\n --1. Sua ten sach";
					cout << "\n --2. Sua ten tac gia";
					cout << "\n --3. Sua nha xuat ban";
					cout << "\n --4. Sua nam xuat ban";
					cout << "\n =================== THE END =====================" << endl;

					cout << " Nhap lua chon: ";
					cin >> luaChon7;
					if (luaChon7 == 0)
					{
						break;
					}
					else if (luaChon7 == 1)
					{
						editSach(list, 1, ma);
						system("pause");
					}
					else if (luaChon7 == 2)
					{
						editSach(list, 2, ma);
						system("pause");
					}
					else if (luaChon7 == 3)
					{
						editSach(list, 3, ma);
						system("pause");
					}
					else if (luaChon7 == 4)
					{
						editSach(list, 4, ma);
						system("pause");
					}
					else
					{
						cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 4!" << endl;
						system("pause");
					}
				}
			}
			
			else {
				cout << " Ma ban nhap khong co trong danh sach!" << endl;
				system("pause");
			}
		}
		else if (luaChon == 7)
			{
			int luaChon7;
			while (true) {
				system("cls");
				cout << "\n ============ THONG KE SACH ============";
				cout << "\n --0. Exit";
				cout << "\n --1. Thong ke sach cua trong tung NXB cua moi tac gia";
				cout << "\n --2. Thong ke sach theo tung nam xuat ban cua tung NXB";
				cout << "\n ================= THE END ==================" << endl;

				cout << " Nhap lua chon: ";
				cin >> luaChon7;
				if (luaChon7 == 0) {
					break;
				}
				else if (luaChon7 == 1)
				{/*
					Book b;
					book_statistics_TG(list,b);
					system("pause");*/
					sortAlphaBet(list, 2);
					Book b;
					intentg(list);
					system("pause");
				}
				else if (luaChon7 == 2)
				{
					sortAlphaBet(list, 3);
					/*sortNamXuatBan(list);*/
					tktheonam(list);
					system("pause");
				}
				else
				{
					cout << " Lua chon cua ban khong hop le, vui long nhap lua chon tu 0 - 2!" << endl;
					system("pause");
				}
			}
		}
	}
}

int main() {
	ListBook list;
	khoiTao(list); // khởi tạo danh sách
	menu(list);
	giaiPhongVungNho(list);
	system("pause");
	return 0;
}