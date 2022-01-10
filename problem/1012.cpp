#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;

int dfs(int i, int j, int m, int n){
    visited[i][j] = 1;
    if(i-1 >= 0 && visited[i-1][j] == 0 && map[i-1][j] == 1)
        dfs(i-1, j, m, n);
    if(i+1 < m && visited[i+1][j] == 0 && map[i+1][j] == 1)
        dfs(i+1, j, m, n);
    if(j-1 >= 0 && visited[i][j-1] == 0 && map[i][j-1] == 1)
        dfs(i, j-1, m, n);
    if(j+1 < n && visited[i][j+1] == 0 && map[i][j+1] == 1)
        dfs(i, j+1, m, n);
    return 1;
}

int main(){
    int T;  // The number of test-case
    cin >> T;
    for(int i = 0; i<T; i++){
        int m, n, k; // width(m) height(n) numOfCabbage(k)
        int answer = 0;
        cin >> m;
        cin >> n;
        cin >> k;
        map.assign(n, vector<int>(m, 0));
        visited.assign(n, vector<int>(m, 0));
        for(int j = 0; j<k; j++){   // Making map
            int x, y;
            cin >> x;
            cin >> y;
            map[y][x] = 1;
        }
        for(int p = 0; p<n; p++){
            for(int q = 0; q<m; q++){
                if(map[p][q] == 1 && visited[p][q] == 0)
                    answer += dfs(p, q, n, m);
            }
        }
        map.clear();
        visited.clear();
        cout << answer;
        if(i != T-1)
            cout << endl;
    }
}