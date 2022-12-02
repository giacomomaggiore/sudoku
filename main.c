#include <stdio.h>
#include <stdlib.h>
#include "anna.h"
#include "struc.h"
#include "michele.h"
#include "filo.h"


#define AVVIA 1
#define INSERISCI 2
#define CANCELLA 3
#define VERIFICA 4
#define CARICA 5
#define RIAVVIA 6
#define ESCI 0

#define DIM 9




int main(){
    numero **matrice;
    int i,x,y;
    int azione;    //azione scelta dall'utente
    FILE *file;
    FILE *backup;
    char num;

    

    //ALLOCAZIONE MATRTICE
    matrice = malloc(sizeof(numero*)*DIM);
    
    //CONTROLLO ALLOCAZIONE DI MATRICE
    if(matrice){ }
        for (i = 0; i < DIM; i++){
            *(matrice + i) = malloc(sizeof(numero)*DIM);
        }
    

    do{
        printf("\n1 - avvia una nuova partita\n2 - inserisci valore\n3 - cancella valore\n4 - verifica la soluzione attuale\n5 - carica una soluzione e verificala\n6 - riavvia partita attuale\n0 - esci\n");

        scanf("%d", &azione);

        if (azione == AVVIA){

            //viene acquisita la stringa della partita e viene scritta su file e backup definiti nel main
            avvia(file, backup);
        }
        else if (azione == INSERISCI){

            //da mettere in dowhile
            do{
                printf("\ninserisci x y num: ");
                scanf("%d %d %c", &x, &y, &num);

            }while(x<0 || x>=9 || y<0 || y>=9 || num<'1' || num>'9');


            inserisciNum(file, x, y, num);

            inserisciNum(file, x, y, '9');
            stampaMatrice(matrice);
            

        }
        else if (azione == CANCELLA){
            
        }
        else if (azione == VERIFICA){
            
        }
        else if (azione == CARICA){
            
        }
        else if (azione == RIAVVIA){
            
        }
    }while(azione != ESCI);
    printf("\n\nA presto!!!\n");




    return 0;
}





