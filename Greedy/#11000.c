#include <stdio.h>
#include <stdlib.h>


int main()
{
    //최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
    int N; // 수업의 개수, 1 <= N <= 200,000
    int **classes; //Si에 시작해서 Ti에 끝나는 수업 1<= S < T <= 10^9
    int i,j;
    int result=0;

    scanf("%d",&N);

    classes = (int **)malloc(sizeof(int*)*N);
    for(i=0; i<N; i++)
        classes[i] = (int*)malloc(sizeof(int*)*2);
    
    for(i=0; i<N; i++)
        for(j=0; j<2; j++)
            classes[i][j] = 0;

    for(i=0; i<N; i++)
        scanf("%d %d",&classes[i][0], &classes[i][1]);


    

    return 0;
}