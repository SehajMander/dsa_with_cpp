#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n(rows) : ";
    cin>>n;
    
    int i = 1;
    while(i<=n){
        int j = i;
        // int val = i;
        while(j<2*i){
            // cout<<val<<" ";
            // val = val+1;
            cout<<j<<" ";
            j = j+1;
        }
        cout<<endl;
        i = i+1;
    }

    return 0;
}

