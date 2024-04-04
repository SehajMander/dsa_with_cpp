#include<iostream>
#include<stack>
using namespace std;

void sortInserted(stack<int>& s, int num) {
    //base case
    if((s.empty()) || ((!s.empty()) && (s.top() < num))){
        s.push(num);
        return ;
    }

    int n = s.top();
    s.pop();

    //recursive call
    sortInserted(s, num);

    s.push(n);
}

void sortStack(stack<int> &s){
    //base case
    if(s.empty()){
        return ;
    }

    int num = s.top();
    s.pop();

    //recursive call
    sortStack(s);

    sortInserted(s, num);
}

void printStack(stack<int> &s){
    stack<int> temp = s;
    while(!temp.empty()){
        cout<<temp.top() <<" ";
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

    cout<<"Original stack : ";
    printStack(s);

    cout<<"Sorted stack : ";
    sortStack(s);
    printStack(s);

    return 0;
}