#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};
void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    //cout << tail -> data << " ";
    //while(tail -> next != temp){
    //   cout << tail -> data << " ";
    //    tail = tail -> next;
    //}
    //cout<<" ";

    //                                                              OR
                                                       
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;

}
Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}
void removeLoop(Node* head) {

    if( head == NULL)
        return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;

}


int main(){
    Node* node1 = new Node(10);
    Node* head = node1; 
    Node* tail = node1;
    
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtPosition(tail,head, 4, 22);
    
    
    tail -> next = head -> next;

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    
    /*if(detectLoop(head)) {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }*/
   if(floydDetectLoop(head) != NULL) {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }
    Node* loop = getStartingNode(head);

    cout << "loop starts at " << loop -> data  << endl;
    removeLoop(head);
    print(head);
}
