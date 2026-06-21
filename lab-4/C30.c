/* WAP to replace lowercase characters by uppercase & vice-versa in a user specified string. */
#include<stdio.h>
#include<string.h>
int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s",str);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') { 
            str[i] = str[i] - 32;  
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;   
        }
    }

    printf("Modified string: %s", str);

    return 0;
}