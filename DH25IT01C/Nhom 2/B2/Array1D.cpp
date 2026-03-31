#include "vector.h"

int main() {
	int *a, n;
	int *b, m;
	int *c, size;

	//Khoi tao
	init(a, n);
	//Xin cap phat vung nho
	n = input();
	a = new int[n];

	m = input();
	b = new int[m];
	//Thao tac tren mang
	//inputArr(a, n);
	srand(time(0));
	genArrRand(a, n);
	genArrRand(b, m);
	outputArr(a, n);

	cout << "=============TIM KIEM============\n";
	int *res = findExtrem(a, n, cmpMin);

	if (res != NULL)
		cout << "Min: " << *res << endl;

	res = find(a, n, 11);
	if (res != NULL)
		cout << "Ket qua: " << res << endl;
	else
		cout << "Khong tim thay!\n";

	cout << "=============NOI MANG============\n";
	c = concateArr(a, n, b, m, size);
	outputArr(c, size);

	cout << "=============SAP XEP============\n";
	sortArr(a, n);
	outputArr(a, n);

	cout << "=============DAO NGUOC MANG============\n";
	reverseArr(a, n);
	outputArr(a, n);

	cout << "=============THEM PHAN TU VAO MANG============\n";
	pushBackArr(a, n, 999);
	outputArr(a, n);
	//Giai phong vung nho
	delete[]c;
	delete[]b;
	delete[]a;
	return 0;
}