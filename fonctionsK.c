// Fonction K et Primitive de K

// K constante

float fonction_k(float t, float y, float Tamb)
{
    float k;
    k = -0.05;
    return k;
}


float primitive_k(float t,float y,float Tamb,float k)  // Primitive de K, Fonction à modifier selon K
{
    float primit;
    primit = k * t;
    return primit;
}

// K en fonction de t   

/*float fonction_k(float t, float y, float Tamb)
{
    float k;
    k = t;
    return k;
}
*/

// K en fonction de t et de y

/*float fonction_k(float t, float y, float Tamb)
{
    float k;
    k = (y * ln(y)) / (y - Tamb);
    return k;
}
*/
