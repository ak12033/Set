#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//                                                            Flatten BST To A Sorted List

// TreeNode class template
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert into BST
template <typename T>
TreeNode<T>* insertIntoBst(TreeNode<T>* root, T d) {
    if (root == NULL) {
        root = new TreeNode<T>(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBst(root->right, d);
    } else {
        root->left = insertIntoBst(root->left, d);
    }

    return root;
}

// Function to take input and create BST
template <typename T>
void takeInput(TreeNode<T>* &root) {
    T data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// Function to perform in-order traversal and store values in inorderVal vector
template <typename T>
void inorder(TreeNode<T>* root, vector<T>& inorderVal) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}

// Function to flatten the binary search tree into a linked list
template <typename T>
TreeNode<T>* flatten(TreeNode<T>* root) {
    vector<T> inorderVal;
    inorder(root, inorderVal);
    int n = inorderVal.size();

    TreeNode<T>* newRoot = new TreeNode<T>(inorderVal[0]);
    TreeNode<T>* curr = newRoot;

    for (int i = 1; i < n; i++) {
        TreeNode<T>* temp = new TreeNode<T>(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

// Function to print the flattened linked list
template <typename T>
void printFlattenedList(TreeNode<T>* root) {
    TreeNode<T>* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

// Main function
int main() {
    TreeNode<int>* root = NULL;

    cout << "Enter data to create BST (-1 to stop): " << endl;
    takeInput(root);

    // Flatten the tree into a linked list
    TreeNode<int>* flattened = flatten(root);

    // Print the flattened linked list
    cout << "Flattened linked list: ";
    printFlattenedList(flattened);

    return 0;
}
