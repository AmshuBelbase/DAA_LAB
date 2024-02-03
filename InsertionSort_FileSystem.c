#include<stdio.h>
int main(){
    FILE *filePtr;
    int arr[1000], i=0, pass, temp,n;
    filePtr = fopen("numbers.txt", "r");
    if(filePtr == NULL){
        printf("Could not Open File");
        return;
    }
    char buf[100];
    while (fscanf(filePtr, "%s", buf) == 1){
        arr[i] = atoi(buf);
        pass = i;
        while((pass-1 >= 0) && (arr[pass]<arr[pass-1])){
            temp = arr[pass];
            arr[pass] = arr[pass-1];
            arr[pass-1] = temp;
            pass--;
        }
        i++;
    }
    n=i;
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    fclose(filePtr);
}
