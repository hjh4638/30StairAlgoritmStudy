/*

VC, GCC���� ���

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
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);
		resolve();
		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}