#include <iostream>
#include <math.h>
#include <limits.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> 
using namespace std;

//                         Longest substring consisting of only zeroes
/*
int pairpro(string s){
    int count = 0;
    int maxi = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            count++;
            maxi = max(count, maxi);
        }
        else{
            count = 0;
        }
    }
    return maxi;
}
int main() {
    string s;
    cin>>s;
    int answer = pairpro(s);
    cout<<answer<<endl;
}
*/

//                                Maximize Pair Product
/*
vector<int> maxpairsum(int n,int arr[]){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int prod = INT_MIN;
    vector<int> answer;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==18){
                int cmaxi=max(arr[i],arr[j]);
                int cmini=min(arr[i],arr[j]);
                int currprod = cmaxi*cmini;
                if(currprod>prod){
                    prod = currprod;
                    maxi=cmaxi;
                    mini=cmini;
                    answer={maxi,mini};
                }
            }
        }
    }
    return {maxi,mini};
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result = maxpairsum(n, arr);
    cout<<"{";
    for(int i=0;i<2;i++){
        cout<<result[i];
        if(i<1){
            cout<<",";
        }
    }
    cout<<"}";
    cout<<endl;   
}
*/

//       Check whether the product of all elements in an array is a perfect 8th power or not
/*
bool check(vector<int> &arr){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]==2){
            count++;
        }
    }
    return (count == 0 || count % 8 == 0);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    cout<<"Enter 1s and 2s"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(check(arr)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
*/

//                      Print leftmost and rightmost nodes of a Binary Tree
/*
struct Node{
    int data;
    Node *left, *right;
 
    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};
void print(Node* root){
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
    // create an empty queue to store tree nodes
    queue<Node*> q;
    // enqueue root node
    q.push(root);
    // loop till queue is empty
    while (!q.empty()){
        // get the size of the current level
        int size = q.size();
        int n = size ;
 
        // process all nodes present in the current level
        while (n--){
            Node* node = q.front();
            q.pop(); 
            // if the corner node is found, print it
            if (n == size - 1 || n == 0) {
                cout << node->data << " ";
            }
            // enqueue left and right child of the current node
            if (node->left != nullptr) {
                q.push(node->left);
            } 
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        // terminate level by printing an empty line
        cout << endl;
    }
}
int main(){

    // Construct the following tree
    //           1
    //          / \
    //         2   3
    //        /   / \
    //       4   5   6
    //      /   / \   \
    //     7   8   9   10
    
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(10);
 
    print(root);
 
    return 0;
}
*/

//                      Square of a number with bit manipulation 
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

//                          Adding Spaces to a String
/*
string addSpaces(string s, vector<int>& spaces) {

    string ans = "";
    int spaceIndex = 0;
    int n = spaces.size();
    for(int i=0; i<s.length(); i++){
        if(spaceIndex < n && i == spaces[spaceIndex]){
            ans.push_back(' ');
            spaceIndex++;
        }
        ans.push_back(s[i]);
    }
    return ans;
}
int main() {

    string s = "spacing";
    vector<int> spaces = {0 , 1, 2, 3, 4, 5, 6};

    string result = addSpaces(s, spaces);
    cout << "Resulting string ->" << result << endl;

    return 0;
}
*/

//                                 Unique Email Addresses
//                                      Approach 1
/*
string normalizeEmail(const string& email) {

    int at_pos = email.find('@');
    string local = email.substr(0, at_pos);
    string domain = email.substr(at_pos);

    // Remove '.' characters from the local part
    local.erase(remove(local.begin(), local.end(), '.'), local.end());

    // Remove the part after '+' in the local part (if any)
    int plus_pos = local.find('+');
    if (plus_pos != string::npos) {
        local = local.substr(0, plus_pos);
    }

    return local + domain;
}
int numUniqueEmails(const vector<string>& emails) {

    set<string> uniqueEmails;

    for (const string& email : emails) {
        string normalizedEmail = normalizeEmail(email);
        uniqueEmails.insert(normalizedEmail);
    }
    return uniqueEmails.size();
}
int main() {

    int n;
    cin >> n;  
    // Ignore newline character
    cin.ignore();  

    vector<string> emails(n);
    for (int i = 0; i < n; ++i) {
        // Read each email address
        getline(cin, emails[i]);  
    }
    cout << numUniqueEmails(emails) << endl;  // Output number of unique mailboxes

    return 0;
}
*/
//                                      Approach 2
/*
string normalizeEmail(const string& email) {

    int c = 0;
    for(int i=0; i<email.length(); i++){
        if(email[i]=='@'){
            c = i;
            break;
        }
    }
    string domain;
    for(int i=c;i<email.length();i++){
        domain.push_back(email[i]);
    }
    string local;
    for(int i=0;i<c;i++){
        if(email[i]=='+'){
            break;
        }
        else if(email[i] == '.'){
            continue;
        }
        else{
            local.push_back(email[i]);
        }
    }
    return local + domain;
}
int numUniqueEmails(const vector<string>& emails) {

    set<string> uniqueEmails;

    for (const string& email : emails) {
        string normalizedEmail = normalizeEmail(email);
        uniqueEmails.insert(normalizedEmail);
    }
    return uniqueEmails.size();
}
int main() {

    int n;
    cin >> n;  
    // Ignore newline character
    cin.ignore();  

    vector<string> emails(n);
    for (int i = 0; i < n; ++i) {
        // Read each email address
        getline(cin, emails[i]);  
    }
    cout << numUniqueEmails(emails) << endl;  // Output number of unique mailboxes

    return 0;
}
*/

//             Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’
/*
int main() {

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    vector<int> result(N, 0);
    for (int i=0; i<N; i++) {
        result[arr[i]] = i;
    }

    // Print the modified array
    for (int i=0; i<N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/