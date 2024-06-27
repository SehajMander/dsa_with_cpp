#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;
    
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node *buildTree(node *root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //level complete
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes left
                q.push(NULL);
            }
        }
        else{
            cout<< temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter the data for root : ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for : "<< temp -> data<<endl;
        int lData;
        cin>>lData;
        
        if(lData != -1){
            temp -> left = new node(lData);
            q.push(temp -> left);
        }

        cout<<"Enter right node for : "<<temp -> data<<endl;
        int rData;
        cin>>rData;

        if(rData != -1){
            temp -> right = new node(rData);
            q.push(temp -> right);
        }
    }

}

int main(){
    node * root = NULL;

    //creating tree
    // root = buildTree(root);

    //level order traversal
    cout<<"From level order : "<<endl;
    buildFromLevelOrder(root);

    cout<<"Level order traversal : "<<endl;
    levelOrderTraversal(root);


    return 0;
}

