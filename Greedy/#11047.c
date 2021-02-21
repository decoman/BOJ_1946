#include <stdio.h>
#include <stdlib.h>


int main(){
    int N,K; //N: 동전의 종류, K: 만드려는 가치의 합
    int *coin;
    int i;

    scanf("%d %d",&N, &K);

    coin = (int*)calloc(N,sizeof(int));

    for(i=0; i<N; i++)
        scanf("%d",&coin[i]);

    for(i=0; i<N; i++)
        printf("%d\n",coin[i]);



    return 0;
}