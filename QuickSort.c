#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
	int pivot = low;
	int i = pivot + 1;
	int j = high, k;
	while (i <= j)
	{
		if (arr[i] <= arr[pivot] && i <= high)
		{
			i++;
		}
		else if (arr[j] > arr[pivot])
		{
			j--;
		}
		else
		{
			arr[i] = arr[i] + arr[j];
			arr[j] = arr[i] - arr[j];
			arr[i] = arr[i] - arr[j];
			printf("\nSwap %d & %d", arr[i], arr[j]);
		}
	}
	if (i > j && arr[pivot] > arr[j])
	{
		arr[pivot] = arr[pivot] + arr[j];
		arr[j] = arr[pivot] - arr[j];
		arr[pivot] = arr[pivot] - arr[j];
		printf("\nSwap Pivot %d & %d", arr[pivot], arr[j]);
	}
	if (low != j)
	{
		printf("\nSend Left Array : %d & %d", low, j);
		quickSort(arr, low, j);
	}
	if (j + 1 <= high){
		printf("\nSend Right Array : %d & %d", j+1, high);
		quickSort(arr, j + 1, high);
	}
	printf("\nArray %d to %d : ",low, high);
	for (k = low; k <= high; k++)
	{
		printf("%d ", arr[k]);
	}
}
int main()
{
	int i, n, key;
	printf("Enter array size :");
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
	{
		printf("Enter element at %d: ", i);
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, n - 1);
	return 0;
}
