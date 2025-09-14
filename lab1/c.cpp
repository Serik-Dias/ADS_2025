#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<char>w1;
    stack<char>w2;
    string word1, word2;
    cin >> word1 >> word2;
    for(int i = 0; i < word1.length(); i++){
        
        if(word1[i] == '#'){
            w1.pop();
        }
        if(word1[i] != '#'){
        w1.push(word1[i]);
    }
}
    for(int i = 0; i < word2.length(); i++){
       
        if(word2[i] == '#'){
            w2.pop();
        }
         if(word2[i] != '#'){
        w2.push(word2[i]);
    }
    }
    if(w1.size() != w2.size()){
        cout << "No";
    }else{
        while(!w1.empty() && !w2.empty())
            if(w1.top() != w2.top()){
                cout << "No";
                break;
            }else if(w1.top() == w2.top()){
                w1.pop();
                w2.pop();
            }
        }
        if(w1.empty() && w2.empty()){
            cout << "Yes";
        }


    return 0;
}