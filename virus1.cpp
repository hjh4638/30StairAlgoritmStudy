#include <stdio.h>
#define ARR_SIZE 1000
class Queue{
	public:
		int arr[ARR_SIZE];
		int head;
		int tail;
		int size;
		Queue(){
			head = 0;
			tail = 0;
			size = 0;
		}
		void enqueue(int n){
			size++;
			if(size > ARR_SIZE){
				//printf("size overflow\n");
				return;
			}
			arr[tail++] = n;
		}
		int dequeue(){
			size--;
			if(size<0){
				size=0;
				//printf("dequeue error\n");
				return -1;
			}
			int result = arr[head++];
			return result;
		}

};

void pTable(int table[101][101], int size){
	for(int i=1;i<=size;i++){
		for(int j=1; j<=size;j++){
			//printf("%d ", table[i][j]);
		}
		//printf("\n");
	}
}

int main(){
	int com_size;
	int conn_size;
	int table[101][101] = {0,};
	int* P_table = new int[com_size+1];
	Queue queue;

	scanf("%d %d", &com_size, &conn_size);

	for(int i=0; i<conn_size;i++){
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		table[c1][c2] = 1;
		table[c2][c1] = 1;
	}

	P_table[1] = 1;
	int check = 1;
	int count = 0;
	while(1){
		for(int j=1;j<=com_size;j++){
			if(table[check][j] == 1 && P_table[j] != 1){
				queue.enqueue(j);
				P_table[j] = 1;
			}
		}
		check = queue.dequeue();
		//printf("size = %d\n check = %d \n",queue.size, check);
		if(check == -1){
			break;
		}
		
		count++;
	}
	//printf("answer is %d\n", count);
	printf("%d\n", count);
	return 0;
}
