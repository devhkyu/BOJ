#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, P, temp;
    unsigned long long score;
    vector<unsigned long long> board;
    cin >> N >> score >> P;
    for(int i = 0; i<N; i++){
        cin >> temp;
        board.push_back(temp);
    }
    board.push_back(score);
    sort(board.begin(), board.end(), greater<>());
    int real_rank = 0;
    int pos_rank = 0;
    for(int i = 0; i<board.size(); i++){
        if(score == board[i]){
            real_rank = i+1;
            pos_rank = i+1;
            for(int j = i+1; j<board.size(); j++){
                if(score == board[j])
                    pos_rank++;
                else
                    break;
            }
            if(pos_rank <= P)
                cout << real_rank;
            else
                cout << -1;
            return 0;
        }
    }
}