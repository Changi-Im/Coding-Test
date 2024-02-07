// The problem is from https://www.acmicpc.net/problem/12100

#include <iostream>
#define MAX 25

using namespace std;

int N;
int MAP[MAX][MAX];
int ANSWER = 0;

void memSet(int arr[][MAX])
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            arr[r][c] = 0;
}

void memCopy(int src[][MAX], int dst[][MAX])
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            dst[r][c] = src[r][c];
}

int findMax(int arr[][MAX])
{
    int max = 0;

    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            if(max < arr[r][c]) max = arr[r][c];

    return max;
}

void moveLeft(int arr[][MAX])
{
    int tmp[MAX][MAX] = {0,};
    memSet(tmp);

    for(int r = 0; r < N; r++)
    {
        int idx = 0;
        /* Move whole numbers to left first */
        for(int c = 0; c < N; c++)
        {
            if(arr[r][c] == 0) continue;
            tmp[r][idx++] = arr[r][c];

        }

        /* Summation */
        for(int c = 0; c < N - 1; c++)
        {
            if(tmp[r][c] == tmp[r][c+1])
            {
                tmp[r][c] *= 2;
                
                for(int cc = c + 1; cc < N - 1; cc++) tmp[r][cc] = tmp[r][cc+1];
                tmp[r][N-1] = 0;
            }
            else
                continue;
        }
    }

    memCopy(tmp, arr);
}

void moveRight(int arr[][MAX])
{
    int tmp[MAX][MAX] = {0,};
    memSet(tmp);

    for(int r = 0; r < N; r++)
    {
        int idx = N-1;
        /* Move whole numbers to right first */
        for(int c = N - 1; c >= 0; c--)
        {
            if(arr[r][c] == 0) continue;
            tmp[r][idx--] = arr[r][c];

        }

        /* Summation */
        for(int c = N - 1; c > 0; c--)
        {
            if(tmp[r][c] == tmp[r][c-1])
            {
                tmp[r][c] *= 2;
                
                for(int cc = c - 1; cc > 0; cc--) tmp[r][cc] = tmp[r][cc-1];
                tmp[r][0] = 0;
            }
            else
                continue;
        }
    }

    memCopy(tmp, arr);
}

void moveUp(int arr[][MAX])
{
    int tmp[MAX][MAX] = {0,};
    memSet(tmp);

    for(int c = 0; c < N; c++)
    {
        int idx = N-1;
        /* Move whole numbers to top first */
        for(int r = N - 1; r >= 0; r--)
        {
            if(arr[r][c] == 0) continue;
            tmp[idx--][c] = arr[r][c];

        }

        /* Summation */
        for(int r = N - 1; r > 0; r--)
        {
            if(tmp[r][c] == tmp[r-1][c])
            {
                tmp[r][c] *= 2;
                
                for(int rr = r - 1; rr > 0; rr--) tmp[rr][c] = tmp[rr-1][c];
                tmp[0][c] = 0;
            }
            else
                continue;
        }
    }

    memCopy(tmp, arr);
}

void moveDown(int arr[][MAX])
{
    int tmp[MAX][MAX] = {0,};
    memSet(tmp);

    for(int c = 0; c < N; c++)
    {
        int idx = 0;
        /* Move whole numbers to bottom first */
        for(int r = 0; r < N; r++)
        {
            if(arr[r][c] == 0) continue;
            tmp[idx++][c] = arr[r][c];

        }

        /* Summation */
        for(int r = 0; r < N - 1; r++)
        {
            if(tmp[r][c] == tmp[r+1][c])
            {
                tmp[r][c] *= 2;
                
                for(int rr = r + 1; rr < N - 1; rr++) tmp[rr][c] = tmp[rr+1][c];
                tmp[N-1][c] = 0;
            }
            else
                continue;
        }
    }

    memCopy(tmp, arr);
}

void output()
{
    cout << "\n";    
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
            cout << MAP[r][c] << " ";
        cout << "\n";
    }
        
}

void DFS(int L, int arr[][MAX])
{
    if(L > 5)
    {
        int maxBlock = findMax(arr);
        if(ANSWER < maxBlock) ANSWER = maxBlock;

        return; 
    }

    int copy[MAX][MAX] = { 0 };
    memSet(copy);    

    for(int i = 0; i < 4; i++)
    {
        memCopy(arr, copy);
        if(i == 0) moveLeft(copy);
        else if(i == 1) moveRight(copy);
        else if(i == 2) moveUp(copy);
        else if(i == 3) moveDown(copy);

        DFS(L + 1, copy);
    }
}

void input()
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> MAP[r][c];
}

int main()
{
    cin >> N;

    input();
    DFS(1, MAP);

    cout << ANSWER;
}