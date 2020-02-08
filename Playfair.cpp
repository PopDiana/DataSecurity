#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>>pos(26);
char polybius[5][5];


void genPolybius(string key) {
	
	bool placed[26] = {0}; int j = 0;
	
	for (int i = 0; i < key.length(); ++i) {
		
		if(key[i] != ' ' && placed[key[i] - 'A'] == false) {
			
			if(key[i] == 'I' || key[i] == 'J') {
				
				polybius[j / 5][j % 5] = 'I';
				placed['I' - 'A' ] = placed['J' - 'A'] = true;
				pos['I' - 'A'] = {j / 5, j % 5};
				
			} else {
				
				polybius[j / 5][j % 5] = key[i];
				placed[key[i] - 'A'] = true;
				pos[key[i] - 'A'] = {j / 5, j % 5};
			}
			
			j++;
		}
	}
	for (int i = 0; i < 26; ++i) {
		
		if(placed[i] == false) {
			
			if (i + 'A' == 'I') {
				placed['J' - 'A' ] = true;
			}
			polybius[j/ 5][j % 5] = 'A' + i;
			pos[i] = {j / 5, j % 5};
			
			j++;
		}
	}
}

string decrypt(string text) {
	
	string result(text.length(), ' ');
	
	for (int i = 0; i < text.length(); i += 2) {

		if (text[i] == text[i + 1]) {
			
			result[i] = text[i];
			result[i + 1] = text[i];
			
		} else {
			
			if (pos[text[i] - 'A'].first == pos[text[i + 1] - 'A'].first) {
				
				result[i] = polybius[pos[text[i] - 'A'].first][(pos[text[i] - 'A'].second + 5 - 1) % 5];
				result[i + 1] = polybius[pos[text[i + 1] - 'A'].first][(pos[text[i + 1] - 'A'].second + 4) % 5];
				
			} else {
				
				if (pos[text[i] - 'A'].second == pos[text[i + 1] - 'A'].second) {
					
					result[i] = polybius[(pos[text[i] - 'A'].first + 4) % 5][pos[text[i] - 'A'].second];
					result[i + 1] = polybius[(pos[text[i + 1] - 'A'].first + 4) % 5][pos[text[i + 1] - 'A'].second];
					
				} else {
					
					result[i] = polybius[pos[text[i] - 'A'].first][pos[text[i + 1] - 'A'].second];
					result[i + 1] = polybius[pos[text[i + 1] - 'A'].first][pos[text[i] - 'A'].second];
				
				}
			}
		}
		
	}
	
	return result;
}

string encrypt(string text) {
	
	if (text.length() % 2 == 1) {
		
		text = text + 'X';
	}
	
	string result(text.length(), ' ');
	
	
	for (int i = 0; i < text.length(); i+=2) {
		
		if (pos[text[i] - 'A'].first == pos[text[i + 1] - 'A'].first) {
			
			result[i] = polybius[pos[text[i] - 'A'].first][(pos[text[i] - 'A'].second + 1) % 5];
			result[i + 1] = polybius[pos[text[i + 1] - 'A'].first][(pos[text[i + 1] - 'A'].second + 1) % 5];
			
		} else {
			
			if(pos[text[i] - 'A'].second == pos[text[i + 1] - 'A'].second) {
				
				result[i] = polybius[(pos[text[i] - 'A'].first + 1) % 5][pos[text[i] - 'A'].second];
				result[i + 1] = polybius[(pos[text[i + 1] - 'A'].first + 1) % 5][pos[text[i + 1] - 'A'].second];
				
			} else {
				
				result[i] = polybius[pos[text[i] - 'A'].first][pos[text[i + 1] - 'A'].second];
				result[i + 1] = polybius[pos[text[i + 1] - 'A'].first][pos[text[i] - 'A'].second];
			}
		}
	}
	return result;
}



int main() {
	
	string text, key;
	
	cout<<"Plaintext: ";
	getline(cin, text);
	
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	replace(text.begin(), text.end(), 'J', 'I');
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
	
	for (int i = 0; i < text.length() - 1; ++i) 
	{		
		if (text[i] == text[i + 1])
		{
			text.insert(i + 1, "X");
		}
	}
	
	cout<<"Key: ";
	getline(cin, key);
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
	transform(key.begin(), key.end(), key.begin(), ::toupper);

	genPolybius(key);
	
	string cipher = encrypt(text);
	cout<<"Ciphertext: "<<cipher<<endl;
	
	string result = decrypt(cipher);
	
	cout<<"Result: "<<result<<endl;

	return 0;
}