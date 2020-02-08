#include <bits/stdc++.h>

using namespace std;

string encrypt(string text, string key)
{
	string result(text.length(), ' ');
	for (int i = 0; i < text.size(); i++) 
	{
		result[i] = 'A' + (text[i] - 'A' + key[i] - 'A') % 26;
	}
	return result;
}

string decrypt(string text, string key)
{
	string result(text.length(), ' ');
	for (int i = 0; i < text.size(); i++)
	{
		result[i] = 'A' + (26 + text[i] - key[i]) % 26;
	}
	return result;
}

int main()
{
	string text;
	cout<<"Plain text: ";
	getline(cin, text);
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
		
	string key;
	cout<<"Key: ";
	getline(cin, key);
	transform(key.begin(), key.end(), key.begin(), ::toupper);
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
	
    while (key.length() < text.length()) 
	{
		key += key;
    }
	
	string cipher = encrypt(text, key);	
	cout<<"Cipher text: "<<cipher<<endl;
	
	cout<<"Result: "<<decrypt(cipher, key);
	
	return 0;
}