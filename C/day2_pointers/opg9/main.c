#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main()
{
    int i, j, n;
    int ar[] = {7, 3, 9, 2, 11};
    int *ptr_i = NULL;
    int *ptr_j = NULL;

    ptr_i = ar;

    printf("Array before sort:\n\n");

    for(i = 0; i<5;i++){
        printf("ar[%d]=%d\n", i, *(ptr_i+i));
    }

    n = 5;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if(*(ptr_i+j)>*(ptr_i+j+1)){
                swap((ptr_i+j), (ptr_i+j+1));
            }
        }
    }

    printf("Array after sort:\n\n");
    for(i=0; i<5;i++){
            printf("ar[%d]=%d\n", i, *(ptr_i+i));
    }
    return 0;
}

void swap(int *a, int *b){

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}




