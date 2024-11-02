//
//  main.c
//  proiect_c
//
//  Created by CLAUDIA-DENISA on 07.04.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fisier.h"

 
int verificare (char nume[20],char prenume[20],int *n,cont **ncont,int *x)
 {
    /*for(int j=0;j<strlen(nume);j++)
    {if(j==0) nume[0]=toupper(nume[0]);
        else nume[j]=tolower(nume[j]);}
    for(int j=0;j<strlen(prenume);j++)
    {if(j==0) prenume[0]=toupper(prenume[0]);
        else prenume[j]=tolower(nume[j]);}*/
    
     for(int i=0;i<(*n);i++)
     {
         if((strcmp(ncont[i]->nume,nume)==0) && (strcmp(ncont[i]->prenume,prenume)==0)) {*x=i; return 1;}
     }
     return 0;
 }


int main(int arcg, char *argv[])
{
    int n = 0,x = 0,opt=-1;
    cont **ncont = citire_persoane(&n, "baza_de_date.csv");
    //printf("nr arg:%d\n",arcg);
    //printf("%s\n%s\n%s\n",argv[0],argv[1],argv[2]);dealocare(n,ncont);return 0;
    if(arcg!=3) {printf("NU ati introdus argumentele!");return 0;}
    else if(verificare(argv[1],argv[2],&n,ncont,&x)==1) meniu(x,n,ncont);
            else{
                    printf("1.Creare cont.\n2.Iesire");
                    while(opt!=1 && opt!=2)
                    {printf("Optiune:");scanf("%opt",&opt);}
        
                    switch(opt)
             {
                 case 1:{creare(&n,ncont,"baza_de_date.csv",x);break;}
                 case 2:{dealocare(n,ncont); return 0;}
        }
    }
    dealocare(n,ncont);
  return 0;
}
