#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& stalls, int k, int mid){
    int cowCount = 1;
    int lastPosition = stalls[0];

    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]-lastPosition >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPosition = stalls[i];
        }
    }
    return false;
}

int aggressiveCow(vector<int>& stalls, int k){
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int maxi = -1;
    for(int i=0; i<stalls.size(); i++){
        maxi = max(maxi, stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(isPossible(stalls, k ,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> stalls;
    cout<<"Enter the elements of the array : ";
    int x;
    cin>>x;
    for(int i=0; i<n; i++){
        cin>>x;
        stalls.push_back(x);
    } 

    int k;
    cout<<"Enter the number of cows : ";
    cin>>k;

    int sol = aggressiveCow(stalls, k);
    cout<<"The largest minimum distance between the cows is : "<< sol <<endl;

    return 0;
}