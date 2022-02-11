#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> result;

bool isDict(string str){
    int vowel = 0;
    int cons = 0;
    for(int i = 0; i<str.size(); i++){
        if(i != str.size()-1 && str[i]>=str[i+1])
            return false;
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            vowel++;
        else
            cons++;
    }
    if(vowel >= 1 && cons >= 2)
        return true;
    else
        return false;
}

void Combination(vector<char> arr, vector<char> comb, int r, int index, int depth){
    string str;
    if (r == 0){
        for(int i = 0; i < comb.size(); i++)
            str.push_back(comb[i]);
        if(isDict(str))
            result.push_back(str);
    }
    else if (depth == arr.size()){
        return;
    }
    else{
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main(){
    int L, C;
    cin >> L >> C;
    vector<char> ch;
    vector<char> comb(L);
    char temp;
    for(int i = 0; i<C; i++){
        cin >> temp;
        ch.push_back(temp);
    }
    sort(ch.begin(), ch.end());
    Combination(ch, comb, L, 0, 0);
    for(int i = 0; i<result.size(); i++){
        printf("%s", result[i].c_str());
        if(i != result.size()-1)
            printf("\n");
    }
}