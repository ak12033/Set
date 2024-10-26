#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n){   
    for(int i=1; i<n; i++) {
        int j = i;
        while(j>0 && arr[j-1]>arr[j]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    
    insertionSort(arr, n);
    
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}