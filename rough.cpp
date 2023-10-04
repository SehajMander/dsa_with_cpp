#include<iostream>

using namespace std;

int update(int a){
    int ans = a * a;
    // cout<< a <<endl;
    return ans;
}

int main(){
    int a = 14;
    a = update(a);
    cout<< a << endl;
    return 0;
}