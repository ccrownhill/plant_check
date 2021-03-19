# Plant check

This arduino program can be used to determine whether a plant needs watering.

Necessary components:

* 1 Arduino
* 1 breadboard
* 1 LED
* 1 10K Ohm resistor
* 2 galvanized nails
* Some jumper wires

The 2 nails need to be put into the earth of the plant. The arduino will then determine how big the resistance between the nails is. The bigger it is the fewer water is inside the plant earth. If there is not enough water the led will light up or flash if the value is close to the threshold value.

It is inspired from the first Lab of the book "Head first C".
