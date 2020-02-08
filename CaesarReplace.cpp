#include <bits/stdc++.h>

using namespace std;

char mostFreqChar(string text) {
    
    int max = 0;
    int count = 0;
    char maxChar;
    
    for(char ch = 'A'; ch <= 'Z'; ++ch) {
        
        count = 0;
        
        for(int i = 0; i < text.length(); ++i)
        {
            if(text[i] == ch) {
                count++;
            }
        }
        
        if(count > max)
        {
            max = count;
            maxChar = ch;
        }
    }
    
    return maxChar;
}

string caesar(string text, int shift) { 

    string result = ""; 
  
    for (int i = 0; i < text.length(); ++i) { 
        
        // eliminate white spaces
        if(text[i] != ' ') {
            
            result += char(int(text[i] + shift - 65) % 26 + 65); 
        }
    } 
  
    return result; 
}

int main() {
    
    string text;
	cout<<"Plain text: ";
	getline(cin, text);
	
	// transform string to upper if necessary
    transform(text.begin(), text.end(), text.begin(), ::toupper);
	
	int shift;
	cout<<"Shift: ";
	cin>>shift;
	
	string cipher = caesar(text, shift);
	
	cout<<"Cipher text: "<<cipher<<endl;
      
    char ch = mostFreqChar(cipher);
    
    cout<<"Most frequent character "<<ch<<endl<<endl;
    cout<<"Replace with R: "<<caesar(cipher, 26 - ch + 'R')<<"\n";
    cout<<"Replace with T: "<<caesar(cipher, 26 - ch + 'T')<<"\n";
    cout<<"Replace with N: "<<caesar(cipher, 26 - ch + 'N')<<"\n";
    cout<<"Replace with S: "<<caesar(cipher, 26 - ch + 'S')<<"\n";
    cout<<"Replace with L: "<<caesar(cipher, 26 - ch + 'L')<<"\n";
    cout<<"Replace with A: "<<caesar(cipher, 26 - ch + 'A')<<"\n";
    
    return 0;
}
