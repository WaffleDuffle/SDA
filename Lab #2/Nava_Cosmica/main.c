#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct planeta{
    float x, y, z;
    int ok;
};

struct planeta* citire(struct planeta* x, int n){
    x = malloc(n*sizeof(struct planeta));
    for(int i = 0 ; i < n ; ++i){
        scanf("%f%f%f", &(x+i)->x, &(x+i)->y, &(x+i)->z);
        (x+i)->ok = 1;
    }

    return x;
}

float distanta(float x, float y, float z){
    return sqrt(x*x + y*y + z*z);
}

void parcurgere(struct planeta* planete, struct planeta* nava, int n){
    float rez = 0;

    for(int k = 0 ; k < n ; ++k){
        float mini = 99999;
        int p = 0;
        for(int i = 0 ; i < n ; ++i){
            if((planete+i)->ok == 1){
                float dist = distanta((planete+i)->x - nava->x,
                                      (planete+i)->y - nava->y,
                                      (planete+i)->z - nava->z);
                if(mini > dist)
                    mini = dist, p = i;
            }
        }
        (planete+p)->ok = 0;
        nava = (planete+p);
        rez += mini;
    }
    printf("%.2f", rez);
}
int main(int args, char* argv[]){
    int n;
    scanf("%d", &n);
    struct planeta* planete = citire(planete, n);
    struct planeta* nava = citire(nava, 1);
    parcurgere(planete, nava, n);
    return 0;
}