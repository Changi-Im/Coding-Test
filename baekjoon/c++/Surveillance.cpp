// The problem is from https://www.acmicpc.net/problem/15683
#include <stdio.h>
#define MAX 10

int N, M;
char MAP[MAX][MAX];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int cidx = 0;
int ANSWER = 0x41234123;

typedef struct st{
    char num;
    int r, c;
} CAMERA;

CAMERA camera[MAX];

void input(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N + 2; i++)
        for(int j = 0; j < M + 2; j++)
            MAP[i][j] = '6';

    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < M + 1; j++){
            scanf(" %c", &MAP[i][j]);
            if(MAP[i][j] != '6' && MAP[i][j] != '0'){
                camera[cidx].num = MAP[i][j];
                camera[cidx].r = i;
                camera[cidx++].c = j;
            }
        }
    }
}

void memcopy(char src[][MAX], char dst[][MAX]){
    for(int i = 0; i < N + 2; i++)
        for(int j = 0; j < M + 2; j++)
            dst[i][j] = src[i][j];
}

void cctvOn(char map[][MAX], CAMERA cam, int dir){
    switch(cam.num)
    {
    case '1':
    {
        int cr = cam.r;
        int cc = cam.c;
        while(1){
            if(map[cr + dr[dir]][cc + dc[dir]] != '6'){
                map[cr + dr[dir]][cc + dc[dir]] = '#';
                cr += dr[dir];
                cc += dc[dir];
            } 
            else
                break;
        }
        break;
    }
    case '2':
    {
        for(int i = 0; i < 2; i++){
            int cr = cam.r;
            int cc = cam.c;
            while(1){
                if(map[cr + dr[dir]][cc + dc[dir]] != '6'){
                    map[cr + dr[dir]][cc + dc[dir]] = '#';
                    cr += dr[dir];
                    cc += dc[dir];
                } 
                else
                    break;
            }
            dir += 2;
            if(dir > 3)
                dir -= 4;
            else if(dir < 0)
                dir += 4;
        }
        break;
    }
    case '3':
    {
        for(int i = 0; i < 2; i++){
            int cr = cam.r;
            int cc = cam.c;
            while(1){
                if(map[cr + dr[dir]][cc + dc[dir]] != '6'){
                    map[cr + dr[dir]][cc + dc[dir]] = '#';
                    cr += dr[dir];
                    cc += dc[dir];
                } 
                else
                    break;
            }
            dir += 1;
            if(dir > 3)
                dir -= 4;
            else if(dir < 0)
                dir += 4;
        }
        break;
    }    
    case '4':
    {
        for(int i = 0; i < 3; i++){
            int cr = cam.r;
            int cc = cam.c;
            while(1){
                if(map[cr + dr[dir]][cc + dc[dir]] != '6'){
                    map[cr + dr[dir]][cc + dc[dir]] = '#';
                    cr += dr[dir];
                    cc += dc[dir];
                } 
                else
                    break;
            }
            dir += 1;
            if(dir > 3)
                dir -= 4;
            else if(dir < 0)
                dir += 4;
        }
        break;
    }    
    }
}

void findAnswer(char map[][MAX]){
    int cnt = 0;
    
    for(int r = 1; r < N + 1; r++){
        for(int c = 1; c < M + 1; c++){
            if(map[r][c] == '0')
                cnt++;
        }
    }

    ANSWER = ANSWER > cnt ? cnt : ANSWER;
}

void DFS(int L, char map[][MAX]){
    if(L == cidx){
        findAnswer(map);
        return;
    }

    for(int dir = 0; dir < 4; dir++){
        char mapCopy[MAX][MAX] = { '0' };
        memcopy(map, mapCopy);

        if(camera[L].num == '5'){
            for(int i = 0; i < 4; i++){
                int cr = camera[L].r;
                int cc = camera[L].c;

                while(1){
                        if(mapCopy[cr + dr[i]][cc + dc[i]] != '6'){
                            mapCopy[cr + dr[i]][cc + dc[i]] = '#';
                            cr += dr[i];
                            cc += dc[i];
                        } 
                        else
                            break;
                }
            }
        }
        cctvOn(mapCopy, camera[L], dir);
        DFS(L+1, mapCopy);

    }
}
int main(){
    input();
    DFS(0, MAP);
    printf("%d", ANSWER);
}
