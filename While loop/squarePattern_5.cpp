#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n(rows) : ";
    cin>>n;
    
    int i = 1;
    char val = 'A';
    while(i<=n){
        int j = 1;
        while(j<=n){
            cout<<val<<" ";
            j = j+1;
        }
        cout<<endl; 
        val = val+1;
        i=i+1;
        
    }

    return 0;
}
