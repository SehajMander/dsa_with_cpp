#include<iostream>
#include<limits>
using namespace std;

double power(double a, int b){
    //base case
    if(b==0){
        return 1;
    }

    if(b==1){
        return a;
    }

    if(a == 0){
          return 0;
      }

      //for negative power
      if (b < 0) {
            a = 1 / a;
            // handling edge case for INT_MIN
            if (b == std::numeric_limits<int>::min()) {
                a *= a;
                b /= 2;
            }
            b = -b;
        }

    //recursive call
    double ans = power(a, b/2);

    //b = even
    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

int main(){
    double a;
    int b;
    cout<<"Enter the value of number : ";
    cin>>a;
    cout<<"Enter the value of power : ";
    cin>>b;

    cout<<"Answer is : "<<power(a,b)<<endl;

    return 0;
}