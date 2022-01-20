#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
int ans=0;
int res_dis;

void bfs(vector <vector <pair<int ,int>>> &graph, int start, int *dis, int *indeg){
    bool visit[100001];
    for(int i=1;i<=n;i++){
        visit[i]=false;
    }
    queue <int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(visit[curr] || indeg[curr]!=0) continue;
        visit[curr]=true;
        for(int i=0;i<graph[curr].size();i++){
            int des = graph[curr][i].first;
            if(dis[des]<dis[curr]+graph[curr][i].second) {
                dis[des] = dis[curr]+graph[curr][i].second;
            }
            q.push(des);
            indeg[des]--;
        }
    }
}

void find_count(int start, int end, vector <vector <pair<int ,int>>> &graph, int *org_dis, int *rev_dis){
    bool visit[100001];
    for(int i=1;i<=n;i++){
        visit[i]=false;
    }
    queue <int> q;
    q.push(start);
    visit[start]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0;i<graph[curr].size();i++){
            int des = graph[curr][i].first;
            int weight = graph[curr][i].second;
            if(weight+org_dis[curr]==org_dis[des] && org_dis[des]+rev_dis[des]==res_dis) {
                if(!visit[des]){
                    visit[des]=true;
                    q.push(des);
                }
                ans++;
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);\
    cin>>n>>m;
    int start, end;
    vector <vector <pair<int ,int>>> org_graph(n+1);
    vector <vector <pair<int ,int>>> rev_graph(n+1);
    int a,b,c;
    int org_dis[100001];
    int rev_dis[100001];
    int org_indeg[100001];
    int rev_indeg[100001];
    for(int i=1;i<=n;i++){
        org_indeg[i]=org_dis[i]=0;
        rev_indeg[i]=rev_dis[i]=0;

    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        org_graph[a].push_back({b,c});
        rev_graph[b].push_back({a,c});
        org_indeg[b]++;
        rev_indeg[a]++;
    }
    cin>>start>>end;
    bfs(org_graph, start,org_dis, org_indeg);
    bfs(rev_graph, end,rev_dis, rev_indeg);
    res_dis = org_dis[end];
    find_count(start, end, org_graph, org_dis, rev_dis);
    cout<<res_dis<<"\n"<<ans;

    return 0;
}