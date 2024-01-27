// The problem is from https://www.acmicpc.net/problem/15652
#include <iostream>
#include <vector>

using namespace std;

int list[10];
int N, M;

void outputPrint(){
    for(int i = 0; i < M; i++)
        cout << list[i] << " ";
    cout << "\n";
}

void dfs(int L, int start){
    if(L == M){
        outputPrint();
        return;
    }
    for(int i = start; i <= N; i++){
        list[L] = i;
        dfs(L+1, i);
    }
}
int main(){
    cin >> N >> M;
    
    dfs(0, 1);
    return 0;
}