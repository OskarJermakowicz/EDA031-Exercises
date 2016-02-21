/*
 * Checks if a word is a palindrome (which reads the same both forwards and backwards).
 */

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string word) {
	for (int i = 0; i < word.size(); i++) {
		if (word.at(i) != word.at(word.size() - 1 - i)) {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	
	while (s != "exit") {
		cout << endl;
		cout << "*** Type a word." << endl;
		getline(cin, s);
		cout << endl;
		if (isPalindrome(s)) {
			cout << "The word '" << s << "' is a palindrome." << endl;
		}
		else {
			cout << "The word '" << s << "' is not a palindrome." << endl;
		}
	}
}
