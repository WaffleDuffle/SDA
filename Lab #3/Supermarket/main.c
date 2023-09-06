#include <stdio.h>
#include "Megafurr.h"
#include <stdlib.h>
int main() {
    char input_filename[] = "date.in";
    FILE *in = fopen(input_filename, "rt");
    if(in == NULL){
        fprintf(stderr, "ERROR: Fisierul nu a putut fi deschis\n");
    }
    int b, n;
    fscanf(in, "%d%d", &b, &n);

    //alocam dinamic vectori si structuri
    struct megafurr *baza_de_date = (struct megafurr*)malloc(b*sizeof(struct megafurr));
    if(baza_de_date == NULL){
        fprintf(stderr, "ERROR: Alocarea pentru baza de date a esuat\n");
        return -1;
    }
    int *produse = (int*)malloc(n*sizeof(int));
    if(produse == NULL){
        fprintf(stderr, "ERROR: Alocarea pentru produse a esuat\n");
        return -1;
    }

    //citim din date.in
    citire_baza(baza_de_date, b, in);
    citire_produse(produse, n, in);

    //afisam rezultatul
    printf("%.2f\n", suma_totala(baza_de_date, produse, b, n));

    //inchidem fisierul
    fclose(in);

    //eliberam memoria
    free(baza_de_date);
    free(produse);
    return 0;
}
