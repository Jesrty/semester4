#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    char character;
    char string[20];

    scanf("%s %c %d", &string, &character, &number);

    printf("Du skrev: %s %c %d", string, character, number);
    return 0;
}
