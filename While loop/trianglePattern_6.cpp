#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n(rows) : ";
    cin>>n;
    
    int i = 1;
    char c = 'A';
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<c<<" ";
            j = j+1;
        }
        c = c+1;
        cout<<endl;
        i = i+1;
    }

    return 0;
}
