#include <bits/stdc++.h>

using namespace std;

char alphabetMatrix[5][5],keyMatrix[5][5];
vector<pair<int, int>> posAlphabet(26), posKey(26);

string encrypt(string text) {
    
    string result; 
    int dif;
    
    for(int i = 0; i < text.length() - 1; ++i) {
        
        if(text[i] == text[i + 1]) {
			
            if(posAlphabet[text[i] - 'A'].second == posKey['X' - 'A'].second) {
                result += text[i];
                result += 'X';
                
            } else {
                if(posAlphabet[text[i]- 'A'].second < posKey['X' - 'A'].second) {
                    dif = posKey['X' - 'A'].second - posAlphabet[text[i]- 'A'].second;
                    
                    result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second + dif];
                    result += keyMatrix[posKey['X' - 'A'].first][posKey['X' - 'A'].second - dif];
                } else {
                    dif = posAlphabet[text[i]- 'A'].second - posKey['X' - 'A'].second;
                    
                    result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second - dif];
                    result += keyMatrix[posKey['X' - 'A'].first][posKey['X' - 'A'].second + dif];
                }
            }
            
        } else {
           
           if(posAlphabet[text[i] - 'A'].second == posKey[text[i + 1] - 'A'].second){
               result += alphabetMatrix[posAlphabet[text[i] - 'A'].first][posAlphabet[text[i] - 'A'].second];
               result += keyMatrix[posKey[text[i + 1] - 'A'].first][posKey[text[i + 1] - 'A'].second];
               
               
           } else if(posAlphabet[text[i]- 'A'].second < posKey[text[i + 1] - 'A'].second){
               dif = posKey[text[i+1] - 'A'].second - posAlphabet[text[i]- 'A'].second;
                    
               result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second + dif];
                result += keyMatrix[posKey[text[i+1] - 'A'].first][posKey[text[i+1] - 'A'].second - dif];
           }else{
               dif = posAlphabet[text[i]- 'A'].second - posKey[text[i+1] - 'A'].second;
                    
                result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second - dif];
                result += keyMatrix[posKey[text[i+1] - 'A'].first][posKey[text[i+1] - 'A'].second + dif];
                
           }
        }
        
        i++;
    }
    
    return result;
    
}

string decrypt(string text) {
    
    string result;
    int dif;
    
    for(int i = 0; i < text.length() - 1; ++i) {

           if(posAlphabet[text[i] - 'A'].second == posKey[text[i + 1] - 'A'].second){
               result += alphabetMatrix[posAlphabet[text[i] - 'A'].first][posAlphabet[text[i] - 'A'].second];
               
               if(keyMatrix[posKey[text[i + 1] - 'A'].first][posKey[text[i + 1] - 'A'].second] == 'X' && i + 1 != text.length()-1){
                   
                   result += alphabetMatrix[posAlphabet[text[i] - 'A'].first][posAlphabet[text[i] - 'A'].second]; 
               } else{
                  result += keyMatrix[posKey[text[i + 1] - 'A'].first][posKey[text[i + 1] - 'A'].second]; 
               }
               
           } else if(posAlphabet[text[i]- 'A'].second < posKey[text[i + 1] - 'A'].second){
               dif = posKey[text[i+1] - 'A'].second - posAlphabet[text[i]- 'A'].second;
                    
                result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second + dif];
                if(keyMatrix[posKey[text[i+1] - 'A'].first][posKey[text[i+1] - 'A'].second - dif] == 'X' && i + 1 != text.length() -1){
                   
                   result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second + dif]; 
               } else{
                  result += keyMatrix[posKey[text[i+1] - 'A'].first][posKey[text[i+1] - 'A'].second - dif]; 
               }
                
           }else{
               dif = posAlphabet[text[i]- 'A'].second - posKey[text[i+1] - 'A'].second;
                    
                result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second - dif];
               if(keyMatrix[posKey[text[i+1] - 'A'].first][posKey[text[i+1] - 'A'].second + dif] == 'X' && i + 1 != text.length() -1){
                   
                   result += alphabetMatrix[posAlphabet[text[i]- 'A'].first][posAlphabet[text[i]- 'A'].second - dif];
               } else{
                  result += keyMatrix[posKey[text[i+1] - 'A'].first][posKey[text[i+1] - 'A'].second + dif];
               }
                
                
           }
        
        i++;
    }
    
    if(result.back() == 'X') {
        result.back() = ' ';
    }
    
    return result;
    
}

void twoSquare(string key) {
    
    bool found[26] = {0};
    int it1 = 0, it2 = 0;
    for(int i = 0; i < key.length(); ++i) {
        
        if(found[key[i]-'A'] == false) {
            keyMatrix[it1 / 5][it1 % 5] = key[i];
            posKey[key[i] - 'A'] = { it1 / 5 , it1 % 5 };
            found[key[i]-'A'] = true;
            it1++;
        }
    }
    
    for(int i = 0; i < 26; ++i) {
        
        if(i + 'A' != 'J') {
            
            if(found[i] == false ) {
                keyMatrix[it1 / 5][it1 % 5] = i + 'A';
                posKey[i] = { it1 / 5, it1 % 5};
                
                it1++;
            }
        
       
            alphabetMatrix[it2 / 5][it2 % 5] =  i + 'A';
            posAlphabet[i] = { it2 / 5, it2 % 5 };
            it2++;
        
        }
    }
 
}

int main() {
    
    string text;
    cout<<"Plaintext: ";
    getline(cin, text);

    transform(text.begin(), text.end(), text.begin(), ::toupper);
	replace(text.begin(), text.end(), 'J', 'I');
	text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
	
    if(text.length() % 2 != 0) {
        text += 'X';
    }
    
    string key;
    cout<<"Key: ";
    getline(cin, key);
     
    transform(key.begin(), key.end(), key.begin(), ::toupper);
	replace(key.begin(), key.end(), 'J', 'I');
	key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
  
    twoSquare(key);
    
    string cipher = encrypt(text);
    
    cout<<"Ciphertext: "<<cipher<<endl;
    cout<<"Result: "<<decrypt(cipher);

    return 0;
}
