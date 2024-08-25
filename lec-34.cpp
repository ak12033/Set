#include<iostream>
using namespace std;

/*void reverse(string& str, int i, int j ) {

    cout << "call recieved for " << str << endl;

    //base case
    if(i>j)
        return ;

    swap(str[i], str[j]);
    i++;
    j--;

    //Recursive call
    reverse(str,i,j);

}

int main() {

    string name = "abcde";
    cout << endl;
    reverse(name, 0 , name.length()-1 );
    cout << endl;
    cout << name << endl;

    return 0;
}*/


//                                                                OR

/*void reverse(string& str, int i){
    if(i==str.length()){
        return;
    }
    reverse(str,i+1);
    cout<<str[i];
}
int main() {

    string name = "babbar";
    cout << endl;
    reverse(name, 0);
    cout << endl;

    return 0;
}*/

//                                                                 OR

/*int reverse(string& str, int i ) {

    cout << "call recieved for " << str << endl;

    //base case
    if(i>str.size()-1-i){
        return false;
    }
    else{
        swap(str[i], str[str.size()-1-i]);
        i++;
    return reverse(str,i);

    }
}

int main() {

    string str;
    cout << "ENTER STRING"<<endl;
    getline(cin,str);
    int i=0;
    reverse(str,i);
    cout << "DESIRED OUTPUT: ";
    cout << str;

    return 0;
}*/


/*bool checkPalindrome(string str, int i, int  j) {

    //base case
    if(i>j)
        return true;

    if(str[i] != str[j])
        return false;
    else{
        //Recursive call
        return checkPalindrome(str, i+1,j-1);
    }
}

int main() {

    string name = "BabbaB";
    cout << endl;

    bool isPalindrome = checkPalindrome(name, 0, name.length()-1 );

    if(isPalindrome) {
        cout << "Its a Palindrome " << endl; 
    }
    else {
        cout << "Its not a Palindrome " << endl;
    }


    return 0;
}*/

/*int power(int a, int b) {
    //base case
    if( b == 0 )
        return 1;

    if(b == 1)
        return a;

    //RECURSIVE CALL
    int ans = power(a, b/2);

    //if b is even
    if(b%2 == 0) {
        return ans * ans;
    }
    else {
        //if b is odd
        return a * ans * ans;
    }
}

int main() {

    int a,b;
    cin >> a >> b;
    cout << endl;
    int ans = power(a,b);

    cout << "Answer is " << ans << endl;

    return 0;
}*/

/*void sortArray(int *arr, int n) {

    //base case - already sorted
    if(n == 0 || n == 1) {
        return ;
    }

    //1 case sovle karlia - largest element ko end me rakh dega
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    //Recursive Call
    sortArray(arr, n-1);

}

int main() {

    int arr[5] = {2,5,1,6,9};
    
    sortArray(arr,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}*/

/*void selectionSort_recursion(int* arr, int n){
    // base case
    if(n==0 || n==1){
        return;
    }
    // swap one item correctly
    int min_idx = 0;
    for(int i=1;i<n;i++){
        if(arr[min_idx]>arr[i]){
            min_idx = i;
        }
    }
    swap(arr[min_idx], arr[0]);
    // arrange other using recursion
    selectionSort_recursion(arr+1, n-1);

}

int main() {

    int arr[5] = {2,5,1,6,9};
    
    selectionSort_recursion(arr,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}*/

void sortArray(int arr[], int s, int e)
{
    //base case 
    if(s==e)
    {
        return ;
    }
    
    
    int temp=arr[s];
    int j=s-1;
    for(; j>=0;j--)
    {
        if(arr[j]>temp)
        {
            //shift
            arr[j+1]=arr[j];
        }
        else{
            break;
        }
    }
    
    arr[j+1]=temp;
    
    // recursive call
    
    sortArray(arr,s+1,5);
    
    
}

int main()
{
    int arr[5]={4,7,1,11,5};
    
    sortArray(arr,1,5);
    
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

