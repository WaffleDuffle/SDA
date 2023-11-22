#pragma once

struct client{
    char nume[20];
    struct client* next;
    int nr_produse;
    int val;
};

struct casa{
    int poz;
    int nr_total;
    struct client* clienti;
    struct casa* next;
};

int search_min_casa(struct casa*);
int timp_total(struct casa*);
struct client* add_last_client(struct client*, char*, int);
struct casa* add_last_case(struct casa*, int);
void afisare_lista_clienti(struct client*);
void redistribuire_1(struct client*, struct casa*);
void afisare_lista_case(struct casa*);
void redistribuire_2(struct client*, struct casa*);
void afisare_cazul3(struct casa*, int);