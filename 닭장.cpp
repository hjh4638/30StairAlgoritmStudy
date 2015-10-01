/*

VC, GCC에서 사용

*/

#include <stdio.h>

int ARR[201] = { 0, };
void INIT()
{
	for (int i = 0; i < 201; i++)
	{
		ARR[i] = 0;
	}
}
int getZeroCount(int count, int index)
{
	if (ARR[index] == 1)
	{
		return count-1;
	}
	ARR[index] = -2;
	return getZeroCount(count + 1, index + 1);
}
void getCheck(int index)
{
	if (ARR[index] == 1)
	{
		return;
	}
	ARR[index] = -1;
	return getCheck(index + 1);
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);
		int Pan, Bird, Leave;
		
		int NONEED[201] = { 0, };
		int NOINDEX[201] = { 0, };
		scanf("%d %d %d", &Pan, &Bird, &Leave);

		for (int i = 1; i <= Leave; i++)
		{
			int num;
			scanf("%d", &num);
			ARR[num] = 1;
		}
		int start, end;
		for (int i = 1; i <= Bird; i++)
		{
			if (ARR[i] == 1){
				start = i;
				break;
			}
		}
		for (int i = Bird; i > 0; i--)
		{
			if (ARR[i] == 1){
				end = i;
				break;
			}
		}

		int index = 1;
		for (int i = start; i <= end; i++)
		{
			if (ARR[i] == 0){
				NONEED[index] = getZeroCount(1, i);
				NOINDEX[index] = i;
				index++;
			}
				
		}

		for (int i = 1; i <= 200; i++)
		{
			for (int j = i + 1; j <= 200; j++)
			{
				if (NONEED[i] < NONEED[j])
				{
					int temp = NONEED[i];
					NONEED[i] = NONEED[j];
					NONEED[j] = temp;
					temp = NOINDEX[i];
					NOINDEX[i] = NOINDEX[j];
					NOINDEX[j] = temp;

				}
			}
		}

		for (int i = 1; i <= Pan-1; i++)
		{
			getCheck(NOINDEX[i]);
		}

		int result = 0;
		for (int i = start; i <= end; i++)
		{
			if (ARR[i] != -1){
				result++;
			}
		}
		printf("%d\n", result);
		
		INIT();

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
