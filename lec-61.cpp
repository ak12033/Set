#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


//                                                  approach 1
/*
//                                      Function to reverse a queue using a stack
queue<int> rev(queue<int> q) {
    stack<int> s;
    
    // Move elements from queue to stack
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // Move elements from stack back to queue
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q; // Return the reversed queue
}

int main() {
    queue<int> originalQueue;
    originalQueue.push(1);
    originalQueue.push(2);
    originalQueue.push(3);

    // Display original queue contents
    cout << "Original Queue: ";
    queue<int> tempQueue = originalQueue; // Create a temporary queue to preserve originalQueue
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    // Reverse the queue
    queue<int> reversedQueue = rev(originalQueue);

    // Display reversed queue contents
    cout << "Reversed Queue: ";
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }
    cout << endl;

    return 0;
}
*/


//                                                 approach 2

/*
// Function to reverse a queue using recursion
void reverseQueue(queue<int>& q) {
    // Base case: If queue is empty, return
    if (q.empty()) {
        return;
    }

    // Recursive case: Dequeue the front element and recursively reverse the remaining queue
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front); // Enqueue the front element to the end of the reversed queue
}

// Function to display queue elements
void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Push elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Original Queue: ";
    displayQueue(q);

    // Reverse the queue using recursion
    reverseQueue(q);

    cout << "Reversed Queue: ";
    displayQueue(q);

    return 0;
}
*/


//                               First negative number in every window of size k

/*
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        deque<long long int> dq;
        vector<long long> ans;
        int negative = -1;
         
         //process first window
        for(int i=0; i<K; i++) {
            if(A[i] < 0) {
                dq.push_back(i);
            }
        }
         
         //push ans for FIRST window
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=K ) {
                dq.pop_front();
            }
             
             //then push current element
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
}
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
*/

//                                     Function to reverse first k elements of a queue.
/*
queue<int> modifyQueue(queue<int> q, int k) {
    //algo:
    //first k element stack me daaldo  and queue se hatado
    // k element stack se nikalke wapas queue me daalde 
    // fer queue k (n-k) starting k elements, wapas queue me daalde
    
    stack<int> s;
    
    for(int i = 0; i<k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    int n = q.size()-k;
    
    while(n--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n;
        queue<int> q;
        
        // Read elements into the queue
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            q.push(a);
        }
        
        cin >> k;
        
        // Modify the queue as per the requirements
        queue<int> ans = modifyQueue(q, k);
        
        // Print the modified queue
        while (!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << endl;
    }
    
    return 0;
}
*/


//                                    First Non-Repeating character in stream

/*
class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char, int> m;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        
		        q.push(ch);
		        m[ch]++;
		        
		        while(!q.empty()) {
		            if(m[q.front()] > 1){
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
*/

//                                     Interleave the First Half of the Queue with Second Half

//                                                  approach 1
/*
using namespace std;

vector<int> rearrangeQueue(queue<int> &q){
    queue<int> newQ;
    
    int n = q.size() / 2;

    // Step-1: Fetch first half elements from input queue and push into newQueue
    for (int i = 0; i < n; i++) {
        int val = q.front();
        q.pop();
        newQ.push(val);
    }

    // Step-2: Push alternative elements in input queue itself
    while (!newQ.empty()) {
        int val = newQ.front();
        newQ.pop();
        q.push(val);

        int val2 = q.front();
        q.pop();
        q.push(val2);
    }

    // Convert queue to vector for returning the rearranged elements
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    return result;
}

int main() {
    // Example usage:
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    vector<int> rearranged = rearrangeQueue(q);

    cout << "Rearranged queue elements: ";
    for (int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                                         approach 2

/*
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
    stack<int> s;
    vector<int> result;
    
    int n=q.size()/2;
    
    // step-1: First half of queue into stack
    for(int i=0;i<n;i++)
    {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    
    // step-2: stack se firse queue me push kardo
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);
    }

    // step-3: first half of queue pop and queue me hi push 
    for(int i=0;i<n;i++)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }

    // step-4: Again First half of queue into stack (Repeat step-1)
    for(int i=0;i<n;i++)
    {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    
    // step-5: first half of queue into stack
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);

        val=q.front();
        q.pop();
        q.push(val);
    }
    while(!q.empty()){
        int val = q.front();
        q.pop();
        result.push_back(val);
    }
    return result;
    }
};

int main() {
    Solution sol;

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    vector<int> rearranged = sol.rearrangeQueue(q);

    cout << "Rearranged queue elements: ";
    for (int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/


//                                                     K queues in a single array

/*
class kQueue {

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn) {

            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

};

int main() {

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}
*/

//                                   Sum of minimum and maximum elements of all subarrays of size k

int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}
