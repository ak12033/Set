#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                                      Aggressive cows

bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
   	int s = 0;
    int e=stalls[n-1];
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main() {
    int n, k;
    cout << "Enter number of stalls and number of cows: ";
    cin >> n >> k; // Read number of stalls and cows
    vector<int> stalls(n);
    
    cout << "Enter the positions of the stalls: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i]; // Read the positions of stalls
    }
    
    int result = solve(n, k, stalls); // Get the result
    cout << "The largest minimum distance is: " << result << endl; // Output the result

    return 0;
}