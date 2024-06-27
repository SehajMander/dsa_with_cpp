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
        } else{
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

void indorderTraversal(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    //recursive calls
    indorderTraversal(root -> left);
    cout<< root -> data <<" ";
    indorderTraversal(root -> right);
}

void postorderTraversal(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    //recursive calls
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout<<root -> data<< " ";
}

void preorderTraversal(node* root){
    //base call
    if(root == NULL){
        return ;
    }

    //recursive call
    cout<<root -> data<<" ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

int main(){
    node * root = NULL;

    //creating tree
    root = buildTree(root);

    //level order traversal
    cout<<"Level order traversal : "<<endl;
    levelOrderTraversal(root);

    //inorder traversal
    cout<<"Inorder Traversal : "<<endl;
    indorderTraversal(root);
    cout<<endl;

    //postorder traversal
    cout<<"Postorder Traversal : "<<endl;
    postorderTraversal(root);
    cout<<endl;

    //preorder traversal
    cout<<"Preorder Traversal : "<<endl;
    preorderTraversal(root);

    return 0;
}

