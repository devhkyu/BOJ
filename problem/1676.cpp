#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int div5 = 0;
    for(int i = 1; i<=N; i++){
        int temp = i;
        while(temp%5 == 0){
            div5++;
            temp/=5;
        }
    }
    cout << div5;
}