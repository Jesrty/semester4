#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar[10][10];
    int *ptr_ar = NULL;
    ptr_ar = &ar[0][0];

    for(int i = 0; i<100;i++){
        *(ptr_ar+i) = i+1;
    }


    int times = 0;
    int timesMax = 3;
    for(int j = 0; j<101;j++){
        if(j != 0 && j % 10 == 0){
            printf("\n");
        }
        if(j == 100 && times < timesMax-1){
           j = 0;
           times++;
        }
        if(j < 100 && times < timesMax){
            printf("%d, ", *(ptr_ar+j));
        }
    }




    return 0;
}
