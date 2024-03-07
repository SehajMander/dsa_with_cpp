#include<iostream>
using namespace std;

long long sumMatrix(long long n, long long q) {
    long long int first = n + 1;
    long long int rem = q - first;
    long long int res;
    if(rem < 0){
        res = n + rem;
    } 
    else {
        res = n - rem;
    }
    
    if(res > 0){
        return res;  
    }    
    else{
        return 0;
    }
    // long long arr[n][n];
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         arr[i][j] = i+j+2;
    //     }
    // }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
 
    // int count = 0;
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(arr[i][j] == q){
    //             count++;
    //         }
    //     }
    // } 
    // return count;
}

int main(){
    long long n;
    cout<<"Enter the size of array : ";
    cin>>n;
    long long q;
    cout<<"Enter the value to be found : ";
    cin>>q;
    long long sol = sumMatrix(n, q);
    cout<<"Answer : "<<sol<<endl;
    return 0;
}