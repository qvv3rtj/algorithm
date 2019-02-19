#include<iostream>
#include<queue>

using namespace std;

#define MAX_N 100
#define MAX_M 100

typedef pair<int, int> P;

char maze[MAX_N][MAX_M];
int N, M;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_M];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            d[i][j] = -1;
    
    q.push(P(sx, sy));
    d[sx][sy] = 0;

    while(!q.empty()) {
        P p = q.front();
        q.pop();
        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == -1) {
                q.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main() {
    cin >> N >> M;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++) {
            cin >> maze[x][y];
            if (maze[x][y] == 'S') sx = x, sy = y;
            if (maze[x][y] == 'G') gx = x, gy = y;
        }
    cout << bfs() << endl;
}