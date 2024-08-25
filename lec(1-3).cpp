#include <iostream>
using namespace std;

/*int main() {
cout << "Hello World" << endl;
}
*/
/*int main(){
    int a;
    cin>>a;
    //cout<< "value of n is:"<<n <<endl;
    if(a>=0){
        cout << "A is positive" << endl;
    }
    else{
        cout << "A is negative" << endl;
    }*/
    //int a,b;
    //cin >> a >> b;
    //cout << "value of a and b is "<<a <<" "<<b << endl;
    /*int a,b;
    cout<<"Enter the value of a"<<endl;
    cin>>a;
    cout<<"Enter the value of b"<<endl;
    cin>>b;
    if(a>b){
        cout<<"a is greater"<<endl;
    }
    else{
        cout<<"b is greater"<<endl;
    }*/
    /*int a;
    cout<<"Enter the value of a"<<endl;
    cin>>a;
    if(a>0){
        cout<<"a is positive";
    }
    else{
        if(a<0){
            cout<<"a is negative";
        }
        else{
            cout<<"a is 0";
        }
    }
    int a;
    cout<<"Enter the value of a"<<endl;
    cin>>a;
    if(a>0){
        cout<<"a is positive";
    }
    else if(a<0){
        cout<<"a is negative";
    }
    else{
        cout<<"a is 0";
    }
    int a=9;
    if(a==9){
        cout<< "Niney"<<endl;
    }
    if(a>0){
        cout<< "Positive";
    }
    else{
        cout<< "Negative";
    }
    int a=2;
    int b=a+1;
    if((a=3)==b){
        cout<< a;
    }
    else{
        cout<< a+1;
    }
    int a=24;
    if(a>20){
        cout<< "Love";
    }
    else if(a==24){
        cout<< "Lovely";
    }
    else{
        cout<< "Babbar";
    }
    char ch;
    cin>>ch;
    if(ch>='a' && ch<='z'){
        cout<< "This is lowercase";
    }
    else if(ch>='A' && ch<='Z'){
        cout<< "This is uppercase";
    }
    else if(ch>='0' && ch<='9'){
        cout<< "This is numeric";
    }
    else{
        cout<<"try again";
    }
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        cout<<i<<" ";
        i=i+1;
    }
    int n;
    cin>>n;
    int sum=0;
    int i=1;
    while(i<=n){
        sum=sum+i;
        i=i+1;
    }
    cout<<"value of sum is "<<sum<<endl;
    int n;
    cin>>n;
    int sum=0;
    int i=2;
    while(i<=n){
        sum=sum+i;
        i=i+2;
    }
    cout<<"value of sum is "<<sum<<endl;
    int n;
    cin>>n;
    int i=2;
    while(i<n){
        if(n%i==0){
            cout<<"not prime"<<endl;
        }
        else{
            cout<<"prime"<<endl;
        }
        i=i+1;
    }
}*/


//PATTERNS
int main(){
    /*int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }*/
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<i;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}