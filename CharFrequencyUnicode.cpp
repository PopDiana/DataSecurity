#include <bits/stdc++.h>

using namespace std;

map<wchar_t, int> freq(wstring text) {
    
    map<wchar_t, int> letters;
    
    int i = 0;
    
    while(text[i]) {
        
        if(text[i] != ' ') {
            auto found = letters.find(text[i]);
            if(found != letters.end()) {
                found->second++; 
            } else {
                letters.insert(pair<wchar_t, int>(text[i], 1));
            }
        }
        
        i++;
    }
    
    return letters;
    
}

int main() {
    
    setlocale(LC_ALL, "");
    
    wcout<<"Text:"<<endl;
    wstring text;
	// reads a line for test, put in a while for text longer that 256 chars
    getline(wcin, text);
    wcout<<endl;
    
    locale loc("");
     
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
    
    auto letters = freq(text);
    
    for(auto it = letters.begin(); it != letters.end(); ++it) {
        wcout<<it->first;
        wcout<<" - "<<it->second<<endl;
    }
    
    return 0;
}
