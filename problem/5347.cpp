#include <iostream>

using namespace std;

int lcm(int a, int b){
    int res = 1;
    int div = 2;
    int maxValue = max(a, b);
    while(div <= maxValue){
        if(a%div == 0 && b%div == 0){
            res *= div;
            a /= div;
            b /= div;
        }else{
            if(a%div == 0){
                res *= div;
                a /= div;
            }else if(b%div == 0){
                res *= div;
                b /= div;
            }
        }
        if(a%div != 0 && b%div != 0)
            div++;
    }
    return res;
}

int main(){
    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
}