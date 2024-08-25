#include<queue>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//                                                     K-th Largest Sum Subarray

//                                                            Approach 1

/*
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int,vector<int>,greater<int> > mini;

	int n = arr.size();
	for(int i = 0; i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Example array
    int k = 3; // Example k value
    
    int result = getKthLargest(arr, k);
    cout << "The " << k << "-th largest subarray sum is: " << result << endl;
    
    return 0;
}
*/

//                                                           Approach 2

/*
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int> sumStore;
	int n = arr.size();

	for(int i =0; i<n;i++){
		int sum =0;
		for(int j=i;j<n;j++){
			sum += arr[j];
            sumStore.push_back(sum);
		}         
    }
	sort(sumStore.begin(),sumStore.end());
	
	return sumStore[sumStore.size()-k];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Example array
    int k = 3; // Example k value
    
    int result = getKthLargest(arr, k);
    cout << "The " << k << "-th largest subarray sum is: " << result << endl;
    
    return 0;
}
*/

//                                                     merge k sorted arrays

/*
class node{
    public:
        int data;
        int i;
        int j;
    
    node(int data,int row,int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*,vector<node*>,compare> minHeap;

    //step 1: saare arrays k first element insert h
    for(int i =0;i<k;i++){
        node* temp = new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int> ans;

    //step 2:
    while(minHeap.size()>0){
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }  
    
    return ans;
}

int main() {
    int k;
    cout << "Enter the number of sorted arrays: ";
    cin >> k;

    vector<vector<int>> kArrays(k);

    for (int i = 0; i < k; ++i) {
        int n;
        cout << "Enter the number of elements in array " << i + 1 << ": ";
        cin >> n;

        kArrays[i].resize(n);
        cout << "Enter the elements of array " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> kArrays[i][j];
        }
    }

    vector<int> mergedArray = mergeKSortedArrays(kArrays, k);

    cout << "Merged sorted array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/