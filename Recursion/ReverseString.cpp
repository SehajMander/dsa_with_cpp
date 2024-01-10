#include<iostream>
using namespace std;

void reverseString(string& str, int i, int j){
    //base case
    if(i>j){
        return ;
    }

    //processing
    swap(str[i], str[j]);
    i++;
    j--;

    //recursive call
    reverseString(str, i, j);
}

int main(){
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    int n = str.length() - 1;
    reverseString(str, 0, n);
    cout<<"Reversed String is : "<<str<<endl;

    return 0;
}