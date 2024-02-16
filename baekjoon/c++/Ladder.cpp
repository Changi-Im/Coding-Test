// The problem is from https://www.acmicpc.net/problem/15684
#include <stdio.h>
#define MAX 40

int N, M, H;
int ANSWER = 4;
int flag = 0;
int MAP[2*MAX][2*MAX];
int visit[2*MAX][2*MAX];
typedef struct st{
    int a;
    int b;
} LADDER;

LADDER ladder[MAX];

void input(){
    scanf("%d %d %d", &N, &M, &H);

    for(int r = 0; r < 2*H + 2; r++){
        for(int c = 0; c < 2*N + 1; c++){
            if(c % 2 != 0 && c != 2*N + 1)
                MAP[r][c] = 1;
            else if(c % 2 == 0 && c != 0 && c != 2*N)
                MAP[r][c] = 0;
            else
                MAP[r][c] = 2;
        }
    }

    for(int i = 1; i < M + 1; i++){
        scanf("%d %d", &ladder[i].a, &ladder[i].b);
        MAP[2*ladder[i].a-1][2*ladder[i].b] = 1;
    }
}

void output(){
    for(int r = 0; r < 2*H + 1; r++){
        for(int c = 0; c < 2*N + 1; c++){
            printf("%d ", MAP[r][c]);
        }
        printf("\n");
    }
}

void findLadder(){
    int num = 1;
    while(num < 2*N){
        int c = num;
        for(int r = 0; r < 2*H + 2; r++){
            if(MAP[r][c+1] == 1)
                c += 2;
            else if(MAP[r][c-1] == 1)
                c -= 2;
        }
        if(c != num){
            flag = 1;
            return;
        }
        num += 2;
    }
}

void DFS(int L, int max, int sc){
    if(L > max){
        // output();
        // printf("\n");
        findLadder();
        if(ANSWER > max && flag == 0){
            ANSWER = max;
            return;    
        }
        flag = 0; 
        return;
    }

    for(int r = 1; r < 2*H + 1; r += 2){
        for(int c = sc; c < 2*N; c += 2){
            if(MAP[r][c] == 1 || MAP[r][c+2] == 1 || MAP[r][c-2] == 1)
                continue;

            if(MAP[r][c] == 0){ 
                MAP[r][c] = 1;   
                DFS(L+1, max, c);
                MAP[r][c] = 0;
                if(ANSWER != 4)
                    return;
            }     
        }
    }
}

int main(){
    input();
    findLadder();
    if(flag == 0){
        printf("0");
        return 0;
    }
    flag = 0;
    for(int i = 1; i < 4; i++){
        DFS(1,i,2);
        if(ANSWER != 4){
            printf("%d", ANSWER);
            return 0;
        }
    }
    printf("-1");
    
}