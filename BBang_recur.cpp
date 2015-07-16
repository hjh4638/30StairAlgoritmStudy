/*

VC, GCC에서 사용

*/

#include <stdio.h>

int n;
int count;

void printArr(int arr[13], int size){
	for (int i = 1; i <= size; i++){
		//printf("%d ", arr[i]);
	}
	//printf("\n\n");
}
void arrCpy(int* src, int* desc, int size){
	for (int i = 1; i <= size; i++){
		desc[i] = src[i];
	}

}
void recur(int Arr[13], int size, int depth){
	
	for (int i = 1; i <= size; i++){
		if (Arr[i] != depth && Arr[i] != 0){
			if (depth == n){
				count++;
			}
			//printf("depth = %d\n", depth);
			//printf("push %d\n\n", i);
			int temp[13];
			arrCpy(Arr, temp, 13);
			temp[i] = 0;
		/*	//printf("push Arr\n");
			printArr(temp, n);*/
			recur(temp, size, depth + 1);
		}
	}

}

void resolve(){
	
	scanf("%d", &n);
	//printf("n = %d\n", n);
	int Arr[13];
	for (int i = 1; i <= n; i++){
		Arr[i] = i;
	}
	printArr(Arr, n);
	recur(Arr, n, 1);
	printf("%d\n", count);

}


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);
		resolve();
		
		
		n = 0;
		count = 0;
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}