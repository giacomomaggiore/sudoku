#include <stdio.h>
#include <stdlib.h>
#include "anna.h"
#include "giacomo.h"
#include "struc.h"
#include "filo.h"
#include "michele.h"

#define AVVIA 1
#define INSERISCI 2
#define CANCELLA 3
#define VERIFICA 4
#define CARICA 5
#define RIAVVIA 6
#define ESCI 0

#define DIM 9



int main(){
    struct numero **matrice;
    int i;
    int azione;    //azione scelta dall'utente
    FILE *file;
    FILE *backup;

    

    //ALLOCAZIONE MATRTICE
    matrice = malloc(sizeof(*numero)*DIM);
    
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



