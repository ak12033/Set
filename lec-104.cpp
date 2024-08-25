#include <bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &num, int x, vector<int> &dp){
    if (x == 0) {
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }

    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = solveMem(num, x-num[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    dp[x] = mini;
    
    return dp[x];

}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1,-1);
    int ans = solveMem(num, x, dp);

    if(ans == INT_MAX){
        return -1;
    }
    else{
        return ans;
    }
}

int main() {
    // Input number of denominations
    int n;
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);

    // Input the coin denominations
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    // Input the amount
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    // Find the minimum number of coins required
    int result = minimumElements(coins, amount);

    // Output the result
    if (result != -1) {
        cout << "The minimum number of coins required is: " << result << std::endl;
    } else {
        cout << "It is not possible to make the amount with the given coins." << std::endl;
    }

    return 0;
}