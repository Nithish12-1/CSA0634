#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    if (*str == '\0') {
        return;
    }
    reverseString(str + 1);
    printf("%c", *str);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Original String: %s\n", str);
    printf("Reversed String: ");
    reverseString(str);
    printf("\n");
    return 0;
}
