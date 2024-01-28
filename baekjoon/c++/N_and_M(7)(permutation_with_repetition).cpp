// The problem is from https://www.acmicpc.net/problem/15656
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int list[10], num_list[10];

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
        list[L] = num_list[i];
        dfs(L+1);
    }
}

int main(){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
        cin >> num_list[i];
    
    sort();
    dfs(0);

}