/*Sa se realizeze in limbajul C o interfață pentru managementul de conținut menită să înregistreze liniile aeriene regulate pentru un aeroport . În acest context, interfața trebuie să permită întregistrarea liniilor aeriene atât pentru terminalul de plecări, cât și pentru terminalul de sosiri. Astfel, un terminal este asociat unui aeroport și este definit de numărul total de linii aeriene precum și de liniile aeriene respective. O linie aeriană este definită de numele companiei de care aparține, identificatorul unic, punctul de plecare, punctul de sosire, data de plecare, ora de plecare, data de sosire, ora de sosire, numărul de coloane de scaune, numărul de linii de scaune, sablonul liniei aeriene, si prețul biletului pentru linia respectivă.

Studiați soluția atașată, modificați și extindeți capabilitatea programului să permită unui potențial călător să interacționeze cu datele înregistrare prin obținerea programului zborurilor ordonate după: punctul de plecare, dată, oră, prețul biletului, sau căutate după punctul de plecare, dată, și oră.

Exemplu intrare: 
Introduceti numele aeroportului: OTOPENI 
Meniu: 
1: Terminal plecari 
2: Terminal sosiri 
0: Iesire 
1 
Meniu terminal plecari: 
1: Adaugare avion. 
2: Afiseaza avioane inregistrate. 
0: Iesire! 
1 
Introduceti numele companiei (alfanumeric): TAROM 
Introduceti identificatorul avionului (alfanumeric): TA541 
Numar randuri scaune (int): 30
Numar coloane scaune (int): 6 
Pleaca de la aeroportul OTOPENI 
Soseste la aeroportul (format alfanumeric): GENEVA 
Pleaca la data ((int) format AAAALLZZ) : 20200320 
Pleaca la ora ((int) format hhmm): 1730 
Soseste la data ((int) format AAAALLZZ): 20200320 
Soseste la ora ((int) format hhmm): 2300 
Pret bilet (float): 985.65 
Meniu terminal plecari: 
1: Adaugare avion. 
2: Afiseaza avioane inregistrate. 
0: Iesire!*/

#include <stdio.h>
#include <stdlib.h>
#include "aeroport.h"

int main()
{
    int optiune;
    // Declarare terminale aeroport si alocare memorie
    struct terminal* plecari = (struct terminal*)malloc(sizeof(struct terminal));
    struct terminal* sosiri  = (struct terminal*)malloc(sizeof(struct terminal));

    // Initializare terminale aeroport
    printf("Introduceti numele aeroportului: ");
    plecari->nume_aeroport = citeste_sir();
    sosiri->nume_aeroport = plecari->nume_aeroport;

    plecari->avioane = sosiri->avioane = NULL;
    plecari->nr_avioane = sosiri->nr_avioane = 0;


    do {
        printf("Meniu:\n");
        printf("1: Terminal plecari\n");
        printf("2: Terminal sosiri\n");
        printf("0: Iesire\n");

        scanf("%d%*c", &optiune);
        switch (optiune)
        {
        case 0:
            eliberare_memorie(plecari);
            eliberare_memorie(sosiri);
            free(plecari);
            free(sosiri);
            /*
             Functia exit() determina terminarea executiei programului. 
             Parametrul functiiei exit() defineste starea programului la momentul
             apelului. Valoarea zero defineste o terminare normala a executiei
             programului, iar o valoare diferita de zero semnaleaza prezenta unei erori.
             */
            exit(0);
        case 1:
            meniu_terminal(plecari, optiune);
            break;
        case 2:
            meniu_terminal(sosiri, optiune);
            break;
        }
    } while (optiune);

    return 0;
}
