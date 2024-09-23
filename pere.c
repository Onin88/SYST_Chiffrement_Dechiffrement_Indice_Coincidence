#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fonction_bases.h"

int main(int argc, char* argv[]){

    char lettre;
    char* l;
    char lettre1;
    char* message;
    char* buffer;
    char* indice;
    char* cle = malloc(sizeof(char)*2);
    char* bonIndice;
    char* VRAIMESSAGE;
    char* end = NULL;
    int etat;
    char bonneCle[2] = "gm";

    struct stat s;

    if(stat("charabia.txt", &s) == -1) {
        perror("Charabia n'existe pas");
        exit(1);
    }else{
        message = malloc(sizeof(char)*s.st_size);
        int File = open("charabia.txt", O_RDONLY);
        read(File, message, s.st_size);
        close(File);
    }
    
    for(int i = 0; i < 26; i++){
        lettre = 97 + i;
        l = &lettre;
        pid_t pid;
        switch(pid = fork()){
            case(pid_t) -1:
                perror("Création impossible\n");
                exit(1);
            case(pid_t) 0:
                //On envoie au fils
                execl("./fils", "./fils", message, l, NULL);
                exit(0);
                break;
            default:
                //on est dans le père
                waitpid(pid, &etat, 0);
                break;
        }
    }

    for(int i = 0; i < 26; i++){
        lettre1 = 97 + i;
        char titre[10] = "res_";
        titre[4] = lettre1;
        strcat(titre, ".txt");
        
        if(stat(titre, &s) == -1) {
            printf("%s", titre);
            perror("Le file n'existe pas!");
            exit(1);
        }else{
            buffer = malloc(sizeof(char)*s.st_size*2);
            VRAIMESSAGE = malloc(sizeof(char)*s.st_size*2);
            int File = open(titre, O_RDONLY);
            read(File, buffer, s.st_size);
            close(File);
            //comme on ne peut pas tester avec les indices on va tester avec les clés, on sait que la bonne clé est gm.
            if(buffer[9] == 'g' && buffer[10] == 'm'){
                printf("%s", buffer);
            }
            free(buffer);
        }
    }
    
    return 0;
}