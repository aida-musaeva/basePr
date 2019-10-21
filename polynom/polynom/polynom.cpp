// polynom.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Polynom.h"


int main()
{
	double kof[] = { 10,2,30,40 };
	Polynom z(2, kof);
	cout << "z = " << z << endl;
	double n = 5;
	cout << "z+5 = " << z + n << endl;
	cout << "z*5 = " << z*n << endl;

	cout << "Enter the degree of a polynomial" << endl;
	bool flag = false;
	Polynom temp(1);
	try {
		cin >> n;
		Polynom temp(n);
	}
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
		return-1;
	}
	if (flag) {
		cout << "Enter the coefficients of the polynomial" << endl;
		cin >> temp;
		cout << temp << endl;
		double k[] = { 1,2,3,4 };
		double k1[] = { 1,2,3,4,5 };
		Polynom A(3, k);
		cout << "A = " << A << endl;
		Polynom B(4, k1);
		cout << "B = " << B << endl;
		cout << "A + B = " << A + B << endl;
		cout << "A - B = " << A - B << endl;
	}
	return 0;
}