#pragma once

struct calendar{
    char nume[20];
    int data;
    struct calendar* next;
};

int my_strcmp(char*, char*);
int dimensiune_lista(struct calendar*);
struct calendar* creare_nod();
struct calendar* adaugare_sfarsit(struct calendar*);
struct NOD * stergere_lista(struct NOD *);
void my_strcpy(char*, char*);
void afisare_elemente(struct calendar*);
void afisare_dupa_nume(struct calendar*, char*);
void afisare_dupa_data(struct calendar*, int);
void sort_cronologic(struct calendar*);
