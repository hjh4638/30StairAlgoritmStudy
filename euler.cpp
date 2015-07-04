#include <stdio.h>
#define MAIN 0
#define TEXT 1
typedef struct _node{
	_node* next;
	int data;
}node;

node* getLast(node* v){
	node* index = v;
	while( index->next !=0){
		index = index->next;
	}
	return index;
}
void printNode(node* n){
	node* index = n;
	printf("%d ", index->data);
	while(index->next !=0){
		index = index->next;
		printf("%d ", index->data);
	}
	printf("\n");
}
int main(){
	int v_size;
	int e_size;
	node* vertex[101];
	scanf("%d %d", &v_size, &e_size);

	for(int i=1;i<=v_size;i++){
		node* v = new node;
		v->data = i;
		v->next = 0;
		vertex[i] = v;
	}
	for(int i=1;i<=v_size;i++){
		printf("%d\n", vertex[i]->data);
	}
#if MAIN
	for(int i=1;i<=e_size;i++){
		int i1, i2;
		node* node;
		scanf("%d %d", &i1, &i2);
		node = getLast(vertex[i1]);
		node->next = vertex[i2];
		node = getLast(vertex[i2]);
		node->next = vertex[i1];
	}
#endif
	
	vertex[1]->next = vertex[2];
	vertex[2]->next = vertex[1];
	for(int i=1;i<=v_size;i++){
		printNode(vertex[i]);
	}
	return 0;
}
