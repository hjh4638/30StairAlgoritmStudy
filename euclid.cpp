#include <stdio.h>

int getQ(int r, int v1, int v2){
	if(r == 0){
		return v2;
	}
	//printf("r = %d, v1 = %d, v2 = %d\n", r, v1, v2);
	return getQ(v2%r, v2, r);
}

int main(){
	//printf("Start!!\n");
	int n1, n2;
	scanf("%d %d", &n1, &n2);

	if(n1<n2){
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}

	//printf("n1 = %d, n2 = %d\n", n1, n2);

	int q = getQ(n1%n2,n1,n2);
	printf("%d %d",q, n1/q*n2 );
	return 0;
}
