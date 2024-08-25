#include<iostream> 
using namespace std;

//factorial

/*int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;

    //int smallerProblem = factorial(n-1);   
    //int biggerProblem = n * smallerProblem;

    //return biggerProblem;
    return n * factorial(n-1);
}

int main() {

    int n;
    cin >> n;

    int ans = factorial(n);

    cout << ans << endl;

    return 0;
}*/

//power

/*int power(int n) {

    //base case 
    if(n == 0)
        return 1;

    //recursive relation
    //int smallerProblem = factorial(n-1);   
    //int biggerProblem = n * smallerProblem;

    //return biggerProblem;
    return 2 * power(n-1);    
}

int main() {

    int n;
    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    return 0;
}*/

//printing 1 to n in reverse order
/*void print(int n) {

    //base case 
    if(n == 0)
        return ;

    //recursive relation
    cout << n << endl;
    print(n-1);
}

int main() {

    int n;
    cin >> n;
    cout << endl;
    print(n);

    return 0;
}*/

//print 1 to n without using loop
void print(int n) {

    //base case 
    if(n == 0)
        return ;

    //recursive relation
    
    print(n-1);
    cout << n << endl;
}

int main() {

    int n;
    cin >> n;
    cout << endl;
    print(n);

    return 0;
}