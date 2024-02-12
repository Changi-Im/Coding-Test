// The problem is from https://www.acmicpc.net/problem/14891
#include <stdio.h>
#define MAX 500000

int chain1[MAX], chain2[MAX], chain3[MAX], chain4[MAX];
int rp1, rp2, rp3, rp4, wp1, wp2, wp3, wp4;
int K;
int ANSWER = 0;

typedef struct st{
    int num;
    int d;
} METHOD;

METHOD method[150];

void input(){
    for(int i = 0; i < 8; i++){
        scanf("%1d", &chain1[wp1++]);
    }

    for(int i = 0; i < 8; i++){
        scanf("%1d", &chain2[wp2++]);
    }

    for(int i = 0; i < 8; i++){
        scanf("%1d", &chain3[wp3++]);
    }

    for(int i = 0; i < 8; i++){
        scanf("%1d", &chain4[wp4++]);
    }

    scanf("%d", &K);

    for(int i = 0; i < K; i++)
        scanf("%d %d", &method[i].num, &method[i].d);

}

void move1(int pos){
    if(pos == 1){
        chain1[wp1++] = chain1[wp1-1];

        for(int i = 0; i < 7; i++)
            chain1[wp1++] = chain1[rp1++];
        rp1++;
    }
    else if(pos == -1){
        for(int i = 1; i < 8; i++)
            chain1[wp1++] = chain1[rp1+i];
        
        chain1[wp1++] = chain1[rp1];
        rp1 += 8;
    }
    else    
        return;
}

void move2(int pos){
    if(pos == 1){
        chain2[wp2++] = chain2[wp2-1];

        for(int i = 0; i < 7; i++)
            chain2[wp2++] = chain2[rp2++];
        rp2++;
    }
    else if(pos == -1){
        for(int i = 1; i < 8; i++)
            chain2[wp2++] = chain2[rp2+i];
        
        chain2[wp2++] = chain2[rp2];
        rp2 += 8;
    }
    else    
        return;
}

void move3(int pos){
    if(pos == 1){
        chain3[wp3++] = chain3[wp3-1];

        for(int i = 0; i < 7; i++)
            chain3[wp3++] = chain3[rp3++];
        rp3++;
    }
    else if(pos == -1){
        for(int i = 1; i < 8; i++)
            chain3[wp3++] = chain3[rp3+i];
        
        chain3[wp3++] = chain3[rp3];
        rp3 += 8;
    }
    else    
        return;
}

void move4(int pos){
    if(pos == 1){
        chain4[wp4++] = chain4[wp4-1];

        for(int i = 0; i < 7; i++)
            chain4[wp4++] = chain4[rp4++];
        rp4++;
    }
    else if(pos == -1){
        for(int i = 1; i < 8; i++)
            chain4[wp4++] = chain4[rp4+i];
        
        chain4[wp4++] = chain4[rp4];
        rp4 += 8;
    }
    else    
        return;
}

void output(int arr[MAX], int rp){
    for(int i = rp; i < rp + 8; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void moveChain(int num, int pos){
    int adPolar1_2 = chain1[rp1 + 2];
    int adPolar2_1 = chain2[rp2 + 6];
    int adPolar2_3 = chain2[rp2 + 2];
    int adPolar3_2 = chain3[rp3 + 6];
    int adPolar3_4 = chain3[rp3 + 2];
    int adPolar4_3 = chain4[rp4 + 6];

    int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;

    if(num == 1){
        pos1 = pos;
        pos2 = adPolar1_2 == adPolar2_1 ? 0 : (-1)*pos1;
        pos3 = adPolar2_3 == adPolar3_2 ? 0 : (-1)*pos2;
        pos4 = adPolar3_4 == adPolar4_3 ? 0 : (-1)*pos3;
    }
    else if(num == 2){
        pos2 = pos;
        pos1 = adPolar1_2 == adPolar2_1 ? 0 : (-1)*pos2;
        pos3 = adPolar2_3 == adPolar3_2 ? 0 : (-1)*pos2;
        pos4 = adPolar3_4 == adPolar4_3 ? 0 : (-1)*pos3;
    }
    else if(num == 3){
        pos3 = pos;
        pos2 = adPolar2_3 == adPolar3_2 ? 0 : (-1)*pos3;
        pos1 = adPolar1_2 == adPolar2_1 ? 0 : (-1)*pos2;
        pos4 = adPolar3_4 == adPolar4_3 ? 0 : (-1)*pos3;
    }
    else{
        pos4 = pos;
        pos3 = adPolar3_4 == adPolar4_3 ? 0 : (-1)*pos4;
        pos2 = adPolar2_3 == adPolar3_2 ? 0 : (-1)*pos3;
        pos1 = adPolar1_2 == adPolar2_1 ? 0 : (-1)*pos2;
    }

    move1(pos1);
    move2(pos2);
    move3(pos3);
    move4(pos4);
}

void solution(){
    for(int i = 0; i < K; i++){
        int chainNum = method[i].num;
        int chainPos = method[i].d;

        moveChain(chainNum, chainPos);
    }

    ANSWER = (chain1[rp1] + chain2[rp2]*2 + chain3[rp3]*4 + chain4[rp4]*8);
}

int main(){
    input();
    solution();
    printf("%d", ANSWER);
}
