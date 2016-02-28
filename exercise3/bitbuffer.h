#ifndef BIT_BUFFER_H
#define BIT_BUFFER_H

#include <iostream>

using namespace std;

class BitBuffer {
public:
	BitBuffer(std::ostream& out);
	void put(bool b);
private:
	unsigned char byte;
	unsigned int n_bits;
	ostream& os;
};

#endif
