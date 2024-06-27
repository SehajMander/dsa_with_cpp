#include<iostream>
#include<map>

using namespace std;

void frequencyOfWords(string s){
    map<string, int> M;
    string word = "";

    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            //found a word
            if(M.find(word) == M.end()) {
                //word not found in the map
                M.insert(make_pair(word, 1));
                word = "";
            } else{
                //word found in map - update freq
                M[word]++;
                word = "";
            }
        } 
        else{
            //word string formation
            word += s[i];
        }
    }

    //storing the last word
    if(M.find(word) == M.end()){
        M.insert(make_pair(word, 1));
    } else{
        M[word]++;
    }

    //traversal and printing
    for(auto& m : M){
        cout << m.first << " - "
        << m.second
        <<endl;
    }
}

int main(){
    string s = "Geeks For Geeks";

    frequencyOfWords(s);

    return 0;
}

