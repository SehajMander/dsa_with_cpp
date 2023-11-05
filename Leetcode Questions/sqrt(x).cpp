#include<iostream>
using namespace std;

long long int SquareRoot(int x){
    int start = 0;
    int end = x;

    long long int mid = start + (end-start)/2;

    long long int ans = -1;

    while(start<=end){
        long long int square = mid*mid;

        if(square == x){
            return mid;
        }

        if(square < x){
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
    int x;
    cout<<"Enter the number whose square root is to be found : ";
    cin>>x;

    int sol = SquareRoot(x);
    cout<<"The square root of the given number is : "<<sol<<endl;
    
    return 0; 
}