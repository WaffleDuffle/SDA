#pragma once

struct copii{
    char nume[30];
    struct cadouri* cadouri;
    struct copii* next;
};

struct cadouri{
    char cadou[30];
    struct cadorui* next;
};
char** citire_jucarii(char**, int);
struct copii* creare_nod(char*);
struct copii* add_last(struct copii*, char*);
struct cadouri* creare_nod_cadou(char*);
struct cadorui* add_last_cadou(struct cadouri*, char*);
void gestiune_cadouri(struct copii*, char**, int);
void afisare_copii(struct copii*);
void afisare_cadouri(struct cadouri*);

