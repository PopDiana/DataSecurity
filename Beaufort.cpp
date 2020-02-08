#include <bits/stdc++.h>

using namespace std;

// encrypt is same as decrypt
string beaufort(string text, string key)
{
	string result(text.length(), ' ');
	for (int i = 0; i < text.size(); i++) 
	{
		result[i] = 'A' + (key[i] - text[i] + 26) % 26;
	}
	return result;
}

int main()
{
	string text;
	cout<<"Ciphertext: ";
	getline(cin, text);
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
	
	
	cout<<"Key: ";
	string key;
	getline(cin, key);
	transform(key.begin(), key.end(), key.begin(), ::toupper);
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
	
	
    while (key.length() < text.length()) {
		key += key;
    }
	
	cout<<"Plaintext: "<<beaufort(text, key);
	
	return 0;
}