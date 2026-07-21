/*Write a program to simulate music player application using suitable data 
structure. There is no estimation about number of music files to be managed by 
the music player. Your program should support all the basic music player 
operations to play and manage the playlist. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char song[50];
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *first = NULL;
struct Node *last = NULL;
struct Node *current = NULL;

void addSong(char name[]){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->song, name);
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if(first == NULL){
        first = last = newNode;
    }
    else{
        newNode->lptr = last;
        last->rptr = newNode;
        last = newNode;
    }

    if(current == NULL)
        current = first;

    printf("Song Added Successfully...\n");
}

void displayPlaylist(){
    struct Node *save = first;

    if(first == NULL){
        printf("Playlist is Empty.\n");
        return;
    }

    printf("\nPlaylist:\n");
    while(save != NULL){
        printf("%s\n", save->song);
        save = save->rptr;
    }
}

void playCurrent(){
    if(current == NULL){
        printf("Playlist is Empty.\n");
    }
    else{
        printf("Now Playing: %s\n", current->song);
    }
}

void nextSong(){
    if(current == NULL){
        printf("Playlist is Empty.\n");
    }
    else if(current->rptr == NULL){
        printf("No Next Song.\n");
    }
    else{
        current = current->rptr;
        printf("Now Playing: %s\n", current->song);
    }
}

void previousSong(){
    if(current == NULL){
        printf("Playlist is Empty.\n");
    }
    else if(current->lptr == NULL){
        printf("No Previous Song.\n");
    }
    else{
        current = current->lptr;
        printf("Now Playing: %s\n", current->song);
    }
}

void deleteSong(char name[]){
    struct Node *save;

    if(first == NULL){
        printf("Playlist is Empty.\n");
        return;
    }

    save = first;

    while(save != NULL){
        if(strcmp(save->song, name) == 0){
            break;
        }
        save = save->rptr;
    }

    if(save == NULL){
        printf("Song Not Found.\n");
        return;
    }

    if(save == first && save == last){
        first = last = NULL;
        current = NULL;
    }
    else if(save == first){
        first = first->rptr;
        first->lptr = NULL;

        if(current == save)
            current = first;
    }
    else if(save == last){
        last = last->lptr;
        last->rptr = NULL;

        if(current == save)
            current = last;
    }
    else{
        save->lptr->rptr = save->rptr;
        save->rptr->lptr = save->lptr;

        if(current == save)
            current = save->rptr;
    }

    free(save);
    printf("Song Deleted Successfully.\n");
}

int main(){
    int choice;
    char name[50];

    do{
        printf("\n===== MUSIC PLAYER =====\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Current Song\n");
        printf("4. Next Song\n");
        printf("5. Previous Song\n");
        printf("6. Delete Song\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter Song Name: ");
                scanf(" %[^\n]",name);
                addSong(name);
                break;

            case 2:
                displayPlaylist();
                break;

            case 3:
                playCurrent();
                break;

            case 4:
                nextSong();
                break;

            case 5:
                previousSong();
                break;

            case 6:
                printf("Enter Song Name to Delete: ");
                scanf(" %[^\n]",name);
                deleteSong(name);
                break;

            case 7:
                printf("Thank You...\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    }while(choice != 7);

    return 0;
}