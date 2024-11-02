//
//  editare.c
//  _PROIECT_C_
//
//  Created by CLAUDIA-DENISA on 13.04.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fisier.h"

void editare(int x,int n,cont **ncont,const char *f)
{
    printf("Ce operatiune doresti sa efectuezi:\n");
    printf("1.Modifica iban-ul\n");
    printf("2.Schimba moneda\n");
    printf("3.Retragere numerar\n");
    printf("4.Introducere numerear\n");
   // printf("5.Cont curent\n");
    printf("5.MENIU\n");
    printf("6.EXIT\n");
    int p = 0,ok=0;
    while(ok!=1)
    {
        printf("Optiunea dvs. :");scanf("%d",&p);
        if(p>6 || p<1) printf("Optiunea dvs. nu e valida!\n");
        else ok=1;
    }
    printf("\n\nContul actual are IBAN:%s MONEDA:%s SUMA:%f !\n\n",ncont[x]->iban,ncont[x]->moneda,ncont[x]->suma);
    switch(p)
    {
        case 1:
            printf("Ati ales sa modificati iban-ul.\n");
            char iiban[25];
            int nr;
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
                for (int i =0; i <n; i++)
                {
                    if(strcmp(ncont[i]->iban,iiban)==0) r=0;  //verifica daca exista un alt iban
                }
                if (nr == strlen(iiban) && r==1) {
                    ok = 1;
                    
                } else {
                    printf("EROARE! Trebuie sa introduci doar litere si cifre!\n");
                }
            }
            strcpy(ncont[x]->iban,iiban);
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
                if(i==x)
                {
                    fseek(file, -strlen(line), SEEK_CUR);
                    fprintf(file, "%s,%s,%s,%s,%f\n", ncont[x]->nume, ncont[x]->prenume, ncont[x]->iban, ncont[x]->moneda, ncont[x]->suma);
                }
            }
            fclose(file);
            printf("Ibanul a fost modificat!\n");
            printf("\n****************************************\n");
            editare(x,n,ncont,f);
            break;
            
        case 2:
           
            printf("Ati ales sa modificati moneda.\n");
            char imoneda[5];int j=1;
            (void)(ok=0),nr=0;
            while (!ok)
            {
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
                if(strcmp(ncont[x]->moneda,imoneda)==0) {printf("Contul dvs. este deja in %s\n",imoneda);j=0;}
                if((strcmp(imoneda,"RON")==0 || strcmp(imoneda,"EURO")==0 || strcmp(imoneda,"USD")==0) && nr == strlen(imoneda) && j==1)
                {
                    ok=1;
                    if((strcmp(ncont[x]->moneda,"RON")==0) && (strcmp(imoneda,"EURO")==0))
                    {ncont[x]->suma=convert_ron_euro(ncont[x]->suma);
                        strcpy(ncont[x]->moneda,imoneda);
                    }
                    if((strcmp(ncont[x]->moneda,"RON")==0) && (strcmp(imoneda,"USD")==0))
                    {ncont[x]->suma=convert_ron_usd(ncont[x]->suma);
                        strcpy(ncont[x]->moneda,imoneda);
                    }
                    if((strcmp(ncont[x]->moneda,"EURO")==0) && (strcmp(imoneda,"RON")==0))
                    {ncont[x]->suma=convert_euro_ron(ncont[x]->suma);
                        strcpy(ncont[x]->moneda,imoneda);
                    }
                    if((strcmp(ncont[x]->moneda,"EURO")==0) && (strcmp(imoneda,"USD")==0))
                    {ncont[x]->suma=convert_euro_usd(ncont[x]->suma);
                        strcpy(ncont[x]->moneda,imoneda);
                    }
                    if((strcmp(ncont[x]->moneda,"USD")==0) && (strcmp(imoneda,"RON")==0))
                    {ncont[x]->suma=convert_usd_ron(ncont[x]->suma);
                        strcpy(ncont[x]->moneda,imoneda);
                    }
                    if((strcmp(ncont[x]->moneda,"USD")==0) && (strcmp(imoneda,"EURO")==0))
                    {ncont[x]->suma=convert_usd_euro(ncont[x]->suma);
                        strcpy(ncont[x]->moneda,imoneda);
                    }
                    
                    
                } else
                {
                    printf("ATENTIE! Trebuie sa introduci doar litere!\nMoneda poate fi doar : RON/EURO/USD!\n");
                    j=1;
                }
                FILE *file;
                file=fopen(f,"r+");
                if (file == NULL) {
                    printf("NU exista conturi!");
                    
                }
                char line[256];
                int i=0;
                while(fgets(line,sizeof(line),file)!=NULL)
                {
                    if(x==i){fseek(file, -strlen(line), SEEK_CUR);
                        fprintf(file, "%s,%s,%s,%s,%f\n",
                                ncont[x]->nume,ncont[x]->prenume, ncont[x]->iban,ncont[x]->moneda, ncont[x]->suma);}
                    i++;
                }
                fclose(file);
            }
            printf("Contul a fost schimbat in %s!\n",imoneda);
            printf("\n****************************************\n");
            editare(x,n,ncont,f);
            break;
            
            
        case 3:
        {
            printf("Ce suma doriti sa retrageti?\n");
            int ok,nr;char isuma[10000];
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
                    ncont[x]->suma=ncont[x]->suma-(atof(isuma));
                } else {
                    printf("EROARE! Trebuie sa introduci doar cifre!\n");
                }
            }
            FILE *file=fopen(f,"r+");
            if (file == NULL) {
                printf("NU exista conturi!");
                
            }
            char line[256];
            int i=0;
            while(fgets(line,sizeof(line),file)!=NULL)
            {
                if(x==i){fseek(file, -strlen(line), SEEK_CUR);
                    fprintf(file, "%s,%s,%s,%s,%f\n",
                            ncont[x]->nume,ncont[x]->prenume, ncont[x]->iban,ncont[x]->moneda, ncont[x]->suma);}
                i++;
            }
            fclose(file);
            printf("\n****************************************\n");
            editare(x,n,ncont,f);
            break;
        }
        case 4:
        {
            printf("Ce suma doriti sa introduceti?\n");
            int ok,nr;char isuma[10000];
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
                    ncont[x]->suma=ncont[x]->suma+(atof(isuma));
                } else {
                    printf("EROARE! Trebuie sa introduci doar cifre!\n");
                }
            }
            FILE *file=fopen(f,"r+");
            if (file == NULL) {
                printf("NU exista conturi!");
                
            }
            char line[256];
            int i=0;
            while(fgets(line,sizeof(line),file)!=NULL)
            {
                if(x==i){fseek(file, -strlen(line), SEEK_CUR);
                    fprintf(file, "%s,%s,%s,%s,%f\n",
                            ncont[x]->nume,ncont[x]->prenume, ncont[x]->iban,ncont[x]->moneda, ncont[x]->suma);}
                i++;
            }
            fclose(file);
            printf("\n****************************************\n");
            editare(x,n,ncont,f);
            break;
        }
        /*case 5:printf("\nContul actual are IBAN:%s MONEDA:%s SUMA:%f !\n",ncont[x]->iban,ncont[x]->moneda,ncont[x]->suma);
            editare(x,n,ncont,"baza_de_date.csv");break;*/
        case 5:meniu(x,n,ncont);break;
        case 6:dealocare(n,ncont);
                exit(0);
                break;
    }
}
