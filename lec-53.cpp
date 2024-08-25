#include<iostream>
using namespace std;

/*class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    

node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

node* merge(node* left, node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}


node* mergeSort(node *head) {
    //base case
    if( head == NULL || head -> next == NULL ) {
        return head;
    }
    
    // break linked list into 2 halvs, after finding mid
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    node* result = merge(left, right);
    
    return result;
}*/


// flattening linked list

class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * }
Node* Merge(Node* left,Node* right)
{
	if(left==NULL)
	{
		return right;
	}
	if(right==NULL)
	{
		return left;
	}
	Node* ans=new Node(-1);
	Node* temp=ans;
	while(left!=NULL && right!=NULL)
	{
		if(left->data<right->data)
		{
			temp->child=left;
			temp=left;
			left=left->child;
			
		}
		else
		{
			temp->child=right;
			temp=right;
			right=right->child;
		}
	}
	while(left!=NULL)
	{
		temp->child=left;
		temp=left;
		left=left->child;
	}
	while(right!=NULL)
	{
		    temp->child=right;
			temp=right;
			right=right->child;    
	}
	ans=ans->child;
	return ans;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	//base case
    if(head == NULL || head->next == NULL){
        return head ;
    }
    
   Node* down =head;
   Node* right=flattenLinkedList(head->next);
   down->next=NULL;
   Node* ans2=Merge(down,right);
   return ans2;
}