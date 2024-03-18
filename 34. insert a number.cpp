#include <stdio.h>

#define MAX_SIZE 100

void insert_number_into_list(int list[], int *size, int number, int position) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Insertion failed.\n");
        return;
    }
    
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to the right to make space for the new number
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the number at the specified position
    list[position] = number;

    // Update the size of the list
    (*size)++;
}

int main() {
    int list[MAX_SIZE];
    int size;
    int number_to_insert;
    int insertion_position;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d elements of the list: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &number_to_insert);

    printf("Enter the insertion position (0-indexed): ");
    scanf("%d", &insertion_position);

    insert_number_into_list(list, &size, number_to_insert, insertion_position);

    printf("List after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
