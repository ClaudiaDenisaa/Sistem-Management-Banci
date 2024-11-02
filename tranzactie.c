//
//  tranzactie.c
//  _PROIECT_C_
//
//  Created by CLAUDIA-DENISA on 13.04.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fisier.h"

void tranzactie (int n,cont **ncont,int x,const char *f)//la x scadem isuma,la y adaugam isuma in functie de ce moneda are
{
    float isuma = 0.0;
    int y = 0;
    vizualizare2(x,"baza_de_date.csv");
    int o=0;
    while(o!=1)
    {
        printf("Alege numarul din dreptul persoanei la care vrei sa faci un transfer:");
        scanf("%d",&y);
            if(y==x) printf("Nu va puteti transfera dumneavoastra!\n");
            else {if(y>n) printf("Alegeti un cont existent!\n");
                else o=1;}
        }
    int u=0;
    while(u!=1) //verificare suma
    { printf("Introdu suma:");scanf("%f",&isuma);
    if(isuma<ncont[x]->suma) u=1;
    else printf("Nu aveti suficiente fonduri!\n");
    }
    /*int ok=0;
    while(ok!=1)
    {
        printf("Alege moneda (RON,EURO,USD) :");scanf("%s",imoneda);
        for (int i = 0; imoneda[i] != '\0'; i++)
        {
            imoneda[i] = toupper(imoneda[i]);
        }
        if(strcmp(imoneda,"RON")==0 || strcmp(imoneda,"EURO")==0 || strcmp(imoneda,"USD")==0) ok=1;
        else printf("Moneda poate fi doar : RON/EURO/USD");
    }*/
    FILE *file;
    file = fopen("baza_de_date.csv", "r+");
        if (file == NULL) {
            printf("NU exista conturi!");
            //intoarcere la meniu();
        }
    char line[256];
    int i=0;
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        if(x==i) {ncont[x]->suma=ncont[x]->suma - isuma;
                fseek(file, -strlen(line), SEEK_CUR);
                fprintf(file, "%s,%s,%s,%s,%f\n", ncont[x]->nume, ncont[x]->prenume, ncont[x]->iban, ncont[x]->moneda, isuma);
            }
    
        if(y==i)
            {   fseek(file, -strlen(line), SEEK_CUR);
                if(strcmp(ncont[y]->moneda,ncont[x]->moneda)==0)
                {ncont[y]->suma=ncont[y]->suma+isuma;
                    fprintf(file, "%s,%s,%s,%s,%f\n", ncont[y]->nume,ncont[y]->prenume, ncont[y]->iban, ncont[y]->moneda, ncont[y]->suma);}
                else{
                    
                    if((strcmp(ncont[x]->moneda,"RON")==0) && (strcmp(ncont[y]->moneda,"EURO")==0))
                    {isuma=convert_ron_euro(isuma);
                        ncont[y]->suma=ncont[y]->suma+isuma;
                        fprintf(file, "%s,%s,%s,%s,%f\n", ncont[y]->nume,ncont[y]->prenume, ncont[y]->iban, ncont[y]->moneda, ncont[y]->suma);}
                    if((strcmp(ncont[x]->moneda,"RON")==0) && (strcmp(ncont[y]->moneda,"USD")==0))
                    {isuma=convert_ron_usd(isuma);
                        ncont[y]->suma=ncont[y]->suma+isuma;
                        fprintf(file, "%s,%s,%s,%s,%f\n", ncont[y]->nume,ncont[y]->prenume, ncont[y]->iban, ncont[y]->moneda, ncont[y]->suma);}
                    if((strcmp(ncont[x]->moneda,"EURO")==0) && (strcmp(ncont[y]->moneda,"RON")==0))
                    {isuma=convert_euro_ron(isuma);
                        ncont[y]->suma=ncont[y]->suma+isuma;
                        fprintf(file, "%s,%s,%s,%s,%f\n", ncont[y]->nume,ncont[y]->prenume, ncont[y]->iban, ncont[y]->moneda, ncont[y]->suma);}
                    if((strcmp(ncont[x]->moneda,"EURO")==0) && (strcmp(ncont[y]->moneda,"USD")==0))
                    {isuma=convert_euro_usd(isuma);
                        ncont[y]->suma=ncont[y]->suma+isuma;
                        fprintf(file, "%s,%s,%s,%s,%f\n", ncont[y]->nume,ncont[y]->prenume, ncont[y]->iban, ncont[y]->moneda, ncont[y]->suma);}
                    if((strcmp(ncont[x]->moneda,"USD")==0) && (strcmp(ncont[y]->moneda,"RON")==0))
                    {isuma=convert_usd_ron(isuma);
                        ncont[y]->suma=ncont[y]->suma+isuma;
                        fprintf(file, "%s,%s,%s,%s,%f\n", ncont[y]->nume,ncont[y]->prenume, ncont[y]->iban, ncont[y]->moneda, ncont[y]->suma);}
                    if((strcmp(ncont[x]->moneda,"USD")==0) && (strcmp(ncont[y]->moneda,"EURO")==0))
                    {isuma=convert_usd_euro(isuma);
                        ncont[y]->suma=ncont[y]->suma+isuma;
                        fprintf(file, "%s,%s,%s,%s,%f\n", ncont[y]->nume,ncont[y]->prenume, ncont[y]->iban, ncont[y]->moneda, ncont[y]->suma);}
                    
                }
            }
        i++;
    }
    fclose(file);
    printf("\n");
    vizualizare_pers(n,x,ncont);
    printf("\n");
    vizualizare_pers(n,y,ncont);
    printf("\n");
    printf("Tranzactia s-a efectuat cu succes!\n");
    printf("\n****************************************\n\n");
    printf("1.MENIU\n");
    printf("2.EXIT\n");
    int opt=0;
    while(opt!=1 && opt!=2)
    {
        scanf("%d",&opt);
    }
    switch(opt)
    {
        case 1:meniu(x,n,ncont); break;
        case 2:
             dealocare(n,ncont);
             exit(0);
             break;
        
        default:break;
    }
}
