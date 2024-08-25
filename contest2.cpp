/*#include <iostream> 
#include <vector> 
#include <algorithm> 
 
int minStreetlights(int N, int M, int R, std::vector<int>& Ci) { 
    std::sort(Ci.begin(), Ci.end()); 
    int count = 0; 
    int currentPos = 0; 
 
    for (int i = 0; i < M; i++) { 
        if (Ci[i] - R > currentPos) { 
            return -1; 
        } 
        if (Ci[i] - R > currentPos) { 
            currentPos = Ci[i] + R; 
            count++; 
        } 
    } 
 
    if (currentPos < N) { 
        return -1; 
    } 
    return count; 
} 
 
int main() { 
    int N = 10; 
    int M = 4; 
    int R = 3; 
    std::vector<int> Ci = {2,4,7}; 
 
    int result = minStreetlights(N, M, R, Ci); 
    std::cout << "Minimum number of streetlights required: " << result << std::endl; 
 
    return 0; 
}*/

#include<iostream> 
using namespace std;
int main(){
    int a=10;
    if(a<11){
        cout<<"A"<<endl;
    }
    else if(a<12){
        cout<<"B"<<endl;
    }
}