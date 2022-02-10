#include <iostream>
#include <string>

using namespace std;

int main(){
    string str, key;
    int cnt = 0;
    int pos = 0;
    getline(cin, str);
    getline(cin, key);
    while((str.substr(pos)).find(key) != string::npos){
        cnt++;
        pos += ((int)key.size() + (int)(str.substr(pos)).find(key));
    }
    cout << cnt;
}