#include<iostream>
using namespace std;

//sort 0s 1s 2s
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}
Node* sortList(Node *head){
    // Write your code here.
    //                        approach 1
    /*int countzero=0;
    int countone=0;
    int counttwo=0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            countzero++;
        }
        else if(temp->data == 1){
            countone++;
        }
        else if(temp->data == 2){
            counttwo++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(countzero!=0){
            temp->data=0;
            countzero--;
        }
        else if(countone!=0){
            temp->data=1;
            countone--;
        }
        else if(counttwo!=0){
            temp->data=2;
            counttwo--;
        }
        temp=temp->next;
    }
    return head;*/

    //                       approach 2
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

int main(){

}