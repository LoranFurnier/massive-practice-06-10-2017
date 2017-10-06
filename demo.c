#include <stdio.h>
#include <time.h>
int main()
{
    int mas [6][5];
    int i,j,tmp1, tmp2;
    srand(time(NULL));
    
    for (i=0; i<6; i++){
        for (j=0; j<5; j++){
            mas[i][j]=rand()%100;
            printf("%d  ", mas[i][j]);
        }
    printf("\n");
    }
    
    for (i=0; i<6; i++){
        for (j=0; j<3; j++){
            tmp1 = mas [0][j/2];
            mas [0][j/2] = mas [5][6-(j/2)];
            mas [5][6-(j/2)] = tmp1;
        }
    }
    printf("\n");
    for (i=0; i<6; i++){
        for (j=0; j<5; j++){
            printf("%d  ", mas[i][j]);
        }
    printf("\n");
    }
}

