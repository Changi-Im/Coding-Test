// The problem is from https://www.acmicpc.net/problem/16234
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 55

using namespace std;

int N;
int ANSWER;
int flag;
int MAP[MAX][MAX];
int COPY[MAX][MAX];
int TER[MAX][MAX];
int visit[MAX][MAX];
int L, R;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
queue <pair<int, int>> q;

void input(){
    int cnt = 1;
    cin >> N >> L >> R;
    for(int r = 1; r < N + 1; r++)
        for(int c = 1; c < N + 1; c++){
            cin >> MAP[r][c];
            COPY[r][c] = MAP[r][c];
            TER[r][c] = cnt++;
        }


}

int abs(int x){
    return x < 0 ? (-1)*x : x;
}

void BFS(){
    flag = 0; // Initialize flag

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < N + 1; c++){
            if(visit[r][c] == 1)
                continue;

            int ter = TER[r][c];

            int sum = MAP[r][c];
            vector <pair<int, int>> loc;

            visit[r][c] = 1;
            q.push(pair<int, int>(r, c));
            loc.push_back(pair<int, int>(r, c));

            while(!q.empty()){
                int mr = q.front().first;
                int mc = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = mr + dr[i];
                    int nc = mc + dc[i];

                    /* Out of range */
                    if(nr == 0 || nc == 0 || nr == N + 1 || nc == N + 1 || visit[nr][nc] == 1)
                        continue;
                    
                    /* Open borderline */
                    if(abs(MAP[mr][mc] - MAP[nr][nc]) >= L && abs(MAP[mr][mc] - MAP[nr][nc]) <= R){
                        TER[nr][nc] = ter;
                        visit[nr][nc] = 1;
                        q.push(pair<int, int>(nr, nc));
                        loc.push_back(pair<int, int>(nr, nc));
                        sum += MAP[nr][nc];
                        flag = 1;
                    }
                }
            }
            /* Population move starts */
            for(int i = 0; i < loc.size(); i++)
                COPY[loc[i].first][loc[i].second] = sum / loc.size();  
        }
    }

    if(flag == 1)
        ANSWER++;
}

void output(){
    cout << "\n";
    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < N + 1; c++){
            cout << MAP[r][c] << " ";
        }
        cout << "\n";
    }
}
int main(){
    input();
    while(1){
        BFS();
        
        /* Update MAP, TER and initialize visit */
        int cnt = 1;
        for(int r = 1; r < N + 1; r++)
            for(int c = 1; c < N + 1; c++){
                MAP[r][c] = COPY[r][c];
                TER[r][c] = cnt++;
                visit[r][c] = 0;
            }

        // output();
        if(flag == 0)
            break;
    }
    cout << ANSWER;

}
