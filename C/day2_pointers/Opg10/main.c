#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ar[100];
    int *ptr_i = NULL;
    ptr_i = ar;

    for(int i = 0; i<100;i++){
        *(ptr_i+i) = i+1;
    }

    for(int i = 0; i<100; i++){
        printf("Array[%d]=%d\n", i, *(ptr_i+i));
    }

    return 0;
}
