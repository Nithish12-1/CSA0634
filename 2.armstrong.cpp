#include <stdio.h>
#include <math.h>
int countDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + countDigits(num / 10);
}
int isArmstrong(int num, int n) {
    if (num == 0)
        return 0;
    return pow(num % 10, n) + isArmstrong(num / 10, n);
}
int main() {
    int num, originalNum, digitCount, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    originalNum = num;
    digitCount = countDigits(num);
    sum = isArmstrong(num, digitCount);
    if (sum == originalNum)
        printf("%d is an Armstrong number.\n", originalNum);
    else
        printf("%d is not an Armstrong number.\n", originalNum);

    return 0;
}
