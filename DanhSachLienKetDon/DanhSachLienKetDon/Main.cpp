#include "Header.h"

void main() {
	LIST l;
	TYPEINFO x, n, pos,y;
	init(l);
	cout << "\nNhap so luong node can them:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nGia tri can them:";
		cin >> x;
		themCuoi(l, x);
	}
	DuyetDS(l);
	
	xoaDau(l);
	DuyetDS(l);
	xoaCuoi(l);
	DuyetDS(l);
	
	XoaBoNho(l);
system("pause");
}