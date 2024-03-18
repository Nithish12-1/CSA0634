#include <stdio.h>

int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("Sum of digits: %d\n", sumOfDigits(number));
    
    return 0;
}
