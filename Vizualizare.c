//
//  Vizualizare.c
//  _PROIECT_C_
//
//  Created by CLAUDIA-DENISA on 13.04.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fisier.h"

void vizualizare2(int x,const char *f)//toate conturile citite din fisier fara persoana care s a logat
{
    printf("\n****************************************\n");
    FILE *file;
    file=fopen(f,"r");
    if(file==NULL)
    {
        printf("NU EXISTA CONTURI!");
    }
    int i=0;
    char line[256];
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        if(x!=i) printf("%d.%s",i,line);
        i++;
    }
    fclose(file);
    printf("\n****************************************\n");
}


void vizualizare1(const char *f,int x)//conturile lui x citite din fisier
{
    printf("\n****************************************\n");
    FILE*file=fopen(f,"r");
    int i=0;
    char linie[256];
    while(fgets(linie,sizeof(linie),file)!=NULL)
    {
        if(x==i) {char *p=strtok(linie,",");
            printf("%d.%s ",i,p);//nume
            p=strtok(NULL,",");
            printf("%s ",p);//prenume
            p=strtok(NULL,",");
            printf("%s ",p);//iban
            p=strtok(NULL,",");
            printf("%s ",p);//moneda
            p=strtok(NULL,",");
            printf("%s ",p);//suma
        }
    }
    fclose(file);
    printf("\n****************************************\n");
}


void vizualizare(int *n,cont **ncont)//toate conturile din ncont, folosim la tranzactie
{printf("\n****************************************\n");
    
   for(int i=0;i<(*n);i++)
   {       printf("%d.%s %s, %s, %s, %f\n",i,ncont[i]->nume,ncont[i]->prenume,ncont[i]->iban,ncont[i]->moneda,ncont[i]->suma);
   }
    printf("****************************************\n");
}


void vizualizare_pers(int n,int x,cont **ncont)  //toate conturile ale unei persoane din ncont
{printf("\n****************************************\n");
    char *inume=strdup(ncont[x]->nume);
    char *iprenume=strdup(ncont[x]->prenume);
    for(int i=0;i<n;i++)
    {
       if((strcasecmp(ncont[i]->nume,inume)==0) && (strcmp(ncont[i]->prenume,iprenume)==0))
             {printf("%d.%s %s, %s, %s, %f\n",i,ncont[i]->nume,ncont[i]->prenume,ncont[i]->iban,ncont[i]->moneda,ncont[i]->suma);
              }
    }
    printf("****************************************\n");
}
