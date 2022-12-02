#include "struc.h"


#ifndef gabri


/*
input:  53__7____6__195____98____6_8___6___34__8_3__17___2___6_6____28____419__5____8__7_

output: 534678912672195348198342567859761423426853791713924856961537284287419635345286179

*/

char* convertistringa (char *p, int len){
    int i;
    for (i = 0; i < len; ++i) {
        if (*(p+i)=='_') {
            *(p+i)= '0';
        }
    }
    return p;
}

/*
int quadrante (numero **m){
    int i, j, k, h;
    int v[9];


    for (k = 0; k < N/9; ++k){
        for (h = 0; h < 9; ++h)
        {
            v[h]=0;
        }
        for (i = k/3; i < (k/3)+3; ++i){
            for (j = k%3; j < (k%3)+3; ++j){
                if (v[*(*(m+i)+j)->valore-1]==1)
                {
                    return 0;
                }
                else v[*(*(m+i)+j)->valore-1]=1;
                
            }
        }

    }


}

*/
#endif

