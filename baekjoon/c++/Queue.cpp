// The problem is from https://www.acmicpc.net/problem/18258

#include <iostream>
#include <string>

using namespace std;


int queue[2000000 + 5000];
int rp, wp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, in;
    string input;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> input;
        if(input.compare("push") == 0){
            cin >> in;
            queue[wp++] = in;
        }
        else if(input.compare("pop") == 0)
            cout << (wp == rp ? -1 : queue[rp++]) << "\n";
        else if(input.compare("size") == 0)
            cout << wp - rp << "\n";
        else if(input.compare("empty") == 0)
            cout << (wp == rp ? 1 : 0) << "\n";
        else if(input.compare("front") == 0)
            cout << (wp == rp ? -1 : queue[rp]) << "\n";
        else if(input.compare("back") == 0)
            cout << (wp == rp ? -1 : queue[wp-1]) << "\n";
    }
}