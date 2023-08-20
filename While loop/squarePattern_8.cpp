#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n(rows) : ";
    cin>>n;
    
    int i = 0;
    while(i<n){
        int j = 0;
        char c = 'A'+i;
        while(j<n){
            cout<<c<<" ";
            c = c+1;
            j = j+1;
        }
        cout<<endl;
        i = i+1;
    }

    return 0;
}
