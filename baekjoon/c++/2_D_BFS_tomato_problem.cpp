// The problem is from https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1500

using namespace std;

/* left up right down*/
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int N, M;
int map[MAX][MAX];
queue<pair<int, int>> q;

void input(){
    
    for(int r = 0; r < N + 2; r++){
        for(int c = 0; c < M + 2; c++){
            map[r][c] = -1;
        }
    }

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++){
            cin >> map[r][c];
        }
    }
}

void bfs(){
    int nr, nc;

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++){
            if(map[r][c] == 1){
                q.push(pair<int, int>(r, c));
            }
        }
    }

    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            nr = q.front().first + dr[i];
            nc = q.front().second + dc[i];

            if(map[nr][nc] == 0){
                q.push(pair<int, int>(nr, nc));
                map[nr][nc] = 1 + map[q.front().first][q.front().second];
            }
        }

        q.pop();
    }
}

int findAns(){
    int max = 0;

    for(int r = 0; r < N + 1; r++){
        for(int c = 0; c < M + 1; c++){
            if(map[r][c] == 0)
                return -1;
            if(max < map[r][c])
                max = map[r][c];
        }
    }

    return max - 1;
}

int main(){
    int flag = 1, out = 0, max = 0;

    cin >> M >> N;

    input();
    bfs();

    cout << findAns();
}

