#include<iostream>
using namespace std;

//for finding maximum element of the array
int getMax(int arr[], int n){
    int max = INT16_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    return max;
}

//for finding minimum element of the array
int getMin(int arr[], int n){
    int min = INT16_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }

    return min;
}

int main(){
    int size;
    cout<<"Enter the size of th array : ";
    cin>>size;

    int num[100];
    
    cout<<"Enter the values of elements of the array :";
    for(int i=0; i<size; i++){
        cin>> num[i];
    } 

    //minimum element
    int minimum = getMin(num, size);
    cout<<"Minimum element of the array is : "<<minimum<<endl;
    
    //maximum element
    int maximum = getMax(num, size);
    cout<<"Maximum element of the array is : "<<maximum<<endl;


    return 0;
}