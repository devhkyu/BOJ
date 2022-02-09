#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> v(n+1);
    vector<int> cost(n+1, 2147000000);

    for(int i=0;i<m;i++){
        int s,e,d;
        cin >> s >> e >> d;
        v[s].push_back(make_pair(d,e));
    }

    int start,end;
    cin >> start >> end;

    priority_queue<pair<int,int>> q;
    cost[start] = 0;
    q.push(make_pair(0,start));

    while(!q.empty()){
        int dist = -q.top().first;
        int cur = q.top().second;
        q.pop();
        if(dist > cost[end])
            continue;
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].second;
            int dt = v[cur][i].first + dist;
            if(cost[next] <= dt)
                continue;
            cost[next] = dt;
            q.push(make_pair(-cost[next], next));
        }
    }

    cout << cost[end];

    return 0;
}