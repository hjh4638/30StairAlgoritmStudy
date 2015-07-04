#include <stdio.h>

void printTable(int table[101][101], int v_size){
	for(int i=1;i<=v_size;i++){
		for(int j=0;j<=v_size;j++){
			//printf("%d ", table[i][j]);
		}
		//printf("\n");
	}
	//printf("\n\n");
}

int Table[101][101]={0,};
int v_size;

void dfs(int start){
	for(int i=1;i<=v_size;i++){
		if(Table[start][i] == 1){
			Table[start][i] = 0;
			Table[i][start] = 0;
			dfs(i);
		}
	}
	printf("%d ", start);
}

int main(){
	int e_size;
	scanf("%d %d", &v_size, &e_size);
	//printf("vertex = %d edge = %d\n\n", v_size, e_size);

	for(int i=1;i<=e_size;i++){
		int i1,i2;
		scanf("%d %d", &i1, &i2);
		//printf("edge create : i1 = %d, i2 = %d\n", i1, i2);
		Table[i1][i2] = 1;
		Table[i2][i1] = 1;
		Table[i1][0]++;
		Table[i2][0]++;
	}
	//printf("\n Table is\n");
	printTable(Table, v_size);

	int flag= 0;
	int odd = 0;
	for(int i=1;i<=v_size;i++){
		if(Table[i][0]%2 !=0){
			flag = 1;
			odd++;
		}
	}
	//printf("flag = %d , odd = %d\n",flag,odd);
	if(flag && odd != 2){
		//printf("odd edge count is not 2\n");
		printf("0\n");
		return 0;
	}

	int startv;
	for(int i=1;i<=v_size;i++){
		if(odd == 2 && Table[i][0]%2 != 0){
			//printf("odd version, startv = %d\n", i);
			startv = i;
		}
		else if(odd !=2 && Table[i][0] %2 == 0){
			//printf("even version, startv = %d\n", i);
			startv = i;
		}
	}
	//printf("startv = %d\n",startv);
	dfs(startv);
	return 0;
}
