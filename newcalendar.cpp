/*

VC, GCC에서 사용

*/

#include <stdio.h>
long long int getLineNum(long long int period, long long int dayOfMonth, long long int dayOfWeek){
	long long int count = 0;
	long long int position = 0;
	long long int day = 0;
	for (long long int i = 1; i <= period*dayOfMonth; i++){
		position++;
		day++;
		////printf("position = %d, day = %d\n", position, day);

		if (position == dayOfWeek && day == dayOfMonth){
			//printf("condition superposition\n");
			count++;
			position = 0;
			day = 0;
		}
		else if (position == dayOfWeek){
			//printf("position %d == dayOfWeek %d\n", position, dayOfWeek);
			count++;
			position = 0;
		}
		else if (day == dayOfMonth){
			//printf("day %d == dayOfMonth %d\n", day, dayOfMonth);
			count++;
			day = 0;
		}
	}
	return count;
}
long long int getLine(long long int period, long long int dayOfMonth, long long int dayOfWeek){
	long long int count = 0;
	long long int position = 0;
	long long int day = 0;

	long long int A = dayOfMonth;
	for (long long int i = 1; i <= period; i++){
		count += A / dayOfWeek;
		if (A % dayOfWeek != 0){
			count += 1;
		}
		A = dayOfMonth + A % dayOfWeek;
	}
	return count;
}
void resolve(){
	//printf("Start!\n");
	long long int monthSize, dayOfMonth, dayOfWeek;
	scanf("%lld %lld %lld", &monthSize, &dayOfMonth, &dayOfWeek);
	//printf("month size = %lld, dayOfMonth = %lld, dayOfWeek = %lld\n", monthSize, dayOfMonth, dayOfWeek);

	long long int period = dayOfWeek;

	long long int count = getLine(period, dayOfMonth, dayOfWeek);
	count = count * (monthSize / period) + getLine(monthSize%period, dayOfMonth, dayOfWeek);
	
	printf("%lld\n", count);
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