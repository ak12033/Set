// next smaller element
#include<iostream>
#include<stack>
#include <vector>
using namespace std;

// next smaller element

//                                                       approach 1


/*vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();
    vector<int> result = nextSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();

    result = nextSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();

    result = nextSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}*/

//                                                      approach 2


/*
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    
    for(int i=n-1;i>=0;i--)
    {
        int curr= arr[i];
        if(s.top()<curr)
        {
            arr[i]=s.top();
            s.push(curr);  
        }
        else
        {
            s.pop();
            i++;
        }
    }
    return arr;
}

int main(){
    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();
    vector<int> result = nextSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();

    result = nextSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();

    result = nextSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//previous smaller element

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=0; i<n ; i++) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();
    vector<int> result = prevSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();

    result = prevSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();

    result = prevSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

