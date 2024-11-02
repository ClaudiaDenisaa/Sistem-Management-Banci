//
//  Fisier.h
//  _PROIECT_C_
//
//  Created by CLAUDIA-DENISA on 13.04.2024.
//

#ifndef Fisier_h
#define Fisier_h
#pragma once

typedef struct cont {
  char nume[20];
  char prenume[20];
  char iban[25];
  char moneda[5];
  float suma;
} cont;


cont *persoana(char *s);
cont **citire_persoane(int *n, const char *f);
void dealocare(int n,cont **ncont);

void stergere(int *n, cont **ncont, int x, const char *f);
void creare(int *n,cont **ncont,const char *f,int x);
void editare(int x,int n,cont **ncont,const char *f);
void tranzactie (int n,cont **ncont,int x,const char *f);

void vizualizare2(int x,const char *f);
void vizualizare1(const char *f,int x);
void vizualizare(int *n,cont **ncont);
void vizualizare_pers(int n,int x,cont **ncont);


float convert_ron_euro(float x);
float convert_ron_usd(float x);
float convert_euro_ron(float x);
float convert_euro_usd(float x);
float convert_usd_euro(float x);
float convert_usd_ron(float x);

void meniu(int x,int n,cont **ncont);
#endif /* Fisier_h */
