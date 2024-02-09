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

//reversing a linked list

//APPROACH - 1 : iterative solution
// Node* reverseLinkedList(Node* &head){
//     if(head == NULL || head -> next == NULL){
//         //empty linked list or has only one node
//         return head;
//     }

//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = NULL;

//     while(curr != NULL){
//         forward = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = forward;
//     }

//     head = prev;
//     return prev;
// }


//APPROACH - 2 : recursive solution
// void reverse(Node* &head, Node* &curr, Node* &prev){
//     //base case
//     if(curr == NULL){
//         head = prev;
//         return;
//     }

//     Node* forward = curr -> next;
//     reverse(head, forward, curr);
//     curr -> next = prev;
// }

// Node* reverseLinkedList(Node* &head){
//     Node* curr = head;
//     Node* prev = NULL;
//     reverse(head, curr, prev);
//     return head;
// }


//APPROACH - 3 
Node* reverse(Node* head){
    //base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* head2 = reverse(head -> next);
    
    head -> next -> next = head;
    head -> next = NULL;

    return head2;
}

void reverseLinkedList(Node* &head){
    head = reverse(head);
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

//printing the linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //created a new node
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

    reverseLinkedList(head);
    cout<<"Reversed linked list is : ";
    print(head);
    
    return 0;
}