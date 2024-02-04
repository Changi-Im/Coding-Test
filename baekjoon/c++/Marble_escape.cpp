// The problem is from https://www.acmicpc.net/problem/13460
#include <iostream>
#define MAX 15

/* left top right bottom*/
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

char MAP[MAX][MAX];
int MIN = 0x0FFFF400;
int N, M;

typedef struct st{
    int r;
    int c;
} MARBLE;

MARBLE RED;
MARBLE BLUE;

void input(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            scanf(" %c", &MAP[r][c]);

            if(MAP[r][c] == 'R'){
                RED.r = r;
                RED.c = c;
            }
            if(MAP[r][c] == 'B'){
                BLUE.r = r;
                BLUE.c = c;
            }
        }
    }
}

void DFS(int L, int Rr, int Rc, int Br, int Bc){
    if(L > 10)
        return;

    for(int i = 0; i < 4; i++){
        int Rnr = Rr, Rnc = Rc;
        int Bnr = Br, Bnc = Bc;
        int flag = 0;

        /* Start tilting until both marbles can't move */
        while(1){
            /* When both marbles are able to move */
            if(MAP[Rnr + dr[i]][Rnc + dc[i]] != '#'
               && MAP[Bnr + dr[i]][Bnc + dc[i]] != '#')
            {
                /* Update new coordinates */
                Rnr += dr[i]; Rnc += dc[i];
                Bnr += dr[i]; Bnc += dc[i];

                if(MAP[Rnr][Rnc] == 'O')
                {
                    int FLAG = 0;
                    /* Keep moving the Blue marble until stopped */
                    while(MAP[Bnr][Bnc] != '#')
                    {
                        if(MAP[Bnr][Bnc] == 'O')
                        {    
                            FLAG = 1;
                            break;
                        }
                        Bnr += dr[i]; Bnc += dc[i];
                    }

                    if(FLAG)
                        break;
                    else
                    {
                        if(MIN > L) 
                            MIN = L;
                        return;
                    }
                }
                
                if(MAP[Bnr][Bnc] == 'O')
                {
                    flag = 1;
                    break;
                }
            }
            
            /* When Blue marble is only able to move */
            else if(MAP[Rnr + dr[i]][Rnc + dc[i]] == '#'
                    && (MAP[Bnr + dr[i]][Bnc + dc[i]] != '#' && !(Bnr + dr[i] == Rnr && Bnc + dc[i] == Rnc)))
            {
                /* Update new coordinates */
                Bnr += dr[i]; Bnc += dc[i];

                if(MAP[Bnr][Bnc] == 'O')
                {
                    flag = 1;
                    break;
                }
            }
            
            /* When Red marble is only able to move */
            else if(MAP[Bnr + dr[i]][Bnc + dc[i]] == '#'
                    && (MAP[Rnr + dr[i]][Rnc + dc[i]] != '#' && !(Rnr + dr[i] == Bnr && Rnc + dc[i] == Bnc)))
            {
                /* Update new coordinates */
                Rnr += dr[i]; Rnc += dc[i];

                if(MAP[Rnr][Rnc] == 'O')
                {
                    if(MIN > L)
                        MIN = L;
                    return;
                }

            }
            
            /* When both marbles are not able to move */
            else
                break;
        }

        if(!flag)
            DFS(L+1, Rnr, Rnc, Bnr, Bnc);
    }
}

int main(){
    scanf("%d %d", &N, &M);

    input();
    DFS(1, RED.r, RED.c, BLUE.r, BLUE.c);

    if(MIN == 0x0FFFF400)
        printf("-1");
    else
        printf("%d", MIN);
}