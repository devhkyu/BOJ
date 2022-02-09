#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    while(num--){
        int n, m;
        cin >> n >> m;
        long long ans = 1;
        int r = 1;
        for(int i = m; i>m-n; i--){
            ans *= i;
            ans /= r++;
        }
        cout << ans << endl;
    }
}