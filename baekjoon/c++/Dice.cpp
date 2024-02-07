// The problem is from https://www.acmicpc.net/problem/14499

#include <stdio.h>
#define MAX 25
#define LENGTH 1500

using namespace std;

int N, M, K;
int x, y;
int order[LENGTH];
int MAP[MAX][MAX];
/* East West North South */
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

typedef struct st{
                 int back;
    int west;    int top;    int east;
                 int front;
                 int bottom;
} DICE;

DICE dice;

void input(){
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    for(int r = 0; r < N + 2; r++)
        for(int c = 0; c < M + 2; c++)
            MAP[r][c] = 10;
    
    for(int r = 1; r < N + 1; r++)
        for(int c = 1; c < M + 1; c++)
            scanf("%d", &MAP[r][c]);

    for(int i = 0; i < K; i++)
        scanf("%d", &order[i]);

    x++, y++;
}

void moveEast(){
    int tmpBottom = dice.bottom;
    int tmpTop = dice.top;
    int tmpEast = dice.east;
    int tmpWest = dice.west;

    dice.top = tmpWest;
    dice.bottom = tmpEast;
    dice.east = tmpTop;
    dice.west = tmpBottom;
}

void moveWest(){
    int tmpBottom = dice.bottom;
    int tmpTop = dice.top;
    int tmpEast = dice.east;
    int tmpWest = dice.west;

    dice.top = tmpEast;
    dice.bottom = tmpWest;
    dice.east = tmpBottom;
    dice.west = tmpTop;
}

void moveNorth(){
    int tmpBottom = dice.bottom;
    int tmpTop = dice.top;
    int tmpFront = dice.front;
    int tmpBack = dice.back;

    dice.top = tmpFront;
    dice.bottom = tmpBack;
    dice.front = tmpBottom;
    dice.back = tmpTop;
}

void moveSouth(){
    int tmpBottom = dice.bottom;
    int tmpTop = dice.top;
    int tmpFront = dice.front;
    int tmpBack = dice.back;

    dice.top = tmpBack;
    dice.bottom = tmpFront;
    dice.front = tmpTop;
    dice.back = tmpBottom;
}

void copyNumber(int r, int c){
    if(MAP[r][c] == 0)
        MAP[r][c] = dice.bottom;
    else{
        dice.bottom = MAP[r][c];
        MAP[r][c] = 0;
    }
}

void algorithm(){
    for(int i = 0; i < K; i++){
        int nr = x + dr[order[i]-1];
        int nc = y + dc[order[i]-1];

        if(MAP[nr][nc] == 10)
            continue;
        
        if(order[i] == 1)
            moveEast();
        else if(order[i] == 2)
            moveWest();
        else if(order[i] == 3)
            moveNorth();
        else   
            moveSouth();

        x = nr, y = nc;

        copyNumber(nr, nc);
        printf("%d ", dice.top);
    }
}

int main(){
    input();
    algorithm();
}