#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, H;
    cin >> N >> H;
    vector<int> bottom(N/2), top(N/2);
    for (int i = 0; i < N/2; i++)
        cin >> bottom[i] >> top[i];
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());
    int result = INF;
    int cnt = 1;
    for (int i = 1; i <= H; i++){
        int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
        temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());
        if (result == temp)
            cnt++;
        else if (result > temp){
            result = temp;
            cnt = 1;
        }
    }
    cout << result << " " << cnt << "\n";
    return 0;
}