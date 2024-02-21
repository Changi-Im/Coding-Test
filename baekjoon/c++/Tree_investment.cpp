// The problem is from https://www.acmicpc.net/problem/16235
#include <stdio.h>
#include <vector>
#include <algorithm>
#define SPRING 0
#define SUMMER 1
#define FALL 2
#define WINTER 3
#define MAX 15

using namespace std;

vector <vector <int>> A;    // Initial energy map
vector <vector <int>> E;    // Energy map
vector <vector <int>> DEAD; // Dead energy map
vector <vector <int>> MAP;  // Tree map

int N, M, K;
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector <vector <vector <int>>> TREE;    // Tree container

void input(){
    scanf("%d %d %d", &N, &M, &K);
    
    E.resize(N, vector <int>(N, 5));    // Initialize Energy map
    A.resize(N, vector <int>(N));
    MAP.resize(N, vector <int>(N));
    DEAD.resize(N, vector <int>(N));
    TREE.resize(N, vector <vector <int>>(N));

    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++){
            scanf("%d", &A[r][c]);
        }
    
    for(int i = 0; i < M; i++){
        int r, c, age;
        scanf("%d %d %d", &r, &c, &age);
        TREE[r-1][c-1].push_back(age);
        MAP[r-1][c-1]++;
    }
}

int cntTree(){
    int sum = 0;

    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++){
            sum += MAP[r][c];
        }

    return sum;
}

void output(){
    printf("\n");
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            printf("%d ", E[r][c]);
        }
        printf("\n");
    }
    printf("\n");
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            printf("%d ", MAP[r][c]);
        }
        printf("\n");
    }
    
}

void solution(){
    int weather = 0;
    int year = 0;
    while(year < K){
        switch (weather)
        {
        case SPRING:
        {
            for(int r = 0; r < N; r++)
                for(int c = 0; c < N; c++){
                    if(MAP[r][c] == 0)
                        continue;
                    if(MAP[r][c] != 1)
                        sort(TREE[r][c].begin(), TREE[r][c].end());

                    for(int i = 0; i < TREE[r][c].size(); i++){
                        int age = TREE[r][c][i];

                        if(age <= E[r][c]){
                            E[r][c] -= age;
                            TREE[r][c][i]++;
                        }
                        else{
                            for(int j = i; j < TREE[r][c].size(); j++){
                                MAP[r][c]--;
                                DEAD[r][c] += (TREE[r][c][j] / 2);
                            }
                            
                            TREE[r][c].erase(TREE[r][c].begin() + i, TREE[r][c].end());
                            break;
                        }
                    }   
                }
            break;
        }
        case SUMMER:
        {
            for(int r = 0; r < N; r++)
                for(int c = 0; c < N; c++){
                    E[r][c] += DEAD[r][c];
                    DEAD[r][c] = 0;
                }


            break;
        }
        case FALL:
        {
            for(int r = 0; r < N; r++)
                for(int c = 0; c < N; c++){
                    if(MAP[r][c] == 0)
                        continue;
                    
                    for(int i = 0; i < TREE[r][c].size(); i++){
                        int age = TREE[r][c][i];

                        if(age % 5 == 0){
                            for(int j = 0; j < 8; j++){
                                int nr = r + dr[j];
                                int nc = c + dc[j];

                                if(nr <= -1 || nc <= -1 || nr >= N || nc >= N)
                                    continue;

                                TREE[nr][nc].push_back(1);
                                MAP[nr][nc]++;
                            }
                        }
                    }
                }
            break;
        }
        case WINTER:
        {
            for(int r = 0; r < N; r++)
                for(int c = 0; c < N; c++)
                    E[r][c] += A[r][c];
                
            break;
        }
        }

        weather++;
        if(weather > 3){
            weather -= 4;
            year++;
            //output();
        }   
    }

}

int main(){
    input();
    solution();
    printf("%d", cntTree());
}
