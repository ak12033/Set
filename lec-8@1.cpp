#include<iostream>
using namespace std;
/*

//1 -> Even
// 0 -> odd
bool isEven(int a) {
    //odd
    if(a&1) {
        return 0;
    }
    else { //Even
        return 1;
    }

}

int main() {
    
    int num;
    cin >> num;

    if(isEven(num)) {
        cout <<" Number is Even" <<endl;
    }
    else {
        cout<< " Number is Odd" <<endl;
    }


    return 0;
}*/
/*int power(int num1, int num2) {
    
    //cout << a <<endl;

    int ans = 1;

    for(int i = 1; i <= num2; i++) {
        ans = ans * num1;
    }

    return ans;
}
int main()
{
    int c , d;
    cin>> c >> d;

    int answer = power(c,d);
    cout << " answer is " << answer << endl;

    return 0;
}*/

// nCr program
/*int factorial(int n) {

    int fact = 1;

    for(int i = 1; i<=n; i++ ) {
        fact = fact * i;
    }

    return fact;
}

int nCr(int n, int r) {

    int num = factorial(n);

    int denom = factorial(r) * factorial(n-r);

    return num/denom;
}


int main( ) {

    int n, r;

    cin>> n >> r ;

    cout <<" Answer is " << nCr(n,r) << endl;

    return 0;
}*/

//counting
//Function Signature
/*void printCounting(int num) {

//    cout << n << endl;
    //Function Body 
    for(int i=1; i<=num; i++) {
        cout<< i << " ";
    }
    cout<<endl;
}

int main() {

    int n;
    cin >> n;

    //function Call
    printCounting(n);


    return 0;
}*/

//checking prime number or not
// 0 -> Not a Prime no.
// 1 -> Prime no.

/*bool isPrime(int n ) {
   for(int i = 2; i < n; i++){
       if(n % i == 0) {
       //divide hogya h , not a prime no.
          return 0;
        }
   }
   return 1;
}

int main() {
   
   int n ;
   cin >> n;
   if(isPrime(n)) {
        cout <<" is a Prime number " <<endl;
   }
   else{
       cout<< "Not a prime number "<<endl;

   }
}*/

//AP
/*int AP(int n)
{
  int ap=3*n+7;
  return ap;
}

int main()
{
  int n;
  cin>>n;
  int ans=AP(n);
  cout<<"Answer is="<<ans<<endl;

  return 0;
}*/

/*int setBits(int n)
{
  int count = 0;
  while(n!=0)
  {
    if(n&1)
    {
      count++;
    }
    n=n>>1;
  }
  return count; 
}

int main()
{
  int a,b;
  cin>>a>>b;
  int ans1=setBits(a);
  int ans2=setBits(b);
  cout<<"Set bits of A="<<ans1<<endl;
  cout<<"Set bits of B="<<ans2<<endl;
  int ans=ans1+ans2;

  cout<<"Total set bits of A and B are ="<<ans<<endl;

  return 0;
}*/

//fibonacci
/*int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    if(n==1){
        return a;
    }
    for (int i = 2; i < n; i++)
    {
        int next = a + b;
        a = b;
        b = next;
    } 
    return b;
}

int main()
{
    int n;
    cin >> n;
    
    cout << "The " <<n<<"th term of the series is = "<< fibonacci(n) << endl;

    return 0;
}*/

//pass by value
/*void dummy(int n ) {
    n++;
    cout << " n is " << n <<endl;

}

int main() {

    int n;
    cin >> n;

    dummy(n);

    cout<<"number n is "<< n << endl;


    return 0;
}*/

//checking output
/*void update(int a){
    a=a/2;
}
int main(){
    int a=10;
    update(a);
    cout<<a<<endl;
}*/

/*int update(int a){
    a-=5;
    return a ;
}
int main(){
    int a=15;
    update(a);
    cout<<a<<endl;
}*/

int update(int a){
    int ans=a*a;
    return ans ;
}
int main(){
    int a=14;
    a=update(a);
    cout<<a<<endl;
}