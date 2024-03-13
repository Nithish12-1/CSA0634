#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
void printFibonacciSeries(int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}
int main() {
    int count;
    printf("Enter the count of Fibonacci numbers to print: ");
    scanf("%d", &count);
    printf("Fibonacci Series: ");
    printFibonacciSeries(count);
    return 0;
}
