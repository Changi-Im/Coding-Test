// The problem is from https://www.acmicpc.net/problem/14890
#include <stdio.h>
#define MAX 150

int MAP[MAX][MAX];
int PATH[MAX], visit[MAX];
int N, L;
int ANSWER = 0;

void input(){
    scanf("%d %d", &N, &L);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &MAP[i][j]);
}

void memSet(int arr[MAX]){
    for(int i = 0; i < N; i++)
        arr[i] = 0;
}

int abs(int num1, int num2){
    return num1 >= num2 ? num1 - num2 : num2 - num1;
}

void solution(){
    int flag = 0;
    memSet(visit);

    for(int i = 0; i < N - 1; i++){
        int h1 = PATH[i];
        int h2 = PATH[i+1];

        if((h2 - h1) == 1){
            int idx = i - (L - 1);
            if(idx < 0 || visit[idx] == 1){
                flag = 1;
                break;
            }
            else{
                if(PATH[idx] != h1){
                    flag = 1;
                    break;
                }
                for(int j = idx; j < L+idx; j++)
                    visit[j] = 1;
            }
        }
        else if((h1 - h2) == 1){
            int idx = i + L;
            if(i > N - 1 || visit[idx] == 1){
                flag = 1;
                break;
            }
            else{
                if(PATH[idx] != h2){
                    flag = 1;
                    break;
                }
                for(int j = idx-L+1; j < idx+1; j++)
                    visit[j] = 1;
            }
        }
        else if(abs(h1, h2) > 1){
            flag = 1;
            break;
        }
    }

    if(flag != 1)
        ANSWER += 1;    
}

int main(){
    input();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            PATH[j] = MAP[i][j];
        solution();
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            PATH[j] = MAP[j][i];
        solution();
    }

    printf("%d", ANSWER);
}