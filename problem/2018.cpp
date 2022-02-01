#include <iostream>

using namespace std;

int main(){
    int N, sum;
    int count = 0;
    cin >> N;
    for(int i = 1; i<=N; i++){
        sum = 0;
        for(int j = i; j<=N; j++){
            sum += j;
            if(sum == N){
                count++;
                break;
            }else if(sum > N){
                break;
            }
        }
    }
    cout << count;
}