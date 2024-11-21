#include<iostream>
#include<math.h>
#include<limits.h>
#include<vector>
using namespace std;

//square of a number with bit manipulation 
/*
int main(){
    int n;
    cin>>n;
    n = abs(n);
    int temp_n = n;
    int pos = 0;
    int res = 0;
    while(temp_n != 0){
        if(temp_n & 1){
            res += n<<pos;
        }
        pos++;
        temp_n = temp_n>>1;
    }
    cout << res <<endl;
}
*/

int main(){
    string st = "Hello World!";
    st.back() = 'd';
    cout<<st<<endl;
}