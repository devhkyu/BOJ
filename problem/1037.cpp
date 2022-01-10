#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n = 0;
    vector<int> v;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << (*min_element(v.begin(), v.end()))*(*max_element(v.begin(), v.end()));
    return 0;
}