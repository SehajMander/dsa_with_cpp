#include<iostream>
using namespace std;

bool isPalindrome(string& str, int i, int j){
    //base case
    if(i>j){
        return true;
    }

    if(str[i] != str[j]){
        return false;
    }
    else{
        return isPalindrome(str, i+1, j-1);
    }
}

int main(){
    string str;
    cout<<"Enter the string : ";
    cin>>str;

    int ans = isPalindrome(str, 0, str.length()-1);
    if(ans){
        cout<<"String is Palindrome!!"<<endl;
    }
    else{
        cout<<"Not a Palindrome :("<<endl;
    }

    return 0;
}