#ifndef CATALOG_H
#define CATALOG_H

#define CMAX 15
#include <stdio.h>
struct catalog{
    char nume[CMAX];
    char prenume[CMAX];
    int *note;
};

void citire_date(struct catalog*, int, FILE*);
void afisare_date(struct catalog*, int);
void eliberare_memorie(struct catalog*, int);
void count(struct catalog*, int);
#endif