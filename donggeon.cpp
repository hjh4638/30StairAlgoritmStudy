/*

VC, GCC���� ���

*/

#include <stdio.h>

void resolve(){
	//printf("resolve Start!\n");
	int N;
	int P[150003] = { 0, };
	scanf("%d", &N);
	//printf("N = %d\n", N);

	int num = -1;
	int index = 1;
	for (int i = 1; i <= N; i++){
		scanf("%d", &num);
		//printf("num = %d, P[%d] = %d\n", num, index-1,P[index - 1]);
		if (num != P[index - 1]){
			P[index] = num;
			//printf("P[%d] = %d\n", index, P[index]);
			index++;
			
		}
	}

	int SUM = 0;
	for (int i = 1; i <= N; i++){
		if (P[i - 1] < P[i] && P[i + 1] < P[i]){
			SUM += P[i];
		}
		else if (P[i - 1] >P[i] && P[i + 1] > P[i]){
			SUM -= P[i];
		}


	}
	printf("%d\n", SUM);

	
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