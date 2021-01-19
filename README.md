# I2C_scan
This code scan the I2C address with an STM32F0xx microcontroller

I2C port information
  SDA -----> PB9
  SCK -----> PB8
  
The code scan from index 0 to index 127 by sending start operation in the CR1 register with the specified Address.
If an Acknoledge is received by the Slave device then it will send a dummy address of register to the slave and finish the I2C protocol
If a Not Acknoledge is received by the Slave device then it will clean the Slave Address Register and finish the I2C protocol.

This was tested with an Accelerometer AXLD345 and a Preassure Sensor BMP180


It is recommended to test each device one at a time

Excel file to calculate timming: https://www.st.com/en/embedded-software/stsw-stm32126.html

specific stm32f0xx.h file must be added
