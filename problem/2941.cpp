#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    string str;
    cin >> str;
    int i = 0;
    while (i < str.size()) {
        answer++;
        if (i != str.size() - 1) {
            if (str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-'))  i+=2;
            else if (str[i] == 'd' && str[i + 1] == '-')    i+=2;
            else if (str[i] == 'd' && str[i + 1] == 'z'){
                if (i != str.size() - 2 && str[i + 2] == '=')   i += 3;
                else    i++;
            }
            else if (str[i] == 'l' && str[i + 1] == 'j')    i+=2;
            else if (str[i] == 'n' && str[i + 1] == 'j')    i+=2;
            else if (str[i] == 's' && str[i + 1] == '=')    i+=2;
            else if (str[i] == 'z' && str[i + 1] == '=')    i+=2;
            else    i+=1;
        }else   i+=1;
    }
    cout << answer;
}