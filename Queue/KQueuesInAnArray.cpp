#include<iostream>
using namespace std;

class kQueue {
    public:
        //defining data members
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        //constructor
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            
            for(int i=0; i<k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }

            next[n-1] = -1;

            arr = new int[n];
            freeSpot = 0;
        }

        void enqueue(int data, int qn){
            //check for overflow
            if(freeSpot == -1){
                cout<<"Queue overflow"<<endl;
                return ;
            }

            //find first freespot
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //if inserting first element
            if(front[qn - 1] == -1){
                front[qn - 1] = index;
            }
            //inserting in the queue, not the first element
            else {
                next[rear[qn - 1]] = index; //linking new element to the prev element
            }

            //update next 
            next[index] = -1;

            //update rear
            rear[qn - 1] = index;

            //pushing the element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //check for underflow
            if(front[qn - 1] == -1){
                cout<<"Queue underflow"<<endl;
                return -1;
            }

            //find index to pop
            int index = front[qn - 1];

            //update front -> front ko aage badhao
            front[qn - 1] = next[index];

            //update next -> managing freespot
            next[index] = freeSpot;

            //update freespot
            freeSpot = index;

            return arr[index];
        }
};

int main(){
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1)<<endl;
    cout << q.dequeue(2)<<endl;
    cout << q.dequeue(1)<<endl;
    cout << q.dequeue(1)<<endl;

    cout << q.dequeue(1)<<endl;

    return 0;
}