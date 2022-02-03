#include <iostream>
#include <vector>

using namespace std;

int main(){
    string input;
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            board[i][j] = (int)input[j] - 48;
        }
    }

    int result = 1;
    for(int wnd = 2; wnd <= min(N, M); wnd++){
        for(int i = 0; i<=N-wnd; i++){
            for(int j = 0; j<=M-wnd; j++){
                if(board[i][j] == board[i+wnd-1][j] && board[i+wnd-1][j] == board[i][j+wnd-1] && board[i][j+wnd-1] == board[i+wnd-1][j+wnd-1]){
                    result = wnd * wnd;
                }
            }
        }
    }
    cout << result;
}