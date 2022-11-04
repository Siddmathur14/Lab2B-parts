# Part 5 : I2C Traffic and Trace

## This is an overview of how the I2C trace was generated on the oscilloscope

1) Connections are made between the RP2040 and the APDS9960 sensor. Values are taken by probing the SDA and SCL along with the ground pins of the APDS9960 sensor.

2) The firefly code is run to generate the I2C trace .

The values are taken using 2 different methods:

1) Using a probe: The probes were connected to the SDA , SCL and ground pins of the APDS9960 sensor.
  
![IMG_9376](https://user-images.githubusercontent.com/114244849/200089636-a2001061-a7c3-424f-9c16-84f968e37814.jpg)



2) Using a logic analyser : The connections remain the same but it is better suited to digital signals.

  ![I2C](https://github.com/Siddmathur14/Lab2B-parts/blob/main/lab2b/part_5/LAB2B_I2C_PART_5/I2C.png)









