#ifndef michele
#include "struc.h"



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
#endif
