#include <stdio.h>
#include <stdlib.h>

void merge(int** A, int** sorted, int left, int mid, int right)
{
	int i,j,k,l;
	
	k = left;

	i = left;
	j = mid + 1;

	while(i <= mid && j <= right){
		if(A[i][0] > A[j][0])
		{
			sorted[k][0] = A[j][0];
			sorted[k++][1] = A[j++][1];
		} else {
			sorted[k][0] = A[i][0];
			sorted[k++][1] = A[i++][1];
		}
	}

	if(i > mid){
		for(l=j; l<=right; l++)
		{
			sorted[k][0] = A[l][0];
			sorted[k++][1] = A[l][1];
		}
	}
	else {
		for(l=i; l<=mid; l++)
		{
			sorted[k][0] = A[l][0];
			sorted[k++][1] = A[l][1];
		}
	}

	for(i=left; i<= right; i++)
	{
		A[i][0] = sorted[i][0];
		A[i][1] = sorted[i][1];
	}
}

void merge_sort(int** A, int** sorted, int left, int right)
{
	int mid;

	if(left < right){
		mid = (left + right) / 2;
		merge_sort(A, sorted, left, mid);
		merge_sort(A, sorted, mid+1, right);
		merge(A, sorted, left, mid, right);
	}
}

int main(){

	//1차 서류심사
	//2차 면접시험
	//서류심사 성적과 면접 시험 성적 중 적어도 하나가 다른 지원보다 떨어지지 않는 자만 선발
	int T;

	scanf("%d",&T); //테스트 케이스의 개수(1 <= T <= 20)

	while(T){
		int **data;
		int **sorted;
		int i,j;
		int N;
		int result;
		int RankInterview;

		scanf("%d",&N);

		//START : Init Data Array
		data = (int**)malloc(sizeof(int*)*N);
		sorted = (int**)malloc(sizeof(int*)*N);
		for(i=0; i<N; i++){
			data[i] = (int*)malloc(sizeof(int)*2);
			sorted[i] = (int*)malloc(sizeof(int)*2);
		}
		
		for(i=0; i<N; i++)
			for(j=0; j<2; j++){
				data[i][j] = 0;
				sorted[i][j] = 0;
			}
		//END : Init Data Array

		//START : Input Data
		for(i=0; i<N; i++)
			scanf("%d %d",&data[i][0], &data[i][1]);
		//END : Input Data

		merge_sort(data, 0, N-1);

// TEST CODE
//		for(i=0; i<N; i++)
//			printf("%d %d\n",data[i][0], data[i][1]);

		result = 1;
		RankInterview = data[0][1];

		for(i=0; i<N; i++)
		{
			if(data[i][1] < RankInterview)
			{
				result++;
				RankInterview = data[i][1];
			}
		}

		printf("%d\n",result);
		
		//START : deInit Data Array
		for(i=0; i<N; i++){
			free(data[i]);
			free(sorted[i]);
		}
		free(data);
		free(sorted);
		//END : deInit Data Array
		
		T--;
	}

	return 0;
}
