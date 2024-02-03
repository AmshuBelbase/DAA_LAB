//Insertion Sort and Linear Search
#include<stdio.h>
int main(){
    int i,pass,n,temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int x[n];
    for(i=0;i<n;i++){
        pass=i;
        printf("\nElement no. %d:", (i+1));
        scanf("%d",&x[i]);
        while((pass-1 >= 0) && (x[pass]<x[pass-1])){
            temp = x[pass];
            x[pass] = x[pass-1];
            x[pass-1] = temp;
            pass--;
        }
    }
    for(i=0;i<n;i++){
        printf("%d ", x[i]);
    }
    printf("\nEnter number to search : ");
    scanf("%d", &pass);
    linear_search(pass, x, n);
}
void linear_search(int pass, int arr[], int n){
	int i;
    for(i=0; i<n; i++){
        if(arr[i] == pass){
            printf("Element %d found at Position : %d", pass, i);
            return;
        }
    }
}
