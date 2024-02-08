// The problem is from https://bloodstrawberry.tistory.com/26

#include <stdio.h>
#define MAX 20

using namespace std;

int N, M;
int MAP[MAX][MAX];

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int ANSWER = 0;

typedef struct st{
    int r;
    int c;
} QUEUE;

QUEUE queue[MAX*MAX];

void memCopy(int src[][MAX], int dst[][MAX]){
    for(int r = 0; r < N + 2; r++)
        for(int c = 0; c < M + 2; c++)
            dst[r][c] = src[r][c];
}

void input(){
    scanf("%d %d", &N, &M);

    for(int r = 0; r < N + 2; r++)
        for(int c = 0; c < M + 2; c++)
            MAP[r][c] = 3;

    for(int r = 1; r < N + 1; r++)
        for(int c = 1; c < M + 1; c++)
            scanf("%d", &MAP[r][c]);
}

void output(int map[][MAX]){
    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++)
            printf("%d ", map[r][c]);\
        printf("\n");
    }
}

void BFS(int map[][MAX]){
    int rp = 0, wp = 0;

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++){
            if(map[r][c] == 2){
                queue[wp].r = r;
                queue[wp++].c = c;
            }
        }
    }

    while(wp > rp){
        for(int i = 0; i < 4; i++){
            int nr = queue[rp].r + dr[i];
            int nc = queue[rp].c + dc[i];

            if(map[nr][nc] == 0){
                map[nr][nc] = 2;

                queue[wp].r = nr;
                queue[wp++].c = nc;
            }
        }
        rp++;
    }
}

void findAnswer(int map[][MAX]){
    int sum = 0;

    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++){
            if(map[r][c] == 0)
                sum += 1;        
        }
    }

    if(sum > ANSWER)
        ANSWER = sum;
}

void DFS(int L, int map[][MAX]){
    if(L > 2){
        BFS(map);
        // printf("\n");
        // output(map);
        findAnswer(map);
        
        return;
    }
    
    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++){
            int copy[MAX][MAX];

            memCopy(map, copy);
            if(copy[r][c] == 0){
                copy[r][c] = 1;
                // printf("\n");
                // output(copy);
                DFS(L+1, copy); 
            }
            else   
                continue;
        }
    }
}

int main(){
    input();
    DFS(0, MAP);

    printf("%d", ANSWER);
}