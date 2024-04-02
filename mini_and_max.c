#include <stdio.h>

// Function to find minimum and maximum using divide and conquer
void findMinAndMax(int arr[], int low, int high, int *min, int *max) {
    int mid, min1, min2, max1, max2;

    // If array has only one element
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // If array has two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    // If array has more than two elements, divide and conquer
    mid = (low + high) / 2;
    findMinAndMax(arr, low, mid, &min1, &max1);
    findMinAndMax(arr, mid + 1, high, &min2, &max2);

    // Compare min and max of two halves
    if (min1 < min2)
        *min = min1;
    else
        *min = min2;

    if (max1 > max2)
        *max = max1;
    else
        *max = max2;
}

int main() {
    int arr[] = {7, 3, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinAndMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element in array: %d\n", min);
    printf("Maximum element in array: %d\n", max);

    return 0;
}

