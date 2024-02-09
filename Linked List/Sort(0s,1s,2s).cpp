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
    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};


//sort 0s, 1s, 2s
//APPROACH 1 :
// Node* sortLinkedList(Node* head){
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     Node* temp = head;
//     while(temp != NULL){
//         if(temp -> data == 0){
//             zeroCount++;
//         }
//         else if(temp -> data == 1){
//             oneCount++;
//         }
//         else if(temp -> data == 2){
//             twoCount++;
//         }
//         temp = temp -> next;
//     }

//     temp = head;
//     while(temp != NULL){
//         if(zeroCount != 0){
//             temp -> data = 0;
//             zeroCount--;
//         }
//         else if(oneCount != 0){
//             temp -> data = 1;
//             oneCount--;
//         }
//         else if(twoCount != 0){
//             temp -> data = 2;
//             twoCount--;
//         }
//         temp = temp -> next;
//     }
//     return head;
// }


//APPROACH 2 :
void insert(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortLinkedList(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    //create separated lists for 0s, 1s, 2s
    while(curr != NULL){
        int value = curr -> data;
        if(value == 0){
            insert(zeroTail, curr);
        }
        else if(value == 1){
            insert(oneTail, curr);
        }
        else if(value == 2){
            insert(twoTail, curr);
        }
        curr = curr -> next;
    }

    //merge all the three lists
    //1s list not empty
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else{
        //1s list is empty
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    //setup head
    head = zeroHead -> next;

    //deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
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
    Node* node1 = new Node(2);

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
    cout<<"Enter the value of data to be entered at head : ";
    cin>>data1;
    insertAtHead(head, data1);
    data2;
    cout<<"Enter the value of data to be entered at tail : ";
    cin>>data2;
    insertAtTail(tail, data2);
    cout<<"Linked list after insertion : ";
    print(head);

    head = sortLinkedList(head);
    cout<<"Linked list after sorting 0s, 1s and 2s is : ";
    print(head);

    return 0;
}