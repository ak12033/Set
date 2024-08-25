#include <bits/stdc++.h> 
#define MOD 1000000007
using namespace std;

//                                               Painting fence algorithm

//                                                        approach 1

/*
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

int solveMem(int n, int k, vector<int> &dp){

    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return add(k, mul(k, k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = add(mul(solveMem(n-2, k, dp), k-1), mul(solveMem(n-1, k, dp), k-1));
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1,-1);
    return solveMem(n,k,dp);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << numberOfWays(n, k) << endl;
    return 0;
}
*/

//                                                     approach 2

/*
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

int solveTab(int n, int k){

    vector<int> dp(n+1,0);

    dp[1] = k;
    dp[2] = add(k, mul(k,k-1));

    for(int i=3; i<=n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}

int numberOfWays(int n, int k) {
    return solveTab(n,k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << numberOfWays(n, k) << endl;
    return 0;
}
*/

//                                                     approach 3

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

int solveTabSO(int n, int k){

    if(n == 1){
        return k;
    }
    int prev2 = k;
    int prev1 = add(k, mul(k,k-1));

    for(int i=3; i<=n; i++){
        int ans = add(mul(prev2, k-1), mul(prev1, k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
    return solveTabSO(n,k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << numberOfWays(n, k) << endl;
    return 0;
}