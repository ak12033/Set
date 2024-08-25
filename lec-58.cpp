#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
     
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        //next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        //check for overflow
        if(freespot == -1) {
            return false;
        }
        
        //find index
        int index = freespot;
        
        //insert element into array
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
       
        //update next;
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index= top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};
 // Assuming NStack class is defined in NStack.h header file

int main() {
    // Example usage of NStack class

    // Create an instance of NStack with 3 stacks and total size of 10
    NStack nStack(3, 10);

    // Push elements onto different stacks
    nStack.push(1, 1); // Push 1 onto stack 1
    nStack.push(2, 1); // Push 2 onto stack 1
    nStack.push(3, 2); // Push 3 onto stack 2
    nStack.push(4, 3); // Push 4 onto stack 3
    nStack.push(5, 1); // Push 5 onto stack 1
    nStack.push(6, 2); // Push 6 onto stack 2
    nStack.push(7, 3); // Push 5 onto stack 1
    nStack.push(8, 2); // Push 6 onto stack 2
    nStack.push(9, 1); // Push 5 onto stack 1
    nStack.push(10, 3); // Push 6 onto stack 2

    // Pop elements from stacks
    cout << "Popped from stack 1: " << nStack.pop(1) << endl; // Pop from stack 1
    cout << "Popped from stack 2: " << nStack.pop(2) << endl; // Pop from stack 2
    cout << "Popped from stack 3: " << nStack.pop(3) << endl; // Pop from stack 3
    cout << "Popped from stack 3: " << nStack.pop(3) << endl; // Pop from stack 3
    cout << "Popped from stack 3: " << nStack.pop(3) << endl; // Pop from stack 3

    // Pop from an empty stack (should return -1)
    cout << "Popped from stack 3: " << nStack.pop(3) << endl; // Pop from stack 3

    return 0;
}
