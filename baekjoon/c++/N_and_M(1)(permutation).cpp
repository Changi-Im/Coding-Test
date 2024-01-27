// The problem is from https://www.acmicpc.net/problem/15649
#include <iostream>
#include <vector>

using namespace std;

int visited[10], list[10];
int N, M;

void outputPrint(){
    for(int i = 0; i < M; i++)
        cout << list[i] << " ";
    cout << "\n";
}

void dfs(int L){
    if(L == M){
        outputPrint();
        return;
    }
    for(int i = 1; i <= N; i++){
        if(visited[i] == 1)
            continue;
        else{
            visited[i] = 1;
            list[L] = i;
            
            dfs(L+1);
            
            visited[i] = 0;
        }
    }
}
int main(){
    cin >> N >> M;
    
    dfs(0);
    return 0;
}