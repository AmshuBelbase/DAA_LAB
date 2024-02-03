#include<stdio.h>
void circular_sorted(int arr[],int pos, int n){
	if(pos<n && arr[pos]<arr[pos+1]){
		circular_sorted(arr, pos+1, n);
	}else{
		printf("No. of rotations required : %d",(n-pos-1));
	}
}
int main(){ 
	int arr[] = {5,6,7,8,1,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	circular_sorted(arr, 0, n);
}
