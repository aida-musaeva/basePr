// unitTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "gtest\gtest.h"
#include "indepWork.h"

TEST(PolynomTest, sumWpolyEqualDeg){
	double coeff1[] = { 8, 17, 7, 9 };
	double coeff2[] = { -8, -17, -7, -9 };
	double coeff3[] = { 0, 0, 0, 0};
	Polynom pol1(3, coeff1);
	Polynom pol2(3, coeff2);
	Polynom polsum(3, coeff3);
	EXPECT_TRUE((pol1 + pol2) == polsum);
}
TEST(PolynomTest, sumWpoly) {
	double coeff1[] = { 1, 2, 3, 3 };
	double coeff2[] = { 1, 2, 3, 3 };
	double coeff3[] = { 2, 4, 6, 6 };
	Polynom pol1(3, coeff1);
	Polynom pol2(3, coeff2);
	Polynom polsum(3, coeff3);
	EXPECT_TRUE((pol1 + pol2) == polsum);
}
TEST(PolynomTest, sumWpolyDiffDeg) {
	double coeff1[] = { 8, 17, 7, 9,10 };
	double coeff2[] = { -8, -17, -7, -9 };
	double coeff3[] = { 0, 0, 0, 0, 10 };
	Polynom pol1(4, coeff1);
	Polynom pol2(3, coeff2);
	Polynom polsum(4, coeff3);
	EXPECT_TRUE((pol1 + pol2) == polsum);
}
TEST(PolynomTest, diffDiffDeg) {
	double coeff1[] = { 4, 7, 9, 10, 10};
	double coeff2[] = { 4, 7, 9, 10 };
	double coeff3[] = { 0, 0, 0, 0, 10};
	Polynom pol1(4, coeff1);
	Polynom pol2(3, coeff2);
	Polynom poldiff(4, coeff3);
	EXPECT_TRUE((pol1 - pol2) == poldiff);
}
TEST(PolynomTest, diffEqDeg) {
	double coeff1[] = { 4, 7, 9, 10 };
	double coeff2[] = { 4, 7, 9, 10 };
	double coeff3[] = { 0, 0, 0, 0 };
	Polynom pol1(3, coeff1);
	Polynom pol2(3, coeff2);
	Polynom poldiff(3, coeff3);
	EXPECT_TRUE((pol1 - pol2) == poldiff);
}
TEST(PolynomTest, diff) {
	double coeff1[] = { 4, 7, 8, 10 };
	double coeff2[] = { 4, 7, 9, 10 };
	double coeff3[] = { 0, 0, -1, 0 };
	Polynom pol1(3, coeff1);
	Polynom pol2(3, coeff2);
	Polynom poldiff(3, coeff3);
	EXPECT_TRUE((pol1 - pol2) == poldiff);
}
TEST(PolynomTest, sumWdouble) {
	double coeff1[] = { 5, 8, 7, 9 };
	Polynom pol1(3, coeff1);

	double num = 3;

	Polynom result = (pol1 + num);

	double coeffsum[] = { 8, 8, 7, 9 };
	Polynom expected(3, coeffsum);
	
	EXPECT_TRUE(result == expected);
}
TEST(PolynomTest, sumWdoubleNegative) {
	double coeff1[] = { 5, 8, 7, 9 };
	double coeffsum[] = { 0, 8, 7, 9 };
	Polynom pol1(3, coeff1);
	double num = -5;
	Polynom polsum(3, coeffsum);
	EXPECT_TRUE((pol1 + num) == polsum);
}
TEST(PolynomTest, multiWdouble) {
	double coeff1[] = { 5, 8, 7, 9 };
	double coeffmulti[] = { 10, 16, 14, 18 };
	Polynom pol1(3, coeff1);
	double num = 2;
	Polynom polmulti(3, coeffmulti);
	EXPECT_TRUE((pol1*num) == polmulti);
}
TEST(PolynomTest, multiWdouble0) {
	double coeff1[] = { 5, 8, 7, 9 };
	double coeffmulti[] = { 0, 0, 0, 0 };
	Polynom pol1(3, coeff1);
	double num = 0;
	Polynom polmulti(3, coeffmulti);
	EXPECT_TRUE((pol1*num) == polmulti);
}