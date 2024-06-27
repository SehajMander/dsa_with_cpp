#include<iostream>
#include<cstring>
using namespace std;

//Approach - 1:
// void productExceptItself(int arr[], int n){
//     //base case
//     if(n == 1){
//         cout<< 0 <<endl;
//         return;
//     }

//     int* prefix = new int[sizeof(int) * n];
//     int* suffix = new int[sizeof(int) * n];
//     int* prod = new int[sizeof(int) * n];

//     prefix[0] = 1;
//     suffix[n-1] = 1;

//     //prefix array
//     for(int i=1; i<n; i++){
//         prefix[i] = prefix[i-1]*arr[i-1];
//     }

//     //suffix array
//     for(int i=n-2; i>=0; i--){
//         suffix[i] = suffix[i+1]*arr[i+1];
//     }

//     //prod array
//     for(int i = 0; i<n; i++){
//         prod[i] = prefix[i]*suffix[i];
//     }

//     //traversal and printing
//     for(int i=0; i<n; i++){
//         cout<<prod[i]<<" ";
//     }

//     return;
// }

//Approach 2 :
void productExceptItself(int arr[], int n){
    //base case
    if(n == 1){
        cout<< 0 <<endl;
        return;
    }

    int* prod = new int[(sizeof(int) * n)];

    memset(prod, 1, n);

    int temp = 1;

    for(int i = 0; i<n; i++){
        prod[i] = temp;
        temp *= arr[i];
    }

    temp = 1;
    for(int i = n-1; i>=0; i--){
        prod[i] *= temp;
        temp *= arr[i];
    }

    for(int i = 0; i<n; i++){
        cout<<prod[i]<<" ";
    }

    return ;
}

int main(){
    int arr[5] = {10, 3, 5, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    productExceptItself(arr,n);

    return 0;
}