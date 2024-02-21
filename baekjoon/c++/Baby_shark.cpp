// The problem is from https://www.acmicpc.net/problem/16236
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <vector <int>> MAP;
vector <pair <int, int>> FISH;
queue <pair <int, int>> QUEUE;

typedef struct st{
    int r, c, size;
} SHARK;

SHARK shark;
int dr[4] = {0, -1 , 0, 1};
int dc[4] = {-1, 0 , 1 ,0};
int N, time;

void input(){
    cin >> N;

    MAP.resize(N, vector <int>(N));
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++){
            cin >> MAP[r][c];
            /* Update baby shark's location & fishes' location */
            if(MAP[r][c] == 9){
                shark.r = r;
                shark.c = c;
                shark.size = 2;
                MAP[r][c] = 0;
            }
            else if(MAP[r][c] != 0)
                FISH.push_back(pair <int, int>(r, c));
        }
}

int BFS(int y, int x){
    vector <vector <int>> COPY;
    vector <vector <int>> VISIT;
    COPY.resize(N, vector <int>(N, 1));
    VISIT.resize(N, vector <int>(N));

    QUEUE.push(pair <int, int>(shark.r, shark.c));
    VISIT[shark.r][shark.c] = 1;
    shark.r = y, shark.c = x;

    while(!QUEUE.empty()){
        int mr = QUEUE.front().first;
        int mc = QUEUE.front().second;
        QUEUE.pop();

        for(int i = 0; i < 4; i++){
            int nr = mr + dr[i];
            int nc = mc + dc[i];

            if(nr == -1 || nc == -1 || nr == N || nc == N)
                continue;
            
            if(MAP[nr][nc] < shark.size && VISIT[nr][nc] == 0){
                COPY[nr][nc] += COPY[mr][mc];
                VISIT[nr][nc] = 1;
                QUEUE.push(pair <int, int>(nr, nc));
            }

            if(nr == y && nc == x)
                return COPY[mr][mc];
        }
    }
}

int allBFS(){
    vector <vector <int>> COPY;
    vector <vector <int>> VISIT;
    COPY.resize(N, vector <int>(N, 1));
    VISIT.resize(N, vector <int>(N));

    QUEUE.push(pair <int, int>(shark.r, shark.c));
    VISIT[shark.r][shark.c] = 1;

    while(!QUEUE.empty()){
        int mr = QUEUE.front().first;
        int mc = QUEUE.front().second;
        QUEUE.pop();

        for(int i = 0; i < 4; i++){
            int nr = mr + dr[i];
            int nc = mc + dc[i];

            if(nr == -1 || nc == -1 || nr == N || nc == N)
                continue;
            
            if(MAP[nr][nc] <= shark.size && VISIT[nr][nc] == 0){
                COPY[nr][nc] += COPY[mr][mc];
                VISIT[nr][nc] = 1;
                QUEUE.push(pair <int, int>(nr, nc));
            }
        }
    }

    // cout << "\n";
    // for(int r = 0; r < N; r++){
    //     for(int c = 0; c < N; c++)
    //         cout << COPY[r][c] << " ";
    //     cout << "\n";
    // }
    int min = 0x12341234;
    vector <int> nx;
    vector <int> ny;
    /* Find the minimum distance among fishes*/
    for(int i = 0; i < FISH.size(); i++){
        if(MAP[FISH[i].first][FISH[i].second] < shark.size){
            if(COPY[FISH[i].first][FISH[i].second] < min && COPY[FISH[i].first][FISH[i].second] != 1)
                min = COPY[FISH[i].first][FISH[i].second];  
        }
    }

    if(min == 0x12341234)
        return 0;

    /* Find the coordinates of the minimum distance */
    for(int i = 0; i < FISH.size(); i++){
        if(MAP[FISH[i].first][FISH[i].second] < shark.size){
            if(COPY[FISH[i].first][FISH[i].second] == min){
                nx.push_back(FISH[i].second);
                ny.push_back(FISH[i].first);
            }
        }
    }
    
    /* When the ny size is 1, return */
    if(ny.size() == 1){
        for(int i = 0; i < FISH.size(); i++){
            if(FISH[i].first == ny[0] && FISH[i].second == nx[0]){
                FISH.erase(FISH.begin() + i);
                shark.r = ny[0], shark.c = nx[0];
                MAP[ny[0]][nx[0]] = 0;
                return COPY[ny[0]][nx[0]] - 1;
            }
        }
        
    }

    /* Sort the coordinates based on y */
    for(int i = 0; i < nx.size() - 1; i++){
        for(int j = 0; j < nx.size() - i - 1; j++){
            int tmp;
            if(ny[j] > ny[j+1]){
                tmp = ny[j];
                ny[j] = ny[j+1];
                ny[j+1] = tmp; 

                tmp = nx[j];
                nx[j] = nx[j+1];
                nx[j+1] = tmp; 
            }
        }
    }
    
    if(ny[0] != ny[1]){
        for(int i = 0; i < FISH.size(); i++){
            if(FISH[i].first == ny[0] && FISH[i].second == nx[0]){
                FISH.erase(FISH.begin() + i);
                shark.r = ny[0], shark.c = nx[0];
                MAP[ny[0]][nx[0]] = 0;
                return COPY[ny[0]][nx[0]] - 1;
            }
        }
    }
    else{
        int cnt = 0;
        for(int i = 1; i < ny.size() - 1; i++){
            if(ny[0] == ny[i])
                cnt++;
        }

        sort(nx.begin(), nx.begin() + cnt);

        for(int i = 0; i < FISH.size(); i++){
            if(FISH[i].first == ny[0] && FISH[i].second == nx[0]){
                FISH.erase(FISH.begin() + i);
                shark.r = ny[0], shark.c = nx[0];
                MAP[ny[0]][nx[0]] = 0;
                return COPY[ny[0]][nx[0]] - 1;
            }
        }

        
    }

}

void solution(){
    /* Count how many fishes the baby shark ate */
    int cnt = 0;

    while(1){
        /* When there is only one fish */
        if(FISH.size() == 1){
            if(MAP[FISH[0].first][FISH[0].second] < shark.size){
                time += BFS(FISH[0].first, FISH[0].second);
                MAP[FISH[0].first][FISH[0].second] = 0;
                FISH.erase(FISH.begin());
                cnt++;
            }
            else
                break;
        }
        /* When there is more than one fish */
        else if(FISH.size() > 1){
            int flag = 0;
            for(int i = 0; i < FISH.size(); i++){
                if(MAP[FISH[i].first][FISH[i].second] < shark.size)
                    flag = 1;
            }
            if(flag == 0)
                break;
            int tmp = allBFS();

            if(tmp == 0)
                break;
    
            time += tmp;
            cnt++;
        }
        else
            break;

        if(cnt == shark.size){
            shark.size++;
            cnt = 0;
        }
    }
}

int main(){
    input();
    solution();
    cout << time;
}