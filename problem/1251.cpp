#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string makeWord(string str, int start, int end){
    string str1 = str.substr(0, start);
    string str2 = str.substr(start, end-start);
    string str3 = str.substr(end, str.size()-end);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    reverse(str3.begin(), str3.end());
    return (str1 + str2 + str3);
}

int main(){
    int answer = 0;
    char ch[100];
    cin.getline(ch, 100, '\n');
    vector<string> str;
    string s = ch;
    for(int i = 1; i<s.size()-1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            string temp = makeWord(s, i, j);
            str.push_back(temp);
        }
    }
    cout << *min_element(str.begin(), str.end());
    return 0;
}