#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double answer = 0;
    int N;
    cin >> N;
    double arr[N+1][2];
    for(int i = 0; i<N; i++) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    arr[N][0] = arr[0][0];
    arr[N][1] = arr[0][1];

    for(int i = 0; i<N; i++){
        answer += arr[i][0] * arr[i+1][1];
        answer -= arr[i][1] * arr[i+1][0];
    }
    answer = abs(answer)/2.0;
    printf("%.1f", answer);
}