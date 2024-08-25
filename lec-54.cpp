#include<iostream>
#include<stack>
using namespace std;

// Implementation using arrays

/*
class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop() {
        if(top >=0 ) {
            top--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

};


int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else{
        cout << "Stack is not Empty mere dost " << endl;
    }

    
    /*
    //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack is " << s.size() << endl;


    return 0;
}*/

//Implementation of Stack using Linked List

/*class Stack{
    public:
    int val;
    Stack* next;


    Stack(int d){
        this -> val = d;
        this -> next = NULL;
    }
    
    void push(int element,Stack* &head,Stack* &tail){
        Stack *newNode = new Stack(element);
        if( head == NULL){
            //first element push
            head = newNode;
            tail = newNode;
            return;
        }else{
            //assuming element is present
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop(Stack* &head,Stack* &tail){
        if( head == NULL){
            //if no element is present
            cout << "Stack Underflow "<<endl;
        }else{
            //edge case for last element
            if( head == tail){
                head = NULL;
                return;
            }
            Stack* temp = head;
            while( temp -> next != tail){
                temp = temp -> next;
            }
            temp -> next = NULL;
            tail = temp;

        }
    }

    int peek(Stack* &tail){
        if( tail == NULL){
            cout << "Stack Underflow " << endl;
        }else{
            return tail -> val;
        }
    }

    bool isEmpty(Stack* &head){
        if( head == NULL){
            return true;
        }else return false;
    }

};
void print( Stack* &head){
    Stack* temp = head;
    if( temp == NULL) cout << temp -> val << endl;
    while(temp != NULL){
        cout<< temp ->  val << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
Stack *head = NULL;
    Stack *tail = NULL;
    Stack st(0);
    st.push(4,head,tail);
    st.push(8,head,tail);
    st.push(6,head,tail);
    print(head);


    cout <<"Peek element is "<< st.peek(tail) <<endl;

    st.pop(head,tail);

    print(head);
    
    cout<<"Peek element is "<<st.peek(tail) <<endl;

    st.pop(head,tail);

    print(head);

    st.pop(head,tail);

    if( st.isEmpty(head)){
        cout << "Stack is empty "<<endl;
    }else{
        cout<< "Stack is not empty"<<endl;
    }



    return 0;
}*/

//Implementing two stacks in an array

class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //atleast a empty space present
        if(top2 - top1 > 1 ) {
            top1++;
            arr[top1] = num;
        } 
       
    }

    // Push in stack 2.
    void push2(int num) {
         if(top2 - top1 > 1 ) {
            top2--;
            arr[top2] = num;
        } 
       
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }

};