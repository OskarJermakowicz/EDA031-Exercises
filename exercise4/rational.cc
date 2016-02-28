#include "rational.h"

#include <iostream>

using namespace std;

Rational::Rational(int n, int d) : num(n), den(d) {
	simplify();
}

Rational& Rational::operator+=(const Rational& r) {
	num = num * r.den + den * r.num;
	den *= r.den;
	simplify();
	return *this;
}

Rational operator+(const Rational& r1, const Rational& r2) {
	Rational local = r1;
	return local += r2;
}

std::ostream& operator<<(ostream& os, const Rational& r) {
	os << r.num;
	if (r.den != 1) {
		os << '/' << r.den;
	}
	return os;
}

void Rational::simplify() {
	int divisor = gcd(num, den);
	num /= divisor;
	den /= divisor;
}

/**
* Simple binary GCD from https://gist.github.com/cslarsen/1635213
*/
int Rational::gcd(int u, int v) {
	int shl = 0;

	while (u && v && u != v) {
		bool eu = !(u & 1);
		bool ev = !(v & 1);

		if (eu && ev) {
			++shl;
			u >>= 1;
			v >>= 1;
		}
		else if (eu && !ev) u >>= 1;
		else if (!eu && ev) v >>= 1;
		else if (u >= v) u = (u - v) >> 1;
		else {
			int tmp = u;
			u = (v - u) >> 1;
			v = tmp;
		}
	}
	return !u ? v << shl : u << shl;
}
