// The problem is from https://www.acmicpc.net/problem/3190
#include <iostream>
#define MAX 150

using namespace std;

int N, K, L;
char MAP[MAX][MAX];

/* right up left down */
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int RP, WP;
int time;

typedef struct st1{
    int r;
    int c;
} APPLE;

typedef struct st2{
    int t;
    char d;
} DIRECTION;

typedef struct st3{
    int r;
    int c;
} SNAKE;

APPLE apple[MAX*MAX];
DIRECTION direction[MAX*MAX];
SNAKE snake[MAX*MAX];

void sort(){
    int tmpr, tmpc;

    for(int i = 0; i < K - 1; i++){
        for(int j = i; j < K - 1 - i; j++){
            if(apple[j].r > apple[j+1].r){
                tmpr = apple[j].r; tmpc = apple[j].c;
                apple[j].r = apple[j+1].r; apple[j].c = apple[j+1].c;
                apple[j+1].r = tmpr; apple[j+1].c = tmpc;
            }
        }
    }
}

void input(){
    cin >> N;   // Map size
    cin >> K;   // Number of apples
    /* Enter location of the apples */
    for(int i = 0; i < K; i++)
        cin >> apple[i].r >> apple[i].c;
    
    cin >> L;   // Number of direction changes
    /* Enter direction change information */
    for(int i = 0; i < L; i++)
        cin >> direction[i].t >> direction[i].d;

    /* Create a map */
    for(int r = 0; r < N + 2; r++)
        for(int c = 0; c < N + 2; c++)
            MAP[r][c] = '#';

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < N + 1; c++){
            MAP[r][c] = '0';
        }
    }

    for(int i = 0; i < K; i++)
        MAP[apple[i].r][apple[i].c] = 'A';

    snake[WP].r = 1; snake[WP++].c = 1;
    MAP[1][1] = '1';
}

void output(){
    for(int r = 0; r < N + 2; r++){
        for(int c = 0; c < N + 2; c++)
            cout << MAP[r][c] << " ";
        cout << "\n";    
    }
}

void BFS(){
    int idx = 0;
    int cnt = 0;

    while(1){
        int nr = snake[WP-1].r, nc = snake[WP-1].c;

        if(direction[cnt].t == time){
            if(direction[cnt].d == 'D'){
                idx++; cnt++;
                if(idx > 3)
                    idx -= 4;
            }

            else if(direction[cnt].d == 'L'){
                idx--; cnt++;
                if(idx < 0)
                    idx += 4;
            }
        }
            
        if(MAP[nr + dr[idx]][nc + dc[idx]] == '0'){
            snake[WP].r = nr + dr[idx]; snake[WP++].c = nc + dc[idx];
            MAP[snake[RP].r][snake[RP].c] = '0';
            RP++;
        }
        else if(MAP[nr + dr[idx]][nc + dc[idx]] == '#' || MAP[nr + dr[idx]][nc + dc[idx]] == '1')
            return;
        else if(MAP[nr + dr[idx]][nc + dc[idx]] == 'A'){
            snake[WP].r = nr + dr[idx]; snake[WP++].c = nc + dc[idx];
            MAP[snake[WP-1].r][snake[WP-1].c] = '0';
        }

        time++;

        /* Update map */
        for(int p = RP; p < WP; p++){
            MAP[snake[p].r][snake[p].c] = '1';
        }

        // cout << "\n";
        // output();
    }
}

int main(){
    input();
    // output();
    BFS();

    cout << time + 1;
}