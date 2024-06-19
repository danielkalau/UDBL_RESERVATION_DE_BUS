// reservationbillets.h
#ifndef attributionsiege_H
#define attributionsiege_H

#include <stdio.h>

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

// Déclaration des fonctions
void attribuer_siege(Bus *buses, int bus_choix, int Siege_choix, const char *prenom, const char *nom, const char *contact_info);
void attributionsiege();

#endif // attributionsiege_H
