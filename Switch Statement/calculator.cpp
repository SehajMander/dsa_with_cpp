#include<iostream>

using namespace std;

int main(){
    int a;
    cout<<"Enter the value of a : ";
    cin>>a;
    
    int b;
    cout<<"Enter the value of b : ";
    cin>>b;

    char operation;
    cout<<"Give the operation to be performed on given numbers : ";
    cin>> operation;

    int ans;

    switch (operation)
    {
    case '*':
        ans = a*b;
        break;
    case '/':
        ans = a/b;
        break;
    case '%':
        ans = a%b;
        break;
    case '+':
        ans = a+b;
        break;
    case '-':
        ans = a-b;
        break;
    default:
        cout<<"Invalid operator entered!"<<endl;
        break;
    }

    cout<<"Answer : "<< ans<<endl;

    return 0;
}