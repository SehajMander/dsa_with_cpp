#include<iostream>
using namespace std;

int modularExponentiation(int x, int n, int m){
    int res = 1;

    while(n>0){
        if(n&1){
            //odd
            res = (1LL * (res) * (x)%m)%m;
        }
        x = ( 1LL * (x)%m * (x)%m)%m;
        n = n>>1;
    }
    return res;
}

int main(){
    int a, b, m;
    cout<<"Enter the number : ";
    cin>>a;
    cout<<"Enter the power : ";
    cin>>b;
    cout<<"Enter the modulus : ";
    cin>>m;

    cout<<"Answer is : "<<modularExponentiation(a,b,m)<<endl;

    return 0;
}