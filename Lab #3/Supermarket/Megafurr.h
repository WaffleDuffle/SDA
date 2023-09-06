#ifndef MEGAFURR_H
#define MEGAFURR_H
#include <stdio.h>
struct megafurr{
    int cod;
    char tip;
    float val;
};

void citire_baza(struct megafurr*, int, FILE*);
void citire_produse(int*, int, FILE*);
void afisare_baza(struct megafurr*, int);
void afisare_produse(int*, int);
float suma_totala(struct megafurr*, const int*, int, int);

#endif