#include "morsecode.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

MorseCode::MorseCode() {
	/** Adds the morse code definitions into a map from morse.def */
	string s;
	char c;
	ifstream myfile("morse.def");

	if (myfile.is_open()) {
		while (myfile >> c >> s) {
			m[c] = s;
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file 'morse.def'." << endl;;
	}

}

string MorseCode::encode(const string& text) const {
	string morse;
	for (char c : text) {
		if (c >= 'a' && c <= 'z') {
			morse += m.find(c)->second + " ";
		}
	}
	return morse;
}

string MorseCode::decode(const string& code) const {
	istringstream iss(code);
	string s;
	string text;
	while (iss >> s) {
		for (auto const &ent : m) {
			if (ent.second == s) {
				text += ent.first;
			}
		}
	}
	return text;
}
