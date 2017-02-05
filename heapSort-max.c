#include<stdio.h>

void swap( int *a, int *b){

	int t = *a;
	*a = *b;
	*b = t;
}

void printAr( int ar[], int s){

	for(int i=0; i<s; i++)
		printf("%d\t", ar[i]);
	printf("\n");
}

void maxHeapify( int ar[], int i, int s){

	int m = i;
	int l = ( i*2) +1;
	int r = ( i*2) +2;

	if( l< s && ar[l] > ar[m])
		m = l;
	if( r< s && ar[r] > ar[m])
		m = r;

	if( m!= i){
	
		swap( &ar[m], &ar[i]);
			maxHeapify(ar, m, s);
	}
}

void createMaxHeap( int ar[], int s){
	
	for( int i=( ( s-1)/2); i>= 0; i--)
		maxHeapify(ar, i, s);
}

void heapSort( int ar[], int s){

	for( int i=s-1; i>= 0; i--){

		swap( &ar[0], &ar[i]);
		maxHeapify( ar, 0, i);
	}	
} 

int main(){

	int s, i;

	printf("Enter size of binary tree:\t");
	scanf("%d", &s);

	int ar[s];

	for( i=0; i<s; i++){
		printf("Enter data:\t");
		scanf("%d", &ar[i]);
	}

	printf("\nInput tree-> ");
	printAr( ar, s);

	printf("\nMax-heap binary tree-> ");
	createMaxHeap( ar, s);
	printAr( ar, s);

	printf("\nMax-heap sorted binary tree-> ");
	heapSort( ar, s);
	printAr( ar, s);
}