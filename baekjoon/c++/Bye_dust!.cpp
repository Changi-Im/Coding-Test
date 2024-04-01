// The problem is from https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 60

using namespace std;

int R, C, T;
int A[MAX][MAX];

typedef struct st{
    int r, c;
} AIR;

AIR air[2];

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1 ,0};

void input(){
    int idx = 0;
    cin >> R >> C >> T;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++){
            cin >> A[r][c];
            if(A[r][c] == -1){
                air[idx].r = r;
                air[idx++].c = c;
            }
        }
}

int cntDust(){
    int cnt = 0;

    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++){
            if(A[r][c] == -1)
                continue;
            cnt += A[r][c];
        }
    
    return cnt;
}

void solution(){
    int t = 0;
    while(t < T){
        /* COPY MAP */
        int COPY[MAX][MAX];
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                COPY[r][c] = A[r][c];

        /* Dust spread */
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++){
                if(A[r][c] == 0 || A[r][c] == -1)
                    continue;
                
                vector <pair<int, int>> tmp;

                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr == -1 || nc == -1 || nr == R || nc == C || A[nr][nc] == -1)
                        continue;

                    tmp.push_back(pair<int, int> (nr, nc));    
                }

                for(int i = 0; i < tmp.size(); i++){
                    int amount = A[r][c] / 5;
                    COPY[tmp[i].first][tmp[i].second] += amount;
                }
                
                COPY[r][c] = COPY[r][c] - (A[r][c] / 5) * tmp.size();
            }
        
        /* Run air purifier */
        vector <int> tmp;
        int idx = 0;

        /* Up part circulation direction */
        for(int r = air[0].r - 1; r >= 0; r--)
            tmp.push_back(COPY[r][0]);

        for(int c = 1; c < C; c++)
            tmp.push_back(COPY[0][c]);

        for(int r = 1; r <= air[0].r; r++)
            tmp.push_back(COPY[r][C-1]);

        for(int c = C - 2; c >= 1; c--)
            tmp.push_back(COPY[air[0].r][c]);

        tmp.erase(tmp.begin());
        tmp.push_back(0);

        for(int r = air[0].r - 1; r >= 0; r--)
            COPY[r][0] = tmp[idx++];

        for(int c = 1; c < C; c++)
            COPY[0][c] = tmp[idx++];

        for(int r = 1; r <= air[0].r; r++)
            COPY[r][C-1] = tmp[idx++];

        for(int c = C - 2; c >= 1; c--)
            COPY[air[0].r][c] = tmp[idx++];
        
        tmp.clear();
        idx = 0;

        /* Down part circulation direction */
        for(int r = air[1].r + 1; r < R; r++)
            tmp.push_back(COPY[r][0]);

        for(int c = 1; c < C; c++)
            tmp.push_back(COPY[R-1][c]);

        for(int r = R - 2; r >= air[1].r; r--)
            tmp.push_back(COPY[r][C-1]);

        for(int c = C - 2; c >= 1; c--)
            tmp.push_back(COPY[air[1].r][c]);

        tmp.erase(tmp.begin());
        tmp.push_back(0);

        for(int r = air[1].r + 1; r < R; r++)
            COPY[r][0] = tmp[idx++];

        for(int c = 1; c < C; c++)
            COPY[R-1][c] = tmp[idx++];

        for(int r = R - 2; r >= air[1].r; r--)
            COPY[r][C-1] = tmp[idx++];

        for(int c = C - 2; c >= 1; c--)
            COPY[air[1].r][c] = tmp[idx++];

        /* Update A map */
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                A[r][c] = COPY[r][c];
        t++;
    }
}

int main(){
    input();
    solution();
    cout << cntDust();
}