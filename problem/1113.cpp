#include<iostream>
#include<queue>
using namespace std;

const int MAX = 52;
int arr[MAX][MAX];

int n, m;

int maximum=0;

int ans = 0;

struct coor {
    int y;
    int x;
};
queue <coor> q;

bool inside(int y, int x) {
    return y >= 0 && y <= n + 1 && x >= 0 && x <= m + 1;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int h) {
    arr[0][0] = h;
    q.push({ 0,0 });
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        int ny, nx;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (inside(ny, nx) && arr[ny][nx] < h) {
                arr[ny][nx] = h;
                q.push({ ny,nx });
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
            if (arr[i][j] > maximum) maximum = arr[i][j];
        }
    }
    for (int o = 1; o <= maximum; o++) {
        bfs(o);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] < o) {
                    ans += 1;
                    arr[i][j] += 1;
                }
            }
        }
    }
    cout << ans << endl;
}