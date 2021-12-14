#include <stdio.h>

int swap_count = 0;
int x = 0;
int size;

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int left_child(int i){
	return (2*i+1);
}

int right_child(int i){
	return (2*i+2);
}

void shift_down(int heap[],int i,int a[][2]){
	int min_index = i;
	if ((left_child(i)<size) && (heap[min_index] > heap[left_child(i)])){
		min_index = left_child(i);
	}
	if ((right_child(i) < size) && (heap[min_index] > heap[right_child(i)])){
		min_index = right_child(i);
	}
	if (min_index != i){
		a[x][0] = min_index;
		a[x][1] = i;
		x++;
		swap(&heap[min_index],&heap[i]);
		swap_count++;
		shift_down(heap,min_index,a);
	}
}

void build_heap(int heap[],int a[][2]){
	int i;
	for(i=(size/2)-1;i>=0;i--){
       shift_down(heap,i,a);
	}
}

int main(){
	int i;
	scanf("%d",&size);
	int heap[size];
	int a[size][2];
	for(i=0;i<size;i++){
		scanf("%d",&heap[i]);
	}
	build_heap(heap,a);
	printf("%d\n",swap_count);
	for(i=0;i<x;i++){
		printf("%d %d\n",a[i][1],a[i][0]);
	}
}

