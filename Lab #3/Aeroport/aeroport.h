#pragma once
struct avion
{
	char* companie;
	char* identificator;
	char* punct_plecare;
	char* punct_sosire;
	int data_plecare;
	int ora_plecare;
	int data_sosire;
	int ora_sosire;
	int randuri_scaune;
	int coloane_scaune;
	int* sablon;
	float pret_bilet;
};

struct terminal
{
	char* nume_aeroport;
	struct avion* avioane;
	int nr_avioane;

};


struct calator
{
	char* nume;
	char* prenume;
	char* punct_plecare;
	char* punct_sosire;
	int data_plecare;
	int ora_plecare;
	int data_sosire;
	int ora_sosire;
	float pret;

};
void meniu_terminal(struct terminal*, int);
char* citeste_sir();
void afiseaza_sir(char*);
int* generare_sablon_avion(int, int);
void afisare_sablon_avion(struct avion*);
struct avion* generare_avion(char*, struct avion*, int*, int);
struct avion* citeste_date_avion(char*, struct avion*, int);  
void afiseaza_date_avion(struct avion*);
void afiseaza_terminal(struct avion*, int);
void eliberare_memorie(struct terminal*);
