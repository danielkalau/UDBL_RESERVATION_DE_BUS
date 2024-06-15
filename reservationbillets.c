#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEATS 40 // Nombre maximum de sièges dans un bus

// Structure pour représenter un siège dans le bus
typedef struct {
    int numero; // Numéro du siège
    int reservation; // Indicateur si le siège est réservé (1) ou non (0)
    char passengerName[100]; // Nom du passager ayant réservé le siège
} siege;

// Structure pour représenter un bus
typedef struct {
    char route[100]; // Itinéraire du bus
    char temp[50]; // Heure de départ du bus
    siege sieges[MAX_SEATS]; // Tableau de sièges pour le bus
} Bus;

// Initialisation des bus avec itinéraires et heures
Bus buses[6] = {
        {"Likasi-Lubumbashi", "09:00 H", {{1, 0, ""}}},
        {"Likasi-Kolwezi", "10:00 H", {{1, 0, ""}}},
        {"Kolwezi-Likasi", "11:00 H", {{1, 0, ""}}},
        {"Kolwezi-Lubumbashi", "12:00 H", {{1, 0, ""}}},
        {"Lubumbashi-Likasi", "01:00 H", {{1, 0, ""}}},
        {"Lubumbashi-Kolwezi", "02:00 H", {{1, 0, ""}}}
};

// Affiche les itinéraires disponibles
void showItineraries() {
    printf("\t**** Choisir un itineraire des bus ****\n");
    for (int i = 0; i < 6; i++) { // Boucle à travers les bus pour afficher les itinéraires
        printf("%d. %s\n", i + 1, buses[i].route); // Affiche chaque itinéraire avec un numéro
    }
}

// Affiche les sièges disponibles pour un itinéraire donné
void place(Bus *bus) {
    printf("Sieges disponibles pour l'itineraire %s (%s):\n", bus->route, bus->temp);
    for (int i = 0; i < MAX_SEATS; i++) { // Boucle à travers les sièges du bus
        if (bus->sieges[i].reservation == 0) { // Si le siège n'est pas réservé
            printf("Siege %d est disponible\n", bus->sieges[i].numero); // Affiche le siège disponible
        }
    }
}

// Réserve un siège pour un itinéraire donné
void reserveSeat(Bus *bus) {
    int seatNumber; // Numéro du siège à réserver
    char passengerName[100]; // Nom du passager

    place(bus); // Affiche les sièges disponibles pour le bus
    printf("Entrez le numero de siege que vous souhaitez reserver: ");
    scanf("%d", &seatNumber); // Demande le numéro du siège

    // Vérifie si le numéro de siège est valide et non réservé
    if (seatNumber < 1 || seatNumber > MAX_SEATS || bus->sieges[seatNumber - 1].reservation) {
        printf("Numero de siege invalide ou déjà réservé.\n");
        return;
    }

    printf("Entrez votre nom: ");
    scanf("%s", passengerName); // Demande le nom du passager

    // Marque le siège comme réservé et enregistre le nom du passager
    bus->sieges[seatNumber - 1].reservation = 1;
    strcpy(bus->sieges[seatNumber - 1].passengerName,passengerName);

    printf("Siege %d reserve avec succes pour %s.\n", seatNumber, passengerName);
}

// Gère le processus de réservation de billets
void reservationBillets() {
    int choice; // Choix de l'itinéraire
    showItineraries(); // Affiche les itinéraires disponibles
    printf("Entrez le numero de l'itineraire pour la reservation (1-6): ");
    scanf("%d", &choice); // Demande le choix de l'itinéraire

    // Vérifie si le choix est valide
    if (choice < 1 || choice > 6) {
        printf("Choix d'itineraire invalide.\n");
        return;
    }

    reserveSeat(&buses[choice - 1]); // Réserve un siège pour l'itinéraire choisi
}

// Fonction principale
int main() {
    int choixPrincipal; // Choix de l'utilisateur dans le menu principal

    while (1) { // Boucle infinie pour afficher le menu principal
        printf("\nMenu Principal:\n");
        printf("1. Afficher les itineraires\n");
        printf("2. Reserver un billet\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choixPrincipal); // Demande le choix de l'utilisateur

        // Exécute l'action en fonction du choix de l'utilisateur
        switch (choixPrincipal) {
            case 1:
                showItineraries(); // Affiche les itinéraires
                break;
            case 2:
                reservationBillets(); // Lance le processus de réservation
                break;
            case 3:
                printf("Au revoir!\n");
                exit(0); // Quitte le programm
            default:
                printf("Choix invalide. Veuillez réessayer.\n"); // Message d'erreur pour choix invalide
        }
    }

    return 0; // Retourne 0 pour indiquer que le programme s'est terminé correctement
}
