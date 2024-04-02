#include<stdio.h>
int get_cross(int arr[], int low, int mid, int high){
	int leftsum = 0, rightsum = 0, leftmax = arr[mid], rightmax = arr[mid+1], i;
	for(i = mid; i>=low; i--){
		leftsum += arr[i]; 
		leftmax = (leftsum>=leftmax)?leftsum:leftmax;
	}
	for(i = mid+1; i<=high; i++){
		rightsum += arr[i]; 
		rightmax = (rightsum>=rightmax)?rightsum:rightmax;
	}
	return (leftmax+rightmax);
}
int divideArray(int arr[], int low, int high){ 
	int leftsum, rightsum, mid = (low+high)/2;
	if(low!=high){
		leftsum = divideArray(arr, low, mid);
		rightsum = divideArray(arr, mid+1, high);
	}else{
		return arr[low];
	}
	int crosssum = get_cross(arr, low, mid, high);
	return (leftsum>rightsum)?((leftsum>crosssum)?leftsum:crosssum):((rightsum>crosssum)?rightsum:crosssum);
}
void main(){
	int arr[] = {1,5,-3,7,-9,1,5,-4,6,-8,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	int max = divideArray(arr, 0, len-1);
	printf("Max is : %d", max);
}
