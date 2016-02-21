#include "editor.h"

#include <string>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char rpar = text[pos];
	char lpar;

	switch (rpar) {
	case ')' :
		lpar = '('; 
		break;
	case ']' : 
		lpar = '['; 
		break;
	case '}' : 
		lpar = '{'; 
		break;
	default : 
		return string::npos;
	}

	int level = 0;
	string::size_type i = pos - 1;
	while (i != string::npos) {
		char ch = text[i];
		if (ch == lpar && level == 0) {
			return i;
		}
		else {
			if (ch == rpar) {
				++level;
			}
			else if (ch == lpar) {
				--level;
			}
			--i;
		}
	}
	return i;
}
