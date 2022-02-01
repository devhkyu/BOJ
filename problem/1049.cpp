#include <iostream>

using namespace std;

int main(){
    int N, M, cost = 0;
    int minPac = 1000, minInd = 1000;
    int pac, ind;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> pac >> ind;
        if(minPac > pac)    minPac = pac;
        if(minInd > ind)    minInd = ind;
    }
    if(minInd * 6 <= minPac)
        cost = minInd * N;
    else{
        while(N >= 6){
            cost += minPac;
            N -= 6;
        }
        if(minInd*N <= minPac)
            cost += minInd * N;
        else
            cost += minPac;
    }
    cout << cost;
}