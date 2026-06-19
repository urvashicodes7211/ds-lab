// WAP to sort the N names in an alphabetical order. 
#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j;
    printf("Enter n : ");
    scanf("%d",&n);
    char words[n][100],temp[100];

    for(i=0;i<n;i++){
        printf("Enter word : ");
        scanf("%s", words[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(words[i], words[j]) > 0){
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    for(int k=0;k<n;k++){
        printf("%s\n", words[k]);
    }

    return 0;
}
