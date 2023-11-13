#ifndef FUNCTII_H
#define FUNCTII_H

#include <stdlib.h>
#include <stdio.h>

/* definire structura stocare date in lista */
struct NOD {
    char cuvant[20];
    struct NOD * next;

};

struct NOD * creare_nod();
struct NOD * adaugare_nod_inceput_lista(struct NOD *);
struct NOD * adaugare_nod_sfarsit_lista(struct NOD *);
struct NOD * adaugare_nod_oriunde_lista(struct NOD *, int);
struct NOD * populare_lista(struct NOD *, int);
struct NOD * stergere_nod_inceput_lista(struct NOD *);
struct NOD * stergere_nod_sfarsit_lista(struct NOD *);
struct NOD * stergere_nod_oriunde_lista(struct NOD *, int);
struct NOD * stergere_lista(struct NOD *);
int dim_lista(struct NOD *);
void afisare_lista(struct NOD *);

#endif