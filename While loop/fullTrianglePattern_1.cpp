#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n(rows) : ";
    cin>>n;
    
    int i = 1;
    while(i<=n){
        int space = n-i;
        //spaces
        while(space>0){
            cout<<" ";
            space = space-1;
        }

        //numbers 1 to n
        int j = 1;
        while(j<=i){
            cout<<j;
            j = j+1;
        }

        //numbers n-1 to 1
        
        int k = i-1;
        while(k>=1){
            cout<<k;
            k = k-1;
        }

        cout<<endl;
        i = i+1;
    }

    return 0;
}