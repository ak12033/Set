#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

//                                             Size of Largest BST in Binary Tree

// TreeNode structure definition
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    
    // Constructor
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};
info solve(TreeNode * root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;

}
int largestBST(TreeNode * root){
    // Write your code here.
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}

int main() {
    // Example usage:
    // Constructing a sample binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    // Find the size of the largest BST
    int largestSize = largestBST(root);

    // Output the result
    cout << "Size of the largest BST: " << largestSize << endl;
}