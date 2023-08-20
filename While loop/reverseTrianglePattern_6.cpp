#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n(rows) : ";
    cin>>n;
    
    int i = 1;
    while(i<=n){
        int space = 0;
        while(space<i-1){
            cout<<" ";
            space = space+1;
        }
        
        int j = i;
        while(j<=n){
            cout<<j;
            j=j+1;
        }
        cout<<endl;
        i = i+1;
    }

    return 0;
}
