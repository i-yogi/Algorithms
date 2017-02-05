#include<stdio.h>

void swap( int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void display( int ar[], int s){
	printf("\n");
	for( int i=0; i< s; i++)
		printf(" %d ", ar[i]);
	printf("\n");
}

void selectionSort( int ar[], int s){
	int i, j, min;
	for( i=0; i< s-1; i++){
		min = i;
		for( j=i+1; j< s; j++){
			if( ar[j] < ar[min])
				min = j;
		}
		swap( &ar[i], &ar[min]);
	}
}

void bubbleSort( int ar[], int s){
	int i, j;
	for( i=0; i< s-1; i++)
		for( j=0; j< s-1; j++)
			if( ar[j+1]< ar[j])
				swap( &ar[j+1], &ar[j]);
}

void insertionSort( int ar[], int s){
	int i, j, key;
	for( i=1; i<s; i++){
		key = ar[i];
		j = i-1;
		while( j >= 0 && ar[j] > key){
			ar[j+1] = ar[j];
			j--;
		}
		ar[j+1] = key;
	}
}

int partition( int ar[], int l, int h){
	int pivot = ar[h];
	int i, j = l-1;
	for( i=l; i<= h-1; i++){
		if( ar[i] <= pivot){
			j++;
			swap( &ar[i], &ar[j]);
		}
	}
	j++;
	swap( &ar[j], &ar[h]);
	return j;
}

void quickSort( int ar[], int l, int h){
	if( l<h){
		int pivot = partition(ar, l, h);

		quickSort( ar, l, pivot-1);
		quickSort( ar, pivot+1, h);
	}
}

void merge( int ar[], int l, int m, int h){

	int n1 = m-l+1;
	int n2 = h-m;
	int i, j, k = l;

	int la[n1], ra[n2];

	for( i=0; i<n1; i++)
		la[i] = ar[i+l];
	
	for( j=0; j<n2; j++)
		ra[j] = ar[j+m+1];
	
	i = j = 0;
	
	while( i<n1 && j<n2){
		if( la[i]<= ra[j]){
			ar[k] = la[i];
			i++;
		} else{
			ar[k] = ra[j];
			j++;
		}
		k++;
	}

	while( i< n1){
		ar[k] = la[i];
		i++; k++;
	}
	
	while( j< n2){
		ar[k] = ra[j];
		j++; k++;
	}
}

void mergeSort( int ar[], int l, int h){
	if( l<h){
		int m = (l+h)/2;

		mergeSort( ar, l, m);
		mergeSort( ar, m+1, h);

		merge(ar, l, m, h);
	}
}

void heapify( int ar[], int i, int s){
	int p = i;	//p = (p/2)-1;
	int l = (p*2)+1;
	int r = (p*2)+2;

	if( l<s && ar[l]>ar[p])
		p = l;
	if( r<s && ar[r]>ar[p])
		p = r;

	if( p != i){
		swap( &ar[i], &ar[p]);
		heapify(ar, p, s);
	}
}

void heapSort( int ar[], int s){
	int i;
	for( i = (s/2)-1; i>=0; i--)
		heapify( ar, i, s);

	for( i=s-1; i>=0; i--){
		swap( &ar[0], &ar[i]);
		heapify(ar, 0, i);
	}
}

int main(){
	int ar[] = { 6, 12, 1, 54, 4, 9, 7};
	
	display( ar, 7);

	//selectionSort( ar, 7);
	//bubbleSort( ar, 7);
	//insertionSort( ar, 7);
	//quickSort( ar, 0, 6);
	//mergeSort( ar, 0, 6);
	heapSort( ar, 7);

	display( ar, 7);

	return 1;
}