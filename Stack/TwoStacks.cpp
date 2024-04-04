#include<iostream>
#include<stack>
using namespace std;

 class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

    public :
    //INITIALIZE TWO STACK
    TwoStack(int s){
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    //push-in stack 1
    void push1(int num){
        //atleast one empty space is present
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
    }

    //push-in stack 2
    void push2(int num){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }
    }

    //pop-out stack 1
    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    //pop-out stack 2
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }

    //peek opreation
    int peek1(){
        if(top1 >= 0){
            return arr[top1];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    int peek2(){
        if(top1 >= 0){
            return arr[top2];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
 };

 int main(){
    //creating an instance of twoStack with size 10
    TwoStack ts(10);

    //pushing elements into stack 1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    //pushing elements into stack 2
    ts.push2(20);
    ts.push2(25);
    ts.push2(30);

    //popping elements from stack 1
    cout << "Popping elements from Stack 1: " << endl;
    ts.pop1() ;
    cout<<ts.peek1()<<endl;
    // ts.pop1() ;
    // ts.pop1() ;

    // Popping elements from stack 2
    cout << "Popping elements from Stack 2: " << endl;
    // cout << ts.pop2() << endl;
    // cout << ts.pop2() << endl;
    ts.pop2();
    cout<<ts.peek2()<<endl;

    return 0;
 }