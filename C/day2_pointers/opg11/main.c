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

    for(int i = 0; i<100;i++){
        if(i != 0 && i % 10 == 0){
            printf("\n");
        }
        printf("%d, ", *(ptr_ar+i));
    }
    return 0;
}
