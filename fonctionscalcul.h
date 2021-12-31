#ifndef DEF_FONCTIONSCALCUL
#define DEF_FONCTIONSCALCUL

void EulerExplicite(float y0, float t0,float nbsolus, float h, float* y, float* t, float Tamb);

void calcul_solution(float y0, float Tamb, float t0,float nbsolus, float h, float* y, float* t);

#endif