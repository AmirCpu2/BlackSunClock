# Black Sun Clock
This is not an ordinary handheld or digital clock based on the usual clock count.
# What are the parts of this watch and who made it?
1. The body of this watch, designed and implemented by team designer, peyman.
2. The electronic part of this watch made by myself and its details will be mentioned.
3. The programming and design part of Algorithm is a clock designed by me and loaded into this data repository.

# Section 1:
Photos of the body:


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
>9. g (LEDGet) # - get Color LED [range 1,2,3,4,5]
>10. b (LEDSet) ## - set Color LED [range LED 1,2 / * - 1.2 - * /, 3 / * - 2 - * /, 4 / * - 3 - * /, 5] [range color 0,1,2,3]
>11. l - Set Game Mode Status [range 0, 1]
>12. r - Print Led Status
>13. a - set AM p - set PM
>14. z - start clock Z - stop clock
>15. q - SQW / OUT = 1Hz Q - stop SQW / OUT
>16. \> ##, ### - write to register ## the value ###
>17. < ## - read the value in register ##

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

# Section 3:
