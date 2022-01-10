#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &s1, const string &s2){
    if(s1.size() == s2.size()){
        return s1 < s2;
    }
    return s1.size() < s2.size();
}
int main(){
    int n = 0;
    cin >> n;
    string str;
    vector<string> v;
    for(int i = 0; i<n; i++){
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), comp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto x : v){
        cout << x << "\n";
    }
    return 0;
}