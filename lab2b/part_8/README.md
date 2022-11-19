# APDS PROTOCOL


- The following demonstration video shows color and proximity readings acquired from the APDS9960 sensor.



https://user-images.githubusercontent.com/114244849/202834933-fc4f8476-e49f-4f84-aab6-71e267219a27.mp4



- The APDS9960 sensor was interfaced with the RP2040 using the PIO module.
- A header file was created to abstract the actual register addresses (on the slave, i.e. APDS9960) and bit positions, to increase the code readability.
- Once, the I2C communication was established, the APDS9960 was initialized with a few configurations, which were setting the right value in the ATIME register, choosing the right gain value to be put into the APDS_CONTROL_ONE register and finally enabling the proximity and the color sensor.
- Then, the STATUS_REGISTER was polled (read using the I2C communication established) to check if the proximity and color data was ready using corresponding bit masks (with the AND operation).
- After that, the data was read, and printed out to the tty.

