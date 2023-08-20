//complement of base 10 integer
#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    
    int m = n;
    int mask = 0;
    int flag = 0;
    if(n == 0){
        flag = 1;
    }

    while(m!=0){
        mask = (mask<<1) | 1;
        m = m>>1;
    }

    int complement = (~n) & mask;
    if(flag == 1){
        cout<<"The complement of given number is : 1"<<endl;
    } else{
        cout<<"The complement of given number is : "<<complement<<endl;
    }

    return 0;
}
