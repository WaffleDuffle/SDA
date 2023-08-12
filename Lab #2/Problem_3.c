/* Să se realizeze un program ce permite stocarea imaginilor unei secvenţe video. Fiecare imagine va conţine următoarele informaţii: o matrice de dimensiune m x n de valori <=16 (imagine), un şir de caractere de maxim 10 elemente (nume) şi histograma imaginii (numărul de apariţii ale fiecărei valori din matrice).

Date de intrare:

numarul de imagini din secventa video (int)
numarul de linii al unei imagini (int)
numarul de coloane al unei imagini (int)
pentru fiecare imagine din secventa:
nume imagine (secventa de caractere)
valorile imaginii (nr_linii * nr_col intregi)
Date de iesire:
valorile fiecarei imagini, in ordinea citirii de la tastatura, separate de un spatiu, pe linii si coloane
histogramele fiecarei imagini (16 valori intregi)*/

#include <stdio.h>
#include <stdlib.h>

struct Imagine{
    int **mat;
    char nume[20];
    int hist[16];
};

void printmat(struct Imagine *imagine, int n, int linii, int coloane){
    for(int k = 0 ; k < n ; ++k){
        for(int i = 0 ; i < linii ; ++i, printf("\n"))
            for(int j = 0 ; j < coloane ; ++j)
                printf("%d ", (imagine + k)->mat[i][j]);
    }
}

void citiremat(struct Imagine *imagine, int n, int linii, int coloane){
    for(int k = 0 ; k < n ; ++k){
        scanf("%s", (imagine + k)->nume);
        (imagine + k)->mat = malloc(linii*sizeof(int*));
        if((imagine + k)->mat == NULL) printf("Alocare esuata!");
            
        for(int i = 0 ; i < linii ; ++i)
            (imagine + k)->mat[i] = calloc(coloane, sizeof(int));
                
        for(int i = 0 ; i < linii ; ++i)
            for(int j = 0 ; j < coloane ; ++j)
                scanf("%d", &(imagine + k)->mat[i][j]);
    }
}

void frecventa(struct Imagine *imagine, int n, int linii, int coloane){
    for(int k = 0 ; k < n ; ++k){
        
        for(int i = 0 ; i < linii ; ++i)
            for(int j = 0 ; j < coloane ; ++j)
                (imagine + k)->hist[(imagine + k)->mat[i][j]]++;
                
        for(int i = 0 ; i < 16 ; ++i)
            printf("%d ", (imagine + k)->hist[i]);
        printf("\n");
    }
}

int main(){
    int linii, coloane, n;
    scanf("%d%d%d", &n, &linii, &coloane);
    
    struct Imagine *imagine = malloc(n*sizeof(struct Imagine));
    citiremat(imagine, n, linii, coloane);
    printmat(imagine, n, linii, coloane);
    frecventa(imagine, n, linii, coloane);
    
    return 0;
}

