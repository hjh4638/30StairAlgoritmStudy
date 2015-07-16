#include <stdio.h>

int isAscend(int arr[10], int size){
	int flag = 1;
	for (int i = 1; i < size; i++){
		if (arr[i] > arr[i + 1]){
			flag = 0;
		}
	}
	return flag;
}
int isDescend(int arr[10], int size){
	int flag = 1;
	for (int i = 1; i < size; i++){
		if (arr[i] < arr[i + 1]){
			flag = 0;
		}
	}
	return flag;
}

int main(){
	int arr[10] = { 0, };
	int size = 8;
	for (int i = 1; i <= size; i++){
		scanf("%d", &arr[i]);
	}
	/*for (int i = 1; i <= size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
*/
	if (isAscend(arr, size)){
		printf("ascending\n");
	}
	else if (isDescend(arr, size)){
		printf("descending\n");
	}
	else{
		printf("mixed\n");
	}


	return 0;
}