#include "fonctionsK.h"
#include <math.h>

// Ce fichier contient les fonctions servant à calculer les solutions de Y 



// Fonction utilisant Euler 
void EulerExplicite(float y0, float t0,float nbsolus, float h, float* y, float* t, float Tamb)
{
    int i;
    t[0] = t0;
    y[0] = y0;
    for(i = 1; i < nbsolus; i++)
    {
        y0 = y0 + h * (fonction_k(t0,y0,Tamb));  // y(t) = y(t) + h * k(t)
        t0 = t0 + h;                
        y[i] = y0;                              // On stocke la valeur de y(t) pour chaque t
        t[i] = t0;
    }
}

// Fonction utilisant solutions directes
void calcul_solution(float y0, float Tamb, float t0,float nbsolus, float h, float* y, float* t)
{    
    int i;
    t[0] = t0;
    y[0] = y0;
    float c = y0 - Tamb;               
    for(i = 1; i < nbsolus; i++)
    {
        y0 = Tamb + c * exp(primitive_k(t0,y0,Tamb,fonction_k(t0,y0,Tamb))); // Tamb + c * e^(k * t)
        t0 = t0 + h;
        y[i] = y0;                          // On stocke la valeur de y(t) pour chaque t
        t[i] = t0;
    }
}