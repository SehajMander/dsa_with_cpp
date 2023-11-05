#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if( pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if( studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m){
    int start = 0;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int end = sum;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start<=end){
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter the elements of the array : ";
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }

    int m;
    cout<<"Enter the number of students to be allocated with books : ";
    cin>>m;

    int sol = allocateBooks(arr, n, m);
    cout<<"The final answer for allocation of books is : "<< sol <<endl;
    
    return 0;
}