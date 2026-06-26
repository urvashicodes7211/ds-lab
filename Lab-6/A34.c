/* WAP to allocate and de-allocate memory for int, char and float variable at 
runtime. */

#include<stdio.h>
#include<stdlib.h>
int main(){
    
    int *intptr ;
    char *charptr ; 
    float *floatptr ; 


    intptr = (int *) malloc(sizeof(int));
    charptr = (char *) malloc(sizeof(char));
    floatptr = (float *) malloc(sizeof(float));


    printf("Enter int : ");
    scanf("%d",intptr);

    printf("Enter char : ");
    scanf(" %c",charptr);

    printf("Enter float : ");
    scanf("%f",floatptr);

    printf("\nInteger = %d", *intptr);
    printf("\nCharacter = %c", *charptr);
    printf("\nFloat = %.2f", *floatptr);

    free(intptr);
    free(charptr);
    free(floatptr);

    return 0;
}