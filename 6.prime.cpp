#include <stdio.h>
int is_prime(int n, int divisor) {
    if (n <= 1) 
        return 0;
    if (divisor == 1) 
        return 1;
    if (n % divisor == 0) 
        return 0;
    return is_prime(n, divisor - 1);
}
int main() {
    int number;
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &number);
    if (is_prime(number, number - 1))
        printf("%d is a prime number.\n", number);
    else
        printf("%d is not a prime number.\n", number);
    
    return 0;
}
