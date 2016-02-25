#include "crypto.h"

#include <string>
#include <random>

using namespace std;

string Crypto::encrypt(const string& text, unsigned int key) {
	string encryptedtext(text.size(), ' ');
	default_random_engine generator(key);
	uniform_int_distribution<int> distribution(1, 256);

	for (int i = 0; i < text.length(); ++i) {
		encryptedtext[i] = (text[i] + distribution(generator)) % 256;
	}

	return encryptedtext;
}

string Crypto::decrypt(const string& crypt, unsigned int key) {
	string decryptedtext(crypt.size(), ' ');
	default_random_engine generator(key);
	uniform_int_distribution<int> distribution(1, 256);

	for (int i = 0; i < crypt.length(); ++i) {
		decryptedtext[i] = (crypt[i] - distribution(generator)) % 256;
	}

	return decryptedtext;
}
