/*
 * celebrate.java:
 *     Java code to calculate the Gregorian date of 'fx6'.
 *
 * Author: Joel Franusic
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

import java.util.Date;

class celebrate
{  
    final static int kMillisecondsPerSecond = 1000;
    // 2008-10-22 21:39:27
    final static String kDateFormat = "%1$tY-%1$tm-%1$td %1$tH:%1$tM:%1$tS";
    final static long kMask = 0xffffff;
    static long time = new Date().getTime() / kMillisecondsPerSecond;
    static long next_event = time | kMask;
    static int num_dates = 10;

    public static void main(String args[])
    {
	try {
	    num_dates = Integer.parseInt(args[0]);
	} catch (NumberFormatException e) {
	    // use the value that num_dates was initialized to
	} catch (ArrayIndexOutOfBoundsException e) {
	    // use the value that num_dates was initialized to
	}

	for (int z = 0; z < num_dates; z++) {
	    long future_event = next_event + z + (kMask * z);
	    System.out.printf("%s\n", String.format(kDateFormat, future_event * kMillisecondsPerSecond));
	}
    }
}
