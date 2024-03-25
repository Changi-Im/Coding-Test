#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int ANSWER = 0x1234123;
vector <vector <int>> MAP;
vector <pair <int, int>> virus;
vector <pair <int, int>> list;

vector <int> visited;

void input(){
    cin >> N >> M;
    MAP.resize(N, vector <int>(N));
    list.resize(M);

    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++){
            cin >> MAP[r][c];
            if(MAP[r][c] == 2)
                virus.push_back(pair <int, int>(r, c));
        }

    visited.resize(virus.size());
}

void BFS(queue <pair <int, int>> q){
    vector <vector<int>> COPY(MAP);
    vector <vector<int>> visit;
    queue <pair <int, int>> q1;
    
    visit.resize(N, vector <int>(N));

    int time = 0;
    int flag = 0;
    int FLAG = 0;

    while(!q.empty() || !q1.empty()){
        int x, y;
        if(flag == 0){
            if(q.empty())
                break;
            y = q.front().first;
            x = q.front().second;
        }
        else{
            if(q1.empty())
                break;
            y = q1.front().first;
            x = q1.front().second;
        }
        
        visit[y][x] = 1;

        for(int i = 0; i < 4; i++){
            int ny = y + dr[i];
            int nx = x + dc[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N || COPY[ny][nx] == 1 || visit[ny][nx] == 1)
                continue;
            
            visit[ny][nx] = 1;
            COPY[ny][nx] = 2;

            if(flag == 0)
                q1.push(pair <int, int>(ny ,nx));
            else
                q.push(pair <int, int>(ny ,nx));
        }

        if(flag == 0)
            q.pop();
        else
            q1.pop();
        
        if((flag == 0 && q.empty()) || (flag == 1 && q1.empty())){
            FLAG = 0;
            time++;
            flag = !flag;

            if(q.empty() && q1.empty())
                break;
            
            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    if(COPY[r][c] == 0){
                        FLAG = 1;
                        break;
                    }
                }
                if(FLAG == 1)
                    break;
            }
            if(FLAG == 0)
                break;
        }
    }

    if(FLAG == 1)
        return;

    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++){
            if(COPY[r][c] == 0)
                return;
        }

    if(time < ANSWER)
        ANSWER = time;

}

void DFS(int L, int start){
    if(L == M){
        /* BFS start */
        queue <pair <int, int>> q;
        for(int j = 0; j < list.size(); j++)
            q.push(list[j]);

        BFS(q);
        return;
    }

    for(int i = start; i < virus.size(); i++){
        if(visited[i] == 1)
            continue;
        list[L] = virus[i];
        visited[i] = 1;
        DFS(L+1, i+1);
        if(ANSWER == 1)
            return;
        visited[i] = 0;
    }
}

int main(){
    input();

    int flag = 0;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++){
            if(MAP[r][c] == 0)
                flag = 1;
        }

    if(flag == 1){
        DFS(0, 0);
        if(ANSWER == 0x1234123)
            ANSWER = -1;
    }
    else   
        ANSWER = 0;

    cout << ANSWER;
    
}