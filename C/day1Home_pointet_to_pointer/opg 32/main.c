#include <stdio.h>
#include <stdlib.h>

int main () {

    //i didn't understand this exercise, what it want me 2 do???

   int    var1,  var2 ;
   int   *ptr1, *ptr2 ;
   int  **pPtr;       // A Pointer to a Pointer

   var1 = 1000;
   var2 = 2000;

   /* take the address of var */
   ptr1 = &var1;
   ptr2 = &var2;

   /* take the address of ptr1 using address of operator & */
   pPtr = &ptr1;

   /* take the value using pptr */
   printf("Value of var1 = %d\n", var1 );
   printf("Value available at  *ptr1 = %d\n",  *ptr1 );
   printf("Value available at **pPtr = %d\n", **pPtr);

   /* change to the address of ptr2 using address of operator & */
   pPtr = &ptr2;

   /* take the value using pptr */
   printf("Value of var2 = %d\n", var2 );
   printf("Value available at  *ptr2 = %d\n",  *ptr2 );
   printf("Value available at **pPtr = %d\n", **pPtr);
   return 0;
}

