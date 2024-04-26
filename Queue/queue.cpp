#include<iostream>
#include<queue>

using namespace std;

int main(){
    //creating a queue
    queue<int> q;

    q.push(11);
    cout<<"Front of q is : "<<q.front()<<endl;
    q.push(15);
    cout<<"Front of q is : "<<q.front()<<endl;
    q.push(19);
    cout<<"Front of q is : "<<q.front()<<endl;

    cout<<"Size of queue before popping : "<<q.size()<<endl;

    q.pop();

    cout<<"Size of queue after popping : "<<q.size()<<endl;

    q.pop();
    // q.pop();

    cout<<"Size of queue after popping : "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is EMPTY!!"<<endl;
    } else {
        cout<<"Queue is NOT EMPTY!!"<<endl;
    }

    return 0;
}