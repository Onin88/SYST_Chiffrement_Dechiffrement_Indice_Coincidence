#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "fonction_bases.h"

int main(int argc, char* argv[]){

    char Lettre1 = *argv[2];
    /*char lettre2;
    char* Lettre2 = malloc(sizeof(char));
    char* cle = malloc(sizeof(char)*2);*/

    char* messageChiffre = argv[1];
    char* messageDechiffre = malloc(sizeof(char)* strlen(argv[1]));
    char* bonMessage = malloc(sizeof(char)* strlen(argv[1]));
    char* clef;

    int tailleClef = 2;
    float indice, bonIndice, ancienIndice;

    /*printf("Message chiffré : %s ", messageChiffre);
    printf("Lettre reçue : %s ", Lettre1);
    printf("Taille de la lettre1 : %d", (int) sizeof(Lettre1));*/

    //Pour comparer
    bonIndice = 0;

    for(int i = 0; i < 26; i++){
        char* cle = &Lettre1;
        char lettre2 = 97 + i;
        char* Lettre2 = &lettre2;
        cle[1] = *Lettre2;
        //printf("Clé : %s \n", cle);
        decryptage(messageChiffre, messageDechiffre, cle, tailleClef);
        indice = indice_de_coincidence(messageDechiffre);
        if(indice > bonIndice){
            strcpy(bonMessage, messageDechiffre);
            bonIndice = indice;
            clef = strdup(cle);
        }
    }

    /*printf("Message déchiffré : %s, ", bonMessage);
    printf("Indice de coïncidence : %f \n", bonIndice);*/

    
    char IndiceCoin[30];
    sprintf(IndiceCoin, "%f", bonIndice);

    char file[10] = "res_";
    file[4] = Lettre1;
    strcat(file, ".txt");
    int File = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    
    write(File, IndiceCoin, strlen(IndiceCoin));
    write(File, "\n", 1);
    write(File, clef, 2);
    write(File, "\n", 1);
    write(File, bonMessage, strlen(bonMessage));

    close(File);

    free(messageDechiffre);
    free(bonMessage);

    return 0;
}