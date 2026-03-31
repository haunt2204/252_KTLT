#include <iostream>
using namespace std;

//S = 1 + 2 + 3 +...+n
int tinhTong(int n, int sum = 0) {
	//Basic case
	if (n == 0)
		return sum;
	//General case
	return tinhTong(n - 1, n + sum);
}

unsigned long long tinhTongBP(int n, unsigned long long sum=0) {
	if (n == 0)
		return sum;

	return tinhTongBP(n - 1, n*n + sum);
}

unsigned long long tinhGT(int n, unsigned long long res = 1) {
	if (n == 0)
		return res;

	return tinhGT(n - 1, res*n);
}

unsigned long long tinhTongGT(int n, unsigned long long sum = 0) {
	if (n == 0)
		return sum;

	return tinhTongGT(n - 1, tinhGT(n) + sum);
}

/*
n = 0 -> 0
n = 1 -> 1
F(n) = F(n-1) + F(n-2)
*/

int tinhFibo(int n, int a = 0, int b = 1) {
	if (n == 0)
		return a;
	if (n == 1)
		return b;

	return tinhFibo(n - 1, b, a + b);
}

double tinhLT(double x, int n, double res = 1) {
	if (n == 0)
		return res;
	if (n > 0)
		return tinhLT(x, n - 1, x*res);
	else {
		if (x == 0)
			return 0;//Loi chia cho so 0
		return tinhLT(x, n + 1, (1.0 / x)*res);
	}
}

int demChuSo(int n, int dem = 0) {
	if (n == 0)
		return dem;
	return demChuSo(n / 10, dem + 1);
}

int tinhSDN(int n, int sdn = 0) {
	if (n == 0)
		return sdn;
	return tinhSDN(n / 10, sdn * 10 + n % 10);
}

void inNhiPhan(int n) {
	if (n == 0)
		return;
	inNhiPhan(n / 2);
	cout << n % 2;
}

int timUCLN(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		return timUCLN(a - b, b);
	else
		return timUCLN(a, b - a);
}

int tinhTgPascal(int i, int j) {
	if (j == 0 || i == j)
		return 1;

	return tinhTgPascal(i - 1, j - 1) + tinhTgPascal(i - 1, j);
}

int main() {

	cout << "Ket qua tinh tong: " << tinhTong(5) << endl;
	cout << "Ket qua tinh tong binh phuong: " << tinhTongBP(3) << endl;
	cout << "Ket qua tinh giai thua: " << tinhGT(3) << endl;
	cout << "Ket qua tinh tong giai thua: " << tinhTongGT(3) << endl;
	//F = {0,1,1,2,3,5,8,...}
	cout << "Ket qua tinh Fibo: " << tinhFibo(7) << endl;
	cout << "Ket qua tinh luy thua: " << tinhLT(2, -3) << endl;
	cout << "Ket qua dem chu so: " << demChuSo(12345) << endl;
	cout << "Ket qua tinh so dao nguoc: " << tinhSDN(12345) << endl;
	cout << "Ket qua in nhi phan: ";
	inNhiPhan(7);
	cout << endl;
	cout << "Tim UCLN: " << timUCLN(9, 6) << endl;

	int h;
	cout << "Nhap chieu cao: ";
	cin >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			cout << tinhTgPascal(i, j) << " ";
		}
		cout << endl;
	}

	return 0;
}