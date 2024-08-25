#include<bits/stdc++.h>
#include<queue>
#include <iostream>
using namespace std;

//                                  Kth smallest element using max heap

/*
int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq;
        
        //step 1
        for(int i = 0; i<k; i++){
            pq.push(arr[i]);
        }
        
        //step 2
        for(int i = k; i <= r; i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }

    int main() {
    // Example array
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Define the range and the value of k
    int l = 0;
    int r = n - 1;
    int k = 3;
    
    int result = kthSmallest(arr, l, r, k);
    cout << result << endl;

    return 0;
}
*/

//                                  Kth largest element using min heap

/*
int kthlargest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int, vector<int>, greater<int> > minheap;
        
        //step 1
        for(int i = 0; i<k; i++){
            minheap.push(arr[i]);
        }
        
        //step 2
        for(int i = k; i <= r; i++){
            if(arr[i]>minheap.top()){
                minheap.pop();
                minheap.push(arr[i]);
            }
        }
        int ans = minheap.top();
        return ans;
    }

    int main() {
    // Example array
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Define the range and the value of k
    int l = 0;
    int r = n - 1;
    int k = 2;
    
    int result = kthlargest(arr, l, r, k);
    cout << result << endl;

    return 0;
}
*/

//                                                           Is tree a heap

/*
// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int countNodes(struct Node* root){
        //base case
        if(root == NULL){
            return 0;
        }
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    bool isCBT(struct Node* root,int index,int cnt){
        if(root == NULL){
            return true;
        }
        if(index >= cnt){
            return false;
        }
        else{
            bool left = isCBT(root->left,2*index + 1,cnt);
            bool right = isCBT(root->right,2*index + 2,cnt);
            return (left && right);
        }
    }
    bool isMaxOrder(struct Node* root){
        //leaf node
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->right == NULL){
            return(root->data > root->left->data );
        }
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            return (left && right && (root->data > root->left->data && root->data > root->right->data));
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int totalCount = countNodes(tree);
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};

Node* createTree() {
    // Example tree:
    //         10
    //        /  \
    //       9    8
    //      / \  / \
    //     7  6 5   4

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    
    return root;
}

int main() {
    Solution solution;
    Node* root = createTree();

    if (solution.isHeap(root)) {
        cout << "The tree is a Heap." << endl;
    } else {
        cout << "The tree is not a Heap." << endl;
    }

    // Clean up allocated memory (in a real application, you'd need to free the memory here)
    return 0;
}
*/

//                                                   Merge two binary Max heaps

/*
class Solution{
    public:
    //1 based indexing
    void maxheapify(vector<int> &arr, int n, int i){

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }  
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //step 1: merge both arrays into one
        vector<int> ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        //step 2: heap creation
        int size = ans.size();
        for(int i = size/2-1 ; i>=0; i--){
            maxheapify(ans,size,i);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example heaps
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> mergedHeap = solution.mergeHeaps(a, b, a.size(), b.size());

    // Output the merged heap
    cout << "Merged Heap: ";
    for (int num : mergedHeap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                                   Convert BST to Min Heap

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(BinaryTreeNode* root, vector<int> &ans)
{
	// base case
	if(root==NULL)
	{
		return;
	}

	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);
}

void preorderFill(BinaryTreeNode* root, int &index, vector<int> &ans)
{
	if(root==NULL)
	{
		return;
	}

	root->data=ans[index++];
	preorderFill(root->left, index, ans);
	preorderFill(root->right, index, ans);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> ans;
	inorder(root, ans);

	int index=0;
	preorderFill(root, index, ans);

	return root;
}

void printInOrder(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}
void levelOrderTraversal(BinaryTreeNode* root) {
    queue<BinaryTreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        BinaryTreeNode* temp = q.front();
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
int main() {
    // Constructing a sample BST
    BinaryTreeNode* root = new BinaryTreeNode(4);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(6);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(3);
    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(7);


    cout << "Original BST In-Order: ";
    printInOrder(root);
    cout << endl;

    root = convertBST(root);

    cout << "Converted BST In-Order: "<<endl;
    levelOrderTraversal(root);

    

    // Clean up allocated memory (in a real application, you'd need to delete nodes here)
    return 0;
}