# Black Sun Clock
This is not a digital clock with a normal count , it represents an hour in beautiful colors with a unique algorithm.
# What are the parts of this watch and who made it?
1. The body of this watch, designed and implemented by team designer, Mr.Peyman.
2. The electronic part of this watch is designed by me to detail the details .
3. The programming and design part of Algorithm is a clock designed by me and loaded into this data repository.

# Section 1:
Photos of the body:<br/>
<img width="400px" src="https://raw.githubusercontent.com/AmirCpu2/BlackSunClock/ed3246eae8bb40ddc21ec27ba59e6c7f36b6eee7/web%20BlackSun%20Clock/clock.svg" />

# Section 2:
There are two main boards in this clock, the first for clock control and the instructions for clock control and control of the main LEDs of the clock.
This board can execute the following commands via serial:
>1. h ## - Set Hours [range 1..12 or 0..24]
>2. i ## - set Minutes [range 0..59]
>3. s ## - set Seconds [range 0..59]
>4. d ## - set Date [range 1.31]
>5. m ## - set Month [range 1..12]
>6. y ## - set Year [range 0..99]
>7. w ## - arbitrary day of the week [range 1..7]
>8. t - Get Status All LED => 00000
>9. g # (LEDGet) - get Color LED [range 1,2,3,4,5]
>10. b ## (LEDSet) - set Color LED [range LED 1,2 / * - 1.2 - * /, 3 / * - 2 - * /, 4 / * - 3 - * /, 5] [range color 0,1,2,3]
>11. l # - Set Game Mode Status [range 0, 1]
>12. r - Print Led Status
>13. a - set AM 
>14. p - set PM
>15. z - start clock 
>16. Z - stop clock
>17. q - SQW / OUT = 1Hz 
>18. Q - stop SQW / OUT
>19. \> ##, ### - write to register ## the value ###
>20. < ## - read the value in register ##

******You can put # the above quotes instead.******

The next board is responsible for controlling the wireless connection between the sun and the LED, and the middle of the hour is controlled by the first version via the web and the second by the mobile application, which has the responsibility of maintaining and reporting the first board.

# What pieces are used in each board?
\- In the first board:
* Arduino pro mini Or ATMEGA 8
* DS 1307
* ULN 2003
* ULN 2803
* Schottky diode 10A07
* CRYSTAL 32.678kHz
* Resistors 10K
* Regulatory 8705
* capacitor 25v 3300uf
* LED Green

\- In the next board:
* Wemos D1 Or ESP 8266 v.12
* ULN 2803
* Schottky diode 10A07
* Resistors 10K

# How is this watch read?
The count is based on the Fibonacci sequence as the first five sentences of this sequence are used to represent sentences from 1 to 12, using LEDs and color schemes as follows:
- Required Sequence {1,1,2,3,5}
- Total Color {Black,Red,Green,Blue}
- Black in order of 0 or non.
- Red means minutes worth five times that unit.
- Green indicates the meaning of a watch worth its time.
- Blue means minutes and hours with listed values.
<h4>For example, if unit 1 is green, it is 1 hour, if it is red, it is 5 minutes, if it is blue, it is 1 hours and 5 minutes.</h4>
