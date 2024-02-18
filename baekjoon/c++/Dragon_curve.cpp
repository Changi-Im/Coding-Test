// The problem is from https://www.acmicpc.net/problem/15685
#include <stdio.h>
#define MAX 30

int MAP[101][101];
int N, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int ANSWER = 0;
typedef struct st{
    int x;
    int y;
    int d;
    int g;
} DRAGON;

DRAGON dragon[MAX];

void output(){
    for(int i = 30; i < 70; i++){
        for(int j = 30; j < 70; j++)
            printf("%d ", MAP[i][j]);
        printf("\n");
    }
}

void makeCurve(DRAGON tmp){
    int x = tmp.x;
    int y = tmp.y;
    int d = tmp.d;
    int g = tmp.g;
    int stack[MAX*MAX*MAX] = { 0 };
    int wp = 0, rp = 0;
    
    MAP[y][x] = 1;
    y += dy[d];
    x += dx[d];
    MAP[y][x] = 1;
    stack[wp++] = d;

    for(int i = 1; i <= g; i++){
        while(rp != -1){
            int nd = stack[rp--] + 1;
            if(nd > 3)
                nd -= 4;
            else if(nd < 0)
                nd += 4;

            y += dy[nd];
            x += dx[nd];
            MAP[y][x] = 1;
            stack[wp++] = nd;
         }
         rp = wp-1;
    }
}

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &dragon[i].x, &dragon[i].y, &dragon[i].d, &dragon[i].g);
        makeCurve(dragon[i]);
    }
}

void cntSqure(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(MAP[i][j] == 1 && MAP[i][j+1] == 1 && MAP[i+1][j] == 1 && MAP[i+1][j+1] == 1)
                ANSWER++;
        }
    }
}
int main(){
    input();
    //output();
    cntSqure();
    printf("%d", ANSWER);
}