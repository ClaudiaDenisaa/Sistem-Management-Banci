//
//  Resurse.c
//  _PROIECT_C_
//
//  Created by CLAUDIA-DENISA on 13.04.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fisier.h"



cont *persoana(char *line) {
  cont *pers = (cont*)malloc(sizeof(cont));
  char *token = strtok(line, ",");
  strcpy(pers->nume, token);
  token = strtok(NULL, ",");
  strcpy(pers->prenume, token);
  token = strtok(NULL, ",");
  strcpy(pers->iban, token);
  token = strtok(NULL, ",");
  strcpy(pers->moneda, token);
  token = strtok(NULL, ",");
  pers->suma = atof(token);
  return pers;
}

cont **citire_persoane(int *n, const char *f) {
  int i = 0;
  cont **ncont = (cont **)malloc((*n) * sizeof(cont *));
  if (ncont == NULL) {
    printf("Eroare la alocarea memoriei pentru ncont.\n");
    return NULL;}
  FILE *file;
  file = fopen(f, "r");
  if (file == NULL) // fisier gol
  {
    printf("Fisierul nu poate fi deschis!");
    // free(cont);
    return NULL;
  }
  char line[256];
  while (fgets(line, sizeof(line), file) != NULL) {
    ncont[i] = persoana(line);
    i++;
    (*n)++;
  }
  fclose(file);
  return ncont;
}

void dealocare(int n,cont **ncont)
{
   for (int i = 0; i <n; i++) {
       if (ncont[i] != 0) {
           //free(ncont[i]->nume);
           //free(ncont[i]->prenume);
           free(ncont[i]);
       }
   }
   free(ncont);
}


float convert_ron_euro(float x)
{
    x=x/4.97;
    return x;
}
float convert_ron_usd(float x)
{
    x=x/4.67;
    return x;
}
float convert_euro_ron(float x)
{
    x=x*4.97;
    return x;
}
float convert_euro_usd(float x)
{
    x=x*1.20;
    return x;
}
float convert_usd_euro(float x)
{
    x=x/1.20;
    return x;
}
float convert_usd_ron(float x)
{
    x=x*4.67;
    return x;
}


void meniu(int x,int n,cont **ncont) 
{      printf("\n****************************************\n");
       printf("                  MENIU                 \n");
       printf("****************************************\n\n");
       printf("1. Creare cont nou\n");
       printf("2. Stergere cont actual\n");
       printf("3. Editare cont actual\n");
       printf("4. Tranzactie\n");
    printf("5. Conturile mele\n");
    printf("6. Contul actual\n");
    printf("7. Iesire\n");
    printf("****************************************\n\n");
    
    int optiune=0;
        while(optiune!=1 && optiune!=2 && optiune!=3 && optiune!=4 && optiune!=5 && optiune!=6 && optiune!=7 )
        {printf("Optiune:");scanf("%opt",&optiune);}
    
        switch(optiune) {
            case 1:
                    creare(&n,ncont,"baza_de_date.csv",x);
                break;
            case 2:
                stergere(&n,ncont,x, "baza_de_date.csv");
                break;
            case 3:
                editare(x,n,ncont,"baza_de_date.csv");
                break;
            case 4:
                tranzactie (n,ncont,x,"baza_de_date.csv");
                break;
            case 5:vizualizare_pers(n,x,ncont);meniu(x,n,ncont);break;
            case 6:printf("\n\nContul actual are IBAN:%s MONEDA:%s SUMA:%f!\n\n",ncont[x]->iban,ncont[x]->moneda,ncont[x]->suma);meniu(x,n,ncont);break;
            case 7:dealocare(n,ncont);
                exit(0);
                break;
            default:
                break;
        }
}
