#include <stdio.h>
#include <string.h>

// Définition de la structure Siege
typedef struct {
    int reservee;  // 1 si le siège est réservé, 0 sinon
    char prenom_client[50];
    char postnom_client[50];
    char contact_info[50];
} Siege;

// Définition de la structure Bus
typedef struct {
    Siege siege[40];  // Supposons qu'un bus a 40 sièges
} Bus;

// Fonction pour attribuer un siège
void attribuer_siege(Bus *buses, int bus_choix, int Siege_choix, const char *prenom, const char *nom, const char *contact_info) {
    // Récupération du siège choisi
    Siege *siege = &buses[bus_choix].siege[Siege_choix - 1];

    // Réservation du siège
    siege->reservee = 1;

    // Enregistrement des informations du client
    strcpy(siege->prenom_client, prenom);
    strcpy(siege->postnom_client, nom);
    strcpy(siege->contact_info, contact_info);
}

int main() {
    // Initialisation des bus (supposons qu'on a 10 bus)
    Bus buses[10] = {0};

    // Variables pour l'exemple
    int bus_choix, Siege_choix;
    char prenom[50], nom[50], contact_info[50];

    // Saisie des informations de l'utilisateur
    printf("Entrez le numero du bus (0-9): ");
    scanf("%d", &bus_choix);

    printf("Entrez le numero du siege (1-40): ");
    scanf("%d", &Siege_choix);

    printf("Entrez votre prenom: ");
    scanf("%s", prenom);

    printf("Entrez votre nom: ");
    scanf("%s", nom);

    printf("Entrez vos informations de contact: ");
    scanf("%s", contact_info);

    // Appel de la fonction pour attribuer le siège
    attribuer_siege(buses, bus_choix, Siege_choix, prenom, nom, contact_info);

    // Affichage pour vérifier (par exemple)
    printf("Bus %d, Siege %d:\n", bus_choix, Siege_choix);
    printf("Reservee: %d\n", buses[bus_choix].siege[Siege_choix - 1].reservee);
    printf("Prenom: %s\n", buses[bus_choix].siege[Siege_choix - 1].prenom_client);
    printf("Nom: %s\n", buses[bus_choix].siege[Siege_choix - 1].postnom_client);
    printf("Contact: %s\n", buses[bus_choix].siege[Siege_choix - 1].contact_info);

    return 0;
}
