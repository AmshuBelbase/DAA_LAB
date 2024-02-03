#include<stdio.h>
void merge(int arr[], int low, int mid, int high){
	int b[high-low+1];
	int k = low, i =low, j=mid+1;
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			b[k-low] = arr[i];
			i++;
		}
		else{
			b[k-low] = arr[j];
			j++;
		}
		k++;
	}
	if(j>high){
		while(i<=mid){
			b[k-low] = arr[i];
			i++;
			k++;
		}
	}
	else{
		while(j<=high){
			b[k-low] = arr[j];
			j++;
			k++;
		}
	}
	for(i=low;i<=high;i++){ 
		arr[i] = b[i-low];
	}
// UNCOMMENT TO VIEW HOW ARRAY IS SORTED AND MERGED
//	printf("\n");
//	for(i=low;i<=high;i++){
//		printf("%d ", arr[i]);
//	}
}
void merge_sort(int arr[], int low, int high){
	int mid = ((high-low)/2)+low;
	if(low!=high){
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
	}
// UNCOMMENT TO VIEW HOW ARRAY IS SPLITTED
//	int i;
//	printf("\n");
//	for(i=low;i<=high;i++){
//		printf("%d ", arr[i]);
//	}
	merge(arr, low, mid, high);
}
void print_arr(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}
int main(){
	int i,n;
	printf("Enter array size :");
	scanf("%d", &n);
	if(n>0){
		int arr[n];
		for(i =0; i<n; i++){
			printf("Enter element at %d: ", i);
			scanf("%d", &arr[i]);
		}
		merge_sort(arr, 0, n-1);
		print_arr(arr, n);
	}
	return 0;
}
