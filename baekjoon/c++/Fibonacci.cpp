#include <stdio.h>

int dp[5000];

void fibonacci(int n) {
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int main(){
    int T;

    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int N;
        scanf("%d", &N);
        if(N < 2){
            switch (N)
            {
            case 0:
            {   printf("%d %d\n", 1, 0);
                break;
            }
            case 1:
            {   printf("%d %d\n", 0, 1);
                break;
            }
            }
            continue;
        }
        fibonacci(N);
        printf("%d %d\n", dp[N-1], dp[N]);
    }
}