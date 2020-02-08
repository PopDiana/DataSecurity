#include <bits/stdc++.h>

using namespace std;

char PlayFairMatrix[10][10];
vector<pair<int,int>>letterPosition1(26);
vector<pair<int,int>>letterPosition2(26);
vector<pair<int,int>>letterPosition3(26);
vector<pair<int,int>>letterPosition4(26);

string encrypt(string text)
{
	if (text.length() % 2 == 1) 
	{
		text = text + 'X';
	}
	string cipher(text.length(), ' ');
	for (int i = 0; i < text.length(); i += 2)
	{
		cipher[i] = PlayFairMatrix[letterPosition1[text[i] - 'A'].first][letterPosition2[text[i + 1] - 'A'].second];
		cipher[i + 1] = PlayFairMatrix[letterPosition2[text[i + 1] - 'A'].first][letterPosition1[text[i] - 'A'].second];
	}
	return cipher;
}

string decrypt(string cipher)
{
	string text(cipher.length(), ' ');
	for (int i = 0; i < cipher.length(); i += 2)
	{
		text[i] = PlayFairMatrix[letterPosition3[cipher[i] - 'A'].first][letterPosition4[cipher[i + 1] - 'A'].second];
		text[i + 1] = PlayFairMatrix[letterPosition4[cipher[i + 1] - 'A'].first][letterPosition3[cipher[i] - 'A'].second];
	}
	return text;
}

void createMatrix(string key1, string key2)
{
	bool exist[26] = {0};
	int nr = 0;
	for (int i = 0; i < key1.length(); i++) 
	{
		if (key1[i] != ' ' && exist[key1[i] - 'A'] == false)
		{
			if (key1[i] == 'I' || key1[i] == 'J')
			{
				PlayFairMatrix[nr / 5][nr % 5 + 5] = 'I';
				letterPosition3['I' - 'A'] = { nr / 5,nr % 5 + 5 };
				exist['I' - 'A'] = exist['J' - 'A'] = true;
			}
			else
			{
				PlayFairMatrix[nr / 5][nr % 5 + 5] = key1[i];
				letterPosition3[key1[i] - 'A'] = { nr / 5,nr % 5 + 5 };
				exist[key1[i] - 'A'] = true;
			}
			nr++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (exist[i] == false)
		{
			if (i + 'A' == 'I') 
			{
				exist['J' - 'A'] = true;
			}
			PlayFairMatrix[nr / 5][nr % 5 + 5] = 'A' + i;
			letterPosition3[i] = { nr / 5,nr % 5 + 5 };
			nr++;
		}
	}
	nr = 0;
	for (int i = 0; i < 26; i++)
	{
		exist[i] = false;
	}
	for (int i = 0; i < key2.length(); i++)
	{
		if (key2[i] != ' ' && exist[key2[i] - 'A'] == false)
		{
			if (key2[i] == 'I' || key2[i] == 'J')
			{
				PlayFairMatrix[nr / 5 + 5][nr % 5] = 'I';
				letterPosition4['I' - 'A'] = { nr / 5 + 5,nr % 5 };
				exist['I' - 'A'] = exist['J' - 'A'] = true;
			}
			else
			{
				PlayFairMatrix[nr / 5 + 5][nr % 5] = key2[i];
				letterPosition4[key2[i] - 'A'] = { nr / 5 + 5,nr % 5 };
				exist[key2[i] - 'A'] = true;
			}
			nr++;
		}
	}
	for (int i = 0; i < 26; i++) 
	{
		if (exist[i] == false)
		{
			if (i + 'A' == 'I')
				exist['J' - 'A'] = true;
			PlayFairMatrix[nr / 5 + 5][nr % 5] = 'A' + i;
			letterPosition4[i] = { nr / 5 + 5,nr % 5 };
			nr++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (i != 9)
		{
			if (i > 9)
			{
				PlayFairMatrix[(i - 1) / 5][(i - 1) % 5] = PlayFairMatrix[(i - 1) / 5 + 5][(i - 1) % 5 + 5] = 'A' + i;
				letterPosition1[i] = { (i - 1) / 5,(i - 1) % 5 };
				letterPosition2[i] = { (i - 1) / 5 + 5,(i - 1) % 5 + 5 };
			}
			else
			{
				PlayFairMatrix[i / 5][i % 5] = PlayFairMatrix[i / 5 + 5][i % 5 + 5] = 'A' + i;
				letterPosition1[i] = { i / 5,i % 5 };
				letterPosition2[i] = { i / 5 + 5,i % 5 + 5 };
			}
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
	text.erase(remove_if(text.begin(), text.end(), isspace), text.end());
	
	for (int i = 0; i < text.length() - 1; i++)
	{
		if (text[i] == text[i + 1])
		{
			text[i + 1] = 'X';
		}
	}
		
	string key1, key2;
	
	cout<<"Key 1: ";
	getline(cin, key1);
	cout<<"Key 2: ";
	getline(cin, key2);

	transform(key1.begin(), key1.end(), key1.begin(), ::toupper);
	key1.erase(remove_if(key1.begin(), key1.end(), isspace), key1.end());
	transform(key2.begin(), key2.end(), key2.begin(), ::toupper);
	key2.erase(remove_if(key2.begin(), key2.end(), isspace), key2.end());
	
	createMatrix(key1, key2);
	
	string cipher = encrypt(text);
	
	cout<<"Ciphertext: "<< cipher << "\n";
	cout<<"Result: "<< decrypt(cipher);
	
	return 0;
}
