// The problem is from https://www.acmicpc.net/problem/14503

#include <stdio.h>
#define MAX 55

using namespace std;

typedef struct st{
    int r;
    int c;
    int d;
} QUEUE;

int N, M;
int MAP[MAX][MAX];
int wp, rp;
int ANSWER = 0;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

QUEUE queue[MAX*MAX];

void input(){
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &queue[wp].r, &queue[wp].c, &queue[wp].d);
    wp++;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            scanf("%d", &MAP[r][c]);
}

void output(){
    printf("\n");
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++)
            printf("%d ", MAP[r][c]);
        printf("\n");
    }
}

void BFS(){
    while(rp < wp){
        QUEUE out = queue[rp++];
        int flag = 0;

        if(MAP[out.r][out.c] == 0){
            MAP[out.r][out.c] = 2;
            ANSWER++;
        }

        //output();

        for(int i = 0; i < 4; i++){
            int nr = out.r + dr[i];
            int nc = out.c + dc[i];

            if(nr < 0 || nc < 0 || nr > N-1 || nc > M-1)
                continue;
            
            if(MAP[nr][nc] == 0)
                flag = 1;
        }

        if(flag == 1){
            int nd = out.d - 1;

            if(nd < 0)
                nd += 4;
            else if(nd > 3)
                nd -= 4;

            if(MAP[out.r + dr[nd]][out.c + dc[nd]] == 0){
                queue[wp].r = out.r + dr[nd];
                queue[wp].c = out.c + dc[nd];
                queue[wp++].d = nd;
            }
            else{
                queue[wp].r = out.r;
                queue[wp].c = out.c;
                queue[wp++].d = nd;
            }
        }

        else{
            int nd = out.d - 2;
            if(nd < 0)
                    nd += 4;
            else if(nd > 3)
                nd -= 4;

            int nr = out.r + dr[nd];
            int nc = out.c + dc[nd];

            if(MAP[nr][nc] != 1){
                queue[wp].r = nr;
                queue[wp].c = nc;
                queue[wp++].d = out.d;
            }
            else
                return;
        }
    }
}

int main(){
    input();
    BFS();
    printf("%d", ANSWER);
}