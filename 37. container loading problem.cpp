#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 1000

// Function to perform First Fit Decreasing (FFD) algorithm
int ffd(int items[], int num_items, int container_capacity) {
    int containers[MAX_CONTAINERS] = {0}; // Array to hold container loads
    int num_containers = 0; // Number of containers used

    // Sort items in non-increasing order
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = 0; j < num_items - i - 1; j++) {
            if (items[j] < items[j + 1]) {
                int temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Perform First Fit Decreasing (FFD) algorithm
    for (int i = 0; i < num_items; i++) {
        int j;
        for (j = 0; j < num_containers; j++) {
            if (containers[j] >= items[i]) {
                containers[j] -= items[i];
                break;
            }
        }
        if (j == num_containers) {
            num_containers++;
            containers[num_containers - 1] = container_capacity - items[i];
        }
    }

    return num_containers;
}

// Main function
int main() {
    int items[MAX_ITEMS];
    int num_items, container_capacity;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the items' sizes:\n");
    for (int i = 0; i < num_items; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the capacity of each container: ");
    scanf("%d", &container_capacity);

    int num_containers = ffd(items, num_items, container_capacity);

    printf("Number of containers required: %d\n", num_containers);

    return 0;
}
