#ifndef FONCTION_BASES_H
#define FONCTION_BASES_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void cryptage(char* message, char* new_mess, char* clef, int tailleClef);

void decryptage(char* message, char* new_mess, char* clef, int tailleClef);

float indice_de_coincidence(char* texte);

#endif