#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i<T; i++){
        vector<string> answer;
        string a, b;
        cin >> a >> b;
        int prev = 0;
        while(!a.empty() || !b.empty()){
            int n = 0;
            if(!a.empty()){
                n += a[a.size()-1]-48;
                a.pop_back();
            }
            if(!b.empty()){
                n += b[b.size()-1]-48;
                b.pop_back();
            }
            n += prev;
            if(n >= 2){
                n -= 2;
                prev = 1;
            }else{
                prev = 0;
            }
            answer.push_back(to_string(n));
        }
        if(prev == 1){
            answer.push_back("1");
        }
        reverse(answer.begin(), answer.end());
        bool isStarted = false;
        for(int j = 0; j<answer.size(); j++){
            if(j == answer.size()-1 && !isStarted){
                isStarted = true;
            }
            if(answer[j] == "0" && !isStarted){
                continue;
            }
            if(answer[j] == "1" && !isStarted){
                isStarted = true;
            }
            cout << answer[j];
        }
        if(i != T-1)
            cout << endl;
    }
}