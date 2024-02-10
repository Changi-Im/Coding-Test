// The problem is from https://www.acmicpc.net/problem/14888

#include <stdio.h>
#define MAX 15

int A[MAX];
int opList[MAX], list[MAX], visit[MAX];
int add, sub, mul, div;
int N;
int cnt = 0;
long long ansMax = -1000000000;
long long ansMin = 1000000000;

void input(){
    int idx = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    scanf("%d %d %d %d", &add, &sub, &mul, &div);

    for(int i = 0; i < add; i++)
        opList[idx++] = 1;
    
    for(int i = 0; i < sub; i++)
        opList[idx++] = 2;

    for(int i = 0; i < mul; i++)
        opList[idx++] = 3;

    for(int i = 0; i < div; i++)
        opList[idx++] = 4;
}

void output(){
    for(int i = 0; i < add + sub + mul + div; i++)
        printf("%d ", list[i]);
    printf("\n");
    cnt++;
}

void solution(){
    int idx = 0;
    long long res = A[idx];

    for(int i = 0; i < add + sub + mul + div; i++){
        if(list[i] == 1)
            res +=  A[idx + 1];
        else if(list[i] == 2)
            res -= A[idx + 1];
        else if(list[i] == 3)
            res *= A[idx + 1];
        else if(list[i] == 4)
            res /= A[idx + 1]; 
        
        idx++;           
    }

    if(res > ansMax)
        ansMax = res;

    if(res < ansMin)
        ansMin = res;    
}

void DFS(int L){
    if(L == add + sub + mul + div){
        solution();
        return;
    }
    
    for(int i = 0; i < add + sub + mul + div; i++){
        if(visit[i] == 1)
            continue;
        
        visit[i] = 1;
        list[L] = opList[i];
        DFS(L+1);
        visit[i] = 0;
    }
}

int main(){
    input();
    DFS(0);
    printf("%d\n%d", ansMax, ansMin);
}