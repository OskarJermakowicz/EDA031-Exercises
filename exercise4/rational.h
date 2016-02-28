#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
	Rational(int numerator, int denominator);
	Rational(int numerator);
	Rational();
	void transformGCD();
	friend std::ostream& operator<<(std::ostream& os, const Rational& obj);
	friend Rational operator+(const Rational& obj);
private:
	int num;
	int den;
};

#endif
