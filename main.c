#include <stdlib.h>
#include <stdio.h>
#include "nom.c"
#include "reservationbillets.c"
#include "gestion passager.c"



int main (){
    //juste l'appel de fonction
    nom();

    gestionpassager();

    reservationbillets ();
    return 0;

}