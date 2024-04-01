// The problem is from https://www.acmicpc.net/problem/17143
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct st1{
    int s, d, z;
} SHARK;


vector <vector <vector <SHARK>>> MAP;

int fR = 1, fC; /* Fisher's location */
int R, C, M;
int ans;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void input(){
    cin >> R >> C >> M;

    MAP.resize(R+1, vector <vector <SHARK>>(C+1));
    
    for(int i = 0; i < M; i++){
        int r, c;
        SHARK tmp;
        
        cin >> r >> c >> tmp.s >> tmp.d >> tmp.z;

        MAP[r][c].push_back(tmp);
    }
}

void solution(){
    int time = 0;

    while(time < C){
        fC++;
        time++;
        for(int r = fR; r <= R; r++){
           if(MAP[r][fC].size() != 0){
                ans += MAP[r][fC][0].z;

                /* Remove the existed shark */
                MAP[r][fC].erase(MAP[r][fC].begin());
                break;
           }
        }

        /* Copy the map */
        vector <vector <vector <SHARK>>> COPY(MAP);

        /* Sharks move */
        for(int r = 1; r <= R; r++)
            for(int c = 1; c <= C; c++){
                if(MAP[r][c].size() != 0){
                    int s = MAP[r][c][0].s;
                    int d = MAP[r][c][0].d - 1;
                    int z = MAP[r][c][0].z;

                    /* Remove the existing shark */
                    COPY[r][c].erase(COPY[r][c].begin());

                    int nr = r;
                    int nc = c;
                    int move;
                    if(d < 2){
                        move = s % ((R - 1) * 2);
                        for(int i = 0; i < move; i++){
                            nr += dr[d];

                            if(nr == 0 || nr == R+1){
                                nr -= dr[d];
                                nc -= dc[d];

                                if(d == 0)
                                    d = 1;
                                else if(d == 1)
                                    d = 0;

                                nr += dr[d];
                            }
                        }
                    }
                    else {
                        move = s % ((C - 1) * 2);
                        for(int i = 0; i < move; i++){
                            nc += dc[d];

                            if( nc == 0 || nc == C+1){
                                nc -= dc[d];

                                if(d == 2)
                                    d = 3;
                                else if(d == 3)
                                    d = 2;

                                nc += dc[d];
                            }
                        }
                    }

                    SHARK tmp;
                    tmp.d = d + 1;
                    tmp.s = s;
                    tmp.z = z;

                    COPY[nr][nc].push_back(tmp);
                }
            }
            
        for(int r = 1; r <= R; r++)
            for(int c = 1; c <= C; c++){
                if(COPY[r][c].size() > 1){
                    SHARK tmp;
                    tmp.z = 0;
                    int idx;

                    for(int i = 0; i < COPY[r][c].size(); i++){
                        if(COPY[r][c][i].z > tmp.z){
                            idx = i;
                            tmp.z = COPY[r][c][i].z;
                        }
                    }
                    tmp.s = COPY[r][c][idx].s;
                    tmp.z = COPY[r][c][idx].z;
                    tmp.d = COPY[r][c][idx].d;

                    COPY[r][c].erase(COPY[r][c].begin(), COPY[r][c].end());
                    COPY[r][c].push_back(tmp);
                }
            }

        /* Create new map*/
        MAP.assign(COPY.begin(), COPY.end());
    }
}

int main(){
    input();
    solution();
    cout << ans;
}