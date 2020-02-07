#include <stdio.h>
#include <stdlib.h>

int main()
{
    char character;
    char name[20];
    gets(name);
    character = getchar();

    printf("%s %c", name, character);
    return 0;
}
