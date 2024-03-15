#include <stdio.h>

void find_max_min(int arr[], int left, int right, int *max_val, int *min_val) {
    if (left == right) {
        *max_val = arr[left];
        *min_val = arr[left];
        return;
    }

    if (right - left == 1) {
        *max_val = (arr[left] > arr[right]) ? arr[left] : arr[right];
        *min_val = (arr[left] < arr[right]) ? arr[left] : arr[right];
        return;
    }

    int mid = (left + right) / 2;
    int max1, min1, max2, min2;
    find_max_min(arr, left, mid, &max1, &min1);
    find_max_min(arr, mid + 1, right, &max2, &min2);

    *max_val = (max1 > max2) ? max1 : max2;
    *min_val = (min1 < min2) ? min1 : min2;
}

int main() {
    int arr[100], n, max_val, min_val;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    find_max_min(arr, 0, n - 1, &max_val, &min_val);

    printf("Maximum value in the list: %d\n", max_val);
    printf("Minimum value in the list: %d\n", min_val);

    return 0;
}
