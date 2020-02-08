#include <bits/stdc++.h>

using namespace std;

string encrypt(string text, string key)
{
	string result;
	
	char matrix[100][100] = {0};
	
	int line = ceil(1.0 * text.size() / key.size());
	
	for(int i = 0; i < line; ++i) {
		for(int j = 0; j< key.size() ; ++j) {
			if (i * key.size() + j <= text.size() - 1)
			{
				matrix[i][j] = text[i*key.size() + j];
			}
		}
	}
	
	for (int j = 0; j < key.size(); ++j) {
		if (matrix[line-1][j] == 0) {
			matrix[line-1][j] = 'X';
		}
	}
	
	vector<pair<int, int>> values;
	
	for (int i = 0; i < key.size(); ++i) {
		
		values.push_back({key[i],i});
	}
	sort(values.begin(), values.end());
	
	for (auto it : values) {
		
		for (int i = 0; i < line; ++i) {
			
			if(matrix[i][it.second] != 0) {
				
				result += matrix[i][it.second]; 
			}
		}
	}
	return result;
}

string decrypt(string text, string key)
{
	string result;
	
	char matrix[100][100] = {0};	
			
	int line = ceil(1.0 * text.size() / key.size());
	
	vector<pair<int, int>> values;
	
	for (int i = 0; i < key.size(); ++i) {
		values.push_back({key[i],i});
	}
	
	sort(values.begin(),values.end());
	
	int k = 0;
	
	for (auto it : values) {
		for (int i = 0; i < line; ++i)
			matrix[i][it.second] = text[k++];
	}
	
	for (int i = 0; i < line; ++i) {
		
		for (int j = 0; j < key.size(); ++j) {
			
			if (matrix[i][j] != 'X') {
				
				result += matrix[i][j];
			}
		}
	}
	return result;
}


int main()
{
	
	string text;
	cout<<"Plainext: ";
	getline(cin, text);

	transform(text.begin(), text.end(), text.begin(), ::toupper);
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
	
	string key;
	cout<<"Key: ";
	getline(cin, key);

	transform(key.begin(), key.end(), key.begin(), ::toupper);
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());

	string cipher = encrypt(text, key);
	cout<<"Ciphertext: "<<cipher<<endl;
	cout<<"Result: "<<decrypt(cipher, key);
	
	return 0;
}