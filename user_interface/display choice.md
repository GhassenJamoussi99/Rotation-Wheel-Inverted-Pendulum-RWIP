
## Introduction

The User Interface project was initially assigned to Jerrey who, unfortunately, had to leave our group.<br> 
That's why i have taken over the responsibility in this late phase of the project.
We already have 3 displays available, the best of them will be used in the UI of our project.<br>
The choice will be based on the compatibility with the used STM32 microcontroller, and the complexity of the implementation.

## DISPLAY 1: [3.5" TFT SPI 480x320 v1.0](http://www.lcdwiki.com/3.5inch_SPI_Module_ILI9488_SKU:MSP3520)

### Description

- 3.5-inch color screen.
- 480x320 resolution.
- Touch function available.
- Utilizes the SPI serial bus.
- Logic IO port voltage: 3.3V(TTL)


### Possible Issues 

- The SPI module's pins can only input a 3.3V high level, whereas the MCU outputs a high level of 5V. As a result, the display could not run properly without a level converter from 5V to 3.3V.
- The display has no compatible libraries with the used STM32 IDE.

---

## DISPLAY 2: [X-NUCLEO-GFX01M2](https://www.st.com/en/evaluation-tools/x-nucleo-gfx01m2.html)

### Description

- 2.2" SPI QVGA TFT LCD.
- 64-Mbit SPI NOR Flash memory.
- Joystick for easy menu navigation (no need for extra navigation buttons).
- Compatible with STM32 Nucleo-64 boards.

### Possible Issues 
- The provided user manual from ST is for a specific Nucleo board which is the G071RB.
- The use of the GFX01M2 require the use of an extra microcontroller and a communication protocoll with our Nucleo-g431rb.

## DISPLAY 3: LCD-Display

### Description

- Display format: 16 x 2 characters
- I2C Interface
- Easy to implement

### Possible Issues 
- The Display doesn't satisfy the stakeholder and team members needs.

## Conclusion
The First display is not easily usable with the STM32CubeIde. <br>
The Second display will now be tested.<br>
The third display may be used if the second display doesnt work correctly.

