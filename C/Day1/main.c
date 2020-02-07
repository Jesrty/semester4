#include <stdio.h>
#include <stdlib.h>





int main()
{
    int numberOfLego = 41112;
    float price = 11.48;
    float moms = 0.25;
    printf("Number %d of Lego\n", numberOfLego);
    printf("Price pr. %.2f kr.\n", price);
    printf("Total %.2f kr.\n", (numberOfLego*price));
    printf("moms %.2f kr.\n", ((numberOfLego*price)*moms));
    printf("Total with moms %.2f kr.\n", (numberOfLego*price*(1 + moms)));
    return 0;
}
