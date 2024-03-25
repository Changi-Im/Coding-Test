// The problem is from https://www.acmicpc.net/problem/17140
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> MAP;
int r, c, k;

void input(){
    cin >> r >> c >> k;

    MAP.resize(3, vector <int>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> MAP[i][j];
}

void sortRow(vector <int> &cnt, vector <int> &num, int row){
    vector <int> visited(MAP[row].size());

    for(int i = 0; i < MAP[row].size(); i++){
        if(visited[i] == 0 && MAP[row][i] != 0){
            int val = MAP[row][i];
            int count = 0;

            for(int j = i; j < MAP[row].size(); j++){
                if(val == MAP[row][j]){
                    visited[j] = 1;
                    count += 1;
                }
            }

            num.push_back(val);
            cnt.push_back(count);
        }
    }

    /* Sort by cnt */
    for(int i = 0; i < cnt.size() - 1; i++)
        for(int j = 0; j < cnt.size() - 1 - i; j++){
            int tmp;

            if(cnt[j] > cnt[j+1]){
                tmp = cnt[j];
                cnt[j] = cnt[j+1];
                cnt[j+1] = tmp;

                tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }

    /* Find same cnt value and length */
    for(int i = 0; i < cnt.size() - 1;){
        int length = 1;
        for(int j = i; j < cnt.size() - 1; j++){ 
            if(cnt[j] == cnt[j+1]){
                length += 1;
            }
            else
                break;
        }
        /* Sort by num */
        for(int a = 0; a < length - 1; a++)
            for(int b = 0; b < length - 1 - a; b++){
                int tmp;

                if(num[i+b] > num[i+b+1]){
                    tmp = cnt[i+b];
                    cnt[i+b] = cnt[i+b+1];
                    cnt[i+b+1] = tmp;

                    tmp = num[i+b];
                    num[i+b] = num[i+b+1];
                    num[i+b+1] = tmp;
                }
            }   
        i += length;
    }

}

void sortCol(vector <int> &cnt, vector <int> &num, int col){
    vector <int> visited(MAP.size());

    for(int i = 0; i < MAP.size(); i++){
        if(visited[i] == 0 && MAP[i][col] != 0){
            int val = MAP[i][col];
            int count = 0;

            for(int j = i; j < MAP.size(); j++){
                if(val == MAP[j][col]){
                    visited[j] = 1;
                    count += 1;
                }
            }

            num.push_back(val);
            cnt.push_back(count);
        }
    }

    /* Sort by cnt */
    for(int i = 0; i < cnt.size() - 1; i++)
        for(int j = 0; j < cnt.size() - 1 - i; j++){
            int tmp;

            if(cnt[j] > cnt[j+1]){
                tmp = cnt[j];
                cnt[j] = cnt[j+1];
                cnt[j+1] = tmp;

                tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }

    /* Find same cnt value and length */
    for(int i = 0; i < cnt.size() - 1;){
        int length = 1;
        for(int j = i; j < cnt.size() - 1; j++){ 
            if(cnt[j] == cnt[j+1]){
                length += 1;
            }
            else
                break;
        }
        /* Sort by num */
        for(int a = 0; a < length - 1; a++)
            for(int b = 0; b < length - 1 - a; b++){
                int tmp;

                if(num[i+b] > num[i+b+1]){
                    tmp = cnt[i+b];
                    cnt[i+b] = cnt[i+b+1];
                    cnt[i+b+1] = tmp;

                    tmp = num[i+b];
                    num[i+b] = num[i+b+1];
                    num[i+b+1] = tmp;
                }
            }   
        i += length;
    }

}

int solution(){
    int t = 0;
    while(1){
        if(MAP.size() >= r && MAP[0].size() >= c){
            if(MAP[r-1][c-1] == k)
                return t;
        }
        if(t == 100)
            return -1;
        
        t++;
        /* R calculation */
        if(MAP.size() >= MAP[0].size()){
            int lineLen = 0;
            int idx = 0;
            vector <vector <int>> newMAP(MAP.size());

            for(int i = 0; i < MAP.size(); i++){
                vector <int> cnt;
                vector <int> num;
                sortRow(cnt, num, i);

                for(int j = 0; j < cnt.size(); j++){
                    newMAP[i].push_back(num[j]);
                    newMAP[i].push_back(cnt[j]);
                }

                if(lineLen < newMAP[i].size())
                    lineLen = newMAP[i].size();
            }

            if(lineLen > 100)
                lineLen = 100;

            for(int i = 0; i < newMAP.size(); i++){
                if(newMAP[i].size() < lineLen){
                    int oldLen = newMAP[i].size();
                    for(int j = 0; j < lineLen - oldLen; j++)
                        newMAP[i].push_back(0);
                }
            }

            MAP.assign(newMAP.begin(), newMAP.end());
        }
        /* C calculation */
        else if(MAP.size() < MAP[0].size()){
            int lineLen = 0;
            int idx = 0;
            vector <vector <int>> newMAP(MAP[0].size());

            for(int i = 0; i < MAP[0].size(); i++){
                vector <int> cnt;
                vector <int> num;
                sortCol(cnt, num, i);

                for(int j = 0; j < cnt.size(); j++){
                    newMAP[i].push_back(num[j]);
                    newMAP[i].push_back(cnt[j]);
                }

                if(lineLen < newMAP[i].size())
                    lineLen = newMAP[i].size();
            }
            
            if(lineLen > 100)
                lineLen = 100;

            for(int i = 0; i < newMAP.size(); i++){
                if(newMAP[i].size() < lineLen){
                    int oldLen = newMAP[i].size();
                    for(int j = 0; j < lineLen - oldLen; j++)
                        newMAP[i].push_back(0);
                }
            }

            vector <vector <int>> newMAPRot(newMAP[0].size());

            for(int j = 0; j < newMAP[0].size(); j++)
                for(int i = 0; i < newMAP.size(); i++)
                    newMAPRot[j].push_back(newMAP[i][j]);

            MAP.assign(newMAPRot.begin(), newMAPRot.end());
        }


    }
}

int main(){
    input();
    cout << solution();

}