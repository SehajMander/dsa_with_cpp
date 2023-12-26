#include<iostream>
using namespace std;

//checking if the characters are valid or not
bool valid(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
        return 1;
    }
    else{
        return 0;
    }
}

//converting to lowercase characters
char toLowerCase(char ch){
    if((ch >='a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

//checking if the given string is palindrome or not
bool checkPalindrome(string s){
    int start = 0;
    int end = s.length() - 1;

    while(start<=end){
        if(s[start] != s[end]){
            return 0;
        }
        else{
            start++;
            end--;
        }
    }
    return 1;
}


//checking palindrome
bool isPalindrome(string s){
    //removing extra characters
    string temp = "";
    for(int i=0; i<s.length(); i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    //converting into lowercase
    for(int i=0; i<temp.length(); i++){
        temp[i] = toLowerCase(temp[i]);
    }

    //checking palindrome
    return checkPalindrome(temp);
}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"Palindrome or not? : "<<isPalindrome(s)<<endl;

    return 0;
}