#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int weight;
    int value;
    float density;
} Item;
void knapsack(int capacity, Item items[], int n) {
    float totalValue = 0;
    int i;
    float currentWeight = 0;
    for (i = 0; i < n; i++) {
        items[i].density = (float) items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(Item), 
        [](const void *a, const void *b) -> int {
            Item *itemA = (Item *)a;
            Item *itemB = (Item *)b;
            return (itemB->density - itemA->density);
        }
    );
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (float) remainingWeight / items[i].weight * items[i].value;
            break;
        }
    }
    printf("Maximum value in knapsack: %.2f\n", totalValue);
}
int main() {
    int capacity, n, i;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    knapsack(capacity, items, n);
    return 0;
}
