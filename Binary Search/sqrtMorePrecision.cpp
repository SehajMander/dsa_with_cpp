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

double morePrecision(int x, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++){
        factor = factor/10;
        for(double j=ans; j*j<x; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int x;
    cout<<"Enter the number whose square root is to be found : ";
    cin>>x;

    int precision;
    cout<<"Enter the precision points : ";
    cin>>precision;

    int tempSol = SquareRoot(x);
    cout<<"The square root of the given number is : "<<tempSol<<endl;
    double finalSol = morePrecision(x, precision,tempSol);
    cout<<"The more precise square root is : "<<finalSol<<endl;
    
    return 0; 
}