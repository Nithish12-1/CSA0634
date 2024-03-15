#include <stdio.h>

int is_prime(int n, int divisor) {
    if (n <= 2) 
        return (n == 2);

    if (n % divisor == 0)
        return 0;
        
    if (divisor * divisor > n)
        return 1;

    return is_prime(n, divisor + 1);
}

void generate_primes(int start, int end) {
    if (start <= end) {
        if (is_prime(start, 2)) {
            printf("%d ", start);
        }
        generate_primes(start + 1, end);
    }
}

int main() {
    int start_range, end_range;

    printf("Enter the start range: ");
    scanf("%d", &start_range);

    printf("Enter the end range: ");
    scanf("%d", &end_range);

    printf("Prime numbers between %d and %d are: ", start_range, end_range);
    generate_primes(start_range, end_range);

    return 0;
}
