// The problem is from https://www.acmicpc.net/problem/15663

#include <iostream>

using namespace std;

int N, M;
int list[10], num_list[10], visited[10], possible[10000+100], input[10];

void sort(){
    int tmp;

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if(num_list[j] > num_list[j+1]){
                tmp = num_list[j];
                num_list[j] = num_list[j+1];
                num_list[j+1] = tmp;
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

void dfs(int L){
    if(L == M){
        outputPrint();
        return;
    }

    for(int i = 0; i < N; i++){
        if(visited[i] == possible[num_list[i]])
            continue;

        visited[i]++;
        list[L] = num_list[i];
        dfs(L + 1);
        visited[i]--;
    }
}

int main(){
    int cnt = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> input[i];

    for(int i = 0; i < N; i++){
        if(possible[input[i]] == 0){
            num_list[cnt++] = input[i];
        }

        possible[input[i]]++;
    }
    
    N = cnt;
    sort();
    dfs(0);
}