#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include<unordered_map>
#include <climits>
#include <queue>
using namespace std;

//                                                     Activity Selection

/*
static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
int activitySelection(vector<int> start, vector<int> end, int n){
    vector<pair<int,int>> meets;
        
    for(int i=0; i<n; i++){
        pair<int,int> p = make_pair(start[i], end[i]);
        meets.push_back(p);
    }
        
    sort(meets.begin(), meets.end(), cmp);
        
    int cnt = 1;
    int ansEnd = meets[0].second;
        
    for(int i=1; i<n; i++){
        if(meets[i].first > ansEnd){
            cnt++;
            ansEnd = meets[i].second;
        }
    }
    return cnt;
}

int main() {
    int n;

    // Input number of activities
    cout << "Enter the number of activities: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of activities must be greater than 0." << endl;
        return 1;
    }

    vector<int> start(n), end(n);

    // Input start and end times of activities
    cout << "Enter the start times of the activities:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Start time of activity " << i + 1 << ": ";
        cin >> start[i];
    }

    cout << "Enter the end times of the activities:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "End time of activity " << i + 1 << ": ";
        cin >> end[i];
    }

    // Find and output the maximum number of activities
    int maxActivities = activitySelection(start, end, n);

    cout << "Maximum number of activities that can be performed: " << maxActivities << endl;

    return 0;
}
*/

//                                                Maximum Meetings in One Room

/*
static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
    vector<tuple<int, int, int>> meets; // (start time, finish time, original index)
        
    for (int i = 0; i < N; i++) {
        meets.push_back(make_tuple(S[i], F[i], i + 1)); // Use i + 1 for 1-based index
    }    
    // Sort meetings by their end time
    sort(meets.begin(), meets.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
        return get<1>(a) < get<1>(b);
    });
        
    vector<int> ans;
    // Add the index of the first meeting
    ans.push_back(get<2>(meets[0]));
    int ansEnd = get<1>(meets[0]);
        
    for (int i = 1; i < N; i++) {
        if (get<0>(meets[i]) > ansEnd) {
            // Add the original index of the current meeting
            ans.push_back(get<2>(meets[i]));
            ansEnd = get<1>(meets[i]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int N;
    
    // Input number of meetings
    cout << "Enter the number of meetings: ";
    cin >> N;

    if (N <= 0) {
        cout << "The number of meetings must be greater than 0." << endl;
        return 1;
    }

    vector<int> S(N), F(N);

    // Input start and end times of meetings
    cout << "Enter the start times of the meetings:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Start time of meeting " << i + 1 << ": ";
        cin >> S[i];
    }

    cout << "Enter the end times of the meetings:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "End time of meeting " << i + 1 << ": ";
        cin >> F[i];
    }

    // Find and output the maximum number of meetings
    vector<int> result = maxMeetings(N, S, F);

    cout << "Maximum number of meetings that can be performed: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                                   Shop in Candy Store

/*
vector<int> candyStore(int candies[], int N, int K){
    sort(candies, candies+N);
    
    int mini = 0;
    int buy = 0;
    int free = N-1;
        
    while(buy <= free){
    	mini = mini + candies[buy];
    	buy++;
    	free = free - K;
    }
    	 
    int maxi = 0;
    buy = N-1;
    free = 0;
    	  
    while(free <= buy){
    	maxi = maxi + candies[buy];
    	buy--;
    	free = free + K;
    }	 
    return{mini,maxi};
}

int main() {
    int N, K;
    
    // Input number of candies and free candies
    cout << "Enter the number of candies: ";
    cin >> N;
    
    if (N <= 0) {
        cout << "The number of candies must be greater than 0." << endl;
        return 1;
    }
    
    cout << "Enter the number of free candies after buying some: ";
    cin >> K;
    
    if (K < 0) {
        cout << "The number of free candies cannot be negative." << endl;
        return 1;
    }
    
    vector<int> candies(N);
    
    // Input the prices of candies
    cout << "Enter the prices of the candies:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Price of candy " << i + 1 << ": ";
        cin >> candies[i];
    }
    
    // Call the candyStore function
    vector<int> result = candyStore(candies.data(), N, K);
    
    // Output the results
    cout << "Minimum cost: " << result[0] << endl;
    cout << "Maximum cost: " << result[1] << endl;
    
    return 0;
}
*/

//                                  Check if it is possible to survive on Island

/*
int minimumDays(int S, int N, int M) {
    int sunday = S/7;
        
    int buyingDays = S - sunday;
    int totalFood = S*M;
    int ans = 0;
        
    if(((N*6) < (M*7) && S > 6)) {
        return -1;
    }
    if(totalFood % N == 0){
        ans = totalFood/N;
    }
    else{
        ans = totalFood/N + 1;
    }
    if(ans <= buyingDays){
        return ans;
    }
    else{
        return -1;
    }
}

int main() {
    int S, N, M;
    
    // Input the total number of days, buying days per week, and daily food requirement
    cout << "Enter the total number of days (S): ";
    cin >> S;
    cout << "Enter the number of buying days per week (N): ";
    cin >> N;
    cout << "Enter the daily food requirement (M): ";
    cin >> M;
    
    // Call the function and display the result
    int result = minimumDays(S, N, M);
    
    if (result == -1) {
        cout << "It's not possible to buy enough food within the given constraints." << endl;
    } else {
        cout << "Minimum number of days required: " << result << endl;
    }
    return 0;
}
*/

//                                                Reverse Words

/*
string reverseWords(string S) 
    { 
    string ans = "";
    string temp = "";
    for(int i=S.length()-1; i>=0; i--){
        if(S[i] == '.'){
            reverse(temp.begin(), temp.end());
            ans = ans + temp;
            ans.push_back('.');
            temp = "";
        }
        else{
            temp.push_back(S[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    ans = ans + temp;
    return ans;
} 

int main() {
    string S;
    
    // Input the string
    cout << "Enter the string with words separated by periods: ";
    getline(cin, S);
    
    // Reverse the words in the string
    string result = reverseWords(S);
    
    // Display the result
    cout << "Reversed words: " << result << endl;    
    return 0;
}
*/

//                                              Chocolate Distribution Problem

/*
long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    int i = 0;
    int j = m-1;
            
    int mini = INT_MAX;
    while(j < a.size()){
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}

int main() {
    long long n, m;
    
    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Number of elements must be positive." << endl;
        return 1;
    }
    
    // Input the size of the subset
    cout << "Enter the size of the subset (m): ";
    cin >> m;
    
    if (m <= 0) {
        cout << "Size of the subset must be positive." << endl;
        return 1;
    }
    
    if (m > n) {
        cout << "Subset size cannot be greater than the number of elements." << endl;
        return 1;
    }
    
    vector<long long> a(n);
    
    // Input the elements of the array
    cout << "Enter the elements of the array:" << endl;
    for (long long i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> a[i];
    }
    
    // Call the function and display the result
    long long result = findMinDiff(a, n, m);
    
    if (result == -1) {
        cout << "Not enough elements to form the subset." << endl;
    } else {
        cout << "Minimum difference is " << result << endl;
    }  
    return 0;
}
*/

//                                                   Huffman Encoding

/*
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
        bool operator()(Node* a, Node* b){
        return (a->data > b->data);
        }
};

class Solution{
	public:
	    void traverse(Node* root, vector<string> &ans, string temp){
	        if (root->left == NULL && root->right == NULL){
	            ans.push_back(temp);
	            return;
	        }
	        
            traverse(root->left, ans, temp + '0');
            traverse(root->right, ans, temp + '1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N){
		    priority_queue<Node*, vector<Node*>, cmp> pq;
    
            // Create a node for each character and add to the priority queue
            for (int i=0; i<N; i++){
                Node* temp = new Node(f[i]);
                pq.push(temp);
            }
            
            // Iterate until the heap contains only one node
            while(pq.size() > 1){
                Node* left = pq.top();
                pq.pop();
                Node* right = pq.top();
                pq.pop();
                
                // Create a new internal node with the sum of frequencies
                Node* newNode = new Node(left->data + right->data);
                newNode->left = left;
                newNode->right = right;
                pq.push(newNode);
            }
            Node* root = pq.top();
            vector<string> ans;
            string temp = "";
            traverse(root, ans, temp);
            return ans;
		}
};

int main() {
    int N;
    cout << "Enter the number of characters: ";
    cin >> N;

    string S;
    cout << "Enter the characters: ";
    cin >> S;

    vector<int> f(N);
    cout << "Enter the frequencies: ";
    for (int i = 0; i < N; i++) {
        cin >> f[i];
    }

    Solution obj;
    vector<string> huffmanCodes = obj.huffmanCodes(S, f, N);

    cout << "Huffman Codes:" << endl;
    for (const auto& code : huffmanCodes) {
        cout << code << endl;
    }

    return 0;
}
*/

//                                               Fractional Knapsack

/*
struct Item{
    int value;
    int weight;
};

static bool cmp(pair<double, Item> a, pair<double, Item> b){
    return a.first > b.first;
}
    // Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int w, Item arr[], int n){
        
    vector<pair<double, Item>> v;
        
    for(int i=0; i<n; i++){
        double perUnitValue = (1.0*arr[i].value)/arr[i].weight;
        pair<double, Item> p = make_pair(perUnitValue, arr[i]);
        v.push_back(p);
    }
        
    sort(v.begin(), v.end(), cmp);

    double totalvalue = 0;
    for (int i=0; i<n; i++) {
        if(v[i].second.weight > w) {
            totalvalue += w*v[i].first;
            w = 0;
        } 
        else{
            totalvalue += v[i].second.value;
            w = w - v[i].second.weight;
        }
    }
    return totalvalue;
}

int main() {
    int N; // Number of items
    cout << "Enter the number of items: ";
    cin >> N;
    
    if (N <= 0) {
        cout << "Number of items must be positive." << endl;
        return 1;
    }

    Item items[N];
    int W; // Maximum weight capacity of the knapsack

    // Input the maximum weight capacity of the knapsack
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    // Input weight and value for each item
    cout << "Enter the weight and value for each item:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Value: ";
        cin >> items[i].value;
    }

    // Call the function and get the maximum total value
    double maxValue = fractionalKnapsack(W, items, N);

    // Print the result
    cout << "Maximum total value in the knapsack: " << maxValue << endl;

    return 0;
}
*/

//                                                   Job Sequencing Problem

/*
struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool cmp(Job a, Job b) {
    return (a.profit > b.profit);
}
    //Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n){ 
    sort(arr, arr+n, cmp);
        
    int maxiDeadline = INT_MIN;
    for (int i=0; i<n; i++){
        maxiDeadline = max(maxiDeadline, arr[i].dead);
    }

    vector<int> schedule(maxiDeadline+1, -1);

    int count = 0; 
    int maxProfit = 0;

    for (int i=0; i<n; i++){
        int currProfit = arr[i].profit;
        int currJobID = arr[i].id;
        int currDead = arr[i].dead;
        for (int k = currDead; k>0; k--){
            if (schedule[k] == -1){
                count++;
                maxProfit += currProfit;
                schedule[k] = currJobID;
                break;
            }
        }
    }
    return {count, maxProfit};
}

int main() {
    int N;
    
    cout << "Enter the number of jobs: ";
    cin >> N;
    
    if (N <= 0) {
        cout << "Number of jobs must be positive." << endl;
        return 1;
    }

    Job jobs[N];

    // Input job details
    cout << "Enter the details of each job (ID Deadline Profit):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].dead >> jobs[i].profit;
    }

    // Call the function and get the result
    vector<int> result = JobScheduling(jobs, N);

    // Output the result
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    return 0;
}
*/

//                                                  Minimum Platforms

/*
int findPlatform(int arr[], int dep[], int n){
    sort(arr, arr+n);
    sort(dep, dep+n);
     
    int ans = 0;
    int count = 0;
    int i=0;
    int j=0;
    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans = max(ans, count); //updating the value with the current maximum
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of trains: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of trains must be positive." << endl;
        return 1;
    }

    int arr[n], dep[n];

    // Input arrival and departure times
    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter departure times: ";
    for (int i = 0; i < n; i++) {
        cin >> dep[i];
    }

    // Call the function and display the result
    cout << "Minimum number of platforms required: " << findPlatform(arr, dep, n) << endl;

    return 0;
}
*/
