#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N >> M;

    vector<int> temp1;
    vector<int> temp2;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(a<0) temp1.push_back(a);
        else temp2.push_back(-a);
    }

    if(!temp1.empty()) sort(temp1.begin(), temp1.end());
    if(!temp2.empty()) sort(temp2.begin(), temp2.end());

    int result=0;
    for(int i=0;i<temp1.size();i=i+M){
        int v = -temp1[i];
        result+=2*v;
    }

    for(int i=0;i<temp2.size();i=i+M){
        int v = -temp2[i];
        result+=2*v;
    }

    if(temp1.empty()) result -= -temp2[0];
    else if(temp2.empty()) result -= -temp1[0];
    else if(temp1[0] < temp2[0]) result -= -temp1[0];
    else result -= -temp2[0];
    cout << result;
    return 0;
}