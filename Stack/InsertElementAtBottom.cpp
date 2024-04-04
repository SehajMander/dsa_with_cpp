#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();

    //recursive call
    solve(s, x);

    s.push(num);
}  

stack<int> pushAtBottom(stack<int> &myStack, int x){
    solve(myStack, x);
    return myStack;
}

void printStack(stack<int> s){
    stack<int> temp = s;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    int n;
    cout<<"Enter the size of the stack : ";
    cin>>n;
    int data;
    cout<<"Enter the data of the stack : ";
    for(int i=0; i<n; i++){
        cin>>data;
        s.push(data);
    }

    int x;
    cout<<"Enter the element to be pushed at bottom : ";
    cin>>x;

    cout<<"Stack before insertion : ";
    printStack(s);

    cout<<"Stack after insertion : ";
    pushAtBottom(s, x);
    printStack(s);

    return 0;
}