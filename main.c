#include <stdio.h>
#include <stdlib.h>
#include "fonctionsK.h"
#include "fonctionscalcul.h"
#include "test.h"



int main()
{
    int test;
    printf("Tapez 0 pour non , 1 pour oui\n");
    printf("Voulez vous faire des tests ? ");
    scanf("%d",&test);
    if(test == 1)
        test_err();
    int i;
    float t0 = 1;                           // On initie t0
    float y0, T, Tamb, h;
    FILE* fichier = NULL;
    printf("Température Initiale : ");
    scanf("%f",&y0);                        // On récupère la température initiale
    printf("Température Ambiante : ");
    scanf("%f",&Tamb);                      // On récupère la température ambiante
    printf("Temps Final : ");
    scanf("%f",&T);                         // On récupère le temps maximal
    printf("Pas de Temps : ");
    scanf("%f",&h);                         // On récupère le pas de temps
    int nbsolus = (T - t0) / h;
    float* y = (float*)malloc(nbsolus*sizeof(float));
    float* t = (float*)malloc(nbsolus*sizeof(float));
    EulerExplicite(y0,t0,nbsolus,h,y,t,Tamb);          // On calcule les solutions pour Euler
    fichier = fopen("Solutions_Euler.txt","w");
    for(i = 0; i < nbsolus; i++)
        fprintf(fichier,"%f %f \n",t[i],y[i]); // On stocke les solutions dans un fichier
    calcul_solution(y0,Tamb,t0,nbsolus,h,y,t);   // On calcule les solutions directes
    fichier = fopen("Solutions_direct.txt","w");
    for(i = 0; i < nbsolus; i++)
        fprintf(fichier,"%f %f \n",t[i],y[i]);  // On stocked les solutions dans un fichier
    fclose(fichier);
    free(y);
    free(t);
}