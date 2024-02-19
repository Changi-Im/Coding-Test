//The problem is from https://www.acmicpc.net/problem/1167
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 150000

using namespace std;

vector<pair<int, int>> graph[MAX];
int visited[MAX];
int answer, firstNode;

void DFS(int start, int dist){
    visited[start] = 1;

    if(answer < dist){
        answer = dist;
        firstNode = start;
    }
    
    for(long long i = 0; i < graph[start].size(); i++){
        int nextNode = graph[start][i].first;
        int nextDist = graph[start][i].second;
        if(visited[nextNode] == 0){
            visited[nextNode] = 1;
            DFS(nextNode, dist+nextDist);
            visited[nextNode] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    long long V;
    cin >> V;

    for(long long i = 0; i < V; i++){
        int u;      // Current node
        int v;      // Next node
        int dist;   // Distance between the nodes
        
        cin >> u;
        while(1){
            cin >> v;
            if(v == -1)
                break;
            cin >> dist;

            graph[u].push_back({v, dist});
        }         
    }

    DFS(1, 0);
    memset(visited, 0, (V+1)*sizeof(int));
    answer = 0;
    DFS(firstNode, 0);

    cout << answer;
}