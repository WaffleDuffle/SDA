#include <stdio.h>
#include <stdlib.h>


struct nava{
    int scut;
    int fazer;
};

bool fight(struct nava nava1, struct nava nava2){
    while(true){
        nava1.scut -= nava2.fazer;
        if(nava1.scut < 0){
            printf("Nava proprie a fost distrusa  %d\n", nava1.scut);
            return 0;
        }
        nava2.scut -= nava1.fazer;
        if(nava2.scut < 0){
            printf("Nava inamica a fost distrusa  %d\n", nava1.scut);
            return 1;
        }
    }
}

void joc(struct nava *eu, struct nava *nave_inamice, int n){
    int nr = 0;
    
    for(int i = 0 ; i < n ; ++i)
        nr += fight(*eu, *(nave_inamice + i));
    
    printf("%d", nr);
}

int main(){
    int n;
    struct nava *eu = (struct nava*)malloc(n*sizeof(struct nava));
    scanf("%d%d", &eu->scut, &eu->fazer);
    scanf("%d", &n);
    struct nava *nave_inamice = (struct nava*)malloc(n*sizeof(struct nava));
    for(int i = 0 ; i < n ; ++i)
        scanf("%d%d", &(nave_inamice + i)->scut, &(nave_inamice + i)->fazer);
    joc(eu, nave_inamice, n);
    free(eu);
    free(nave_inamice);
    return 0;

}
