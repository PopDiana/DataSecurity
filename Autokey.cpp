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
		key += result[i];
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
	
	string key;
	cout<<"Key: ";
	getline(cin, key);
	transform(key.begin(), key.end(), key.begin(), ::toupper);
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
    
    string decoded = decrypt(text, key);
    
	cout<<"Plaintext: "<<decoded<<endl;
	
	string autokey = key;
	
    for(int i = 0; autokey.length() < decoded.length(); ++i){
        autokey = autokey + decoded[i];
    }
	
	cout<<"Result: "<<encrypt(decoded, autokey);
	
	return 0;
}