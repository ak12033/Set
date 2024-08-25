#include<iostream>
#include<queue>
using namespace std;

//                                         kth largest, predecessor and successor element in BST

class TreeNode{
public:
    
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int d){
        this->data = d;
        this->left =  NULL;
        this->right = NULL;
    }
    
};
TreeNode* insertIntoBst(TreeNode* root,int d)
{
    // base case
    if(root==NULL){
        root =  new TreeNode(d);
        return root;
    }
    
    if(d > root -> data)
    {
        // righ part me insert karna h
        root->right =  insertIntoBst(root->right,d);
    }
    else
    {
        // left part me insert karna h
        root->left = insertIntoBst(root->left,d);
    }
    
    return root;
}

void takeInput(TreeNode* &root)
{
    int data;
    cin >> data;
    
    while(data != -1)
    {
        root = insertIntoBst(root,data);
        cin >> data;
    }
}
int solve(TreeNode* root,int &i,int k){
    //base case
        if(root == NULL){
            return -1;
        }
        //Left call
        int right = solve(root->right,i,k);

        if(right != -1){
            return right;
        }
        
        //Node
        i++;
        if(i==k){
            return root->data;
        }

        //Right call
        return solve(root->left,i,k);
}
int kthlargest(TreeNode* root, int k) {
    int i = 0;
    int ans = solve(root,i ,k);
    return ans;
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int predecessor = -1;
    int successor = -1;

    // Initializing temporary node with head.
    TreeNode *temp = root;

    // Traversing in tree.
    while (temp != NULL)
    {
        if (key > temp->data)
        {
            // Updating predecessor.
            predecessor = temp->data;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    temp = root;

    // Traversing in tree.
    while (temp != NULL)
    {
        if (key >= temp->data)
        {
            temp = temp->right;
        }
        else
        {
            // Updating successor.
            successor = temp->data;
            temp = temp->left;
        }
    }

    return make_pair(predecessor, successor);
}
int main(){
    TreeNode* root = NULL;
    
    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);

    int klarge = kthlargest(root,1);
    cout << klarge << endl;

    pair<int, int> result = predecessorSuccessor(root, 31);
    cout << "Predecessor of  is: " << result.first << endl;
    cout << "Successor of  is: " << result.second << endl;
}

