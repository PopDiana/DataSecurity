#include<bits/stdc++.h>
using namespace std;

vector<tuple<int, int,int>>pos(27);
char trifidMatrix[3][3][3];

void trifid(string key) {
	
	bool found[26] = {0};
	int it = 0;

	for (int i = 0; i < key.length(); ++i) {
		
		if (key[i] != ' '&& !found[key[i] - 'A']) {
			
			trifidMatrix[it/9][(it%9)/3][(it%9)%3]= key[i];
			found[key[i] - 'A'] = true;
			pos[key[i] - 'A'] = make_tuple(it/9, (it%9)/3, (it%9)%3);
			it++;
		}
	}
	for (int i = 0; i < 26; i++) {
		
		if (!found[i]) {
			
			trifidMatrix[it/9][(it%9)/3][(it%9)%3] = i + 'A';
			pos[i] = make_tuple(it/9, (it%9)/3, (it%9)%3);
			it++;
		}
	}
	
	trifidMatrix[2][2][2] = '+';
	pos[26] = make_tuple(2, 2, 2);
}

string encrypt(string text) {
	
	int matrix[3][100];
	int x1, x2, x3;
	string result;
	
	for(int i=0; i < text.length(); ++i) {
		
		x1 = get<0>(pos[text[i] - 'A']); matrix[0][i] = x1;
		x2 = get<1>(pos[text[i] - 'A']); matrix[1][i] = x2;
		x3 = get<2>(pos[text[i] - 'A']); matrix[2][i] = x3;
		
	}
	
	for (int i = 0; i < text.length()/5; ++i) {
		
		int it = 0;
		
		for (int j = i*5; j < i*5 + 5; ++j) {
			
			x1 = matrix[(it/5)][i*5+it%5]; it++;
			x2 = matrix[(it/5)][i*5+it%5]; it++;
			x3 = matrix[(it/5)][i*5+it%5]; it++;
			result += trifidMatrix[x1][x2][x3];
		}
	}
	
	return result;
}

string decrypt(string text) {
	
	string result;
	int matrix[3][100];
	int x1, x2, x3;
	int it = 0;
	
	for (int i = 0; i < text.length(); ++i) {
		
		if(text[i] != '+') {
			
			x1 = get<0>(pos[text[i] - 'A']);
			x2 = get<1>(pos[text[i] - 'A']); 
			x3 = get<2>(pos[text[i] - 'A']); 
			
		} else {
			x1 = x2 = x3 = 2;
		}
		
		matrix[(it/5)][(i/5)*5+it%5] = x1; it++;
		matrix[(it/5)][(i/5)*5+it%5] = x2; it++;
		matrix[(it/5)][(i/5)*5+it%5] = x3; it++;
		
		it = it % 15;
	}

	for (int i = 0; i < text.length(); ++i) {
		
		x1 = matrix[0][i];
		x2 = matrix[1][i];
		x3 = matrix[2][i];
		
		result += trifidMatrix[x1][x2][x3];
	}

	return result;
}



int main() {
	
	string text;
	cout<<"Plaintext: ";
	getline(cin, text);
	
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	replace(text.begin(), text.end(), 'J', 'I');
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
	
	string key;
	cout<<"Key: ";
	getline(cin, key);

	transform(key.begin(), key.end(), key.begin(), ::toupper);
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
	
	trifid(key);
	string cipher = encrypt(text);
	cout<<"Ciphertext: "<<cipher<<endl;
	cout<<"Result: "<<decrypt(cipher);
	
	return 0;
}