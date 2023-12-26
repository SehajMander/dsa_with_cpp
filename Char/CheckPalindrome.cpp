#include<iostream>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch -'A' +'a';
        return temp;
    }
}

bool checkPalindrome(char name[], int n){
    int start = 0;
    int end = n-1;

    while(start<end){
        if(toLowerCase(name[start]) != toLowerCase(name[end])){
            return 0;
        }
        else{
            start++;
            end--;
        }
    }
    return 1;
}

int getLength(char name[]){
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){
        count++;
    }

    return count;
}

int main(){
    char name[20];
    cout<<"Enter your name : ";
    cin>> name;

    cout<<"Your name is : "<<name<<endl;
    int len = getLength(name);
    cout<<"Length of your name is : "<<len<<endl;

    cout<<"Palindrome or not? : "<<checkPalindrome(name, len)<<endl;

    return 0;
}