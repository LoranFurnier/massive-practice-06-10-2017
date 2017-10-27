#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define vert 9
#define horiz 6
int main(){
    int massive1[horiz][vert];
    int massive2[horiz-1][vert-1];
    int a, b, c, i, j, x, y;
    
    c = INT_MAX;/*for Quest 03*/
    
    srand(time(NULL));
    
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
    
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            if(i==x || j==y){
                continue;
            }
            massive2[i][j] = massive1[i][j];
        }
    }
    
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            free(massive1[i][j]);
        }
    }
    
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            printf("%d  ", massive2[i][j]);
        }
    printf("\n");
    }
}
