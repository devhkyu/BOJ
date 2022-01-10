#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isOK(vector<int> v){
    for(int i = 1; i<v.size(); i++){
        if(v[0] <= v[i])
            return false;
    }
    return true;
}

int main(){
    int n = 0;
    int answer = 0;
    vector<int> v;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    while(!isOK(v)){
        sort(v.begin()+1, v.end(), greater<>());
        v[0]++;
        v[1]--;
        answer++;
    }
    cout << answer;
    return 0;
}