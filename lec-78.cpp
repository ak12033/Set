#include<iostream>
#include<map>
#include <vector>
#include<unordered_map>
using namespace std;

// for unordered map

/*
int main(){

    //creation
    unordered_map<string,int> m;

    //insertion

    // 1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);

    // 2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;

    // updation
    m["mera"] = 2;

    // search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // will give an error
    //cout << m.at("unknownKey") << endl;
    
    // to avoid error
    cout << m["unknownKey"] << endl;
    cout << m.at("unknownKey") << endl;

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("love") << endl;

    // erase
    m.erase("love");
    cout << m.size() << endl;

    //traversing a map

    // 1
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    // 2 using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}
*/

// for map

/*
int main(){

    //creation
    map<string,int> m;

    //insertion

    // 1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);

    // 2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;

    // updation
    m["mera"] = 2;

    // search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // will give an error
    //cout << m.at("unknownKey") << endl;
    
    // to avoid error
    cout << m["unknownKey"] << endl;
    cout << m.at("unknownKey") << endl;

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("love") << endl;

    // erase
    m.erase("love");
    cout << m.size() << endl;

    //traversing a map

    // 1
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    // 2 using iterator
    map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}
*/

//                                               Maximum Frequency Number

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here

    unordered_map<int,int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i = 0; i<n; i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq,count[arr[i]]);
    }

    for(int i = 0; i<n; i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main() {
    int n;

    // Taking input for the size of the vector
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Check if the size is valid
    if (n <= 0) {
        std::cerr << "The number of elements must be positive." << std::endl;
        return 1;
    }

    std::vector<int> arr(n);

    // Taking input for the elements of the vector
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    try {
        int result = maximumFrequency(arr, n);
        std::cout << "Element with maximum frequency: " << result << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}