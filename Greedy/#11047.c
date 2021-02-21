#include <stdio.h>
#include <stdlib.h>


int main(){
    int N,K; //N: 동전의 종류 (1 <= N <= 10)
             //K: 만드려는 가치의 합 (1 <= K <= 100,000,000), A[0] = 1, index가 2 이상인 경우 이전 값의 배수
    int *coin;
    int i,r;
    int count = 0;

    scanf("%d %d",&N, &K);

    coin = (int*)calloc(N,sizeof(int));

    for(i=0; i<N; i++)
        scanf("%d",&coin[i]);

    while(K != 0 && N > 0)
    {
        if(coin[N-1] <= K)
        {
            count += K/coin[N-1];
            K %= coin[N-1];
        }
        N--;
    }

    printf("%d",count);

    return 0;
}