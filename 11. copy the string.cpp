#include <stdio.h>
void stringCopy(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0';
        return;
    }
    *destination = *source;
    stringCopy(source + 1, destination + 1);
}
int main() {
    char source[100]; 
    char destination[100]; 
    printf("Enter a string: ");
    scanf("%s", source);
    stringCopy(source, destination);
    printf("Copied String: %s\n", destination);
    return 0;
}
