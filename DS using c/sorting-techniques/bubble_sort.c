#include<stdio.h>
int i,j;
int temp;
void display(int a[],int n){
	for( i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n\n");
}

void swap(int *x,int *y){
    temp=*x;
	*x=*y;
	*y=temp;
}

void bubble_sort(int a[],int n){
	for( i=0;i<n-1;i++){
		for( j=i+1;j<n;j++){
			if(a[i]>a[j])
			swap(&a[i],&a[j]);
		}
	}
	printf("After sorting elements of array are: ");
	display(a,n);
}

void intialize(int n){
	int a[n];
	for( i=0;i<n;i++){
		printf("Enter element-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	system("cls");
	printf("Before sorting elements of array are: ");
	display(a,n);
	bubble_sort(a,n);
}

int main(){
	int n;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	printf("\n");
	intialize(n);
	return 0;
}
