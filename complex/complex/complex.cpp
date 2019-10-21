
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Complex {
private:
	double re;
	double im;
public:
	Complex(double r, double i) :re(r), im(i) {
	}
	friend Complex operator+(Complex& z1, Complex & z2);
	friend Complex operator*(Complex& z1, Complex & z2);
	friend Complex operator-(Complex& z1, Complex & z2);
	operator double() {
		return this->re * this->re + this->im * this->im;
	}
	double operator[](string s) {
		if (s == "Re") {
			return this->re;
		}
		if (s == "Im") {
			return this->im;
		}
	}
};
Complex operator+(Complex& z1, Complex& z2) {
	return Complex(z1.re + z2.re, z1.im + z2.im);
};
Complex operator-(Complex& z1, Complex& z2) {
	return Complex(z1.re - z2.re, z1.im - z2.im);
};
Complex operator*(Complex& z1, Complex& z2) {
	return Complex(z1.re*z2.re - z1.im*z2.im, z1.re*z2.im + z2.re*z1.im);
};


int main()
{
	Complex z(23, 34);
	cout << z["Im"];
    return 0;
}

