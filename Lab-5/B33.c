/* Design anagram game using array.  
->  Allow a user to enter N words and store it in an array.  
->  Generate a random number between 0 to N-1.  
->  Based  on  the  random  number  generated  display  the  word  stored  at  that 
index of an array and allow user to enter its anagram.  
->  Check  whether  the  word  entered  by  the  user  is  an  anagram  of  displayed 
number or not and display an appropriate message.  
->  Given a word A and word B. B is said to be an anagram of A if and only if the 
characters  present  in  B  is  same  as  characters  present  in  A,  irrespective  of 
their sequence. For ex: “LISTEN” == “SILENT” */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int N,word;
    printf("Enter N : ");
    scanf("%d",&N);
    int a[N];
    for(i=0;i<N;;i++){
        printf("Enter word : ");
        scanf("%s",word)
    }
    int ran = rand() % N;
    char words[50];

    int w;
    printf("Enter your word : ");
    scanf("%s",w);

    int sl = w.length();
    printf("%d",sl);
    return 0;
}