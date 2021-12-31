#ifndef DEF_TEST
#define DEF_TEST

void erreur(float* y_eul, float* y_exa, float* err, int nbsolus);
void test_pas();
void test_temp();
void test_err();
void traitement_temp(const char* nomfichier, float y0, float Tamb);
void traitement_pas(float h,const char* nomfichier);
#endif