// The problem is from https://www.acmicpc.net/problem/15666

#include <iostream>

using namespace std;

int N, M;
int list[10], input[10], possible[10000 + 100];

void sort(){
    int tmp;

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if(input[j] > input[j+1]){
                tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }
        }
    }
}

void outputPrint(){
    for(int i = 0; i < M; i++){
        cout << list[i] << " ";
    }
    cout << "\n";
}

void dfs(int L, int start){
    if(L == M){
        outputPrint();
        return;
    }

    for(int i = start; i < N; i++){
        list[L] = input[i];
        dfs(L+1, i);
    }
}

int main(){
    int in, cnt = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> in;

        if(possible[in] == 0){
            input[cnt++] = in;
            possible[in]++;
        }
        else
            possible[in]++;
    }

    N = cnt;
    sort();
    dfs(0, 0);

}