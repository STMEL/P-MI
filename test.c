#include "fonctionsK.h"
#include "fonctionscalcul.h"
#include <stdio.h>
#include <stdlib.h>


// Ce fichier contient les fonctions permettant de faire les tests d'erreurs


// Fonction calcul erreur entre Euler et Exacte
void erreur(float* y_eul, float* y_exa, float* err, int nbsolus)
{
    int i;
    for(i = 0; i < nbsolus; i++)
        err[i] = y_eul[i] - y_exa[i];
}

// Fonction traitement pas de temps
void traitement_pas(float h,const char* nomfichier,float y0,float T,float Tamb)
{
    int i;
    float t0 = 1;                                   // On initie t0
    int nbsolus = (T - t0) * (1 / h);
    float* y_eul = (float*)malloc(nbsolus*sizeof(float));
    float* t_eul = (float*)malloc(nbsolus*sizeof(float));
    float* y_exa = (float*)malloc(nbsolus*sizeof(float));
    float* t_exa = (float*)malloc(nbsolus*sizeof(float));
    EulerExplicite(y0,t0,nbsolus,h,y_eul,t_eul,Tamb);           // On calcule les solutions pour Euler
    calcul_solution(y0,Tamb,t0,nbsolus,h,y_exa,t_exa);          // On calcule les solutions directes
    float* err = (float*)malloc(nbsolus*sizeof(float));
    erreur(y_eul,y_exa,err,nbsolus);
    FILE* fichier = NULL;
    fichier = fopen(nomfichier,"w");
    for(i = 0; i < nbsolus; i++)
        fprintf(fichier,"%f %f \n",t_eul[i],err[i]);            // On stocke les erreurs dans un fichier
    fclose(fichier);
    free(y_eul);
    free(y_exa);
    free(err);
    free(t_eul);
    free(t_exa);
}



// Fonction faisant varier le pas de temps
void test_pas()
{
    int y0, T, Tamb;
    printf("Température Initiale : ");
    scanf("%d",&y0);                                // On récupère la température initiale
    printf("Température Ambiante : ");
    scanf("%d",&Tamb);                              // On récupère la température ambiante
    printf("Temps Final : ");
    scanf("%d",&T);                                 // On récupère le temps maximal
    // h = 0.1
    traitement_pas(0.1,"Erreur_1.txt",y0,T,Tamb);
    // h = 0.01
    traitement_pas(0.01,"Erreur_01.txt",y0,T,Tamb);
    // h = 0.001
    traitement_pas(0.001,"Erreur_001.txt",y0,T,Tamb);
    // h = 0.0001
    traitement_pas(0.0001,"Erreur_0001.txt",y0,T,Tamb);
    // h = 0.00001
    traitement_pas(0.00001,"Erreur_00001.txt",y0,T,Tamb);
}

// Fonction traitement température
void traitement_temp(const char* nomfichier, float y0, float Tamb,float T,float h)
{
    int i;
    float t0 = 1;                           // On initie t0
    int nbsolus = (T - t0) / h;
    float* y_eul = (float*)malloc(nbsolus*sizeof(float));
    float* t_eul = (float*)malloc(nbsolus*sizeof(float));
    float* y_exa = (float*)malloc(nbsolus*sizeof(float));
    float* t_exa = (float*)malloc(nbsolus*sizeof(float));
    FILE* fichier = NULL;
    float* err = (float*)malloc(nbsolus*sizeof(float));
    EulerExplicite(y0,t0,nbsolus,h,y_eul,t_eul,Tamb);          // On calcule les solutions pour Euler
    calcul_solution(y0,Tamb,t0,nbsolus,h,y_exa,t_exa);         // On calcule les solutions directes
    erreur(y_eul,y_exa,err,nbsolus);
    fichier = fopen(nomfichier,"w");
    for(i = 0; i < nbsolus; i++)
        fprintf(fichier,"%f %f \n",t_eul[i],err[i]);           // On stocke les erreurs dans un fichier
    fclose(fichier);
    free(y_eul);
    free(y_exa);
    free(err);
    free(t_eul);
    free(t_exa);
}


//Fonction faisant varier les températures
void test_temp()
{
    float T, h;
    printf("Temps Final : ");
    scanf("%f",&T);                         // On récupère le temps maximal
    printf("Pas de Temps : ");
    scanf("%f",&h);                         // On récupère le pas de temps
    // Cas y0 = 0
    traitement_temp("Erreur_0.txt",0,50,T,h);
    // Cas y0 < Tamb
    traitement_temp("Erreur_infer.txt",20,50,T,h);
    // Cas y0 > Tamb
    traitement_temp("Erreur_super.txt",50,20,T,h);
    //Cas y0 = Tamb 
    traitement_temp("Erreur_egal.txt",50,50,T,h);
    // Cas y0 < 0, Tamb > 0
    traitement_temp("Erreur_yinf0.txt",-50,50,T,h);
    //Cas y0 > 0, Tamb < 0
    traitement_temp("Erreur_ysup0.txt",50,-50,T,h);
    // Cas Tamb = 0
    traitement_temp("Erreur_amb0.txt",50,0,T,h);
}


void test_err()
{
    int pas, temp;
    printf("Tapez 0 pour non , 1 pour oui\n");
    printf("Voulez vous tester en variant le pas de temps ? ");
    scanf("%d",&pas);
    if(pas == 1)
        test_pas();
    printf("Tapez 0 pour non , 1 pour oui\n");
    printf("Voulez vous tester en variant la température ? ");
    scanf("%d",&temp);
    if(temp == 1)
        test_temp();
    exit(0);
}

