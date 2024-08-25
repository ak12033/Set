#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//                                         Longest Arithmetic Subsequence using Recursion

int solve(int index, int diff, vector<int> &nums) {
    //backward check
    if(index < 0){
        return 0;
    }

    int ans = 0;
    
    for(int j = index-1; j>=0; j--){
        if(nums[index]-nums[j] == diff){
            ans = max(ans, 1 + solve(j, diff, nums));
        }
    }
    return ans;
}

int lengthOfLongestAP(vector<int>& arr){
    int n = arr.size();

    if(n<=2){
        return n;
    }
        
    int ans = 0;
        
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            ans = max(ans, 2 + solve(i, arr[j]-arr[i], arr));
        }
    }
    return ans;
}

int main(){

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Array size should be greater than 0." << endl;
        return 1;
    }
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int result = lengthOfLongestAP(arr);
    cout << "Length of the longest arithmetic progression: " << result << endl;
    
    return 0;
}