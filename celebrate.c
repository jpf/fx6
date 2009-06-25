/*
 * celebrate.c
 *     celebrate prints 128 lines, where each line lists the conventional calendar date and time of 'fx6'
 *
 * To compile: "gcc -o celebrate celebrate.c"
 * To execute: "./celebrate"
 *
 * Authors: Pete Franusic
 *          Joel Franusic
 *
 * TODO: Figure out why the times that this code generates is off by one second...
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// The include file "time.h" has definitions for the "time_t" structure,
// the "tm" structure, the "gmtime" function, and the "strftime" function.
#include "time.h"

// The include file "stdio.h" has a definition for the "printf" function.
#include "stdio.h"

// A celebration period is defined as 2^{24} = 16,777,216 seconds.
#define CELEBRATE (1 << 24)

// The integer variable "year" is the number of celebration periods since the Epoch.
static int year;

// The time_t variable "secs" is the number of seconds since the Epoch.
static time_t secs;

// The function "gmtime" only works correctly for values of secs 
// that are less than GTIME_SECS_MAX.
#define GTIME_SECS_MAX (0x80000000)

// The pointer "tptr" is the address of a tm structure.
// A tm structure contains various fields that represent a specific date and time.
// tptr is an output of the gmtime function and an input of the strftime function.
static struct tm* tptr;

// The string "DATE_SPEC" specifies a custom format for printing the date and time.
// In this case, the format is year.month.day hour.minute.second.
#define DATE_SPEC "%Y-%m-%d %H:%M:%S"

// The string buffer "date" is DATE_LEN=64 characters in length and is used
// to store a formatted date string from the strftime function.
#define DATE_LEN (64)
static char date [DATE_LEN];

// Here's the main program...
int main (void)
{
  // Initialize the secs counter to the Epoch.
  secs = 0; 

  // Loop until secs is too big for the gmtime function.
  while (secs < GTIME_SECS_MAX)
    {
      // The celebration period is the most-significant 8 bits,
      // so we simply shift secs 24 bits to the right.
      year = secs >> 24;

      // &secs is the address of the secs variable.
      // gtime reads the value at this address,
      // fills in the various fields of a tm structure,
      // and then returns the address of this structure.
      // We save this address in tptr.
      tptr = localtime (&secs);

      // The strftime function takes the tptr address of the tm structure,
      // the format specification DATE_SPEC, and the maximum buffer length DATE_LEN,
      // and then writes a formatted string into the date buffer starting at date [0].
      strftime (date, DATE_LEN, DATE_SPEC, tptr);

      // The printf function writes the conventional calendar date of each celebration.
      printf ("%s\n", date);

      // Increment the secs counter by 2^{24} seconds.
      secs += CELEBRATE;
    }
}
