#include "Header.h"

void init(LIST& list) {
	list = NULL;
}
LIST taoNode(TYPEINFO x) {
	LIST p = new Node();
	p->info = x;
	p->next = NULL;
	return p;
}
void themDau(LIST& list, TYPEINFO x) {
	Node* p = taoNode(x);
	if (p == NULL) return;
	p->next = list;
	list = p;
}
void themCuoi(LIST& list, TYPEINFO x) {
	Node* p = taoNode(x);
	if (p == NULL) return;

	if (list == NULL) {
		list = p; // Nếu danh sách rỗng, node mới là đầu danh sách
	}
	else {
		Node* last = list;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = p;
	}
}
bool themCoViTri(LIST& list, TYPEINFO x, int vitri) {
	if (vitri < 0) return false;

	Node* p = taoNode(x);
	if (p == NULL) return false;

	if (vitri == 0) {
		p->next = list;
		list = p;
		return true;
	}

	Node* q = list;
	int i = 0;
	while (q != NULL && i < vitri - 1) {
		q = q->next;
		i++;
	}

	if (q == NULL) {
		delete p; // vị trí vượt quá độ dài danh sách
		return false;
	}

	p->next = q->next;
	q->next = p;
	return true;
}
bool themTruocQ(LIST& list, TYPEINFO x, TYPEINFO y) {
	Node* p = taoNode(x);
	if (p == NULL) return false;

	// Trường hợp đặc biệt: y nằm ở đầu danh sách
	if (list != NULL && list->info == y) {
		p->next = list;
		list = p;
		return true;
	}

	// Duyệt danh sách để tìm node đứng trước node có info = y
	Node* prev = list;
	while (prev != NULL && prev->next != NULL && prev->next->info != y) {
		prev = prev->next;
	}

	if (prev == NULL || prev->next == NULL) {
		delete p; // không tìm thấy y
		return false;
	}

	p->next = prev->next;
	prev->next = p;
	return true;
}
bool themSauQ(LIST& list,TYPEINFO x, TYPEINFO y) {
	Node* q = list;

	// Tìm node có info == y
	while (q != NULL && q->info != y) {
		q = q->next;
	}

	if (q == NULL) return false; // không tìm thấy y

	Node* p = taoNode(x);
	if (p == NULL) return false;

	p->next = q->next;
	q->next = p;

	return true;
}

void DuyetDS(LIST list) {
	for (Node* p = list; p != NULL; p = p->next) {
		cout << p->info << " ";
	}
	cout << endl;
}
void XoaBoNho(LIST& list) {
	Node* p;
	while (list != NULL) {
		p = list;
		list = list->next;
		delete p;
	}
}

bool xoaDau(LIST& list) {
	if (list == NULL) return false; // Danh sách rỗng

	Node* temp = list;
	list = list->next;  // Di chuyển đầu danh sách sang node tiếp theo
	delete temp;  // Giải phóng node cũ

	return true;
}
bool xoaCuoi(LIST& list) {
	if (list == NULL) return false; // Danh sách rỗng

	if (list->next == NULL) {
		// Danh sách chỉ có 1 phần tử
		delete list;
		list = NULL;
		return true;
	}

	Node* p = list;
	while (p->next->next != NULL) {
		p = p->next;
	}

	// p là node kế cuối
	delete p->next;
	p->next = NULL;

	return true;
}
//xóa trước giá trị 
bool xoaTruocQ(LIST& list, TYPEINFO x) {
	if (list == NULL || list->next == NULL) return false;

	// Trường hợp node thứ hai là x → xóa node đầu tiên
	if (list->next->info == x) {
		return xoaDau(list);
	}

	// Khai báo 3 con trỏ: trỏ trước - hiện tại - sau
	Node* prev = list;
	Node* curr = list->next;
	Node* next = curr->next;

	while (next != NULL && next->info != x) {
		prev = curr;
		curr = next;
		next = next->next;
	}

	if (next == NULL) return false; // Không tìm thấy node có giá trị x

	// curr đứng trước node có info == x
	prev->next = curr->next;
	delete curr;

	return true;
}





