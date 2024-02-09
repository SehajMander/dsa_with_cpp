#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

//reverse linked list in K groups
Node* reverseKGroup(Node* head, int k){
    //base case
    Node* curr = head;
    int count = 0;

    while(curr != NULL && count < k){
        curr = curr -> next;
        count++;
    }

    if(count < k){
        return head; // not enough nodes to reverse
    }

    // step 1 : reverse first k nodes
    Node* prev = NULL;
    curr = head;
    Node* next = NULL;
    count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 : recursive call 
    if( next != NULL){
        head -> next = reverseKGroup(next, k);
    }

    //step 3 : return the prev
    return prev;
}


//insert at the head
void insertAtHead(Node* &head, int d){
    //created a new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}


//insert at the tail
void insertAtTail(Node* &tail, int d){
    //created a new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}


//insert at a given position
void insertAtPosition(Node* &head, Node* & tail, int position, int d){
    //insert at beginning
    if(position == 1){
        insertAtHead(head, d);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    //insert at last
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return ;
    }

    //creating a new node
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}


//printing linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(3);

    //insertions
    Node* head = node1;
    int data1;
    cout<<"Enter the value of data to be entered at head : ";
    cin>>data1;
    insertAtHead(head, data1);
    Node* tail = node1;
    int data2;
    cout<<"Enter the value of data to be entered at tail : ";
    cin>>data2;
    insertAtTail(tail, data2);
    int data4;
    cout<<"Enter the value of data to be entered at tail : ";
    cin>>data4;
    insertAtTail(tail, data4);
    int position;
    cout<<"Enter the position where element is to be inserted : ";
    cin>>position;
    int data3;
    cout<<"Enter the data to be inserted : ";
    cin>>data3;
    cout<<"Linked list : ";
    insertAtPosition(head, tail, position, data3);
    print(head);

    int k;
    cout<<"Enter the value of k for reversing the groups : ";
    cin>>k;
    Node* ans = reverseKGroup(head,k);
    print(ans);

    return 0;
}