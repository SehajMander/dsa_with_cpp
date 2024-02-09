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
//return the middle of the linked list

//APPROACH 1 :
// int getLength(Node* head){
//     int len = 0;
//     while(head != NULL){
//         len++;
//         head = head -> next;
//     }
//     return len;
// }

// Node* middleNode(Node* head){
//     int len = getLength(head);
//     int ans = (len/2);

//     Node* temp = head;
//     int count = 0;
//     while(count < ans){
//         temp = temp -> next;
//         count++;
//     }
//     return temp;
// }


//APPROACH 2 :
Node* getMiddle(Node* head){
    //1 node or empty list
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //2 nodes
    if(head -> next -> next == NULL){
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

Node* middleNode(Node* head){
    return getMiddle(head);
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
    Node* node1 = new Node(10);
    
    //head pointed to node1
    Node* head = node1;
    int data1;
    cout<<"Enter the value of data to be entered at head : ";
    cin>>data1;
    insertAtHead(head, data1);

    //tail pointed to node1
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

    cout<<"Linked list after the middle : ";
    Node* middle = middleNode(head);
    print(middle);

    return 0;
}