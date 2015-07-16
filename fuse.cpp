#include <stdio.h>

int main(){
	//printf("test\n");
	int a = 25, b = 20, c = 5;
	int a_size, b_size, c_size;
	int sum = 0;
	scanf("%d %d %d", &a_size, &b_size, &c_size);
	//printf("as = %d, bs = %d, cs = %d\n", a_size, b_size, c_size);
	//printf("a = %d, b = %d, c = %d\n", a, b, c);
	//printf("a*a_size = %d\n", a*a_size + b*b_size + c*c_size);
	
	sum = a*a_size + b*b_size + c*c_size;
	//printf("sum = %d\n",sum);
	
	sum = sum * 2;
	//printf("sum = %d\n", sum);

	if (sum % 100 != 0){
		sum += 100;
	}
	//printf("sum = %d\n", sum);
	sum = sum / 100 * 100;
	//printf("sum = %d\n", sum);

	printf("%d amperes\n", sum/10);
	return 0;
}