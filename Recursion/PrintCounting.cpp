#include<iostream>
using namespace std;

void print(int n){
    //base case 
    if(n==0){
        return ;
    }

    //tail recursion
    // cout<< n << " ";
    // print(n-1);

    //head recursion
    print(n-1);
    cout<< n << " ";
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    cout<<"Counting : "<<endl;
    print(n);

    return 0;
}