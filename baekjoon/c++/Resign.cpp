// The problem is from https://www.acmicpc.net/problem/14501

#include <stdio.h>
#define MAX 20

using namespace std;

int N;
int T[MAX], P[MAX];
int visited[MAX];
int ANSWER = 0;
int sum;

void input(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d %d", &T[i], &P[i]);
}

void solution(int start){
    for(int i = start; i < N; i++){
        if(visited[i] == 0){
            visited[i] = 1;

            if(visited[i] == 1){
                start = (i+T[i]);
            }

            if(start > N){
                visited[i] = 0;
                continue;
            }
            solution(start);

            visited[i] = 0;
        }
    }

    for(int i = 0; i < N; i++){
        if(visited[i] == 1)
            sum += P[i];
    }

    if(ANSWER < sum)
        ANSWER = sum;

    sum = 0;
    return;
}

int main(){
    input();
    solution(0);
    printf("%d", ANSWER);
}