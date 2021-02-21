#include <stdio.h>
#include <stdlib.h>




int main(){

	//1차 서류심사
	//2차 면접시험
	//서류심사 성적과 면접 시험 성적 중 적어도 하나가 다른 지원보다 떨어지지 않는 자만 선발
	int T;

	scanf("%d",&T); //테스트 케이스의 개수(1 <= T <= 20)

	while(T){
		int **data;
		int i,j;
		int N;

		scanf("%d",&N);

		//START : Init Data Array
		data = (int**)malloc(sizeof(int*)*N);
		for(i=0; i<N; i++)
			data[i] = (int*)malloc(sizeof(int)*2);
		
		for(i=0; i<N; i++)
			for(j=0; j<2; j++)
				data[i][j] = 0;
		//END : Init Data Array

		for(i=0; i<N; i++)
			scanf("%d %d",data[i][0], data[i][1]);
		
		//START : deInit Data Array
		for(i=0; i<N; i++)
			free(data[i]);
		free(data);
		//END : deInit Data Array
		
		T--;
	}

	return 0;
}
