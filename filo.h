#ifndef filo
#include "struc.h"


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

		printf("\n\n%s", str);

		str[pos] = num;

		printf("\n\n%s", str);

		fclose(ftpr);

	}else{
		printf("\nerrore nel malloc");
	}


	ftpr = fopen("sudoku.txt", "w");

	if(ftpr){
		printf("sonodentro");

		fprintf(ftpr, "%s", str);

		printf("\n\n%s", str);

		fclose(ftpr);

	}else{
		printf("\nerrore nel malloc");
	}

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

#endif