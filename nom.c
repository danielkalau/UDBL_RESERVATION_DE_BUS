#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//menu de choix
//declaration de var

void nom ()
{
    char prenom[50],nom[50],postnom[50],sex[2],numTel[11],tempo[100];
    int age ;

    //demande de l'idenfication du client

    printf("quel est votre prenom:\n");
    fgets(tempo, sizeof(tempo),stdin);
    sscanf(tempo,"%s ",prenom);


    printf("quel est votre nom:\n");
    fgets(tempo, sizeof(tempo),stdin);
    sscanf(tempo,"%s",nom);

    printf("quel est votre postnom:\n");
    fgets(tempo,sizeof (tempo),stdin);
    strtok(tempo,"");
    strcpy(postnom,tempo);

    printf("entrez votre numero de telephone:");

    fgets(tempo,sizeof (tempo),stdin);
    sscanf(tempo,"%s ",numTel);

    //le sex
    printf("quel votre sex (m/f):\n");
    scanf("%c",sex);

    printf("entrer votre age:\n");
    while (scanf("%d",&age)!=1|| age <=0){
        printf("erreur:veuillez entrer un nombre entier positif.\n");
        scanf("%*c");
    }

//affichage des informations


    printf("prenom  :%s,", prenom);
    printf(" nom:%s,",nom);
    printf(" postnom:%s,", postnom);
    printf("sex:%s,", sex);
    printf(" numero :%s,", numTel);
    printf(" Age est :%d\n", age);
    printf("merci de vous etre enregistrer!\n\n ");

}
