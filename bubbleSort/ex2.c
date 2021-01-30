// ex3.2
// Take your bubble sort and binary search code, make them into functions. Then
// provide interfaces to them using header files. Compile them into a static library
// Then rewrite your main program so that you simply include the header and use the
// functions but not the source of the implementaton. Instead you should link with
// the library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubble.h"

static void PrintArray (char *apszArray[], int iSze);

int main (int iArgC, char *apszArgV[])
{
   char **apszArray = NULL;
   int iCount = iArgC - 1;

   if (iArgC < 2) {
      printf ("Usage: ex6 <string1> <string2> ... <stringN>\n");
      return 1;
   }

   apszArray = (char **) malloc (iCount * sizeof(char *));
   if (apszArray == NULL) return 1;

   // Copy the program parameters into the new array:
   for (int i = 0; i < iCount; i++) {
      apszArray[i] = apszArgV[i + 1];
   }

   BubbleSort (apszArray, iCount); // Sort the array
   PrintArray (apszArray, iCount); // And print it.

   free (apszArray);               // Free the array

   return 0;
}

static void PrintArray (char *apszArray[], int iSze)
{
   printf ("Number of strings %d: \n", iSze);
   for (int i = 0; i < iSze; i++) {
      printf ("%d: %s\n", i, apszArray[i]);
   }
}

