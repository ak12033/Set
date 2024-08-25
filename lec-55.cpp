#include<iostream>
#include<stack>
using namespace std;


//reversing a string using stack

/*int main () {
    string str = "babbar";

    stack<char> s;

    for (int i = 0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout << "answer is: "<< ans << endl;

    return 0;
}*/

// deleting a middle element in a stack

/*void solve(stack<int>&inputStack, int count, int size) {
    //base case
    if(count == size/2) {
        inputStack.pop();
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
    
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   solve(inputStack, count, N);
   
}*/


// Inserting an element at the bottom of a stack

/*void solve(stack<int>& s, int x) {
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    solve(s, x);
    
    s.push(num);
}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}
*/

//reversing stack using recursion

/*void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}
void reverseStack(stack<int> &stack) {
  	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}
*/


//sort a stack

/*void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}
*/

//Redundant brackets are present or not

/*
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else
        {
            //ch ya toh ')' hai or lowercase letter
            
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true) {
                    return true;
                }
                st.pop();
            }
            
        } 
    }
    return false;
}
int main(){

    string check1 = "(c*(a+b))";
    cout << findRedundantBrackets(check1) << endl;
    string check2 = "(())";
    cout << findRedundantBrackets(check2) << endl;

}
*/

// Bracket Reversals (minimum cost to make string valid)

int findMinimumCost(string str) {
  // Write your code here
  //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
}
int main(){
    string check1 = "{}}{}}";
    cout << findMinimumCost(check1) << endl;
    string check2 = "{{{{";
    cout << findMinimumCost(check2) << endl;
    string check3 = "{{{}}";
    cout << findMinimumCost(check3) << endl;
    string check4 = "}}}{{{";
    cout << findMinimumCost(check4) << endl;
}