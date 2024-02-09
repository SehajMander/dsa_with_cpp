#include<iostream>
#include<vector>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


//checking palindrome in linked list
//APPROACH 1 :
// bool checkPalindrome(vector<int> arr){
//     int n = arr.size();
//     int s = 0;
//     int e = n-1;

//     while(s<=e){
//         if(arr[s] != arr[e]){
//             return false;
//         }
//         s++;
//         e--;
//     }
//     return true;
// }

// bool isPalindrome(Node* head){
//     vector<int> arr;
//     Node* temp = head;
//     while(temp != NULL){
//         arr.push_back(temp -> data);
//         temp = temp -> next;
//     }

//     return checkPalindrome(arr);
// }

//APPROACH 2 :
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node* reversedList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if(head == NULL || head -> next == NULL){
        return true;
    }

    //step 1 : get middle of the linked list
    Node* middle = getMid(head);

    //step 2 : reverese the linked list after the middle
    Node* temp = middle -> next;
    middle -> next = reversedList(temp);

    //step 3 : compare both the halves
    Node* head1 = head;
    Node* head2 = middle -> next;
    while(head2 != NULL){
        if(head2 -> data != head1 -> data){
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    //step 4 : repeat step 2 (optional)
    temp = middle -> next;
    middle -> next = reversedList(temp);
    return true;
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
    int data3;
    cout<<"Enter the value of data to be entered at head : ";
    cin>>data3;
    insertAtHead(head, data3);
    int data4;
    cout<<"Enter the value of data to be entered at tail : ";
    cin>>data4;
    insertAtTail(tail, data4);
    cout<<"Linked list after insertion: ";
    print(head);

    cout<<"Linked list is palindrome or not : "<<isPalindrome(head)<<endl;

    return 0;
}