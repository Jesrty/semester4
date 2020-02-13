#include <stdio.h>
#include <stdlib.h>

int main()
{
    char character;
    character = tolower(getchar());
    //printf("%c\n", character);

    //if - else if - else
    /*
    if(character == 'a'){
        printf("Apple");
    }
    else if(character == 'b'){
        printf("Banana");
    }
    else if(character == 'c'){
        printf("Cherry");
    }
    else if(character == 'd'){
        printf("Date");
    }
    else if(character == 'e'){
        printf("Elderberry");
    }
    else{
        printf("I don't know any fruit with a %c", character);
    }
    */

    //switch
    /*
    switch(character){
        case 'a':
            printf("Apple");
            break;
        case 'b':
            printf("Banana");
            break;
        case 'c':
            printf("Cherry");
            break;
        case 'd':
            printf("Date");
            break;
        case 'e':
            printf("Elderberry");
            break;
        default:
            printf("I don't know any fruit with a %c", character);
    }
    */

    return 0;
}
