#include <stdio.h>
#include <stdlib.h>

int main(){
    int score = 0;
    int TD2pt = 8;
    int TDFG = 7;
    int TD = 6;
    int FG = 3;
    int safety = 2;

    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);

    //goes through every possible combination of scores (starting with the max amount of safeties) that combine to add up to the given score number
    for (int i = 0; i < score; i += TD2pt){
        for (int j = 0; j < score; j += TDFG){
            for (int k = 0; k <  score; k += TD){
                for (int l = 0; l < score; l += FG){
                    for (int m = 0; m < score; m += safety){
                        if (i + j + k + l + m == score){
                            int iCount = i / TD2pt;
                            int jCount = j / TDFG;
                            int kCount = k / TD;
                            int lCount = l / FG;
                            int mCount = m / safety;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", iCount, jCount, kCount, lCount, mCount); //prints the score combination
                        }
                    }
                }
            }
        }
    }
    system("Pause");
    return 0;
}