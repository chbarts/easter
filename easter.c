#include <stdio.h>
#include <stdlib.h>

static char *months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

static void easter(int year, int *month, int *day)
{
   /* https://rosettacode.org/wiki/Holidays_related_to_Easter */
   /* Easter date algorithm from J.M. Oudin (1940), reprinted in:
    * P.K. Seidelmann ed., "Explanatory Supplement to the Astronomical
    * Almanac" [1992] (Chapter 12, "Calendars", by L.E. Doggett) */
   int c, n, i, m;
   c = year / 100;
   n = year % 19;
   i = (c - c / 4 - (c - (c - 17) / 25) / 3 + 19 * n + 15) % 30;
   i -= (i / 28) * (1 - (i / 28) * (29 / (i + 1)) * ((21 - n) / 11));
   m = i - (year + year / 4 + i + 2 - c + c / 4) % 7;
   *month = 3 + (m + 40) / 44;
   *day = m + 28 - 31 * (*month / 4);
   return;
}

int main(int argc, char *argv[])
{
   int month, day;
   if (1 == argc) {
      puts("easter YEAR");
   } else {
      easter(atoi(argv[1]), &month, &day);
      printf("%s %d\n", months[month - 1], day);
   }

   return 0;
}
