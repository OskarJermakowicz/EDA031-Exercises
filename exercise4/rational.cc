#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational(int numerator, int denominator) : num(numerator), den(denominator) {
	transformGCD();
}

Rational::Rational(int numerator) : num(numerator), den(1) { 
	transformGCD();
}

Rational::Rational() : num(0), den(1) { 
	transformGCD();
}

void Rational::transformGCD() {
	int shl = 0;

	while (num && den && num != den) {
		bool eu = !(num & 1);
		bool ev = !(den & 1);

		if (eu && ev) {
			++shl;
			num >>= 1;
			den >>= 1;
		}
		else if (eu && !ev) num >>= 1;
		else if (!eu && ev) den >>= 1;
		else if (num >= den) num = (num - den) >> 1;
		else {
			int tmp = num;
			num = (den - num) >> 1;
			den = tmp;
		}
	}

	int gcd = !num ? den << shl : num << shl;
	num /= gcd;
	den /= gcd;
}

ostream& operator<<(ostream& os, const Rational& obj) {
	os << obj.num;
	if (obj.den != 1) {
		os << '/' << obj.den;
	}
	return os;
}

Rational operator+(const Rational& obj) {
	Rational res;
	res.num = num + obj.num;
	res.den = den + obj.den;
	res.transformGCD();
	return res;
}