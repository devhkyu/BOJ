#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "end") break;
        bool flag = false;
        int countVowel = 0;
        vector<bool> isVowel(s.size());

        if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
            countVowel++;
            isVowel[0] = true;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != 'e' && s[i] != 'o' && s[i - 1] == s[i]) {
                flag = true;
                break;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                countVowel++;
                isVowel[i] = true;
            }
        }
        if (flag || countVowel == 0) {
            cout << '<' << s << "> is not acceptable.\n";
            continue;
        }
        for (int i = 2; i < s.size(); i++) {
            if (isVowel[i - 2] == isVowel[i - 1] && isVowel[i - 1] == isVowel[i]) {
                flag = true;
                break;
            }
        }
        if(flag) cout << '<' << s << "> is not acceptable.\n";
        else cout << '<' << s << "> is acceptable.\n";
    }
    return 0;
}