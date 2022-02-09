#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char a[600000];

int main(){
    scanf("%s", a);
    stack<char> left, right;
    int m = strlen(a);
    for(int i = 0; i<m; i++){
        left.push(a[i]);
    }
    int n;
    scanf("%d", &n);
    while(n--){
        char com;
        scanf(" %c", &com);
        if(com == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }else if(com == 'D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }else if(com == 'B'){
            if(!left.empty()){
                left.pop();
            }
        }else if(com == 'P'){
            scanf(" %c", &com);
            left.push(com);
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        printf("%c", right.top());
        right.pop();
    }
}