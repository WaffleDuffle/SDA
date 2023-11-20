#pragma once

struct cuvant{
    char x;
    struct cuvant* next;
};

struct cuvant* creare_nod(char);
struct cuvant* push(struct cuvant*, char);
struct cuvant* pop(struct cuvant*);
struct cuvant* merge(struct cuvant*, struct cuvant*);
void afisare(struct cuvant*);