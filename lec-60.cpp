#include<iostream>
#include<queue>
using namespace std;

/*int main() {
    cout << (-1)%1<< endl;
    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();
    
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_back();

    if(d.empty()) {
        cout << "queue is empty" << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }

    //create a queue
    queue<int> q;

    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;

    q.push(13);
    cout << "front of q is: " << q.front() << endl;

    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }


    return 0;
}*/


//Implementation of queue using arrays

/*
class Queue {
    
    int* arr;
    int qfront;
    int rear; 
    int size;
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    //----------------- Public Functions of Queue -----------------

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {	int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.front() << endl;

    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Front element after dequeue: " << queue.front() << endl;

    while (!queue.isEmpty()) {
        cout << "Dequeued element: " << queue.dequeue() << endl;
    }

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
*/

//Implementation of queue using Linked List
/*
class node{
    public:
     int data;
     node* next;

     node(int d){
         data = d;
         next = NULL;
     }
};

class Queue {

    node* Front;
    node* rear;


public:
    Queue() {
        // Implement the Constructor
        Front = NULL;
        rear = NULL;
    }

    //----------------- Public Functions of Queue -----------------

    bool isEmpty() {
        // Implement the isEmpty() function
        if(Front == NULL)
            return true;
        else return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        node* temp = new node(data);

        if(rear == NULL){
            rear = temp;
            Front = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }

    }

    int dequeue() {
        // Implement the dequeue() function
        if(Front == NULL)
            return -1;
        
        int val = Front->data;
        node* temp = Front;
        Front = Front->next;;
        if(Front == NULL){
            rear = NULL;
        }
        free(temp);
        return val;
    }

    int front() {
        // Implement the front() function
        if(Front == NULL)
            return -1;
        
        return Front->data;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.front() << endl;

    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Front element after dequeue: " << queue.front() << endl;

    while (!queue.isEmpty()) {
        cout << "Dequeued element: " << queue.dequeue() << endl;
    }

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
*/

//Implementation of Circular Queue
/*
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //to check whther queue is full
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            //cout << "Queue is Full";
            return false;
        }
        else if(front == -1) //first element to push
        {
			front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear++;
        }
        //push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }
    bool isEmpty() {
        return front == -1;
    }
};
int main() {
    CircularQueue q(5);  // Create a circular queue of size 5

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << "Dequeuing elements from the queue:" << std::endl;
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << std::endl;

    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);

    std::cout << "Dequeuing elements again from the queue:" << std::endl;
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/

//Implementation of Deque
class Deque
{	
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check full or not
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
         if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
		if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(){
    Deque dq(5);  // Create a deque of size 5

    dq.pushRear(1);    // Deque: [1]
    dq.pushRear(2);    // Deque: [1, 2]
    dq.pushFront(3);   // Deque: [3, 1, 2]
    
    std::cout << "Front element: " << dq.getFront() << std::endl;  // Output: 3
    std::cout << "Rear element: " << dq.getRear() << std::endl;    // Output: 2

    dq.popFront();     // Deque: [1, 2]
    dq.popRear();      // Deque: [1]

    std::cout << "Front element after popFront(): " << dq.getFront() << std::endl;  // Output: 1
    std::cout << "Rear element after popRear(): " << dq.getRear() << std::endl;    // Output: 1 (since only one element left)

    return 0;
}