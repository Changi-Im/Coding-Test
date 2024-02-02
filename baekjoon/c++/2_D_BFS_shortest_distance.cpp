// The problem is from https://www.acmicpc.net/problem/2178

#include <iostream>
#include <vector>
#include <queue>
#define MAX 150

using namespace std;

int map[MAX][MAX], visited[MAX][MAX];
int N, M;
/* left, up, right, down */
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

int bfs(int r, int c){
    int nc, nr;

    q.push(pair<int, int>(r, c));
    visited[r][c] = 1;

    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            nr = q.front().first + dr[i];
            nc = q.front().second + dc[i];

            if((map[nr][nc] == 1) && (visited[nr][nc] == 0)){
                q.push(pair<int, int>(nr, nc));
                visited[nr][nc] = 1 + visited[q.front().first][q.front().second];
            }
        }

        q.pop();
    }

    return visited[N][M];
}

int main(){
    scanf("%d %d", &N, &M);

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++)
            scanf("%1d", &map[r][c]);
    }

    printf("%d", bfs(1,1));
}
