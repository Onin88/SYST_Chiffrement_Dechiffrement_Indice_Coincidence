# Programme de Chiffrement et Déchiffrement

## Description

Ce programme en C implémente des fonctions pour chiffrer et déchiffrer des messages à l'aide d'une clé, ainsi que pour calculer l'indice de coïncidence d'un texte. L'indice de coïncidence permet d'évaluer la probabilité qu'un texte soit en français, tandis que les fonctions de chiffrement et de déchiffrement utilisent une méthode de substitution simple pour sécuriser les messages.

## Fonctionnalités

- **Indice de Coïncidence** : Calcule la probabilité qu'un texte soit en français. Un indice proche de 0.0385 indique une forte probabilité.
  
- **Chiffrement** : Transforme un message en utilisant une clé, tout en préservant les caractères non alphabétiques.

- **Déchiffrement** : Récupère le message original à partir du texte chiffré en utilisant la même clé.

## Utilisation

1. **Compilation** : Utilisez un compilateur C pour compiler le programme.
2. **Exécution** : Lancez le programme et entrez le message et la clé souhaités pour le chiffrement ou le déchiffrement.

## Exemple

```c
char message[] = "Bonjour";
char clef[] = "cle";
char encrypted[sizeof(message)];
char decrypted[sizeof(message)];

cryptage(message, encrypted, clef, sizeof(clef));
decryptage(encrypted, decrypted, clef, sizeof(clef));
