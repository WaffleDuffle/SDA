#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"

int main() {
    unsigned short n;
    char input_filename[] = "date.in";
    FILE *in = fopen(input_filename, "rt");
    if(in == NULL){
        fprintf(stderr, "ERROR: Fisierul nu a putut fi deschis");
        return -1;
    }

    fscanf(in, "%hu", &n);

    struct catalog *elevi = (struct catalog*)malloc(n*sizeof(struct catalog));
    if(elevi == NULL){
        fprintf(stderr, "ERROR: Alocare de memorie esuata");
        return -1;
    }

    citire_date(elevi, n, in);
    afisare_date(elevi, n);
    count(elevi,n);
    eliberare_memorie(elevi, n);
    free(elevi);

    return 0;
}
