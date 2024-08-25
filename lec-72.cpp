#include <iostream>
#include <vector>
using namespace std;

//                                                         Merge Two BSTs

//                                                          approach 1

/*
// TreeNode structure for Binary Tree / Binary Search Tree (BST)
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void convertIntoSortedDLL(TreeNode *root,TreeNode * &head){
    //base case
    if(root==NULL){
        return;
    }
    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if(head!=NULL){
        head->left=root;
    }
    head = root;
    convertIntoSortedDLL(root->left, head);
}

TreeNode * mergeLinkedList(TreeNode *head1,TreeNode *head2){
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1 -> data < head2 -> data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(TreeNode* &head){
    int cnt = 0;
    TreeNode* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp -> right;
    }
    return cnt;
}

TreeNode* sortedLLToBST(TreeNode* &head,int n){
    //base case
    if(n <= 0 || head == NULL){
        return NULL;
    }
    TreeNode* left = sortedLLToBST(head,n/2);
    TreeNode* root = head;
    root->left = left;
    head = head -> right;
    root->right = sortedLLToBST(head,n-n/2-1);
    return root;
}

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    // Traverse left subtree
    inorderTraversal(root->left, result);
    
    // Visit current node (add to result)
    result.push_back(root->data);
    
    // Traverse right subtree
    inorderTraversal(root->right, result);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    //step1: convert BST into Sorted DLL in-place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;

    //Step2: merge sorted Linked List
    TreeNode* head = mergeLinkedList(head1,head2);

    //Step3: convert SLL into BST
    TreeNode* balancedBST =  sortedLLToBST(head, countNodes(head));

    vector<int> result;
    inorderTraversal(balancedBST, result);

    return result;

}

int main() {
    // Example BSTs
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);

    // Merge BSTs
    vector<int> merged = mergeBST(root1, root2);

    // Print merged values
    cout << "Merged BST values in sorted order:" << endl;
    for (int val : merged) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                                     approach 2

void inorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size()+b.size());
    int i = 0, j = 0;
    int k=0;

    // Traversing in both arrays.
    while (i < a.size() && j < b.size())
    {
        // Comparing array elements.
        if (a[i] < b[j])
        {
            ans[k++]=a[i];
            i++;
        }
        else
        {
            ans[k++]=b[j];
            j++;
        }
    }

    // Pushing rest elements.
    while (i < a.size())
    {
        ans[k++]=a[i];
        i++;
    }

    // Pushing rest elements.
    while (j < b.size())
    {
        ans[k++]=b[j];
        j++;
    }

    return ans;
}


TreeNode* inorderToBST(int s, int e, vector<int> &in){
    //base case
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e,in);
    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    //step 1: store inorder -
    vector<int> bst1, bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    //step 2: merge both sorted arrays
    vector<int> mergeArray = mergeArrays(bst1,bst2);

    //step 3: use merge inorder array to build BST
    //int s=0, e=mergeArray.size()-1;
    //return inorderToBST(s,e,mergeArray); 
    return mergeArray;
}