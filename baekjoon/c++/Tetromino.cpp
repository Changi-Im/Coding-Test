// The problem is from https://www.acmicpc.net/problem/14500

#include <stdio.h>
#define MAX 550

using namespace std;

int N, M;
int MAP[MAX][MAX];
int ANSWER = 0;
int sum;

void input(){
    scanf("%d %d", &N, &M);

    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            scanf("%d", &MAP[r][c]);
}

void fistBlock(){
    /* Original shape && Original symmetry shape */
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M - 3; c++){
            for(int cc = c; cc < c + 4; cc++)
                sum += MAP[r][cc];
            
            if(sum > ANSWER)
                ANSWER = sum;
            
            sum = 0;   
        }
    }

    /* Rotated shape && Rotated symmetry shape */
    for(int r = 0; r < N - 3; r++){
        for(int c = 0; c < M; c++){
            for(int rr = r; rr < r + 4; rr++)
                sum += MAP[rr][c];
        
            if(sum > ANSWER)
                ANSWER = sum;
            
            sum = 0;    
        }
    }
}

void secondBlock(){
    /* Original shape && Symmetry shape && Rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 0; c < M - 1; c++){
            for(int rr = r; rr < r + 2; rr++)
                for(int cc = c; cc < c + 2; cc++)
                    sum += MAP[rr][cc];

            if(sum > ANSWER)
                ANSWER = sum;
            
            sum = 0;

        }   
    }
}

void thirdBlock(){
    /* Original shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 0; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+2][c] + MAP[r+2][c+1]);
        
            if(sum > ANSWER)
                ANSWER = sum;
            
            sum = 0;
        }     
    }

    /* Original symmetry shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 1; c < M; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+2][c] + MAP[r+2][c-1]);
        
            if(sum > ANSWER)
                ANSWER = sum;
            
            sum = 0;
        }   
    }

    /* -90 deg rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 2; c < M; c++){
            sum += (MAP[r][c] + MAP[r+1][c-2] + MAP[r+1][c-1] + MAP[r+1][c]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* Symmetry of -90 deg rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 0; c < M - 2; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+1][c+1] + MAP[r+1][c+2]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* -180 deg rotated shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 0; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r][c+1] + MAP[r+1][c+1] + MAP[r+2][c+1]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* Symmetry of -180 deg rotated shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 0; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+2][c] + MAP[r][c+1]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* -270 deg rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 0; c < M - 2; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r][c+1] + MAP[r][c+2]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* Symmetry of -270 deg rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 0; c < M - 2; c++){
            sum += (MAP[r][c] + MAP[r][c+1] + MAP[r][c+2] + MAP[r+1][c+2]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }
}

void fourthBlock(){
    /* Original shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 0; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+1][c+1] + MAP[r+2][c+1]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* Symmetry of original shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 1; c < M; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+1][c-1] + MAP[r+2][c-1]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* Rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 1; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r][c+1] + MAP[r+1][c] + MAP[r+1][c-1]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* Symmetry of rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 0; c < M - 2; c++){
            sum += (MAP[r][c] + MAP[r][c+1] + MAP[r+1][c+1] + MAP[r+1][c+2]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }
}

void fifthBlock(){
    /* Original shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 0; c < M - 2; c++){
            sum += (MAP[r][c] + MAP[r][c+1] + MAP[r][c+2] + MAP[r+1][c+1]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* -90 deg rotated shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 0; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+1][c+1] + MAP[r+2][c]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* -180 deg rotated shape */
    for(int r = 0; r < N - 1; r++){
        for(int c = 1; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r+1][c-1] + MAP[r+1][c] + MAP[r+1][c+1]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }

    /* -270 deg rotated shape */
    for(int r = 0; r < N - 2; r++){
        for(int c = 1; c < M - 1; c++){
            sum += (MAP[r][c] + MAP[r+1][c] + MAP[r+1][c-1] + MAP[r+2][c]);
        
            if(sum > ANSWER)
                ANSWER = sum;  
            
            sum = 0;
        }
    }
}

void solution(){
    for(int i = 0; i < 5; i++){
        if(i == 0)
            fistBlock();
        else if(i == 1)
            secondBlock();
        else if(i == 2)
            thirdBlock();
        else if(i == 3)
            fourthBlock();
        else
            fifthBlock();
    }
}

int main(){
    input();
    solution();

    printf("%d", ANSWER);
}