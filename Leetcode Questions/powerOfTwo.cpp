#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int flag = 0;

    for(int i=0; i<=30; i++){
        int ans = pow(2,i);

        if(ans==n){
            flag = 1;
        }

    }

    if(flag == 0){
        cout<<"False! Given number is not a power of 2."<<endl;
    } else{
        cout<<"True! Given number is a power of 2."<<endl;
    }

    return 0;
}