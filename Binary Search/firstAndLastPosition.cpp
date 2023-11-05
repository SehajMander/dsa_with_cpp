#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e = mid-1;
        } else if(arr[mid]<key){
            s = mid+1;
        } else if(arr[mid]>key){
            e = mid-1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e = mid+1;
        } else if(arr[mid]<key){
            s = mid+1;
        } else if(arr[mid]>key){
            e = mid-1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[15];
    cout<<"Enter the elements of the array  : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the value of the key to be searched : ";
    cin>>key;

    int firstOccurrence = firstOcc(arr, n, key);
    int LastOccurrence = lastOcc(arr, n, key);
    
    if (firstOccurrence != -1) {
        cout << "First Occurrence of " << key << " is at index " << firstOccurrence << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    if (LastOccurrence != -1) {
        cout << "Last Occurrence of " << key << " is at index " << LastOccurrence << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }
    return 0;
}