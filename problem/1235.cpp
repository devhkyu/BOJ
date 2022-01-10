#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isDuplicated(vector<string> v, int k){
    vector<string> sub;
    int init = v.size();
    int len = v[0].size();
    for(int i = 0; i<v.size(); i++){
        v[i] = v[i].substr(len-k, k);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(init != v.size())
        return true;
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<string> student;
    for(int i = 0; i<N; i++){
        string str;
        cin >> str;
        student.push_back(str);
    }
    int k = 0;
    do{
        k++;
    }while(isDuplicated(student, k) && k<student[0].size());
    cout << k;
}