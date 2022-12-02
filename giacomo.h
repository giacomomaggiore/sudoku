#ifndef giacomo

#define DIM 9
#include "gabri.h"
#include <string.h>
#include <stdlib.h>


typedef struct{
    int valore;
    int asterisco;
}numero;
  
int controlla_asterisco(numero** matrice, int x, int y){
    numero elemento_da_controllare;

    elemento_da_controllare = *(*(matrice + x) + y);
    if (elemento_da_controllare.asterisco  == 1){
        return 1;
    }
    else{
        return 0;
    }

}

void avvia(FILE *file, FILE* backup){
    char stringa[82];
    printf("Benvenuto! \nPrima di iniziare a giocare, inserisci la tua stringa di avvio\n");
    scanf("%s", stringa);

    //chiama la funzione che scrive la stringa su file


    convertistringa(stringa, 82);
   
    
    file  = fopen("sudoku.txt", "w");
    fprintf(file, "%s", stringa);
    fclose(file);

    printf("%s\n",stringa);
    
    backup = fopen("sudoku_backup.txt", "w");
    fprintf(backup, "%s", stringa); 
    fclose(backup);


    //printf("\nho scritto questa scritta suil file\n");
    //printf("\n%s\n", stringa);

    //printf("Ho scritto sui file\n");



}




#endif