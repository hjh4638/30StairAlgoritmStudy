#include <stdio.h>

int recur(int G, int E){
	if(E == 1){
		return G;
	}

	return recur(G, E-1) * G;
}

int main(){
	//printf("Start!!\n");
	int G, E;
	scanf("%d %d", &G, &E);
	//printf("Gisu = %d, E = %d\n", G, E);


	printf("%d\n", recur(G, E));

	return 0;
}
