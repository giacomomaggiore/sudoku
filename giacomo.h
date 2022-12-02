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

    //printf("%s\n",stringa);
    
    backup = fopen("sudoku_backup.txt", "w");
    fprintf(backup, "%s", stringa); 
    fclose(backup);


    //printf("\nho scritto questa scritta suil file\n");
    //printf("\n%s\n", stringa);

    //printf("Ho scritto sui file\n");



}


void cancellaNum(FILE* ftpr, int x, int y){

    char str[82];
    FILE* ftpw;

    int pos = x*9+y;

    ftpr = fopen("input.txt", "r");

    if(ftpr){

        fgets(str, 82, ftpr);

        str[pos] = '0';

        fclose(ftpr);

    }else{
        printf("\nerrore nel malloc");
    }


    ftpw = fopen("input.txt", "w");

    if(ftpw){

        fprintf(ftpw, "%s", str);

    }else{
        printf("\nerrore nel malloc");
    }

}

void inserisciNum(FILE* ftpr, int x, int y, char num){

    char str[82];
    FILE* ftpw;

    int pos = x*9+y;

    ftpr = fopen("sudoku.txt", "r");

    if(ftpr){

        fgets(str, 82, ftpr);

        //printf("\n\n%s", str);

        str[pos] = num;

        //printf("\n\n%s", str);

        fclose(ftpr);

    }else{
        printf("\nerrore nel malloc");
    }


    ftpr = fopen("sudoku.txt", "w");

    if(ftpr){
        //printf("sonodentro");

        fprintf(ftpr, "%s", str);

        //printf("\n\n%s", str);

        fclose(ftpr);

    }else{
        printf("\nerrore nel malloc");
    }

}

void leggiFile(FILE* file, char* str){

    file = fopen("sudoku.txt", "r");

    if(file){

        fgets(str, 82, file);

        fclose(file);

    }else{

        printf("\n\nerrore nel malloc");

    }


}
/*
int checkColonne(numero **m){

    int i, j, k, l;
    int vet[9];

    for(j=0;j<9;j++){

        for(i=0; i<9; i++){

            for(k=0;k<i;k++){

                if(vet[k] == (*(m+i)+j)->valore){

                    return 0;
                }
            }

            vet[i] = (*(m+i)+j)->valore;

        }

    }

    return 1;
}
*/
void riempiMatriceConInputIniziale(numero** m, char* str){

    //nota questa funzione assegna m->asterisco 1 a principio quindi non puo essere usata per caricare anche numeri inseriti dall'utente
    //altra nota li sotto c'è un -48 che serve per una conversione implicita ASCII

    int i,j;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){

            if(str[i*9+j] == '0'){
                (*(m+i)+j)->valore = 0;
                (*(m+i)+j)->asterisco = 0;

            }else{
                (*(m+i)+j)->valore = str[i*9+j]-48;
                (*(m+i)+j)->asterisco = 1;

            }

        }
    }
}


/* ---------------------------------------------------------------------------------------------------------*/

void stampaMatrice(numero **m){              // DA TESTARE!!

    int i; //contatore righe
    int j; //contatore colonne
    int k;
    int t;
    
    for(k=0; k<3; k++){
        
        printf(" +-----------+-----------+----------+\n");
        
        for(i=3*k; i<3*(k+1); i++){
            
            for(t=0; t<3; t++){
                
                printf(" | ");
                
                for(j=3*t; j<3*(t+1); j++){
                    if( (*(*(m+i)+j)).valore!=0){
                        
                        if( (*(*(m+i)+j)).asterisco==1 ){
                            printf(" %d*",(*(*(m+i)+j)).valore );
                        }
                        else{
                            printf(" %d ", (*(*(m+i)+j)).valore);
                        }
                    }
                    else{
                        printf("   ");
                    }

                    if(j ==8){
                        printf("| ");
                    }
                }
                
                
            }
            printf("\n");
        }
        
    }
    printf(" +-----------+-----------+----------+\n");
    
    
}
/*
int checkRighe(numero **matrice){                  // DA TESTARE!!
    
    int i;
    int j;
    int flag=0;
    int vet[9];
    
    for(i=0; i<9; i++){
        
        for(j=0; j<9; j++){
            
            for(k=0; k<j; k++){
                
                if(vet[j] == *(*(m+i)+j)->valore){
                    
                    return 0;
                    
                }
            }
            
            vet[j] = *(*(m+i)+j)->valore;
            
        }
        
    }
    
    return 1;
    
}

int checkCompletezza(**matrice){                // DA TESTARE!!
    
    int i;
    int j;
    for(i=0; i<9; i++){
        for(j=0; j<9, j++){
            if( (*(*(m+i)+j)->valore)==0 ){
                return 0;
            }
        }
    }
    return 1;
}

*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
/*FUNZIONI DI CONTROLLOP */
int checkValido(int a, int b, int c){
    if (a+b+c == 3){
        return 1;
    }
    else{
        return 0;
    }
}


int checkCompleto(numero **matrice){
    int i;
    int j;
    int flag = 1;
    for (i = 0; flag == 1 && i < 9 ; i++){
        for(j = 0; flag == 1 && j < 9; j++){
            if( (*(*(matrice+i)+j)).valore = 0){
                flag = 0;
            }
        }
    }
    return flag;
}
int verifica(int a, int b){
    if (a + b == 2){
        printf("Sudoku completo e corretto, complimenti!\n");
        return 1;
    }
    else{
        printf("Sudoku errato! Prova ancora. \n");
    }
}
int checkRighe(numero **m){                  // DA TESTARE!!
    
    int i;
    int j;
    int k;
    int flag=0;
    int vet[9];
    
    for(i=0; i<9; i++){
        
        for(j=0; j<9; j++){
            
            for(k=0; k<j; k++){
                
                if(vet[j] == (*(*(m+i)+j)).valore){
                    
                    return 0;
                    
                }
            }
            
            vet[j] = (*(*(m+i)+j)).valore;
            
        }
        
    }
    
    return 1;
    
}
int checkColonne(numero **m){

    int i, j, k, l;
    int vet[9];

    for(j=0;j<9;j++){

        for(i=0; i<9; i++){

            for(k=0;k<i;k++){

                if(vet[k] == (*(m+i)+j)->valore){

                    return 0;
                }
            }

            vet[i] = (*(m+i)+j)->valore;

        }

    }

    return 1;
}
int checkQuadrante (numero **m){
    return 1;


}

#endif