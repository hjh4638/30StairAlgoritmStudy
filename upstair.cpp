#include <stdio.h>

int RESULT = 0;

void divideAndConquer(int n, int k){

	if(k == n){
		RESULT++;
		return;
	}
	else if(k>n){
		return;
	}

	divideAndConquer(n, k+1);
	divideAndConquer(n, k+2);
}

int main(){
	//printf("Start!!\n");
	int N;
	scanf("%d", &N);
	//printf("Stair N = %d\n", N);

	divideAndConquer(N, 0);
	printf("%d\n",RESULT);
	return 0;
}
