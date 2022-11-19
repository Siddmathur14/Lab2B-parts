
-The logic_analyser example from pico-examples was adapted to capture an I2C trace whenever the BOOT button was pressed.

The capture included both the SCL and SDA pins.
Two separate boards were utilized to display the capture on PuTTY. The first board was running the adapted code from logic_analyser and the other board (RP2040) runs the code that interfaces APDS9960 with the QtPy using micropython.


https://user-images.githubusercontent.com/114244849/202833897-ab7fc0ba-1f86-4dc3-8489-0afbff8fdd0b.mp4

