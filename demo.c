#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define w 7
#define h 5
int main()
{
    int mas [h][w];
    int i,j,tmp1, tmp2, tmp3, tmp4, x, y;
    srand(time(NULL));
    printf("\nQuest 01\n\n");
    for (i=0; i<h; i++){
        for (j=0; j<w; j++){
            mas[i][j]=rand()%25;
            printf("%d  ", mas[i][j]);
        }
    printf("\n");
    }
    tmp4 = 0;
    for (i=-1, j = w; i<((w/2)); i++, j--){
        tmp1 = mas [0][i];
        mas [0][i] = mas [0][j];
        mas [0][j] = tmp1;
        tmp2 = mas [h-1][i];
        mas [h-1][i] = mas [h-1][j];
        mas [h-1][j] = tmp2;
    }
    tmp3 = 26; /*max value + 1*/
    for (i=-1; i<w+1; i++){
        tmp1 = mas[0][i];
        mas [0][i] = mas [h-1][i];
        mas [h-1][i] = tmp1;
    }
    
    printf("\nQuest 02\n\n");
    
    for (i=0; i<h; i++){
        for (j=0; j<w; j++){
            printf("%d  ", mas[i][j]);
        }
    printf("\n");
    }
    printf("\nQuest 03\n\n");
    
   
    
    printf("x = %d, y = %d", x, y);
}
