/* Să se realizeze un program ce permite stocarea numelui, prenumelui, salariului plătit pe oră, numărului de ore lucrate într-o lună şi a salariului total pentru fiecare din angajaţii unei companii (maxim 100 de angajați). Salariul total va fi calculat în funcţie de numărul de ore lucrate, astfel încât dacă numărul de ore lucrate pe lună depăşeşte valoarea 160, se adaugă un bonus de 50% la orele lucrate în plus. La final, programul va afişa pe ecran numele şi prenumele angajaţilor care au salariul lunar mai mare ca o valoare specificată.

Date de intrare:
- nr. de angajati (int)
- pentru fiecare angajat:
- nume (sir caractere)
- prenume (sir caractere)
- salariu pe ora (float)
- numar de ore lucrate (int)
- salariul minim specificat (float)

Date de iesire:
<nume> <prenume> <salariu (cu 2 zecimale)> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Angajat{
    char nume[10];
    char prenume[10];
    float sal_ora;
    int nr_ore;
    float salariu;
}angajati[100];

void afisare(struct Angajat angajat){
    printf("%s %s %.2f\n", angajat.nume, angajat.prenume, angajat.salariu);
}

float calcul_salariu(struct Angajat angajat){
    angajat.salariu = angajat.sal_ora * angajat.nr_ore;
        if(angajat.nr_ore > 160)
            angajat.salariu += ((angajat.nr_ore - 160)*angajat.sal_ora)/2;
    return angajat.salariu;
}

int main(){
    int n;
    float sal_min;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%s", angajati[i].nume);
        scanf("%s", angajati[i].prenume);
        scanf("%f%d", &angajati[i].sal_ora, &angajati[i].nr_ore);
        
    }
    scanf("%f", &sal_min);
    for(int i = 0 ; i < n ; ++i){
        angajati[i].salariu = calcul_salariu(angajati[i]);
        if(angajati[i].salariu > sal_min)
            afisare(angajati[i]);
        
    }
    return 0;
}
