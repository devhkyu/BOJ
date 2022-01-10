#include <iostream>

using namespace std;

int sumOf(int n){
    int result = 0;
    int cnt = 1;
    while(n > 0){
        for(int i = 0; i<cnt; i++){
            if(n<=0)
                break;
            result += cnt;
            n--;
        }
        cnt++;
    }
    return result;
}
int main(){
    int answer = 0;
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    cout << sumOf(b) - sumOf(a-1);
    return 0;
}