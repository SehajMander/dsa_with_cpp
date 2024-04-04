#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* newLinkedList(Node* head, int k){
    Node* temp = head;
    Node* newHead = new Node(-1);
    Node* newTemp = newHead;

    while(temp != NULL){
        int count = 0;
        int sum = 0;
        Node* start = temp;
        while(count < k && temp != NULL){
            sum += temp -> data;
            count++;
            temp = temp -> next;
        }

        if(count == k){
            int avg = sum/k;
            if(avg%2 == 0){
                Node* newNode = new Node(avg);
                newTemp -> next = newNode;
                newTemp = newTemp -> next;
            }
        }
        else {
            newTemp -> next = start;
            while(start != temp){
                newTemp = newTemp -> next;
                start = start -> next;
            }
        }
    }
    return newHead->next;
}

//insert at the tail
void insertAtTail(Node* &tail, int d){
    //created a new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << " --> ";
        temp = temp -> next;
    }
    cout<<"null"<<endl;
}

int main(){
    int k;
    int n;
    cout<<"Enter the value of k :";
    cin>>k;
    cout<<endl;
    cout<<"Enter the value of num of nodes : ";
    cin>>n;
    cout<<endl;

    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;

    int data;
    cout<<"Enter the data values : ";
    for(int i=0; i<n; i++){
        cin>>data;
        insertAtTail(tail, data);
    }

    cout<<"Original ll : ";
    print(head);

    cout<<"New ll : ";
    Node* ans = newLinkedList(head, k);
    print(ans);

    return 0;
}