// The problem is from https://www.acmicpc.net/problem/17779
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int ANS = 0xf777000;
vector <vector <int>> MAP;

void input(){
    cin >> N;
    MAP.resize(N+2, vector <int>(N+2, -1));
    for(int r = 1; r <= N; r++)
        for(int c = 1; c <= N; c++)
            cin >> MAP[r][c];
}

void solution(int sr, int sc, int d1, int d2){
    vector <vector <int>> area;
    area.resize(N+2, vector <int>(N+2));
    vector <int> sum(5);
    int top, bot;
    int min = 0xf777000;
    int max = -1;

    top = bot = sr;
    /* Fill 5 in area vector */
    for(int c = sc; c <= sc+d1+d2; c++){
        for(int r = bot; r <= top; r++)
            area[r][c] = 5;
        if(c >= sc+d1)    bot++;
        else    bot--;

        if(c >= sc+d2)    top--;
        else    top++;
    }
    
    /* Make sum vector using the area map */
    for(int r = 1; r <= N; r++)
        for(int c = 1; c <= N; c++){
            if(area[r][c] == 5) sum[4] += MAP[r][c];
            else if(r >= 1 && r < sr && c >= 1 && c <= sc+d1){   sum[0] += MAP[r][c];
                // area[r][c] = 1;
            }
            else if(r >= 1 && r <= sr+d2-d1 && c > sc+d1 && c <= N){   sum[1] += MAP[r][c];
                // area[r][c] = 2;
            }
            else if(r >= sr && r <= N && c >= 1 && c < sc+d2){   sum[2] += MAP[r][c];
                // area[r][c] = 3;
            }
            else if(r > sr+d2-d1 && r <= N && c >= sc+d2 && c <= N){   sum[3] += MAP[r][c];
                // area[r][c] = 4;
            }
        }

    /* Compare values and find minimum * maximum value */
    for(const auto& s : sum){
        if(s > max) max = s;
        if(s < min) min = s;
    }

    /* Find answer */
    if(ANS > (max - min))   ANS = (max - min);

    // cout << "\n";
    // for(int r = 1; r <= N; r++){
    //     for(int c = 1; c <= N; c++)
    //         cout << area[r][c] << " ";
    // cout << "\n";
    // }

    
}

int main(){
    input();

    for(int r = 2; r <= N - 1; r++)
        for(int c = 1; c <= N - 2; c++)
            for(int d1 = 1; ; d1++){
                if(MAP[r - d1][c + d1] == -1)  break;
                for(int d2 = 1; ; d2++){
                    if(MAP[r + d2][c + d2] == -1)  break;
                    else if(MAP[r - d1 + d2][c + d1 + d2] == -1)    break;
                    
                    solution(r, c, d1, d2);
                }
            }
    
    cout << ANS;
    
}