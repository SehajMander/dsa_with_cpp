#include<iostream>

using namespace std;

int power(int a, int b){
    int ans = 1;
    for(int i = 1; i<=b; i++){
        ans = ans*a;
    }
    return ans;
}

int main(){
    int a;
    cout<<"Enter the value of a (number) : ";
    cin>>a;
    int b;
    cout<<"Enter the value of b (power) : ";
    cin>>b;

    cout<<"The end answer is : "<<power(a,b);

    return 0;


}