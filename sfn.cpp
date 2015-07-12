#include <stdio.h>

int SUM = 0;
void getDigitSum(int num, int degree){
	if(num == 0){
		return;
	}
	SUM += num % degree;
	getDigitSum(num/degree, degree);
}
int main(){
	//printf("Start!!\n");
	
	int ten;
	int twelve;
	int sixteen;

	for(int i=2992;i<10000;i++){
		getDigitSum(i, 10);
		ten = SUM;
		SUM = 0;
		getDigitSum(i, 12);
		twelve = SUM;
		SUM = 0;
		getDigitSum(i, 16);
		sixteen = SUM;
		SUM = 0;

		if(ten == twelve && twelve == sixteen){
			printf("%d\n", i);
		}
	}

	return 0;
}
