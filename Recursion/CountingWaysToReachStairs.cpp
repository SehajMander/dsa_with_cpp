#include<iostream>
using namespace std;

int countWays(long long n){
    //base case 
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }

    int ans = countWays(n-1) + countWays(n-2);
    return ans;
}

int main(){
    long long n;
    cout<<"Enter the number of stairs : ";
    cin>>n;

    int sol = countWays(n);
    cout<<"NUmber of ways : "<<sol<<endl;

    return 0;
}