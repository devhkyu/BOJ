#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> v;
    for(int item = 1; item<=N; item++){
        v.push_back(item);
    }
    vector<int> answer;
    int idx = 0, cnt = 0;
    while(v.size() != 0){
        cnt++;
        if(idx>=v.size()){
            idx = idx % (v.size());
        }
        if(cnt % K == 0){
            answer.push_back(v[idx]);
            v.erase(v.begin()+idx, v.begin()+idx+1);
            idx--;
        }
        idx++;
    }
    cout << "<";
    for(int i = 0; i<answer.size(); i++){
        cout << answer[i];
        if(i != answer.size()-1){
            cout << ", ";
        }
    }
    cout << ">";
}