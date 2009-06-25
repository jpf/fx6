#!/usr/bin/python
#
# celebrate.py:
#     Python code to calculate the Gregorian date of 'fx6'.
#
# Authors: Adam Marshall Smith
#          Joel Franusic
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
#
# Original notes from when this event was conceived:
#
# 0xffffff - six hex efs
# one second before 24 zeros
# when the 25th bit flips
# one flip up, and one flip down per year
#
# dichotomy/duality
## fun/serious
## black/white
## 

from time import *

kDateFormat = '%Y-%m-%d %H:%M:%S'
kMask = 0xffffff
time = int(time())
next_event = time | kMask

num_dates = 10

for n in range(0, num_dates):
    future_event = next_event + n + (kMask * n)
    print "%s" % strftime(kDateFormat, localtime(future_event))
