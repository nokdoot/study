#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 101

void sort(int list[], int n);
void swap(int *a, int *b);
void print(int list[], int n);

int main(){
	int i, n;
	int list[MAXSIZE];
	printf("배열의 최대 크기 : %d\n배열의 크기 입력...\n", MAXSIZE);
	scanf("%d", &n);
	if(n > MAXSIZE || n < 1){
		fprintf(stderr, "error\n");
		exit(1);
	}

	for(i = 0; i < n; i++){
		list[i] = rand() % n;
		printf("%d ", list[i]);
		if(i % 100 == 0 && i != 0){
			printf("\n");
		}
	}
	printf("\n\n");
	sort(list, n);
}

void sort(int list[], int n){
	int i, j, min;
	for(i = 0; i<n-1; i++){
		min = i;
		for(j = i+1; j < n; j++){
			if(list[j] < list[min]){
				min = j;
			}
		}
		swap(&list[min], &list[i]);
	}

	print(list, n);
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int list[], int n){
	int i;
	for(i = 0; i<n; i++){
		printf("%d ", list[i]);
		if(i % 100 == 0 && i != 0){
			printf("\n");
		}
	}
}
