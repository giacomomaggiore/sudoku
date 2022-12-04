#include <stdio.h>
#include <stdlib.h>
#include "giacomo.h"

//#include "michele.h"

//#include "filo.h"


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
    char str[82];

    //variabili per CARICA
    char stringa_backup[82];
    char stringa_inserita[82];


    //VARIABILI PER LA VERIFICA
    int righe;
    int colonne;
    int quadrante;
    int completo;
    int valido;

    

    //ALLOCAZIONE MATRTICE
    matrice = malloc(sizeof(numero*)*DIM);
    
    //CONTROLLO ALLOCAZIONE DI MATRICE
    if(matrice){ }
        for (i = 0; i < DIM; i++){
            *(matrice + i) = malloc(sizeof(numero)*DIM);
        }
    

    do{

        stampaMatrice(matrice);

        printf("\n1 - avvia una nuova partita\n2 - inserisci valore\n3 - cancella valore\n4 - verifica la soluzione attuale\n5 - carica una soluzione\n6 - riavvia partita attuale\n0 - esci\n");

        scanf("%d", &azione);

        if (azione == AVVIA){

            //viene acquisita la stringa della partita e viene scritta su file e backup definiti nel main
            avvia(file, backup);
            leggiFile(file, str);
            riempiMatriceConInputIniziale(matrice, str);
        }
        else if (azione == INSERISCI){

            //da mettere in dowhile
            do{
                printf("\ninserisci x y num: ");
                scanf("%d %d %c", &x, &y, &num);

            }while(x<0 || x>=9 || y<0 || y>=9 || num<'1' || num>'9'|| controlla_asterisco(matrice, x, y) != 0);

            inserisciNum(file, x, y, num); //aggiunge l'elemento nel file

            leggiFile(file, str); 

            riempiMatriceConNuovoInput(matrice, str); //aggiorna la matrice guardando il file

        }
        else if (azione == CANCELLA){

            do{
                printf("\ninserisci x y: ");
                scanf("%d %d", &x, &y);

            }while(x<0 || x>=9 || y<0 || y>=9 || controlla_asterisco(matrice, x, y) != 0);

            cancellaNum(file, x, y);

            leggiFile(file, str); 

            riempiMatriceConNuovoInput(matrice, str); //aggiorna la matrice guardando il file
            
        }
        else if (azione == VERIFICA){
            righe = checkRighe(matrice);
            colonne = checkColonne(matrice);
            quadrante = checkQuadrante(matrice);

            completo = checkCompleto(matrice);

            valido = checkValido(righe, colonne, quadrante);

            verifica(valido, completo);
            
        }
        else if (azione == CARICA){

            carica(stringa_backup, stringa_inserita, matrice);
            
        }
        else if (azione == RIAVVIA){

            riavvia(file, backup);
            leggiFile(file, str);
            riempiMatriceConInputIniziale(matrice, str);
            
        }
    }while(azione != ESCI);
    printf("\n\nA presto!!!\n");




    return 0;
}





