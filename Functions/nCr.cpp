#include<iostream>

using namespace std;

int factorial(int a){
    int fact = 1;
    for(int i=1; i<=a; i++){
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r){
    int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n-r);

    int ans = numerator/denominator;
    return ans;
}

int main(){
    int num1;
    cout<<"Enter the value of num1 : ";
    cin>>num1;

    int num2;
    cout<<"Enter the value of num2 : ";
    cin>>num2;

    cout<<"The nCr value for given number is : "<<nCr(num1,num2)<<endl;

    return 0;
}

