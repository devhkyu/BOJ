#include <iostream>

using namespace std;

int main(){
    int a, b, n;
    int answer = 0;
    scanf("%d %d %d", &a, &b, &n);
    while(a>=b){
        a = a%b;
    }
    int cnt = 1;
    while(n>=cnt){
        a *= 10;
        answer = (int)a/b;
        a = a%b;
        cnt++;
    }
    cout << answer;
}