#include<iostream>
using namespace std;

int powerOf2(int n){
    //base case
    if(n==0){
        return 1;
    }

    //recursive relation
    int pow = powerOf2(n-1);
    int ans = 2 * pow;

    return ans;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int sol = powerOf2(n);
    cout<<"Final answer is : "<<sol<<endl;

    return 0;
}