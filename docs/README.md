# STM32 Utilities

This document provides information on a set of STM32 utilities that can enhance your development experience. These utilities include ease of debugging and overriding C library functions. Follow the instructions below to incorporate these utilities into your project.

## Ease Debugging
To enable easy debugging using printf, follow these steps:

1. Open the main.c file of your project.
2. Add the following code snippet to the file:

		/* Private user code ---------------------------------------------------------*/
		/* USER CODE BEGIN 0 */
		int _write(int file, char *ptr, int len)
		{
			HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, HAL_MAX_DELAY);
			return len;
		}
		/* USER CODE END 0 */

3. Make sure to replace huart2 with the appropriate huart that you have initialized for UART communication.

4. Set the SYS (Serial Wire) to be used for debugging. This setting allows you to use the printf function effectively during debugging.

5. Configure USART2 to the following settings:
	* Asynchronous mode
	* Baud Rate: 115200 Bits/s
	* Word Length: 8 Bits (Including Parity)
	* Parity: None
	* Stop bits: 1

## Overriding C lib functions in STM32
To override C library functions in your STM32 project, follow these guidelines:

1. Ensure that the library functions you intend to override have the '__weak' attribute. The '__weak' attribute declares a symbol as weak, allowing its definition to be overridden or replaced at link-time without linker errors.

2. How the '__weak' attribute works:

	* If a symbol is declared as weak in one module (source file), and another module defines the same symbol without the weak attribute, the definition in the latter module will take precedence.

	* If multiple modules define the same symbol as weak, the linker will arbitrarily choose one of the definitions. Please note that the actual behavior may vary depending on the linker and specific implementation.

	* If a symbol is declared as strong (without the weak attribute) in one module, it will always take precedence over any weak definitions of the same symbol.

By following these guidelines, you can customize and override C library functions in your STM32 project according to your requirements.


## Issues and solutions
`MCI_Handle_t *pHandle = pMCI[M1];` needs to be initialized after all STM32 INITS have been performed. Otherwise the pHandle won't work correctly.

I was having a very weird behavior in the following functionality:

	 if (encoder.pendulum_angle > pre_stabilize_limit && encoder.pendulum_angle < post_stabilize_limit)
    {
      	regulator.computeStabilization();
    } else {
		regulator.computeSwingUp();
	}


This following code in the main function could not run because pendulum_angle was not getting updated. 

How did I fix it is that I added a printf before the if statement, and the program (if statements) were considered and the values of pendulum angles were updated accordingly.
The fact that removing printf causes computeStabilization to not be called suggests a subtle issue related to timing, synchronization, or compiler optimization. 
Variable Volatility: encoder.pendulum_angle needs to be declared as volatile if it's being updated by an ISR (Interrupt Service Routine) or another asynchronous source.
Normally, compilers optimize code by caching variables in registers and eliminating redundant reads and writes. When a variable is declared as volatile, the compiler is instructed not to optimize these reads and writes. It ensures that every read and write to the variable is actually carried out, and in the order, the code specifies.
THe live expression under debugger was not considering the register caching.

The axle that connects the pendulum must be fixed and not shake, otherwise it will not be difficult to stabilize if the motor wobbles with the pendulum