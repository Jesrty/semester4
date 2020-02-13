#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int y = 20;
    int *ptr_x = NULL;
    int *ptr_y = NULL;

    ptr_x = &x;
    ptr_y = &y;

    printf("x = %d y = %d\n", *ptr_x, *ptr_y);

    printf("x = %p y = %p", &x, &y);

    return 0;
}
