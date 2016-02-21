/*
 * MorseCode: translates letters a-z to/from Morse code. The code
 * definitions are in the file morse.def.
 */
#ifndef MORSECODE_H
#define MORSECODE_H

#include <string>
#include <map>

using namespace std;

class MorseCode {
public:
	MorseCode();
	string encode(const string& text) const;
	string decode(const string& code) const;
private:
	map<char, string> m;
};

#endif
