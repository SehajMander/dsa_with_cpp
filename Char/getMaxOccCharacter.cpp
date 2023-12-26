#include<iostream>
using namespace std;

char getMaxOccChar(string s){
    int arr[26] = {0};

    //create an array for the count of characters
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        //lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    //find maximum occuring character
    int maxi = -1;
    int ans = -1;
    for(int i=0; i<26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
}

int main(){
    string s;
    cout<<"Enter you string : ";
    cin>> s;

    cout<<"The maximum occuring character in the given string is : "<<getMaxOccChar(s)<<endl;

    return 0;
}