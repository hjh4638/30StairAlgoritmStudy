#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

int SUM1[1000001] = { 0, };
int SUM2[1000001] = { 0, };
int K, N;
int TABLE[5][1001] = { 0, };

int binary_search(int value, int low, int high){
	if (high < low){
		if (abs(value - SUM2[high]) > abs(value - SUM2[low])){
			return SUM2[low];
		}
		else
			return SUM2[high];
	}
	int mid = (low + high) / 2;
	//printf("data = %d\n", SUM2[mid]);
	if (SUM2[mid] > value){
		return binary_search(value, low, mid-1);
	}
	else if (SUM2[mid] < value){
		return binary_search(value, mid + 1, high);
	}
	else
		return SUM2[mid];
}

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}




void q_sort(int numbers[], int left, int right)
{
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = numbers[left]; // 0번째 원소를 피봇으로 선택
	while (left < right)
	{
		// 값이 선택한 피봇과 같거나 크다면, 이동할 필요가 없다
		while ((numbers[right] >= pivot) && (left < right))
			right--;

		// 그렇지 않고 값이 피봇보다 작다면,
		// 피봇의 위치에 현재 값을 넣는다.
		if (left != right)
		{
			numbers[left] = numbers[right];
		}
		// 왼쪽부터 현재 위치까지 값을 읽어들이면서
		// 피봇보다 큰 값이 있다면, 값을 이동한다.
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	// 모든 스캔이 끝났다면, 피봇값을 현재 위치에 입력한다.
	// 이제 피봇을 기준으로 왼쪽에는 피봇보다 작거나 같은 값만 남았다.
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;

	// 재귀호출을 수행한다.
	if (left < pivot)
		q_sort(numbers, left, pivot - 1);
	if (right > pivot)
		q_sort(numbers, pivot + 1, right);
}

void quickSort(int numbers[], int array_size)
{
	q_sort(numbers, 0, array_size - 1);
}



void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}


int main()
{


	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);

		LARGE_INTEGER liCounter1, liCounter2, liFrequency;

		QueryPerformanceFrequency(&liFrequency);  // retrieves the frequency of the high-resolution performance counter    
		QueryPerformanceCounter(&liCounter1);         // Start


		scanf("%d %d", &K, &N);
		for (int i = 1; i <= 4; i++){
			for (int j = 1; j <= N; j++){
				scanf("%d", &TABLE[i][j]);
			}
		}

		int index1 = 1, index2 = 1;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				SUM1[index1++] = TABLE[1][i] + TABLE[2][j];
			}
		}

		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				SUM2[index2++] = TABLE[3][i] + TABLE[4][j];
			}
		}


		
		

		//quickSort(SUM1, index1);
		//quickSort(SUM2, index2);
		
		//bubble_sort(SUM1, index1);
		//bubble_sort(SUM2, index2);
		qsort(SUM1, index1, sizeof(int), compare);
		qsort(SUM2, index2, sizeof(int), compare);


		
		/*for (int i = 1; i < index1; i++){
			for (int j = i + 1; j < index1; j++){
				if (SUM1[i] > SUM1[j]){
					int temp = SUM1[i];
					SUM1[i] = SUM1[j];
					SUM1[j] = temp;
				}
			}
		}
		for (int i = 1; i < index2; i++){
			for (int j = i + 1; j < index2; j++){
				if (SUM2[i] > SUM2[j]){
					int temp = SUM2[i];
					SUM2[i] = SUM2[j];
					SUM2[j] = temp;
				}
			}
		}*/
		int size1 = index1 - 1;
		int size2 = index2 - 1;

		int answer = -999999;
		for (int i = 1; i <= size1; i++){
			int as = SUM1[i] + binary_search(K - SUM1[i], 1, size2);
			//printf("data = %d\n", as);
			if (abs(K - answer) > abs(K - as)){
				answer = as;
			}

		}



		printf("%d\n",answer);

		QueryPerformanceCounter(&liCounter2);         // End

		printf("Time : %f\n", (double)(liCounter2.QuadPart - liCounter1.QuadPart) / (double)liFrequency.QuadPart);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
