#include<stdio.h>
int first, last;
void print_arr(int arr[], int n){
	int i;
	for(i =0; i<n; i++){ 
		printf("%d ", arr[i]);
	}
}
void bubble_sort(int arr[], int n){
	int i,j, count=0;
	for(i =0; i<(n-1); i++){
		for(j =0; j<(n-1-i);j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				count++;
			}
			printf("\nAt i = %d and j = %d : ", i, j);
			print_arr(arr, n);
		}
		printf("\nSwaps for pass i = %d is : %d\n", i, count);
		if(count==0){
			printf("Array already sorted.\n");
			return;
		}
		count = 0;
	}
}

int binary_search(int arr[], int low, int high, int key, int flag){
	int pos = ((high-low)/2)+low; 
	printf("\n Search Array : [%d , %d] Index : %d", low, high, pos);
	if(key < arr[pos] && low != pos){
		flag = binary_search(arr, low, pos, key, flag);
	}
	else if(key > arr[pos] && high != (pos+1)){
		flag = binary_search(arr, pos+1, high, key, flag);
	}  
	else if(arr[pos] == key){
		printf(" (Found)");
		if(pos > last){
			printf(" Previous Last: %d ", last);
			last=pos;
			printf(" Now Last: %d ", last);
		}
		if(pos < first){
			printf(" Previous First: %d ", first);
			first=pos;
			printf(" Now First: %d ", first);
		}
		
		if(low != pos){  
			flag = binary_search(arr, low, pos, key, flag);	
		}
		if(high != (pos+1)){ 
			flag = binary_search(arr, pos+1, high, key, flag);
		} 
		
		flag = 2;
		return flag; 
	}
	return flag;
}
int main(){
	int i,n, key;
	printf("Enter array size :");
	scanf("%d", &n);
	int arr[n];
	for(i =0; i<n; i++){
		printf("Enter element at %d: ", i);
		scanf("%d", &arr[i]);
	}
	bubble_sort(arr, n);
	print_arr(arr, n);
	while(1==1){
		first = n; 
		last = -1; 
		printf("\nEnter the number to search :");
		scanf("%d", &key);
		if(binary_search(arr, 0, n, key, 3) != 2){
			printf("\n\n\t\t  --- Not Found --- ");
		}
		else{
			printf(" \n FIRST OCCURANCE : %d \n LAST OCCURANCE : %d", first, last);
		}
	}
	return 0;
}
