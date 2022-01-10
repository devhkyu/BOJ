#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, temp;
    vector<int> v;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i<v.size(); i++){
        printf("%d", v[i]);
        if(i != v.size()-1)
            printf("\n");
    }
}