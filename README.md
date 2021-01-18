# I2C_scan
This code scan the I2C address with an STM32F0xx microcontroller

I2C port information
  SDA -----> PB9
  SCK -----> PB8
  
The code scan from index 0 to index 127 by sendin an start in the CR1 register.
If an Acknolege is received by the Slave device then it will send an register and finish the I2C protocol
If a Not Acknolege is received by the Slave device then it will clean the register and the bus protocol.

This was tested with an Accelerometer AXLD345 and a Preassure Sensor BMP180
