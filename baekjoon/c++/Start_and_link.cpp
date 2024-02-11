// The problem is from https://www.acmicpc.net/problem/14889
#include <stdio.h>
#define MAX 25

using namespace std;

int N;
int S[MAX][MAX];
int listFirst[MAX], listSecond[MAX];
int ANSWER = 200;

void input(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &S[i][j]);
        
}

void solution(){
    int firstScore = 0;
    int secondScore = 0;

    for(int i = 0; i < N/2; i++){
        for(int j = i + 1; j < N/2; j++){
            firstScore += S[listFirst[i]][listFirst[j]] + S[listFirst[j]][listFirst[i]];
            secondScore += S[listSecond[i]][listSecond[j]] + S[listSecond[j]][listSecond[i]];
        }
    }

    if(secondScore >= firstScore)
        ANSWER = secondScore - firstScore < ANSWER ? secondScore - firstScore : ANSWER;
    else
        ANSWER = firstScore - secondScore < ANSWER ? firstScore - secondScore : ANSWER;
}

void DFS(int L, int start){
    if(L == N/2){
        int idx = 0;
        for(int i = 1; i <= N; i++){
            int flag = 0;
            for(int j = 0; j < N/2; j++){
                if(listFirst[j] == i){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                listSecond[idx++] = i;
        }
        solution();
        return;
    }

    for(int i = start; i <= N; i++){
        listFirst[L] = i;
        DFS(L+1, i+1);
    }
}

int main(){
    input();
    DFS(0, 1);
    printf("%d", ANSWER);
}