#pragma once

struct masina{
    char nr_inmatriculare[20];
    struct masina* next;
};


int is_empty(struct masina*);
int size(struct masina*);
void enqueue(struct masina**, char*);
void afisare(struct masina**);
struct masina* dequeue(struct masina*);
struct masina* interclasare(struct masina*, struct masina*);
