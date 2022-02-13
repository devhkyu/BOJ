#include <iostream>
#include <vector>

using namespace std;

static int N = 5;
static int M = 25;
vector<vector<int>> board(N, vector<int>(N, 0));

bool isBingo(){
    int cnt_bingo = 0;
    for(int i = 0; i<N; i++){
        int tempX = 0;
        int tempY = 0;
        for(int j = 0; j<N; j++){
            if(board[i][j] == 0)
                tempX++;
            if(board[j][i] == 0)
                tempY++;
        }
        if(tempX == N)
            cnt_bingo++;
        if(tempY == N)
            cnt_bingo++;
    }
    if(board[0][0]+board[1][1]+board[2][2]+board[3][3]+board[4][4] == 0)
        cnt_bingo++;
    if(board[0][4]+board[1][3]+board[2][2]+board[3][1]+board[4][0] == 0)
        cnt_bingo++;
    if(cnt_bingo >= 3)
        return true;
    else
        return false;
}

void bingo(int n){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(board[i][j] == n){
                board[i][j] = 0;
                break;
            }
        }
    }
}

int main(){
    vector<int> count(25, 0);
    int answer = 0;
    for(int i = 0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i<M; i++){
        cin >> count[i];
    }
    for(int i = 0; i<M; i++){
        bingo(count[i]);
        answer++;
        if(isBingo()){
            cout << answer;
            break;
        }
    }
}