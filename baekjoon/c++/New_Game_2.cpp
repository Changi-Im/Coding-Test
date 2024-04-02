// The problem is from https://www.acmicpc.net/problem/17837

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int FLAG = 0;
vector <vector <int>> MAP;
vector <vector <vector <pair <int, int>>>> chess;
vector <pair <int, int>> info;
int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};

void input(){
    cin >> N >> K;
    MAP.resize(N+2, vector <int>(N+2, -1));
    chess.resize(N+2, vector <vector <pair <int, int>>>(N+2));
    info.resize(K);

    for (int r = 1; r <= N; ++r)
        for (int c = 1; c <= N; ++c)
            cin >> MAP[r][c];
    
    for (int i = 0; i < K; ++i){
        int r, c, d;
        cin >> r >> c >> d;
        info[i] = pair <int, int>(r, c);
        chess[r][c].push_back(pair <int, int>(d, i));
    }
}

void whiteMove(int j, int r, int c, int nr, int nc){
    /* When this piece is the only piece or located on bottom*/
    if (j == chess[r][c].size() - 1){
        chess[nr][nc].push_back(pair <int, int>(chess[r][c][j].first, chess[r][c][j].second));
        chess[r][c].erase(chess[r][c].begin() + j);
        info[chess[r][c][j].second] = pair <int, int>(nr, nc);
    }
    /* When there is another piece on this piece */
    else{
        int cnt = j;
        for (int k = j; k < chess[r][c].size(); ++k){
            chess[nr][nc].push_back(pair <int, int>(chess[r][c][k].first, chess[r][c][k].second));
            info[chess[r][c][k].second] = pair <int, int>(nr, nc);
            ++cnt;
        }
        chess[r][c].erase(chess[r][c].begin() + j, chess[r][c].begin() + cnt);
    }
    /* Check if there are more than 4 pieces on the block */
    if (chess[nr][nc].size() >= 4)  FLAG = 1;
}

void redMove(int j, int r, int c, int nr, int nc){
    /* When this piece is the only piece or located on top*/
    if (j == chess[r][c].size() - 1){
        chess[nr][nc].push_back(pair <int, int>(chess[r][c][j].first, chess[r][c][j].second));
        chess[r][c].erase(chess[r][c].begin() + j);
        info[chess[r][c][j].second] = pair <int, int>(nr, nc);
    }
    /* When there is another piece on this piece */
    else{
        int cnt = j;
        for (int k = chess[r][c].size() - 1; k >= j; --k){
            chess[nr][nc].push_back(pair <int, int>(chess[r][c][k].first, chess[r][c][k].second));
            info[chess[r][c][k].second] = pair <int, int>(nr, nc);
            ++cnt;
        }
        chess[r][c].erase(chess[r][c].begin() + j, chess[r][c].begin() + cnt);
    }
    /* Check if there are more than 4 pieces on the block */
    if (chess[nr][nc].size() >= 4)  FLAG = 1;
}

int solution(){
    int turn = 1;
    while(turn <= 1000){
        /* Move chess pieces in order */
        for (int i = 0; i < info.size(); ++i){
            int r = info[i].first, c = info[i].second;

            for (int j = 0; j < chess[r][c].size(); ++j){
                if (chess[r][c][j].second == i){
                    int nr = r + dr[chess[r][c][j].first];
                    int nc = c + dc[chess[r][c][j].first];
                    
                    /* Case 1 : block is white */
                    if (MAP[nr][nc] == 0)   whiteMove(j, r, c, nr, nc);
                    /* Case 2 : block is red */
                    else if (MAP[nr][nc] == 1)  redMove(j, r, c, nr, nc);
                    /* Case 3 : block is blue or out of board */
                    else if (MAP[nr][nc] == 2 || MAP[nr][nc] == -1){
                        if (chess[r][c][j].first == 1)   chess[r][c][j].first = 2;
                        else if (chess[r][c][j].first == 2)  chess[r][c][j].first = 1;
                        else if (chess[r][c][j].first == 3)  chess[r][c][j].first = 4;
                        else if (chess[r][c][j].first == 4)  chess[r][c][j].first = 3;

                        nr = r + dr[chess[r][c][j].first];
                        nc = c + dc[chess[r][c][j].first];

                        if (MAP[nr][nc] == 0)   whiteMove(j, r, c, nr, nc);
                        else if (MAP[nr][nc] == 1)  redMove(j, r, c, nr, nc);
                    }
                }
            }

            if(FLAG == 1)   break;
        }

        if(FLAG == 1)   return turn;
        turn++;
    }

    return -1;
}
int main(){
    input();
    cout << solution();
    
}