#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n){
    if(n == 1)
        return false;
    for(int i = 2; i<=sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int M, N;
    int sum = 0;
    int minPrime = -1;
    cin >> M >> N;
    for(int i = M; i<=N; i++){
        if(isPrime(i)){
            sum += i;
            if(minPrime == -1){
                minPrime = i;
            }
        }
    }
    if(sum != 0)
        cout << sum << endl << minPrime;
    else
        cout << minPrime;
}