#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
	Rational(int n = 0, int d = 1);
	Rational& operator+=(const Rational& r);
	friend std::ostream& operator<<(std::ostream&, const Rational&);
private:
	int num;
	int den;
	int gcd(int u, int v);
	void simplify();
};

// Not included in the class Rational
Rational operator+(const Rational& lhs, const Rational& rhs);

#endif
