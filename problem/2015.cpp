#include <iostream>
#include <map>

using namespace std;
int p_sum[200001];

int main(){
    int n, k, num;
    cin >> n >> k;

    map<int, long long> m;
    long long cnt = 0;
    m[0] = 1;

    for (int i=1; i<=n; i++){
        cin >> num;
        p_sum[i] = p_sum[i-1] + num;
        cnt += m[p_sum[i] - k];
        m[p_sum[i]]++;
    }

    cout << cnt;
}