#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;

//                                                     Cut Into Segments

//                                                        approach 1

/*
int solveMem(int n, int x, int y, int z, vector<int> &dp){

    // base case
    if (n == 0) {
     	return 0;
   	}

    if(n<0){
        return INT_MIN;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int a = solveMem(n-x, x, y, z, dp) + 1;
	int b = solveMem(n-y, x, y, z, dp) + 1;
	int c = solveMem(n-z, x, y, z, dp) + 1;
		
	dp[n] = max(a, max(b, c));
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	
	vector<int> dp(n+1, -1);
	int ans = solveMem(n, x, y, z, dp);
	
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
}

int main() {
    int n, x, y, z;

    // Taking user input
    cout << "Enter the length of the rod (n): ";
    cin >> n;
    cout << "Enter the length of the first segment (x): ";
    cin >> x;
    cout << "Enter the length of the second segment (y): ";
    cin >> y;
    cout << "Enter the length of the third segment (z): ";
    cin >> z;

    int result = cutSegments(n, x, y, z);

    cout << "Maximum number of segments: " << result << std::endl;

    return 0;
}
*/

//                                                           approach 2

/*
int solveTab(int n, int x, int y, int z){
      
    vector<int> dp(n+1, -1);
    dp[0]= 0;
    
    for(int i=1; i<=n; i++){
        
        if(i-x >= 0 && dp[i-x] != -1){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        
        if(i-y >= 0 && dp[i-y] != -1){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }

        if(i-z >= 0 && dp[i-z] != -1){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }
    
    if (dp[n] < 0) {
        return 0; // No valid cut configuration found
    }
    else{
        return dp[n];
    }
}

int cutSegments(int n, int x, int y, int z) {

	return solveTab(n,x,y,z);

}

int main(){
    int n, x, y, z;

    // Taking user input
    cout << "Enter the length of the rod (n): ";
    cin >> n;
    cout << "Enter the length of the first segment (x): ";
    cin >> x;
    cout << "Enter the length of the second segment (y): ";
    cin >> y;
    cout << "Enter the length of the third segment (z): ";
    cin >> z;

    int result = cutSegments(n, x, y, z);

    cout << "Maximum number of segments: " << result << std::endl;

    return 0;
}
*/

//                                                           approach 2(using INT_MIN)

int solveTab(int n, int x, int y, int z){
      
    vector<int> dp(n+1, INT_MIN);
    dp[0]= 0;
    
    for(int i=1; i<=n; i++){
        
        if(i-x >= 0){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        
        if(i-y >= 0){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }

        if(i-z >= 0){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }
    
    if (dp[n] < 0) {
        return 0;
    }
    else{
        return dp[n];
    }
}

int cutSegments(int n, int x, int y, int z) {

	return solveTab(n,x,y,z);

}

int main(){
    int n, x, y, z;

    // Taking user input
    cout << "Enter the length of the rod (n): ";
    cin >> n;
    cout << "Enter the length of the first segment (x): ";
    cin >> x;
    cout << "Enter the length of the second segment (y): ";
    cin >> y;
    cout << "Enter the length of the third segment (z): ";
    cin >> z;

    int result = cutSegments(n, x, y, z);

    cout << "Maximum number of segments: " << result << endl;

    return 0;
}