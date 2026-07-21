/*Write a program to determine if an input character string is of the form aibi 
where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’. */

#include <stdio.h>

int main() {
    char str[100];
    int i = 0, a = 0, b = 0;

    printf("Enter string: ");
    scanf("%s", str);

    while (str[i] == 'a') {
        a++;
        i++;
    }

    while (str[i] == 'b') {
        b++;
        i++;
    }

    if (str[i] != '\0') {
        printf("Invalid String");
        return 0;
    }

    if (a == b && a >= 1)
        printf("Valid String");
    else
        printf("Invalid String");

    return 0;
}