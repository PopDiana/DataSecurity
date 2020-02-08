#include <bits/stdc++.h>

using namespace std;

int charFrequency(string text, char ch) {
    
    int freq = 0;
    
    for (int i = 0; i < text.length(); ++i) {
        if(toupper(text[i]) == ch){
            freq++;
        }
    }
    
    return freq;
}


int main()
{
    cout<<"Your text: ";
    string text;
    getline(cin, text);
    
    for(char ch = 'A'; ch <= 'Z'; ch++){
       cout<<ch<<" - "<<charFrequency(text, ch)<<"\n"; 
    }

    return 0;
}