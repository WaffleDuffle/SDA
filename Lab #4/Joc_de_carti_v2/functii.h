#pragma once

struct jucator{
    int carte;
    char nume[20];
    struct jucator* next;

};

struct jucator* creare_nod();
struct jucator* adaugare_sfarsit_lista(struct jucator*);
struct jucator* adaugare_carti(struct jucator*, const int*);
struct jucator* stergere_jucator(struct jucator*, int);
void afisare_lista(struct jucator*);