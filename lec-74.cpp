#include<iostream>
#include<queue>
using namespace std;

//                                                Heaps concept

/*
class heap{
    public:
        int arr[100];
        int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2; 
            if(arr[parent] < arr[index]){
                swap( arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromheap(){
        if(size == 0){
            cout << "nothing to delete" << endl;
            return;
        }

        //step 1: put last element into first index
        arr[1] = arr[size];

        //step 2: remove last element
        size--;

        //step 3: take root node to its correct position
        int i =1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};

void maxheapify(int arr[], int n, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }  
}

void minheapify(int arr[], int n, int i){

    int smallest = i;
    int left = 2*i ;
    int right = 2*i + 1;

    if(left <= n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right <= n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        minheapify(arr,n,smallest);
    }  
}

void heapSort(int arr[],int n){
    int size = n;
    while(size > 1){
        //step 1: swap
        swap(arr[size],arr[1]);
        size--;

        //step 2: place the root element to the correct position
        maxheapify(arr,size,1);
    }
}

void heapSort2(int arr[],int n){
    int size = n;
    while(size > 1){
        //step 1: swap
        swap(arr[size],arr[1]);
        size--;

        //step 2: place the root element to the correct position
        minheapify(arr,size,1);
    }
}

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromheap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    //heap creation
    for(int i = n/2; i>0; i--){
        maxheapify(arr,n,i);
    }
    cout << "printing the max heap array" << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    heapSort(arr, n);

    cout << "printing sorted array in increasing order" << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int arr1[6] = {-1,54,53,55,52,50};

    for(int i = n/2 ; i>0; i--){
        minheapify(arr1,n,i);
    }
    cout << "printing the min heap array" << endl;
    for(int i = 1; i <= n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    heapSort2(arr1, n);

    cout << "printing sorted array in decreasing order" << endl;
    for(int i = 1; i <= n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                          Implementation of priority queue using STL

/*
int main(){

    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "element at Top " << pq.top() << endl;
    pq.pop();
    cout << "element at Top " << pq.top() << endl;
    cout << "Size is " << pq.size() << endl;

    if(pq.empty()){
        cout << "pq is empty" << endl;
    }
    else{
        cout << "pq is not empty" << endl;
    }

    priority_queue<int, vector<int>, greater<int> > minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "element at Top " << minheap.top() << endl;
    minheap.pop();
    cout << "element at Top " << minheap.top() << endl;
    cout << "Size is " << minheap.size() << endl;

    if(minheap.empty()){
        cout << "minheap is empty" << endl;
    }
    else{
        cout << "minheap is not empty" << endl;
    }

}*/

//                                                  Minimum Cost of ropes

/*
long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        for(int i =0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long cost =0;
    
        while(pq.size()>1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a+b;
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
    }

int main() {
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum cost to combine all ropes: " << minCost(arr, n) << endl;

    return 0;
}
*/
