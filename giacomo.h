#ifndef giacomo

#define DIM 9
#include "gabri.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int valore;
    int asterisco;
}numero;

void riempiMatriceConInputIniziale(numero** m, char* str);
void riempiMatriceConNuovoInput(numero** m, char* str);



void da_matrice_a_stringa(numero **matrice, char* stringa){
    int i;
    int j;
    int k = 0;
    char temp;

    for(i = 0; i < 9; i++){
        for(j = 0; j<9; j++){
            temp = (*(*(matrice+i)+j)).valore + 48;
            stringa[i*9+j] = temp;
        }
    }
}
  
int controlla_asterisco(numero** matrice, int x, int y){
    numero elemento_da_controllare;

    elemento_da_controllare = *(*(matrice + x) + y);
    if (elemento_da_controllare.asterisco  == 1){
        printf("asterisco\n");
        return 1;
    }
    else{
        printf("non asterisco\n");
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

void avvia_non_backup(FILE *file, char* str){

    convertistringa(str, 82);
    
    file  = fopen("sudoku.txt", "w");
    fprintf(file, "%s", str);
    fclose(file);
}


void cancellaNum(FILE* ftpr, int x, int y){

    char str[82];
    FILE* ftpw;

    int pos = x*9+y;

    ftpr = fopen("sudoku.txt", "r");

    if(ftpr){

        fgets(str, 82, ftpr);

        str[pos] = '0';

        fclose(ftpr);

    }else{
        printf("\nerrore nel malloc");
    }

    ftpw = fopen("sudoku.txt", "w");

    if(ftpw){

        fprintf(ftpw, "%s", str);
        fclose(ftpw);

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

void riavvia(FILE *file, FILE* backup){
    char stringa[82];
    printf("\n\nLa partita è stata riavviata\n\n");

    file  = fopen("sudoku_backup.txt", "r");

    if(file){

        fgets(stringa, 82, file);
        fclose(file);
    }

    file = fopen("sudoku.txt", "w");

    if(file){

        fprintf(file, "%s", stringa);
        fclose(file);
    }
}

void carica(char* str_b, char* str_i, numero **m){

    FILE* file;
    FILE* file2;
    int i,j;

    file  = fopen("sudoku_backup.txt", "r");

    if(file){

        fgets(str_b, 82, file);
        fclose(file);
    }

    riempiMatriceConInputIniziale(m, str_b);

    printf("\n\ninserire la stringa:\n");
    scanf("%s", str_i);

    convertistringa(str_i, 82);

    riempiMatriceConNuovoInput(m, str_i);

    da_matrice_a_stringa(m, str_i);


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

void riempiMatriceConNuovoInput(numero** m, char* str){

    int i,j;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){

           if((*(m+i)+j)->asterisco != 1){

            (*(m+i)+j)->valore = str[i*9+j]-48;

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

/*----------------------------------------------------------------------------------------------------------------------------------*/
//-----------------------------------------------------------------------------------
int checkValido(int a, int b, int c){
    if (a+b+c == 3){
        printf("Soluzione valida\n");
        return 1;
    }
    else{
        return 0;
    }
}


int checkCompleto(numero **matrice){
    int i;
    int j;
    for (i = 0; i < 9 ; i++){
        for(j = 0; j < 9; j++){
            if( (*(*(matrice+i)+j)).valore == 0){

                printf("Sudoku NON completo\n");
                return 0; //ritorna 0 e blocca la funzione se trova uno 0
            }
        }
    }
    printf("Sudoku completo!\n");
    return 1; //ritorna 1 se alla fine del ciclo non ha mai trovato uno 0

}
int verifica(int a, int b){
    //prende in input checkCOMPLETO e checkVALIDO

    if (a + b == 2){
        printf("PARTITA TERMINATA: Sudoku completo e corretto, complimenti!\n");
        return 1;
    }
    else{
        return 0;
    }
}
int checkRighe(numero **m){                  // DA TESTARE!!
    
    int i; //CONTATORE RIGHE
    int j;
    int k;
    int vet[9];
    
    for(i=0; i<9; i++){ //ITERA TUTTE LE RIGHE DELLA MATRICE
        
        for(j=0; j<9; j++){ //ITERA TUTTI GLI ELEMENTI DELLA RIGA
            
            for(k=0; j!=k && k<9; k++){ //RI-ITERA TUTTI GLI ELEMTI DELLA RIGA
                
                if((*(*(m+i)+j)).valore == (*(*(m+i)+k)).valore && (*(*(m+i)+j)).valore != 0){
                    
                    return 0; //elementi uguali e ritorna 0
                    
                }
            }
            
        }
        
    }

    
    return 1; //Se completa tutto il ciclo senza trovare alcun elemento uguale
    
}
int checkColonne(numero **m){

    int i; //contatore righe
    int j; //contatore colonne
    int k;


    for(j=0;j<9;j++){ //itera tutte le colonne

        for(i=0; i<9; i++){ //itera tutte gli elementi della colonna

            for(k=0; i != k && k<9;k++){ //ri itera tutti gli elementi della colonna

                if((*(*(m+i)+j)).valore == (*(*(m+k)+j)).valore &&  (*(*(m+i)+j)).valore != 0){
                    return 0;
                }
            }

            
        }

    }

    return 1;
}
int checkQuadrante (numero **m){
    int i; //indica RIGA SOTTOquadrante
    int j; //indica COLONNA SOTTOquadrante

    int a; //itera righe del quadrante
    int b; //itera colonne del quadrante


    int vett[9];
    int l = 0; 
    int h;

    for(i = 0; i < 3; i ++){

        for (j = 0; j < 3; j++){
            
            for(a = 3*i; a < (i+1)*3; a++){
                //si inizia a iterare ogni quadrante
                
                for(b = 3*j; b < (j+1)*3; b++){
                    //printf("%d\n", (*(*(m+a)+b)).valore );
                    vett[l] = (*(*(m+a)+b)).valore;
                    l = l +1;

                    }
                }

                for (l = 0; l < 9; l++){
                    for (h = 0; h < 9; h++){
                        //printf("%d %d\n", vett[l], vett[h]);
                        if (l != h && vett[l] != 0){
                            if(vett[l] == vett[h]){ 
                                //printf("%d %d %d%d\n", vett[l], vett[h], l, h);
                                return 0;
                                }
                            }
                    
                        }

                }
                l = 0;            

                


            
            

            
        }
    }

    return 1;

}

#endif