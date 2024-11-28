#include <bits/stdc++.h>
using namespace std;

int c=0;
void merge(vector<int> &arr, int low, int mid, int high) {

    // Temporary Array
    vector<int> temp; 
    
    // Starting index of left half of arr
    int left = low; 

    // Starting index of right half of arr
    int right = mid + 1;   

    // Storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            c+=(mid-left+1);
            right++;
        }
    }
    // If elements on the left half are still left 
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    // If elements on the right half are still left 
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // Transfering all elements from temporary to arr 
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
}