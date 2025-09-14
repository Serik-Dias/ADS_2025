#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<char>letters;
    string word;
    cin >> word;
    for(int i = 0; i < word.length(); i++){
        if(!letters.empty() && letters.top() == word[i]){
            letters.pop();
        }else if(!letters.empty() && letters.top() != word[i]){
            letters.push(word[i]);
        }
        else if(letters.empty()){
        letters.push(word[i]);
    }

    }
    if(letters.empty()){
        cout << "YES";
        
    }else{
        cout << "NO";
    }

    return 0;
}