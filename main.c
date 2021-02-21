#include <stdio.h>
#include <stdlib.h>

int partition(int** A, int left, int right)
{
	int low, high;
	int pivot;
	int temp_doc;
	int temp_inter;

	low = left;
	high = right+1;
	pivot = A[left][0];

	do{
		do{
			low++;
		}while(low <= right && A[low][0] < pivot);

		do{
			high--;
		} while(high >= left && A[high][0] > pivot);

		if(low < high) {
			temp_doc = A[low][0];
			temp_inter = A[low][1];

			A[low][0] = A[high][0];
			A[low][1] = A[high][1];

			A[high][0] = temp_doc;
			A[high][1] = temp_inter;
		}

	} while(low < high);

		temp_doc = A[left][0];
		temp_inter = A[left][1];
		
		A[left][0] = A[high][0];
		A[left][1] = A[high][1];

		A[high][0] = temp_doc;
		A[high][1] = temp_inter;

		return high;
}

void quick_sort(int** A, int left, int right)
{
	int q;

	if(left < right){
		q = partition(A,left,right);
		quick_sort(A,left,q-1);
		quick_sort(A,q+1,right);
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
		int i,j;
		int N;
		int result;
		int RankInterview;

		scanf("%d",&N);

		//START : Init Data Array
		data = (int**)malloc(sizeof(int*)*N);
		for(i=0; i<N; i++)
			data[i] = (int*)malloc(sizeof(int)*2);
		
		for(i=0; i<N; i++)
			for(j=0; j<2; j++)
				data[i][j] = 0;
		//END : Init Data Array

		//START : Input Data
		for(i=0; i<N; i++)
			scanf("%d %d",&data[i][0], &data[i][1]);
		//END : Input Data

		quick_sort(data, 0, N-1);

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


/* TEST CODE
		for(i=0; i<N; i++)
			printf("%d %d\n",data[i][0], data[i][1]);
*/

		printf("%d\n",result);
		
		//START : deInit Data Array
		for(i=0; i<N; i++)
			free(data[i]);
		free(data);
		//END : deInit Data Array
		
		T--;
	}

	return 0;
}
