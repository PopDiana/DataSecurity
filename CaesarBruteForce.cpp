#include <bits/stdc++.h>

using namespace std;

string caesar(string text, int shift) { 

    string result = ""; 
  
    for (int i = 0; i < text.length(); ++i) { 
        
        // eliminate white spaces
        if(text[i] != ' ') {
            
            if (isupper(text[i])) {
                result += char(int(text[i] + shift - 65) % 26 + 65); 
            } else {
                result += char(int(text[i] + shift - 97) % 26 + 97);
            }
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
    
    for (int i = 1; i < 25; ++i)
    {
        cout<<"Shift "<<(i > 9 ? "" : "0")<<i<<": "<<caesar(cihper, 26 - i)<<endl;
    }
    
    return 0;
}
