#include <stdio.h>
#include <time.h>
#define vert 9
#define horiz 6
int main(){
    int massive1[horiz][vert];
    int a, b, c, i, j;
    srand(time(NULL));
    printf("\nQuest 01: just make some MASSIVE thing\n\n");
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            massive1[i][j]=rand()%25;
            printf("%d  ", massive1[i][j]);
        }
    printf("\n");
    }
    
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
    
    printf("\nQuest 02: show first and last rows backwards and make first one last and last one first\n\n");
    
    for (i=0; i<horiz; i++){
        for (j=0; j<vert; j++){
            printf("%d  ", massive1[i][j]);
        }
    printf("\n");
    }
    
    
}
