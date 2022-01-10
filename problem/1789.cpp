#include <iostream>

using namespace std;

int main(){
    unsigned long n;
    cin >> n;
    int answer;
    if(n == 1)
        answer = 1;
    int i = 2;
    while(true){
        unsigned long sum = (1+i)*((double)i/2);
        if(n<sum)
            break;
        i++;
    }
    answer = i-1;
    cout << answer;
}