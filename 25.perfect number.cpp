#include <stdio.h>
int isPerfect(int num) {
    int sum = 1; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i != num) 
                sum = sum + i + num / i;
            else
                sum = sum + i;
        }
    }
    if (sum == num && num != 1)
        return 1;
    else
        return 0;
}
int main() {
    int start, end;
    printf("Enter the range to find perfect numbers (start end): ");
    scanf("%d %d", &start, &end);
    printf("Perfect numbers in the range %d to %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPerfect(i))
            printf("%d\n", i);
    }

    return 0;
}
