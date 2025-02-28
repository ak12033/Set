#include <iostream>
#include<vector>
using namespace std;

//                                         Maximum sum of non-adjacent elements

//                                                    approach 1

/*
int solveMem(vector<int> &nums, int n, vector<int> &dp){
    //base case
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    
    int incl = solveMem(nums, n-2, dp) + nums[n];
    int excl = solveMem(nums, n-1, dp) + 0;
    
    dp[n] = max(incl, excl);
    return dp[n];
} 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    return solveMem(nums, n-1, dp);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Array size must be positive!" << endl;
        return 1;
    }
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    
    return 0;
}
*/

//                                                      approach 2

/*
int solveTab(vector<int> &nums){

    int n = nums.size();
    vector<int> dp(n,0);
        
    dp[0] = nums[0];
    if (n > 1) {
        dp[1] = max(nums[0], nums[1]);
    }
        
    for(int i = 2; i<n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }
       
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solveTab(nums); 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Array size must be positive!" << endl;
        return 1;
    }
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    
    return 0;
}
*/

//                                                      approach 3

int solveTab(vector<int> &nums){

    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];
        
    for(int i = 1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
       
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solveTab(nums); 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Array size must be positive!" << endl;
        return 1;
    }
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    
    return 0;
}