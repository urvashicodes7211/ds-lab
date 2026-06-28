// WAP to check whether the string is Palindrome or not using Pointer.

#include <stdio.h>
#include <string.h>
int main() {
    char s1[50];
    char *start, *end;

    printf("Enter a string: ");
    scanf("%s", s1);

    start = s1;
    end = s1 + strlen(s1) - 1;

    while (start < end) {
        if (*start != *end) {
            printf("Not a Palindrome");
            return 0;
        }
        start++;
        end--;
    }

    printf("Palindrome");

    return 0;
}