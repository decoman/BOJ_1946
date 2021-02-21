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


int main()
{
    //최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
    int N; // 수업의 개수, 1 <= N <= 200,000
    int **classes; //Si에 시작해서 Ti에 끝나는 수업 1 <= S < T <= 10^9
    int **count;
    int i,j;
    int result=0;

    scanf("%d",&N);

    classes = (int **)malloc(sizeof(int*)*(N+1));
    count = (int **)malloc(sizeof(int*)*(N+1));

    for(i=0; i<=N; i++){
        classes[i] = (int*)calloc(2,sizeof(int));
        count[i] = (int*)calloc(2,sizeof(int));
    }
        
    for(i=1; i<=N; i++)
        scanf("%d %d",&classes[i][0], &classes[i][1]);

    merge_sort(classes,count,1,N);

    
  
//   for(i=1; i<=N; i++){
//       printf("%d %d\n",classes[i][0], classes[i][1]);
//    }
    

    return 0;
}