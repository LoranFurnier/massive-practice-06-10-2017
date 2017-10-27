#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define vert 9
#define horiz 6
void main(){
    int a, b, c, i, j, x, y;
    int **massive1 = NULL;
    massive1 = (int**) malloc(horiz * sizeof(int*));
    for (i = 0; i < horiz; i++) {
        massive1[i] = (int*) malloc(vert * sizeof(int));
    }
    
    c = INT_MAX;/*for Quest 03*/
    
    srand(time(NULL));/*for random*/
    
    printf("\nQuest 01: just make some MASSIVE thing\n\n");
    
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            massive1[i][j]=rand();
            printf("%d  ", massive1[i][j]);
        }
    printf("\n");
    }
    
    printf("\nQuest 02: show first and last rows backwards and make first one last and last one first\n\n");
    
    for (i=0, j=vert-1; i<vert/2; i++, j--){
        a = massive1[0][j];
        massive1[0][j] = massive1[0][i];
        massive1[0][i] = a;
        
        b = massive1[horiz-1][j];
        massive1[horiz-1][j] = massive1[horiz-1][i];
        massive1[horiz-1][i] = b;
    }
    
    for (i=0; i<vert; i++){
        a = massive1[0][i];
        massive1[0][i] = massive1[horiz-1][i];
        massive1[horiz-1][i] = a;
    }
    
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            printf("%d  ", massive1[i][j]);
        }
    printf("\n");
    }
    
    printf("\nQuest 03: be a bulldozer, crash the least\n\n");
    
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            if(massive1[i][j]<c){
                c = massive1[i][j];
                x = i;
                y = j;
            }
        }
    }
    
    for (i=0; i<horiz; i++) {
        for (j=0;j<vert;j++) {
            massive1[x][j] = 0;
            massive1[i][y] = 0;
        }
    }

    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            printf("%d  ", massive1[i][j]);
        }
    printf("\n");
    }
    
    for (i = 0; i < horiz; i++) {
        free(massive1[i]);
    }
    free(massive1);
    
}
