#define TAILLE_ALPHA  26


float indice_de_coincidence(char* text){
  //Calcule d'indice de coincidence d'un texte. Plus cet indice est proche de  0.0385, plus de texte a une probabilité forte d'être en français.
  int frequences[TAILLE_ALPHA];
  for(int i = 0; i < TAILLE_ALPHA; i++){
    frequences[i] = 0;
  }

  //Calcule de la table des fréquences.
  int nb = 0;
  while(text[nb] != '\0'){
    //Cas d'une miniscule
    if((text[nb] >= 'a' && text[nb] <= 'z')){
      frequences[text[nb] - 'a']++;//text[nb] - 'a' :  position de la lettre dans l'alphabet (entre 0 et 25)
     }
    //Cas d'une majuscule
    else if((text[nb]>='A' && text[nb] <= 'Z')){
      frequences[text[nb] - 'A']++;//text[nb] - 'A' :  position de la lettre dans l'alphabet (entre 0 et 25)
    }
    nb++;
  }

  //Calcule de l'indice de coincidence à partir de la table des fréquences
  float ind = 0.0;
  for(int i = 0; i < TAILLE_ALPHA; i++){
    ind += (frequences[i]*(frequences[i] - 1)*1.0)/(nb*(nb-1));
  }
  return ind;
}


void cryptage(char* message, char* new_mess, char* clef, int tailleClef){
  //Chiffre message avec la clef (de taille tailleClef), et écrit le résultat dans new_mess
  //new_mess doit avoir une taille suffisante

  int i = 0;
  int res;
  while(message[i] != '\0'){
      //Cas d'une miniscule : on chiffre
      if((message[i] >= 'a' && message[i] <= 'z')){
        res = (message[i] + (clef[i%tailleClef] - 'a'));
        if(res > 'z'){
          res = res % ('z'+1) + 'a';
        }
      }

      //Cas d'une majuscule : on chiffre
      else if((message[i]>='A' && message[i] <= 'Z')){
        res = (message[i] + (clef[i%tailleClef] - 'a'));
        if(res > 'Z'){
          res = res % ('Z'+1) + 'A';
        }
      }

      //Autre caractère : on recopie sans chiffrer. Notemment les accents et les espaces.
      else{
        res = message[i];
      }

      //Pour le débuggage
      //printf("%c (%d)->%d - %c (%d) - %c (%d)\n", clef[i%tailleClef],clef[i%tailleClef], i, message[i], message[i], res, res);

      new_mess[i] = res;
      i++;
  }
  new_mess[i] = '\0';
}


void decryptage(char* message, char* new_mess, char* clef, int tailleClef){
  //Déchiffre message avec la clef (de taille tailleClef), et écrit le résultat dans new_mess
  //new_mess doit avoir une taille suffisante
  //C'est le symétrique exacte de la fonction cryptage

  int i = 0;
  int res;
  while(message[i] != '\0' ){
      //Cas d'une miniscule : on déchiffre
      if((message[i] >= 'a' && message[i] <= 'z')){//||(message[i]>='A' && message[i] <= 'Z')){
         res = (message[i] + ('a'- clef[i%tailleClef]));
         if(res < 'a'){
           res += 26;
         }
       }

      //Cas d'une majuscule : on déchiffre
       else if(message[i]>='A' && message[i] <= 'Z'){
          res = (message[i] + ('a'- clef[i%tailleClef]));
          if(res < 'A'){
            res += 26;
          }
        }
        //Autre caractère : on recopie sans chiffrer. Notemment les accents et les espaces.

       else{
         res = message[i];
       }

      //Pour le débuggage
      // printf("%c (%d)->%d - %c (%d) - %c (%d)\n", clef[i%tailleClef],clef[i%tailleClef], i, message[i], message[i], res, res);

       new_mess[i] = res;
      i++;
  }
  new_mess[i] = '\0';
}
