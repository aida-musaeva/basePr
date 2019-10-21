#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <exception>
using namespace std;

class Polynom {
private:
	double *a;
	int n;
public:
	Polynom(int deg){
		n = deg;
		a = new double[n + 1];
		for (int i = 0; i <= n; ++i)
			a[i] = 0;
	}
	
		Polynom(int deg, double *k) {
			n = deg;
			a = new double[n + 1];
			for (int i = 0; i <= n; ++i)
				a[i] = k[i];
		}
	
	~Polynom() {
		delete[]a;
	}
	friend Polynom operator+(Polynom & pol1, Polynom & pol2);
	friend Polynom operator*(Polynom & pol1, double & num);
	friend Polynom operator-(Polynom & pol1, Polynom & pol2);
	friend Polynom operator+(Polynom & pol1, double & num);
	friend ostream &operator<<(ostream &, Polynom &);
	friend istream &operator>> (istream &, Polynom &);
	Polynom& operator=(Polynom & pol)
	{
		n = pol.n;
		delete[]a;
		a = new double[n + 1];
		for (int i = 0; i <= n; ++i)
			a[i] = pol.a[i];
		return *this;
	}

};
Polynom operator*(Polynom & pol, double & num)
{
	Polynom *ans = new Polynom(pol.n);
	*ans = pol;
	for (unsigned int i = 0; i <= pol.n; ++i)
	{
		ans->a[i] = pol.a[i] * num;
	}
	return *ans;
}
Polynom operator+(Polynom & pol1, Polynom & pol2)
{
	bool flag = false;
	Polynom *sum = new Polynom(max(pol1.n, pol2.n));
	if (pol1.n >= pol2.n) flag = true;
	*sum = (flag) ? pol1 : pol2;
	if (flag)
	{
		for (int i = 0; i <= min(pol1.n, pol2.n); ++i)
		{
			sum->a[i] += pol2.a[i];
		}
	}
	else
	{
		for (int i = 0; i <= min(pol1.n, pol2.n); ++i)
		{
			sum->a[i] += pol1.a[i];
		}
	}
	return *sum;
}
Polynom operator-(Polynom & pol1, Polynom & pol2)
{
	bool flag = false;
	Polynom *diff = new Polynom(max(pol1.n, pol2.n));
	if (pol1.n >= pol2.n) flag = true;
	*diff = (flag) ? pol1 : pol2;
	if (flag)
	{
		for (int i = 0; i <= min(pol1.n, pol2.n); ++i)
		{
			diff->a[i] -= pol2.a[i];
		}
	}
	else
	{
		for (int i = 0; i <= min(pol1.n, pol2.n); ++i)
		{
			diff->a[i] -= pol1.a[i];
		}
	}
	return *diff;
}

Polynom operator+(Polynom & pol, double &num)
{
	Polynom *ans = new Polynom(pol.n);
	*ans = pol;
	ans->a[0] = pol.a[0] + num;
	return *ans;
}
ostream &operator<<(ostream &fo, Polynom &pol)
{
	fo << int(pol.a[0]);
	for (int i = 1; i <= pol.n; ++i)
		fo << " + " << int(pol.a[i]) << "x^" << i;
	return fo;
}
istream &operator>>(istream &fi, Polynom &pol)
{
	pol.a = new double[pol.n + 1];
	for (int i = 0; i <= pol.n; ++i)
	{
		fi >> pol.a[i];
	}
	return fi;
}

int main()
{
	/*double kof[] = { 10,2,30,40 };
	Polynom z(3, kof);
	cout << "z = " << z << endl;
	double n = 5;
	cout << "z+5 = " << z + n << endl;
	cout << "z*5 = " << z*n << endl;

	cout << "Enter the degree of a polynomial" << endl;
	cin >> n;
	Polynom temp(n);
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
	cout << "A - B = " << A - B << endl;*/
	return 0;
}

