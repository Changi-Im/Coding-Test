// The problem is from https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;


int main(){
    int N, K;
    int value;
    queue<int> q;

    cin >> N >> K;

    // push 1 to N
    for(int i = 0; i < N; i++){
        q.push(i + 1);
    }

    cout << "<";

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K - 1; j++){
            value = q.front();
            q.pop(); 
            q.push(value);
        }

        if(i < N-1){
            cout << q.front() << ", ";
            q.pop();
        }
        else{
            cout << q.front();
            q.pop();
        }
    }

    cout << ">";
}