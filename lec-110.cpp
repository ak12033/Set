#include <bits/stdc++.h> 
using namespace std;

//                                                     0/1 Knapsack

//                                                      approach 1

/*
int solveMem(vector<int>& weight, vector<int>& value, int index, int capacity, vector<vector<int>>& dp) {
    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if (index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}
      	else{
        	return 0;
      	}
    }

    // If the result for this state is already calculated, return it
    if (dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    // Calculate the maximum value by either excluding the current item or including it
    // Check if the current item can be included without exceeding the knapsack's capacity
	int include = 0;
    if (weight[index] <= capacity){
        include = value[index] + solveMem(weight, value, index-1, capacity-weight[index], dp);
    }
	int exclude = solveMem(weight, value, index-1, capacity, dp);

    // Store the result in the DP table and return
	dp[index][capacity] = max(exclude, include);
    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solveMem(weight, value, n-1, maxWeight, dp);
}

int main() {
    int n, maxWeight;
    
    // Take input for number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;

    vector<int> weights(n);
    vector<int> values(n);

    // Take input for weights
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Take input for values
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int result = knapsack(weights, values, n, maxWeight);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}
*/

//                                                      approach 2

/*
int solveTab(vector<int>& weight, vector<int>& value, int n, int capacity){

	//step1:
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));	
    //step2: analyze base case
    for (int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
			dp[0][w] = value[0];
		}
		else{
			dp[0][w] = 0;
		}
    }

    for (int index=1; index<n; index++){
        for (int w=0; w<=capacity; w++){
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + dp[index-1][w-weight[index]];
            }

			int exclude = dp[index-1][w];
            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n-1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return solveTab(weight, value, n, maxWeight);
}

int main() {
    int n, maxWeight;
    
    // Take input for number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;

    vector<int> weights(n);
    vector<int> values(n);

    // Take input for weights
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Take input for values
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int result = knapsack(weights, values, n, maxWeight);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}
*/

//                                                      approach 3

/*
int solveTabSO(vector<int>& weight, vector<int>& value, int n, int capacity){

	//step1:
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

    //step2: analyze base case
    for (int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
			prev[w] = value[0];
		}
		else{
			prev[w] = 0;
		}
    }

    for (int index=1; index<n; index++){
        for (int w=0; w<=capacity; w++){
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + prev[w-weight[index]];
            }

			int exclude = prev[w];
            curr[w] = max(exclude, include);
        }
		prev = curr;
    }
    return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return solveTabSO(weight, value, n, maxWeight);
}

int main() {
    int n, maxWeight;
    
    // Take input for number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;

    vector<int> weights(n);
    vector<int> values(n);

    // Take input for weights
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Take input for values
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int result = knapsack(weights, values, n, maxWeight);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}
*/

//                                                      approach 4(using one array)

int solveTabSO(vector<int>& weight, vector<int>& value, int n, int capacity){

	//step1:
	vector<int> curr(capacity+1, 0);

    //step2: analyze base case
    for (int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
			curr[w] = value[0];
		}
		else{
			curr[w] = 0;
		}
    }

    for (int index=1; index<n; index++){
        for (int w=capacity; w>=0; w--){
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + curr[w-weight[index]];
            }

			int exclude = curr[w];
            curr[w] = max(exclude, include);
        }
    }
    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return solveTabSO(weight, value, n, maxWeight);
}

int main() {
    int n, maxWeight;
    
    // Take input for number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;

    vector<int> weights(n);
    vector<int> values(n);

    // Take input for weights
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Take input for values
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int result = knapsack(weights, values, n, maxWeight);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}