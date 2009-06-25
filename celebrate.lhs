This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

The author of this program is Adam Marshall Smith.

> import System.Time
> import Text.Printf

Our events happen when something interesting happens to the
bits in the timestamp Above the twenty-four low order bits.
That is, we will have a crazy party when the timestamp is
some multiple of 2^24.

> stamp i = i * 2^24

To display a particular event (given by the number i), we
should print i and its fancily formatted date (using the
System.Time library) on a single line.

> displayEvent i = printf "%02x :: %s\n" i date
>   where date = calendarTimeToString $ toUTCTime $ TOD (stamp i) 0

Finally, when we run this program, we we should print each
event, starting at the 0th and continuing up to some limit.

> main = sequence_ $ map displayEvent [0..128]
