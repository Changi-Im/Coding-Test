// The problem is from https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
#define MAX 150

using namespace std;

int map[MAX][MAX][MAX];
int N, M, H;

/* left up right down front back*/
int dr[6] = {0, -1, 0, 1, 0, 0};
int dc[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

typedef struct st{
    int r;
    int c;
    int z;
} QUEUE;

QUEUE queue[MAX*MAX*MAX];
int wp = 0, rp = 0;

void input(){
    for(int i = 0; i < H + 2; i++){
        for(int j = 0; j < N + 2; j++){
            for(int k = 0; k < M + 2; k++)
                map[i][j][k] = -1;
        }
    }

    for(int i = 1; i < H + 1; i++){
        for(int j = 1; j < N + 1; j++){
            for(int k = 1; k < M + 1; k++)
                cin >> map[i][j][k];
        }
    }
}

void bfs(){
    for(int i = 1; i < H + 1; i++){
        for(int j = 1; j < N + 1; j++){
            for(int k = 1; k < M + 1; k++){
                if(map[i][j][k] == 1){
                    queue[wp].z = i;
                    queue[wp].r = j;
                    queue[wp++].c = k;
                }
            }
        }
    }

    while(wp > rp){
        QUEUE out = queue[rp++];

        for(int i = 0; i < 6; i++){
            int nr = out.r + dr[i];
            int nc = out.c + dc[i];
            int nz = out.z + dz[i];

            if(map[nz][nr][nc] == 0){
                queue[wp].z = nz;
                queue[wp].r = nr;
                queue[wp++].c = nc;

                map[nz][nr][nc] = map[out.z][out.r][out.c] + 1;
            }
        }
    }

}


int findAns(){
    int max = 0;

    for(int i = 1; i < H + 1; i++){
        for(int j = 1; j < N + 1; j++){
            for(int k = 1; k < M + 1; k++){
                if(map[i][j][k] == 0)
                    return -1;
                if(max < map[i][j][k])
                    max = map[i][j][k];
            }
        }
    }

    return max - 1;
}

int main(){
    cin >> M >> N >> H;

    input();
    bfs();
    cout << findAns();
}
