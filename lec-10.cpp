#include <iostream>
using namespace std;

/*void printArray(int arr[], int n) {

    for(int i = 0; i<n; i++ ) {
        cout<< arr[i] <<" ";
    }cout<<endl;

}

void swapAlternate(int arr[], int size) {

    for(int i = 0; i<size; i+=2 ) {
        if(i+1 < size) {
            swap(arr[i], arr[i+1]);
        }
    }

}

int main() {

    int even[8] = {5,2,9,4,7,6,1,0};
    int odd[5] = {11, 33, 9, 76, 43};

    printArray(even, 8);
    swapAlternate(even, 8);
    printArray(even, 8);

    cout << endl;

    printArray(odd, 5);
    swapAlternate(odd, 5);
    printArray(odd, 5);



    return 0;
}*/

//sort 0 1
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOne(int arr[], int n) {

    int left = 0, right = n-1;

    while(left < right) {

        if(arr[left] == 0  )  {
            left++;
        }

        else if(arr[right]==1){
            right--;
        }

        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        else
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

}

int main() {

    int arr[8] = {1,1,1,1,1,0,0,0};

    sortOne(arr, 8);
    printArray(arr, 8);


    return 0;
}