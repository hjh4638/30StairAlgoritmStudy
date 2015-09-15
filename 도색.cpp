#define Sol 1
#if Sol
#include <stdio.h>

int vertex_size;
int adjArr[16][16] = { 0, };
int adjVal[16] = { 0, };
int count = 0;

// 전역변수 초기화
void init()
{
	for (int i1 = 0; i1 < 16; i1++){
		for (int i2 = 0; i2 < 16; i2++){
			adjArr[i1][i2] = 0;
		}
		adjVal[i1] = 0;
	}
	count = 0;
	vertex_size = 0;
}
// 1 1
void back(int depth, int color)
{
	// 연결되있는거 제한하는 연산
	adjVal[depth] = color;

	// promising()
	for (int parent = 1; parent < depth; parent++)
	{
		// 현재와 부모가 연결되고 부모와 현재의 값이 같은지 체크
		if (adjArr[depth][parent] == 1 && adjVal[parent] == adjVal[depth]){
			adjVal[depth] = 0;
			return;
		}
	}
	if (depth == vertex_size){
		count++;
		return;
	}
	for (int colorNum = 1; colorNum <= 4; colorNum++)
	{
		back(depth + 1, colorNum);
	}
	adjVal[depth] = 0;
}


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);
		scanf("%d", &vertex_size);

		// 입력받는부분
		for (int i1 = 1; i1 <= vertex_size; i1++)
			for (int i2 = 1; i2 <= vertex_size; i2++)
				scanf("%d", &adjArr[i1][i2]);
		
		// 실제 연산
		back(1, 1);
		back(1, 2);
		back(1, 3);
		back(1, 4);

		// 답 출력
		printf("%d\n", count);
		init();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
#endif
