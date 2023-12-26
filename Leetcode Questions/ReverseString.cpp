#include<iostream>
using namespace std;

void reverseString(char name[], int n){
    int start = 0;
    int end = n-1;

    while(start<end){
        swap(name[start++], name[end--]);
    }
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

    reverseString(name, len);
    cout<<"Your reversed name is : "<<name<<endl;

    return 0;
}