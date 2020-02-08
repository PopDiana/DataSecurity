#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>>letters(26);
char matrix[5][5];


string encrypt(string text) {
	
	string result;
	deque<int> deq;
	
	int i = 0, j, k;
	while (i < text.length()) {
		
		for (k = i + 4; i < text.length() && i <= k; ++i) {
			deq.push_back(letters[text[i] - 'A'].first);
		}
		for (j = k - 4; j < text.length() && j <= k; ++j) {
			deq.push_back(letters[text[j] - 'A'].second);
		}
	}
	
	for (auto it = deq.begin(); it != deq.end(); ++it) {	
		auto val = *it;
		it++;
		result += matrix[val][*it];
	}
	
	return result;
}

string decrypt(string text) {
	
	string result;
	int i = 0;
	while (i < text.length()) {
		
		deque<int> deq;
		int k = i + 4;
		
		for (; i < text.length() && i <= k; ++i) {
			
			deq.push_back(letters[text[i] - 'A'].first);
			deq.push_back(letters[text[i] - 'A'].second);
		}
		
		for (int j = 0; j < deq.size() / 2;  ++j) {
			
			result += matrix[deq[j]][deq[j+ deq.size() / 2]];
		}
			
	}
	return result;
}

void playfair(string key)
{
	bool found[26] = {0};
	int k = 0;

	for (int i = 0; i < key.length(); ++i) {
		
		if (key[i] != ' ' && !found[key[i] - 'A'])
		{
			if (key[i] == 'I' || key[i] == 'J')
			{
				matrix[k / 5][k % 5] = 'I';
				found['I' - 'A'] = found['J' - 'A'] = true;
				letters['I' - 'A'] = { k / 5, k % 5 };
			}
			else
			{
				matrix[k / 5][k % 5] = key[i];
				found[key[i] - 'A'] = true;
				letters[key[i] - 'A'] = { k / 5, k % 5 };
			}
			k++;
		}
	}
	for (int i = 0; i < 26; ++i) {
		
		if (!found[i])
		{
			if (i + 'A' == 'I') {
				found['J' - 'A'] = true;
			}
			matrix[k / 5][k % 5] = 'A' + i;
			letters[i] = { k / 5, k % 5 };
			k++;
		}
	}
}

int main()
{
	string text;
	cout<<"Plainext: ";
	
	getline(cin, text);
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	replace(text.begin(), text.end(), 'J', 'I');
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
	
	string key;
	cout<<"Key: ";
	getline(cin, key);
	transform(key.begin(), key.end(), key.begin(), ::toupper);
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
	
	playfair(key);
	string cipher = encrypt(text);
	
	cout<<"Ciphertext: "<<cipher<<endl;
	cout<<"Result: "<<decrypt(cipher);
	
	return 0;
}