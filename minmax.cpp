#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void minMAX(int* A,int i,int j,int &min,int &max){
int low =i;
int high= j;
if(i==j){
if (max < A[low]) {
            max = A[low];
        }
 
        if (min > A[high]) {
            min = A[high];
        }
    return;
}
if((j-1)==1){
if(A[i] < A[j]){
if (max < A[low]) {
max = A[low];
        }
 
        if (min > A[high]) {
            min = A[high];
        }
        return;
}
else{
if (min > A[high]) {
            min = A[high];
        }
if (max < A[low]) {
max = A[low];
        }
        return;
}
}
int mid = (i+j)/2;
cout<<"current min"<<min<<endl;
cout<<"current max"<<max<<endl;
minMAX(A,i,mid,min,max);
minMAX(A,mid+1,j,min,max);

}

int main(){
int arr[10] = {31,1,9,21,6,0,64,21,7,21};
int max = INT_MIN, min = INT_MAX;
minMAX(arr,0,9,min,max);
cout<<"min is "<<min<<endl;
cout<<"max is "<<max;
}
