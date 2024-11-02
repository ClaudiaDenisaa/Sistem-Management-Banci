//
//  Actiuni.c
//  _PROIECT_C_
//
//  Created by CLAUDIA-DENISA on 13.04.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fisier.h"

void creare(int *n,cont **ncont,const char *f,int x)
{
    FILE *file;
    file=fopen(f,"a+");
    char inume[20],iprenume[20],iiban[25],imoneda[5],isuma[10000];
    char sir[1000]={0};
    int ok = 0,nr;
    while (!ok) {
          int nr = 0;
          printf("NUME:");
          scanf("%s", inume);
          for (int i = 0; i < strlen(inume); i++)
          {
              if (isalpha(inume[i])) {
                  nr++;
              }
          }
          if (nr == strlen(inume)) {
              ok = 1;
              for (int i = 0; i < strlen(inume); i++) {
                  if(i==0) inume[0]=toupper(inume[0]);
                  else inume[i] = tolower(inume[i]);
              }
        ok = 1;
              strcat(sir, inume);
              strcat(sir, ",");
          } else {
              printf("EROARE! Trebuie sa introduci doar litere!\n");
          }
      }
    (void)(ok=0),nr=0;
    while (!ok) {
          int nr = 0;
          printf("PRENUME:");
          scanf("%s", iprenume);
          for (int i = 0; i < strlen(iprenume); i++)
          {
              if (isalpha(iprenume[i])) {
                  nr++;
              }
          }
          if (nr == strlen(iprenume)) {
              ok = 1;
              for (int i = 0; i < strlen(iprenume); i++)
              {
                  if(i==0) iprenume[0]=toupper(iprenume[0]);
                  else iprenume[i] = tolower(iprenume[i]);
              }
              ok = 1;
              strcat(sir, iprenume);
              strcat(sir, ",");
          } else {
              printf("EROARE! Trebuie sa introduci doar litere!\n");
          }
      }
    
    (void)(ok=0),nr=0;
    while (!ok) {
          int nr = 0,r=1;
          printf("IBAN:");
          scanf("%s", iiban);
          for (int i = 0; i < strlen(iiban); i++)
          {
              if (isalpha(iiban[i])) nr++;
              if (isdigit(iiban[i])) nr++;
          }
        for (int i =0; i <(*n); i++)
        {
            if(strcmp(ncont[i]->iban,iiban)==0) r=0;  //verifica daca exista un alt iban
        }
          if (nr == strlen(iiban) && r==1) {
              ok = 1;
              strcat(sir, iiban);
              strcat(sir, ",");
          } else {
              printf("EROARE! Trebuie sa introduci doar litere si cifre!\n");
          }
      }
    (void)(ok=0),nr=0;
    while (!ok) {
          int nr = 0;
          printf("MONEDA:");
          scanf("%s", imoneda);
          for (int i = 0; i < strlen(imoneda); i++) {
              if (isalpha(imoneda[i])) {
                  nr++;
              }
          }
        for (int i = 0; imoneda[i] != '\0'; i++)
        {
            imoneda[i] = toupper(imoneda[i]);
        }
        if((strcmp(imoneda,"RON")==0 || strcmp(imoneda,"EURO")==0 || strcmp(imoneda,"USD")==0) && nr == strlen(imoneda)) 
        {     ok=1;
              strcat(sir, imoneda);
              strcat(sir, ",");
          } else 
          {
              printf("EROARE! Trebuie sa introduci doar litere!\nMoneda poate fi doar : RON/EURO/USD!\n");
          }
      }
    (void)(ok=0),nr=0;
    while (!ok) {
          int nr = 0;
          printf("SUMA:");
          scanf("%s", isuma);
          for (int i = 0; i < strlen(isuma); i++)
          {
              if (isdigit(isuma[i]))  nr++;
          }
        if (nr == strlen(isuma))
        {
              ok = 1;
              strcat(sir, isuma);
              strcat(sir, "\n");
          } else {
              printf("EROARE! Trebuie sa introduci doar cifre!\n");
          }
      }
    
   fprintf(file, "%s", sir); //adaug datele noului cont in fisier
   fclose(file);
    *ncont = realloc(*ncont, (*n + 1) * sizeof(cont *));
    (*ncont)[*n] = *(cont*)malloc(sizeof(cont));
    char *token = strtok(strdup(sir), ",");
    //(*ncont)[*n].nume = strdup(token);
    strcpy((*ncont)[*n].nume, token);
        token = strtok(NULL, ",");
    //(*ncont)[*n].prenume = strdup(token);
    strcpy((*ncont)[*n].prenume, token);
        token = strtok(NULL, ",");
    strcpy((*ncont)[*n].iban, token);
        token = strtok(NULL, ",");
    strcpy((*ncont)[*n].moneda, token);
        token = strtok(NULL, ",");
    (*ncont)[*n].suma = atof(token);
   printf("Cont creat cu succes!\n");
    printf("\n****************************************\n\n");
    printf("1.MENIU\n");
    printf("2.EXIT\n");
   (*n)++;
    int opt=0;
    while(opt!=1 && opt!=2)
    {
        scanf("%d",&opt);
    }
    switch(opt)
    {
        case 1:
            meniu(x,*n,ncont);
            break;
        case 2:
             dealocare(*n,ncont);
             exit(0);
             break;
        default:break;
    }
}



void stergere(int *n,cont **ncont,int x,const char *f)
{
    if (x < 0 || x >= *n) //daca indexul dat pentru stergere este invalid
    {
       return;
    }
   FILE *file=fopen(f,"w");
   for (int i = 0; i < *n; i++)
   {
       if (i != x)
           {fprintf(file, "%s,%s,%s,%s,%f\n", ncont[i]->nume, ncont[i]->prenume, ncont[i]->iban, ncont[i]->moneda, ncont[i]->suma);}
   }
   fclose(file);
   //free(ncont[x]->nume);
   //free(ncont[x]->prenume);
   free(ncont[x]);
   for (int j = x; j < *n - 1; j++)
   {
       ncont[j] = ncont[j + 1];
   }
   (*n)--;
   printf("Contul a fost sters cu succes!\n");
    printf("\n****************************************\n\n");
    printf("1.MENIU\n");
    printf("2.EXIT\n");
    int opt=0;
    while(opt!=1 && opt!=2)
    {
        printf("Alege 1 sau 2:\n");scanf("%d",&opt);
    }
    switch(opt)
    {
        case 1:
            meniu(x,*n,ncont);
            break;
        case 2:
            
             dealocare(*n,ncont);
             exit(0);
             break;
        
        default:break;
    }
}


