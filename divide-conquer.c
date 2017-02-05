#include<stdio.h>
#include<stdlib.h>

void printfMenu(){

	printf("\nChoose sorting algorithm:");
	printf("\n1. Display Array");
	printf("\n2. Quick Sort");
	printf("\n3. Merge Sort");
	printf("\n0. Exit");
	printf("\n\nEnter choice: \t");
}

void displayArray(int ar[], int s){

	printf("\n");
	for(int i=0; i<s; i++){
		printf("%d\t|", ar[i]);
	}
}

void swap(int *a, int *b){
	// printf("\naP is %d and bP is %d", *a, *b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int ar[], int l, int r){

	int i = l-1;
	int pivot = ar[r];

	for(int j = l; j<= r-1; j++){
		if(ar[j]<= pivot){
			i++;
			swap(&ar[i], &ar[j]);
		}
	}
	i++;
	swap(&ar[i], &ar[r]);
	return i;
}

void quickSort(int ar[], int l, int r){

	// printf("\nlow- %d, high- %d", l, r);
	if(l<r){
		int pivot = partition(ar, l, r);

		quickSort(ar, l, pivot-1);
		quickSort(ar, pivot+1, r);
	}
}

void merge(int a[], int lt, int m, int rt){

	int i=0, j=0, k=0;

	int n1 = m-lt+1;
	int n2 = rt-m;
	int l[n1], r[n2];

	for(i=0; i<n1; i++)
		l[i] = a[lt+i];
	for(j=0; j<n2; j++)
		r[j] = a[m+j+1];

	i = j = 0; k = lt;

	while(i<n1 && j<n2){

		if(l[i] <= r[j]){
			a[k] = l[i];
			i++; k++;
		} else {
			a[k] = r[j];
			j++; k++;
		}
	}

	while(i<n1){
		a[k] = l[i];
		i++; k++;
	}

	while(j<n2){
		a[k] = r[j];
		j++; k++;
	}
}

void mergeSort(int a[], int l, int r){

	if(l<r){

		int m = (l+r)/2;

		mergeSort(a, l, m);
		mergeSort(a, m+1, r);

		merge(a, l, m, r);
	}
}

int main(){

	int s, ch;

	int a = 10, b = 20;

	printf("\nCreate an Array \nEnter array size: \t");
	scanf("%d", & s);

	int ar[s];

	for(int i=0; i<s; i++){

		printf("\n Enter element [%d]: \t", i+1);
		scanf("%d", &ar[i]);
	}

	do{
		printfMenu();
		scanf("%d", &ch);

		switch(ch){
			case 0:
				printf("\nQuiting Program...\n");
				break;

			case 1:
				displayArray(ar, s);
				break;

			case 2:
				quickSort(ar, 0, s-1);
				break;

			case 3:
				mergeSort(ar, 0, s-1);
				break;

			case 4:
				printf("\nBEFORE aP is %d and bP is %d", a, b);
				swap(&a, &b);
				printf("\nAFTER aP is %d and bP is %d", a, b);
				break;
		}

	} while( ch != 0);

	return 0;
}