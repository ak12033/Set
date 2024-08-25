#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//                                                  Count Ways To Reach The N-th Stairs

int solve(int n,vector<int> &dp){
    const int mod = 1000000007;
    // Base cases
    if(n<0){
        return 0;
    }
    if (n == 0) {
      return 1;
    }
    if(dp[n]!=-1){
      return dp[n];
    }
    dp[n] = (solve(n-1,dp)+solve(n-2,dp))% mod;
    return dp[n];
} 

int countDistinctWays(int nStairs) {

    vector<int> dp(nStairs + 1,-1);
    
    // Recursive case: number of ways to reach nth stair
    return solve(nStairs,dp);
}

int main() {
    int nStairs;
    cin >> nStairs;
    cout << countDistinctWays(nStairs) << endl;
    return 0;
}