#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n(rows) : ";
    cin>>n;

    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=n-i+1){
            cout<<j;
            j = j+1;
        }

        int star = 2*(i-1);
        while(star){
            cout<<"*";
            star = star-1;
        }

        int k = n-i+1;
        while(k>0){
            cout<<k;
            k = k-1;
        }
        cout<<endl;
        i= i+1;
    }

    return 0;
}