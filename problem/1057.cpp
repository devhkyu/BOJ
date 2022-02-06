#include <iostream>

using namespace std;

int getRound(int n, int p1, int p2){
    int round = 1;
    while(n){
        if ((p1 + 1) / 2 == (p2 + 1) / 2)
            break;
        p1 = (p1 + 1) / 2;
        p2 = (p2 + 1) / 2;
        round += 1;
        n /= 2;
    }
    if(!n)
        return -1;
    return round;
}

int main(){
    int N, player1, player2;
    cin >> N >> player1 >> player2;
    cout << getRound(N, player1, player2) << endl;
    return 0;
}
