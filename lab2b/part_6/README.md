
-The logic_analyser example from pico-examples was adapted to capture an I2C trace whenever the BOOT button was pressed.

The capture included both the SCL and SDA pins.
Two separate boards were utilized to display the capture on PuTTY. The first board was running the adapted code from logic_analyser and the other board (RP2040) runs the code that interfaces APDS9960 with the QtPy using micropython.
