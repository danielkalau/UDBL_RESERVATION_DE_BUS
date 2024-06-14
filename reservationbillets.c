#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIEGE 40 //le nombre de sige dans un bus
//structure pour le sièege dans un bus
typedef struct {
    int numero; //numero de siège
    int reservation; //indique le siège reserver
    char passagernom[100];//nom du passager
}siege;
//structure pour enregistre le bus
typedef struct {
    char route [100];//
    char time [50];//heurre de depart
    char siege[MAX_SIEGE];//sige du bus

}bus;