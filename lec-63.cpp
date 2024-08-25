#include <iostream>
#include <utility> // for std::pair
using namespace std;

//                                                            Sum tree or not

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root) {
        
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        bool condn = root->data == leftAns.second + rightAns.second;
        
        pair<bool, int> ans;
        
        if(isLeftSumTree && isRightSumTree && condn) {
            ans.first = true;
            //ans.second = root->data + leftAns.second + rightAns.second ;
            ans.second = 2 * root->data  ;
        }
        else
        {
            ans.first = false;
        }
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumTreeFast(root).first;
    }
};

Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    // Constructing the tree
    Node* root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
    
    Solution sol;
    if (sol.isSumTree(root)) {
        cout << "The tree is a Sum Tree.\n";
    } else {
        cout << "The tree is not a Sum Tree.\n";
    }
    
    return 0;
}