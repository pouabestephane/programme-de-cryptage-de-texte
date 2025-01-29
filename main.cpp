#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

// Fonction de chiffrement César
void chiffrement_cesar(char *texte, int decalage) {
    for (int i = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            char base = isupper(texte[i]) ? 'A' : 'a';
            texte[i] = (texte[i] - base + decalage) % 26 + base;
        }
    }
}

// Fonction de déchiffrement César
void dechiffrement_cesar(char *texte, int decalage) {
    chiffrement_cesar(texte, 26 - decalage);  // Décalage inverse
}

// Fonction de chiffrement Vigenère
void chiffrement_vigenere(char *texte, char *cle) {
    int cle_len = strlen(cle);
    for (int i = 0, j = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            char base = isupper(texte[i]) ? 'A' : 'a';
            int decalage = tolower(cle[j % cle_len]) - 'a';
            texte[i] = (texte[i] - base + decalage) % 26 + base;
            j++;
        }
    }
}

// Fonction de déchiffrement Vigenère
void dechiffrement_vigenere(char *texte, char *cle) {
    int cle_len = strlen(cle);
    for (int i = 0, j = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            char base = isupper(texte[i]) ? 'A' : 'a';
            int decalage = tolower(cle[j % cle_len]) - 'a';
            texte[i] = (texte[i] - base - decalage + 26) % 26 + base;
            j++;
        }
    }
}

// Mode brute force pour César
void brute_force_cesar(char *texte) {
    char copie[MAX_LEN];
    for (int i = 1; i < 26; i++) {
        strcpy(copie, texte);
        dechiffrement_cesar(copie, i);
        printf("Décalage %d : %s\n", i, copie);
    }
}

// Fonction pour lire une chaîne de l'utilisateur
void lire_chaine(char *texte) {
    printf("Entrez le texte : ");
    fgets(texte, MAX_LEN, stdin);
    texte[strcspn(texte, "\n")] = '\0';  // Supprimer le saut de ligne
}

int main() {
    int choix;
    char texte[MAX_LEN];
    char cle[MAX_LEN];
    int decalage;

    do {
        printf("\nMenu :\n");
        printf("1. Chiffrer (César)\n");
        printf("2. Déchiffrer (César)\n");
        printf("3. Chiffrer (Vigenère)\n");
        printf("4. Déchiffrer (Vigenère)\n");
        printf("5. Brute Force (César)\n");
        printf("6. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar();  // Absorber le retour à la ligne

        switch (choix) {
            case 1:
                lire_chaine(texte);
                printf("Entrez le décalage : ");
                scanf("%d", &decalage);
                getchar();
                chiffrement_cesar(texte, decalage);
                printf("Texte chiffré : %s\n", texte);
                break;
            case 2:
                lire_chaine(texte);
                printf("Entrez le décalage : ");
                scanf("%d", &decalage);
                getchar();
                dechiffrement_cesar(texte, decalage);
                printf("Texte déchiffré : %s\n", texte);
                break;
            case 3:
                lire_chaine(texte);
                printf("Entrez la clé Vigenère : ");
                fgets(cle, MAX_LEN, stdin);
                cle[strcspn(cle, "\n")] = '\0';
                chiffrement_vigenere(texte, cle);
                printf("Texte chiffré : %s\n", texte);
                break;
            case 4:
                lire_chaine(texte);
                printf("Entrez la clé Vigenère : ");
                fgets(cle, MAX_LEN, stdin);
                cle[strcspn(cle, "\n")] = '\0';
                dechiffrement_vigenere(texte, cle);
                printf("Texte déchiffré : %s\n", texte);
                break;
            case 5:
                lire_chaine(texte);
                brute_force_cesar(texte);
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 6);

    return 0;
}

