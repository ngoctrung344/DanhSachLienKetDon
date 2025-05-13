#pragma once
#include "iostream"
using namespace std;
typedef int TYPEINFO;
struct Node {
	TYPEINFO info;
	Node* next;
};
typedef Node* LIST;
//toa node
//kiểm tra rỗng
//thêm/xóa/tìm kiếm - đầu/ cuối/ vị trí bất kỳ
//in danh sách
//đêm số node 
//giải phóng bộ nhớ 

void init(LIST& list);
LIST toaNode(TYPEINFO list);

void themDau(LIST& list, TYPEINFO x); 
void themCuoi(LIST& list, TYPEINFO x);
bool themCoViTri(LIST& list, TYPEINFO x, int vitri);
bool themTruocQ(LIST& list, TYPEINFO x, TYPEINFO y);
bool themSauQ(LIST& list, TYPEINFO x, TYPEINFO y);

void DuyetDS(LIST list);
void XoaBoNho(LIST& list);

bool xoaDau(LIST& list);
bool xoaCuoi(LIST& list);
bool xoaTruocQ(LIST& list, TYPEINFO x);
