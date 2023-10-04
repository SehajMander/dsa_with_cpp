#include<iostream>

using namespace std;

bool isEven(int a){
    if(a&1){
        //odd
        return 0;
    }
    //even
    return 1;
}

int main(){
    int num;
    cout<<"Enter the number to be tested for even or odd : ";
    cin>>num;

    if(isEven(num)){
        cout<<"The given number is even."<<endl;
    }
    else{
        cout<<"THe given number is odd."<<endl;
    }

    return 0;
}