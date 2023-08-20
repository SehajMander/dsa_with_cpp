#include <iostream>

using namespace std;

int main()
{
    int n;
    //for n = 4
    cout<<"Enter the value of n(rows) : ";
    cin>>n;
    
    int i = 0;
    while(i<n){
        int j = 0;
        char c = 'D'-i;
        while(j<=i){
            cout<<c<<" ";
            c = c+1;
            j = j+1;
        }
        cout<<endl;
        i = i+1;
    }

    return 0;
}
