#include<iostream>
using namespace std;
int main(){
    /*char ch='1';
    int num = 1;
    cout << endl;
    switch(ch){
        case 1: cout<<"First"<< endl;
                cout<<"First again"<<endl;
                break;
        case '1':   cout<<"character one"<< endl;
                break;
        default: cout<<"it is default case"<<endl;
    }
    cout<<endl;*/
    
    //calculator
    /*int a, b;

    cout <<" Enter the value of a "<<endl;
    cin >> a;

    cout<<" Enter the value of b " <<endl;
    cin >> b;

    char op;
    cout<<" Enter the Operation you want to perform" <<endl;
    cin >> op;

    switch( op ) {

        case '+':  cout << (a+b) <<endl; 
                  break;

        case '-': cout<< (a-b) <<endl;
                  break;  

        case '*': cout<< (a*b) <<endl;
                  break;

        case '/': cout<< (a/b) <<endl;
                  break;

        case '%': cout<< (a%b) <<endl;
                  break;

        default: cout << "Please enter a valid Operation " << endl;

    }*/
    /*int amount;
    cout<<"Enter the amount"<<endl;
    cin>>amount;
    int Rs100 , Rs50 , Rs20 , Rs1;

    switch(1){
        case 1: Rs100=amount/100;
                amount=amount%100;
                cout<<"No of 100 Rupee notes required are="<<Rs100<<endl;
              
         
        case 2: Rs50=amount/50;
                amount=amount%50;
                cout<<"No of 50 Rupee notes required are="<<Rs50<<endl;
              

        case 3: Rs20=amount/20;
                amount=amount%20;
                cout<<"No of 20 Rupee notes required are="<<Rs20<<endl;
               

        case 4: Rs1=amount/1;
                amount=amount%1;
                cout<<"No of 1 Rupee notes required are="<<Rs1<<endl; 
    }*/

    //functions
    int a,b;
    cin>> a >> b;
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
    cout<<"answer is"<<ans<<endl;
}