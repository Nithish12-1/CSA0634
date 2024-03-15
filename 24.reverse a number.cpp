#include <stdio.h>
int reverseNumber(int num) {
    int reversedNum = 0;

    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return reversedNum;
}

int main() {
    int num;

    printf("Enter a number to reverse: ");
    scanf("%d", &num);

    int reversedNum = reverseNumber(num);

    printf("Reversed number: %d\n", reversedNum);

    return 0;
}
