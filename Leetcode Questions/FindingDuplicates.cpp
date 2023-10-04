#include<iostream>
using namespace std;

int FindingDupicates(int arr[], int n){
    int ans=0;

    //XORing all the elements
    for(int i=0; i<n; i++){
       ans = ans^arr[i];
    }

    //XOR [1, n-1]
    for(int i=1; i<n; i++){
        ans = ans^i;
    }

    return ans;
}

int main(){
    int n;

    cout<< "Enter the size of the array : ";
    cin>>n;

    int arr[10];
    cout<<"Enter the values of elements of an array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    } 
 
    cout<<"The duplicate element is : "<<FindingDupicates(arr, n)<<endl;

    return 0;
}