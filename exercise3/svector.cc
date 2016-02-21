/*
 * Class SVector: implementation.
 */

#include "svector.h"

SVector::SVector(size_t size) : n(size), v(new int[n]) {}

/** Since the object is moved when calling the method print() in svectortest.cc we need 
    to implement a copy constructor */
SVector::SVector(const SVector& sv) : n(sv.n), v(new int[sv.n]) {
	for (size_t i = 0; i != n; ++i) {
		v[i] = sv.v[i];
	}
}

/** When using operators (for example '='), the same error may occur, in that case we 
	need to overload operators. I.e SVector& SVector::operator=(const SVector& rhs) */

SVector::~SVector() {
	delete[] v;
}

size_t SVector::size() const {
	return n;
}

int SVector::get(size_t i) const {
	return v[i];
}

void SVector::set(size_t i, int value) {
	v[i] = value;
}
