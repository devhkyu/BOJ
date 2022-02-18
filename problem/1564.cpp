#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long res = 1;
    for(int i = 1; i<=N; i++){
        res *= i;
        while(res % 10 == 0)
            res /= 10;
        res = res % 1000000000000;
    }
    res = res % 100000;
    int digit = 0;
    for(int i = 0; i<5; i++){
        if((double)res/pow(10, i) > 1)
            digit++;
    }
    for(int i = 0; i<5-digit; i++){
        cout << "0";
    }
    cout << res;
}