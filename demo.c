#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define w 7
#define h 5
int main()
{
    int mas [h][w];
    int i,j,tmp1, tmp2;
    srand(time(NULL));
    
    for (i=0; i<h; i++){
        for (j=0; j<w; j++){
            mas[i][j]=rand()%25;
            printf("%d  ", mas[i][j]);
        }
    printf("\n");
    }
    
    for (i=0, j = w; i<(1+(w/2)); i++, j--){
        tmp1 = mas [0][i];
        mas [0][i] = mas [0][j];
        mas [0][j] = tmp1;
        tmp2 = mas [h-1][i];
        mas [h-1][i] = mas [h-1][j];
        mas [h-1][j] = tmp2;
    }
    
    for (i=0; i<w; i++){
        tmp1 = mas[0][i];
        mas [0][i] = mas [h-1][i];
        mas [h-1][i] = tmp1;
    }
    
    printf("\n");
    
    for (i=0; i<h; i++){
        for (j=0; j<w; j++){
            printf("%d  ", mas[i][j]);
        }
    printf("\n");
    }
}
