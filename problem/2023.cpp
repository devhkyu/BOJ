#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

bool decimalChk(int num) {
    for(int i=2; i<=sqrt(num); i++) {
        if(num%i == 0) {
            return false;
        }
    }
    return true;
}

int N;

void dfs(int num) {
    if(to_string(num).size() == N) {
        cout << num << '\n';
        return;
    }
    for(int i=0; i<=9; i++) {
        string es = to_string(num) + to_string(i);
        int ei = stoi(es);
        if(decimalChk(ei) == 1) {
            dfs(ei);
        }
    }
}


int main() {
    cin >> N;
    for(int i=2; i<10; i++) {
        if(decimalChk(i) == 1) {
            dfs(i);
        }
    }
    return 0;
}