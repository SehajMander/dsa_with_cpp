#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number to be reversed : ";
    cin>>n;

    int reverse = 0;
    int flag = 0;
    while(n!=0){
        int rem = n%10;
        
        if(reverse > INT32_MAX/10 || reverse <INT32_MIN/10){
            flag = 1;
        }

        reverse = reverse*10 + rem;
        n = n/10;
    }

    if(flag == 1){
        cout<<"Oops! Reversed number was out of range."<<endl;
    } else{
        cout<<"The reversed number is : "<<reverse<<endl;
    }

    return 0;
}