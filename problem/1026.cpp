#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int answer = 0;
    int n = 0;
    vector<int> a;
    vector<int> b;
    cin >> n;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i<n; i++){
        answer += a[i] * b[n-i-1];
    }
    cout << answer;
}