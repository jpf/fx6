/*
 * celebrate.js:
 *     Javascript code to calculate the Gregorian date of 'fx6'.
 *
 *     This program was designed to run from the command line via Rhino (http://www.mozilla.org/rhino/)
 *     For example:
 *     $ java -jar rhino1_7R2/js.jar celebrate.js
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

var kMask = 0xffffff;
var kNumberOfMaskBits = 24;
var kMillisecondsPerSecond = 1000;
var kBase2 = 2;

var now = new Date; // Generic JS date object
var time = parseInt(now.getTime() / kMillisecondsPerSecond);
var next_event = time | kMask;

var num_dates = 10;

function zpad(input, len) {
  // by default, pad to 2 characters
  len = len ? len : 2;
  var str = String(input);
  while(str.length < len) { str = '0' + str; }
  return str;
}

function make_date_string(d) {
  // the results of getMonth are zero indexed
  var ymd = [d.getFullYear(), zpad(d.getMonth() + 1), zpad(d.getDate())];
  var hms = [zpad(d.getHours()), zpad(d.getMinutes()), zpad(d.getSeconds())];
  return(ymd.join('-') + ' ' + hms.join(':'))
}  

for (n = 0; n < num_dates; n++) {
  var future_event = next_event + n + (kMask * n);
  var future_date = new Date(future_event * kMillisecondsPerSecond);
  var future_event_string = make_date_string(future_date);
  print(future_event_string);
 }
