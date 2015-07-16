/*

VC, GCC에서 사용

*/

#include <stdio.h>

void resolve(){
	//printf("Resolve Start!!\n");
	int n;
	scanf("%d", &n);
	//printf("n = %d\n", n);

	int P[14] = { 0, };
	P[1] = 0;
	P[2] = 1;
	for (int i = 3; i <= 12; i++){
		P[i] = (i - 1) * (P[i - 1] + P[i - 2]);
		//printf("P[%d] = %d\n", i, P[i]);
	}
	printf("%d\n", P[n]);
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
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}