#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker les details d'un passager
struct Passager {
    char nom[50];
    char contact[20];
    int historiqueReservations;
};

// Fonction pour ajouter un nouveau passager
void ajouterPassager(struct Passager *passagers, int *nombrePassagers) {
    if (*nombrePassagers < 100) {
        printf("Entrez le nom du passager : ");
        scanf("%s", passagers[*nombrePassagers].nom);
        printf("Entrez les informations de contact numero de telephone  : ");
        scanf("%s", passagers[*nombrePassagers].contact);
        passagers[*nombrePassagers].historiqueReservations = 0;
        (*nombrePassagers)++;
        printf("Passager ajoute avec succes !\n");
    } else {
        printf("La liste des passagers est pleine.\n");
    }
}

// Fonction pour afficher les details d'un passager
void afficherPassager(struct Passager passager) {
    printf("Nom : %s\n", passager.nom);
    printf("Contact : %s\n", passager.contact);
    printf("Historique des reservations : %d\n", passager.historiqueReservations);
}

int main() {
    struct Passager passagers[100];
    int nombrePassagers = 0;
    int choix;

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un passager\n");
        printf("2. Afficher les details d'un passager\n");
        printf("3. sortir\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterPassager(passagers, &nombrePassagers);
                break;
            case 2:
                if (nombrePassagers > 0) {
                    int index;
                    printf("Entrez l'index du passager (0-%d) : ", nombrePassagers - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < nombrePassagers) {
                        afficherPassager(passagers[index]);
                    } else {
                        printf("Index invalide.\n");
                    }
                } else {
                    printf("Aucun passager enregistre.\n");
                }
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Reessayez.\n");
        }
    } while (choix != 3);

    return 0;
}
