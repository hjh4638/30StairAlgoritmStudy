/*

VC, GCC���� ���

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
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);
		resolve();
		
		
		n = 0;
		count = 0;
		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}