// The problem is from https://www.acmicpc.net/problem/15686
#include <stdio.h>
#define MAX 55

int MAP[MAX][MAX];
int N, M;
int MIN = 0x01231234;
int select[MAX*2];
int hidx;
int cidx;
typedef struct st{
    int r;
    int c;
} INFO;

INFO house[MAX*2];
INFO chicken[MAX*2];

int calDist(int r1, int r2, int c1, int c2){
    int abs1 = r1 > r2 ? r1 - r2 : r2 - r1;
    int abs2 = c1 > c2 ? c1 - c2 : c2 - c1;

    return abs1 + abs2;
}

void input(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%d", &MAP[i][j]);
            if(MAP[i][j] == 1){
                house[hidx].r = i;
                house[hidx++].c = j;
            }
            else if(MAP[i][j] == 2){
                chicken[cidx].r = i;
                chicken[cidx++].c = j;
            }
        }
}

void DFS(int L, int start){
    if(L == M){
        /* calculate total distance */
        int sum = 0;

        for(int i = 0; i < hidx; i++){
            int min = 0x01231234;
            for(int j = 0; j < M; j++){
                int res = calDist(house[i].r, chicken[select[j]].r, house[i].c, chicken[select[j]].c);
                if(min > res)
                    min = res;
            }
            sum += min;
        }

        if(MIN > sum)
            MIN = sum;
        return;
    }
    /* calculate each distance */
    for(int i = start; i < cidx; i++){
        select[L] = i;
        DFS(L+1, i+1);
    }
}

int main(){
    input();
    DFS(0, 0);
    printf("%d", MIN);
}