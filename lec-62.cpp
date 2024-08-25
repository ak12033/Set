#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

void ReverseLevelOrderTraversal(node* root){
    queue<node*> Q;
    stack<node*> S;
    S.push(NULL);
    Q.push(root);
    Q.push(NULL);
    node* temp;
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp){
            S.push(temp);
            if(temp->right){
                Q.push(temp->right);
            }
            if(temp->left){
                Q.push(temp->left);
            }
        }else{
            S.push(NULL);
            if(!Q.empty()){
                Q.push(NULL);
            }
        }
    }
    S.pop();
    while(!S.empty()){
        temp = S.top();
        S.pop();
        if(temp){
            cout << temp->data << " ";
        }else{
            cout << endl;
        }
    }
    return;
}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

int main() {

    node* root = NULL;

    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
    cout << "Printing the reverse level order tracersal output " << endl;
    ReverseLevelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    cout << endl << "postorder traversal is:  ";
    postorder(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    return 0;
}
*/

//count leaf nodes

template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
//*********************************************************************************
void inorder(BinaryTreeNode<int> * root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
    
    inorder(root->right, count);
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }

}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main() {
    // Create a binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);
    
    // Calculate the number of leaf nodes
    int leafCount = noOfLeafNodes(root);
    
    // Output the result
    cout << "Number of leaf nodes: " << leafCount << endl;
    
    // Clean up memory (if needed)
    // Clean up the binary tree (optional)
    // You can implement a function to delete all nodes
    // or use a separate utility for that purpose.
    
    return 0;
}