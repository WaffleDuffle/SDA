#include <stdio.h>
#include <stdlib.h>

struct jucator{
    char nume[20];
    int mana[5];
    int punctaj;
};

struct jucator* citire(struct jucator* x, int n){
    x = malloc(n*sizeof(struct jucator));
    for(int i = 0 ; i < n ; ++i){
        scanf("%s%d%d", (x+i)->nume, &(x+i)->mana[0], &(x+i)->mana[1]);
        (x+i)->punctaj = 0;
    }
    return x;
}

int* citire_masa(int* masa, int n){
    masa = malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; ++i)
        scanf("%d", (masa+i));
    return masa;
}

/////////////////////////////////////////////TASK 1/////////////////////////////////////////
void afisare_masa(const int* masa, int n){
    for(int i = 0 ; i < n ; ++i)
        printf("%d ", *(masa+i));

}

void afisare_jucatori(struct jucator* x, int n){
    for(int i = 0 ; i < n ; ++i){
        printf("%s\n%d %d\n", (x+i)->nume, (x+i)->mana[0], (x+i)->mana[1]);
    }
}

///////////////////////////////////////TASK 2////////////////////////////////////////////

void sort(int nr_elemente, int* ptr)
{
    int i, j, temp;

    // Sortare folosind pointeri catre elemente
    for (i = 0; i < nr_elemente - 1; i++) {

        for (j = i + 1; j < nr_elemente; j++) {

            if (*(ptr + j) < *(ptr + i)) {

                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}

int* introducere_in_deck(struct jucator x, const int* masa, int* deck){
    *(deck+0) = x.mana[0];
    *(deck+1) = x.mana[1];
    for(int i = 0 ; i < 5 ; ++i){
        *(deck+i+2) = *(masa+i);
    }
    sort(7, deck);
    return deck;
}

void afisare_rezultat(struct jucator x, const int *deck, int k){
    printf("%s\n", x.nume);
    for(int i = 0 ; i < 5 ; ++i){
        printf("%d ", *(deck+i+k));
    }
    printf("\n");
}

void chinta(struct jucator* x, int* masa, int n){
    int* deck = malloc(7*sizeof(int));


    for(int i = 0 ; i < n ; ++i){
        int nr = 1;
        deck = introducere_in_deck(*(x+i), masa, deck);

        for(int j = 0 ; j < 7 ; ++j){
            if(*(deck+j) == *(deck+j+1) - 1)
                nr++;
            else
                nr = 1;
            if(nr == 5){
                afisare_rezultat(*(x+i), deck, nr-j-2);
            }
        }

    }

}

//////////////////////////////////////////TASK 3///////////////////////////////////////

void afisare_mana(struct jucator* x, int n){
    for(int i = 0 ; i < n ; ++i, printf("\n")){
        printf("%s\n", (x+i)->nume);
        for(int j = 0 ; j < 5 ; ++j)
            printf("%d ", (x+i)->mana[j]);
    }
}

struct jucator* mana_buna(struct jucator* x, int* masa, int n){
    int* deck = malloc(7*sizeof(int));

    int nr = 0;
    deck = introducere_in_deck(*x, masa, deck);
    for(int j = 0 ; j < 3 ; ++j){
        if((*(deck+j) == *(deck+j+1)) && (*(deck+j) == *(deck+j+2))){
            x->mana[nr] = *(deck+j);
            x->mana[nr+1] = *(deck+j+1);
            x->mana[nr+2] = *(deck+j+2);
            nr += 3;
            j += 2;
        }
        else if(*(deck+j) == *(deck+j+1)){
            x->mana[nr] = *(deck+j);
            x->mana[nr+1] = *(deck+j+1);
            nr += 2;
            j++;
        }
    }

        for(int j = nr+2 ; j < 7 ; ++j) {
            x->mana[nr++] = *(deck + j);

        }
    return x;
}

//////////////////////////////////////TASK 4///////////////////////////////////////////

void afisare_nume(struct jucator*x, int n){
    for(int i = 0 ; i < n ; ++i, printf("\n"))
        printf("%s", (x+i)->nume);
}

void calcul_punctaj(struct jucator* x){
        for(int i = 0 ; i < 5 ; ++i){
            if(x->mana[i] == x->mana[i+1] && x->mana[i] == x->mana[i+2]){
                x->punctaj += 3;
                i += 2;
            }
            else if(x->mana[i] == x->mana[i+1]){
                x->punctaj += 1;
                i++;
            }
        }

}
int compare_eq(struct jucator x1, struct jucator x2){
    for(int i = 4 ; i >= 0 ; --i){
        if(x1.mana[i] > x2.mana[i])
            return 1;
        else if(x1.mana[i] < x2.mana[i])
            return 0;
    }
}

void sort_mana(struct jucator* x, int n){
    for(int i = 0 ; i < n-1 ; ++i)
        for(int j = i+1 ; j < n ; ++j){
            if((x+i)->punctaj < (x+j)->punctaj){
                struct jucator tmp;
                tmp = *(x+i);
                *(x+i) = *(x+j);
                *(x+j) = tmp;
            }
            else if((x+i)->punctaj == (x+j)->punctaj){
                if(compare_eq(*(x+i), *(x+j)) == 0){
                    struct jucator tmp;
                    tmp = *(x+i);
                    *(x+i) = *(x+j);
                    *(x+j) = tmp;
                }
            }
        }
}

int main(){
    int n;
    scanf("%d", &n);
    struct jucator *jucatori = citire(jucatori, n);
    int* masa = citire_masa(masa, 5);
    int op;
    scanf("%d", &op);
    switch(op){
        case 1: {
            afisare_jucatori(jucatori, n);
            afisare_masa(masa, 5);
            break;
        }
        case 2: {
            chinta(jucatori, masa, n);
            break;
        }
        case 3: {
            for(int i = 0 ; i < n ; ++i)
                mana_buna((jucatori+i), masa, n);
            afisare_mana(jucatori, n);
            break;
        }
        case 4: {
            for(int i = 0 ; i < n ; ++i){
                mana_buna((jucatori + i), masa, n);
                calcul_punctaj((jucatori+i));
            }
            sort_mana(jucatori, n);
            afisare_nume(jucatori, n);
        }
    }

    return 0;
}