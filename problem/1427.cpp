#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string input;
    cin >> input;
    vector<int> v;
    for(int i = 0; i<input.size(); i++){
        v.push_back(input[i]-48);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i<input.size(); i++){
        cout << v[i];
    }
}