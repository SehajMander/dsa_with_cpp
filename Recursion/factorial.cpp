#include<iostream>
using namespace std;

int factorial(int n){
    // base case
    if(n == 0){
        return 1;
    }

    int fact = factorial(n-1);
    int ans = n * fact;

    return ans;
}

int main(){
    int n;
    cout<<"Enter a number whose factorial is to be calculated : ";
    cin>>n;

    int finalAns = factorial(n);
    cout<<"Factorial of "<<n<<" is "<<finalAns<<endl;

    return 0;  
}
