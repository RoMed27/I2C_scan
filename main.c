/**
  ******************************************************************************
/  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
uint8_t  Meassured = 0;
uint16_t Received_Data[3] = {0};


/* Main ------------------------------------------------------------------*/
int main ()
{
/* Enable the peripheral clock of I2C */
   RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
/* Enable the peripheral clock of GPIOB */
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

/* MODER : Alternative function for PB8 and PB9 */
    GPIOB->MODER &= ~(GPIO_MODER_MODER8_0);
    GPIOB->MODER |=  (GPIO_MODER_MODER8_1);

    GPIOB->MODER &= ~(GPIO_MODER_MODER9_0);
    GPIOB->MODER |=  (GPIO_MODER_MODER9_1);

//    GPIOB->AFR[1] |= 1<<GPIO_AFRH_AFSEL8_Pos | 1<<GPIO_AFRH_AFSEL9_Pos;
    GPIOB->AFR[1] = 0x00000011;

/* OTYPER: Open Drain */
    GPIOB->OTYPER |= GPIO_OTYPER_OT_8;
    GPIOB->OTYPER |= GPIO_OTYPER_OT_9;

/* OSPEED: Low */
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR8_0);
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR9_0);

/* PUPD: Low */
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR8);
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR8);

/* Enable I2C */
    I2C1->TIMINGR = (uint32_t) 0x0010020A;

#if 0
	for(uint8_t i = 0x57; i < 128; i++)
	{
	    I2C1->CR1 |= I2C_CR1_PE;
	/* Set Slave Address */
		I2C1->CR2 |= (i << 1);

	/* Set Write on RD_WRN */
		I2C1->CR2 &= ~(I2C_CR2_RD_WRN);

	/* Set the   of byte to transmit */
		I2C1->CR2 |= (1 << 16);

	/* Start condition */
		I2C1->CR2 |= I2C_CR2_START;
		while(I2C1->CR2 & I2C_CR2_START)
		{
			;
		}

		if ((I2C1->ISR & I2C_ISR_NACKF) == 0)
		{
			/* Write Register Adress to Transmit Data Register */
			I2C1->TXDR = 0x2;
			while(!(I2C1->ISR & I2C_ISR_TXE))
			{
				;
			}
			/* Stop Condition */
			I2C1->CR2 |= I2C_CR2_STOP;
			while(I2C1->CR2 & I2C_CR2_STOP)
			{
				;
			}
			Meassured = i;
		}
		else
		{
			I2C1->CR2 &= ~0xFF;
		    I2C1->CR1 &= ~I2C_CR1_PE;
		}
	}
	while(1)
	{}
#endif
#if 1
    I2C1->CR1 |= I2C_CR1_PE;

/* Set Slave Address */
    I2C1->CR2 |= (0x53 << 1);

/* Start condition */
/* Set Write on RD_WRN */
    I2C1->CR2 &= ~(I2C_CR2_RD_WRN);
/* Set the   of byte to transmit */
    I2C1->CR2 |= (2 << 16);
    I2C1->CR2 |= I2C_CR2_START;
    while(I2C1->CR2 & I2C_CR2_START)
    {;}
/* Write Register Adress to Transmit Data Register */
    I2C1->TXDR = 0x2D;
    while(!(I2C1->ISR & I2C_ISR_TXE))
    {;}
    I2C1->TXDR = 0b00001000;
    while(!(I2C1->ISR & I2C_ISR_TXE))
    {;}
/* Stop Condition */
    I2C1->CR2 |= I2C_CR2_STOP;
    while(I2C1->CR2 & I2C_CR2_STOP)
    {;}

/* Start condition */
/* Set Write on RD_WRN */
    I2C1->CR2 &= ~(I2C_CR2_RD_WRN);
/* Set the   of byte to transmit */
    I2C1->CR2 |= (1 << 16);
    I2C1->CR2 |= I2C_CR2_START;
    while(I2C1->CR2 & I2C_CR2_START)
    {;}
/* Write Register Adress to Transmit Data Register */
    I2C1->TXDR = 0x2D;
    while(!(I2C1->ISR & I2C_ISR_TXE))
    {;}
/* Stop Condition */
    I2C1->CR2 |= I2C_CR2_STOP;
    while(I2C1->CR2 & I2C_CR2_STOP)
    {;}
/* Set Read on RD_WRN */
    I2C1->CR2 |= (I2C_CR2_RD_WRN);
/* Set the Number of byte to receive */
    I2C1->CR2 |= (1<<16);
/* Start condition */
    I2C1->CR2 |= I2C_CR2_START;
    while(I2C1->CR2 & I2C_CR2_START)
    {;}
/* Read Register Adress */
    while (!(I2C1->ISR & I2C_ISR_RXNE))
    {;}
    Meassured = I2C1->RXDR;
/* Stop Condition */
    I2C1->CR2 |= I2C_CR2_STOP;
    while(I2C1->CR2 & I2C_CR2_STOP)
    {;}


    while (1)
    {
    /* Set Write on RD_WRN */
        I2C1->CR2 &= ~(I2C_CR2_RD_WRN);
    /* Set the   of byte to transmit */
        I2C1->CR2 |= (1 << 16);
    /* Start condition */
        I2C1->CR2 |= I2C_CR2_START;
        while(I2C1->CR2 & I2C_CR2_START)
        {;}
    /* Write Register Adress to Transmit Data Register */
        I2C1->TXDR = 0x32;
        while(!(I2C1->ISR & I2C_ISR_TXE))
        {;}
    /* Stop Condition */
        I2C1->CR2 |= I2C_CR2_STOP;
        while(I2C1->CR2 & I2C_CR2_STOP)
        {;}
    /* Set Read on RD_WRN */
        I2C1->CR2 |= (I2C_CR2_RD_WRN);
    /* Set the Number of byte to receive */
        I2C1->CR2 |= (6<<16);
    /* Start condition */
        I2C1->CR2 |= I2C_CR2_START;
        while(I2C1->CR2 & I2C_CR2_START)
        {;}
    /* Read Register Adress */
        while (!(I2C1->ISR & I2C_ISR_RXNE))
        {;}
        Received_Data[0]  = I2C1->RXDR;
        while (!(I2C1->ISR & I2C_ISR_RXNE))
        {;}
        Received_Data[0] |= I2C1->RXDR << 8;
        while (!(I2C1->ISR & I2C_ISR_RXNE))
        {;}
        Received_Data[1] = I2C1->RXDR;
        while (!(I2C1->ISR & I2C_ISR_RXNE))
        {;}
        Received_Data[1] |= I2C1->RXDR << 8;
        while (!(I2C1->ISR & I2C_ISR_RXNE))
        {;}
        Received_Data[2] = I2C1->RXDR;
        while (!(I2C1->ISR & I2C_ISR_RXNE))
        {;}
        Received_Data[2] |= I2C1->RXDR << 8;
    /* Stop Condition */
        I2C1->CR2 |= I2C_CR2_STOP;
        while(I2C1->CR2 & I2C_CR2_STOP)
        {;}

        Received_Data[0] = Received_Data[0]/256;
        Received_Data[1] = Received_Data[1]/256;
        Received_Data[2] = Received_Data[2]/256;

    }
#endif
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
