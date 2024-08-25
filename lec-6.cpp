#include <iostream>
#include<math.h>
using namespace std;
int main(){
    //deimal to binary
    /*int n;
    cin>> n;
    float ans = 0;
    int i = 0;
    while(n != 0 ){
        int bit = (n & 1);
        ans= (bit*pow(10, i) )+ans;
        n= n >> 1;
        i++;
    }
    cout<<"Answer is "<< ans <<endl;*/

    //reversing the number
    /*int n;
    cin>> n;
    int ans=0;
    while(n!=0){
        int digit=n%10;
        n=n/10;
        ans=(ans*10)+digit;
    }
    cout<<ans;*/
    
    //binary to decimal
    int n;
    cin>>n;
    int ans=0,i=0;
    while(n!=0){
        int digit=n%10;
        if(digit==1){
            ans=ans+(pow(2,i));
        }
        n=n/10;
        i++;
    }
    cout<<ans<<endl;
}