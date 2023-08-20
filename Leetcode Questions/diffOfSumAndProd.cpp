#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of digit : ";
    cin>>n;

    int prod = 1;
    int sum = 0;

    while(n!=0){
        int digit = n%10;
        prod = prod * digit;
        sum = sum + digit;
        n = n/10;
    }

    cout<<"Sum : "<<sum<<endl;
    cout<<"Product : "<<prod<<endl;

    int diff = prod - sum;
    cout<<"Difference of product and sum of digits is : "<<diff<<endl;

    return 0;
}