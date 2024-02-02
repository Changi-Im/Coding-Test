// The problem is from https://www.acmicpc.net/problem/2667

#include <iostream>
#include <queue>
#include <utility>
#define MAX 30

using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int N;
/* left, up, right, down*/
int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

queue<pair<int, int>> q;

void input(){
    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < N + 1; c++){
            scanf("%1d", &map[r][c]);
        }
    }
}

int bfs(int r, int c){
    int cnt = 1;
    pair<int, int> out;

    q.push(pair<int, int>(r, c));
    visited[r][c] = 1;

    while(!q.empty()){
        out = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = out.first + dr[i];
            int nc = out.second + dc[i];

            if(visited[nr][nc] == 0 && map[nr][nc] == 1){
                q.push(pair<int, int>(nr, nc));
                visited[nr][nc] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}

void sort(int arr[], int cnt){
    int tmp;

    for(int i = 0; i < cnt - 1; i++){
        for(int j = 0; j < cnt - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
int main(){
    int cnt1 = 0, cnt2[MAX*MAX] = {0,}; 
    scanf("%d", &N);

    input();

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < N + 1; c++){
            if((map[r][c] == 1) && (visited[r][c] == 0))
                cnt2[cnt1++] = bfs(r, c);
        }
    }

    sort(cnt2, cnt1);
    
    printf("%d\n", cnt1);
    
    for(int i = 0; i < cnt1; i++)
        printf("%d\n", cnt2[i]);
}