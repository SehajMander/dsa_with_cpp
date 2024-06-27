#include<iostream>
using namespace std;

void triangle(int n){
    for(int i=0; i<n;i++){ //rows
        for(int j=0; j<n-i-1;j++){
            cout<<" ";
        }
        
        for(int stars = 0; stars < i+1; stars++){
            if(stars!=0){
                cout<<" ";
            }
            
            cout<<"*";
        }
        
        cout<<endl;
    }
    // int i, k, flag = 1;
    
    // for(int i=1, k=0; i<=2*n-1; i++){
    //     //spaces
    //     if(i < n-k){
    //         cout<<" ";
    //     } else{
    //         //stars
    //         if(flag){
    //             cout<<"*";
    //         } else{
    //             cout<<" ";
    //         }
            
    //         flag = 1-flag;
    //     }
        
    //     //spaces - newline
    //     if(i == n+k){
    //         k++;
    //         cout<<endl;
            
    //         //pattern complete
    //         if(i == 2*n-1){
    //             break;
    //         }
            
    //         i = 0;
    //         flag = 1;
    //     }
    // }
}

int main(){
    int n = 6;
    
    triangle(n);
    return 0;
}