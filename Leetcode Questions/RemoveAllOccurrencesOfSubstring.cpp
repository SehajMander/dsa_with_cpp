#include<iostream>
using namespace std;

string removeOccurrences(string s, string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }

    return s;
}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    string part;
    cout<<"Enter the part to be removed : ";
    cin>>part;

    cout<<"The left string is : "<<removeOccurrences(s, part)<<endl;

    return 0;
}