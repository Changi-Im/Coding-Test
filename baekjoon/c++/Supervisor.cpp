#include <stdio.h>
#define MAX 1500000

using namespace std;

long long N, B, C;
long long A[MAX];
long long s[MAX], ss[MAX];

void input(){
    long long i;
    scanf("%lld", &N);
    for(i = 0; i < N; i++)
        scanf("%lld", &A[i]);
    scanf("%lld %lld", &B, &C);
}

long long algorithm(){
    long long r;
    long long sum = 0;
    long long i;

    for(i = 0; i < N; i++)
        s[i] = 1;

    for(i = 0; i < N; i++){
        A[i] -= s[i]*B;
        
        if(A[i] > 0){
            r = A[i] % C;

            if(r == 0)
                ss[i] = (A[i] / C);
            else
                ss[i] = (A[i] / C) + 1;
        }
    }

    for(i = 0; i < N; i++){
        sum += (s[i] + ss[i]);
    }

    return sum;
}

int main(){
    input();
    printf("%lld", algorithm());
}
