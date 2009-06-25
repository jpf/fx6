#!/bin/bash
#
# celebrate.sh:
#     Bash code to calculate the Gregorian date of 'fx6'.
#
# Author: Joel Franusic
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

kDateFormat='%Y-%m-%d %H:%M:%S'
kMask=0xffffff
time=`date +%s`
next_event=$(( $time | $kMask))

num_dates=10

for (( n=0; n < $num_dates; n++ )); do
    future_event=$(( $next_event + $n + ( kMask * $n) ));
    date -r $future_event "+$kDateFormat"
done

