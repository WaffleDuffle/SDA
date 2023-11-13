#include "functii.h"

/* functie creare a unui nod */
struct NOD * creare_nod(){
    struct NOD * nod;

    /* alocare memorie nod*/
    nod = (struct NOD * ) malloc(sizeof(struct NOD));

    if (nod == NULL) {
        perror("ERROR: memoria nu a putut fi alocata!\n");
        return NULL;
    }

    /* citire valori nod */
    printf("\nIntroduceti cuvant:");
    scanf("%s", nod -> cuvant);

    nod -> next = NULL;

    return nod;
}

/* functie populare lista cu n cuvinte */
struct NOD * populare_lista(struct NOD * head, int n){
    int i;
    for (i = 0; i < n; i++){
        head = adaugare_nod_sfarsit_lista(head);
    }
    return head;
}

/* functie afisare lista cuvinte */
void afisare_lista(struct NOD * head){
    int i = 0;
    struct NOD * nod_curent;

    if (head == NULL) {
        printf("Atentie, lista este goala!\n");
        return;
    }

    nod_curent = head;

    while (nod_curent != NULL) {
        /* afisare valoare curenta si pozitionare nod urmator */
        printf("%d: %s\n", i++, nod_curent -> cuvant);
        nod_curent = nod_curent -> next;
    }
}

/* functie adaugare cuvant la inceputul listei */
struct NOD * adaugare_nod_inceput_lista(struct NOD * head) {
    if (head == NULL) {
        printf("Atentie: lista este goala.");
        head = creare_nod();
        printf("Cuvantul a fost adaugat.\n");
        return head;
    }
    struct NOD * nod_nou = creare_nod();
//    if(head == NULL){
//        head = creare_nod();
//        return head;
//    }
//    nod_nou = malloc(sizeof(struct NOD));
//    if(nod_nou == NULL){
//        printf("ERROR: Memoria nu a putut fi alocata!");
//        return head;
//    }
//    printf("\nIntroduceti cuvant:");
//    scanf("%s", nod_nou -> cuvant);
//    printf("Cuvantul a fost adaugat.\n");
//    nod_nou->next = head;
    nod_nou -> next = head;
    return nod_nou;

}

/* functie adaugare cuvant la sfarsitul listei */
struct NOD * adaugare_nod_sfarsit_lista(struct NOD * head) {
    struct NOD * nod_curent, * nod_nou;

    if (head == NULL) {
        printf("Atentie: lista este goala.");
        head = creare_nod();
        printf("Cuvantul a fost adaugat.\n");
        return head;
    }

    /*parcurge lista element cu element pentru a ajunge la ultimul nod*/
    nod_curent = head;

    while (nod_curent != NULL) {
        if (nod_curent -> next == NULL) {
            /* creare si inserare nod nou in lista */
            nod_nou = creare_nod();
            nod_curent -> next = nod_nou;

            printf("Cuvantul a fost adaugat.\n");
            return head;
        }
        nod_curent = nod_curent -> next;
    }
}

struct NOD * adaugare_nod_oriunde_lista(struct NOD * head, int poz){
    if (head == NULL) {
        printf("Atentie, lista este goala!");
        head = creare_nod();
        printf("Cuvantul a fost adaugat.\n");
        return head;
    }
    int i = 0;
    struct NOD * nod_nou;
    struct NOD * tmp = head;
    while(tmp != NULL){
        if(poz == i++){
            if(tmp -> next == NULL){
                nod_nou = creare_nod();
                tmp -> next = nod_nou;

                printf("Cuvantul a fost adaugat.\n");
                return head;
            }
            else{
                nod_nou = creare_nod();
                nod_nou -> next = tmp -> next;
                tmp -> next = nod_nou;
                return head;
            }

        }
        tmp = tmp -> next;
    }
    perror("ERROR: Pozitia depaseste dimenisunea listei!\n");
}

struct NOD * stergere_nod_inceput_lista(struct NOD * head){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return NULL;
    }
    else if(head -> next == NULL){
        free(head);
        printf("Lista a fost sterasa\n");
        return NULL;
    }
    else{
        struct NOD * nodSters = head;
        head = head -> next;
        free(nodSters);
        printf("Cuvantul a fost sters.\n");
        return head;
    }
}

struct NOD * stergere_nod_sfarsit_lista(struct NOD * head){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return head;
    }
    struct NOD * tmp = head;
    while(tmp -> next != NULL){
        if(tmp -> next -> next == NULL){
            struct NOD * nodSters = tmp -> next;
            tmp -> next = NULL;
            free(nodSters);
            printf("Cuvantul a fost sters.\n");
            return head;
        }
        tmp = tmp -> next;
    }
}

struct NOD * stergere_nod_oriunde_lista(struct NOD * head, int poz){

    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return head;
    }
    else if(head -> next == NULL){
        head = stergere_nod_inceput_lista(head);
        printf("Atentie, Lista este goala!\n");
        return head;
    }
    else if(poz - 1 == dim_lista(head)){
        head = stergere_nod_sfarsit_lista(head);
        printf("Cuvantul a fost sters.\n");
        return head;
    }
    int i = 0;
    struct NOD * tmp = head;
    while(tmp -> next != NULL){
        if(poz - 1 == i++){
            struct NOD * nodSters = tmp -> next;
            tmp -> next = nodSters -> next;
            free(nodSters);
            return head;
        }
        tmp = tmp -> next;
    }
    perror("ERROR: Pozitia depaseste dimenisunea listei!\n");
}

struct NOD * stergere_lista(struct NOD * head){
    struct NOD * tmp = head;
    while(tmp != NULL) {
        tmp = tmp->next;
        free(head);
        head = tmp;
    }
    printf("Lista a fost stearsa.\n");
    return head;
}

int dim_lista(struct NOD * head){
    int nr = 0;
    struct NOD * tmp = head;
    while(tmp != NULL){
        nr++;
        tmp = tmp->next;
    }
    return nr;
}