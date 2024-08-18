# STM Project Modules for the RWIP

This folder contains all the modules that are implemented and linked to the STM project. This README file serves as a guide to provide an overview and clarity on what is being implemented within these modules.

# Module Descriptions
Here is a brief description of the current implemented modules:

## Control

### **main.c**
This module handles the control logic for the system. It includes functions for starting and stopping the motor, as well as monitoring the motor status.

### **encoder.c/h**
The encoder module provides functions to read the position and velocity of the pendulum. It interfaces with the encoder sensor to retrieve the necessary data.

### **error_handling.c/h**
The error handling module handles any fault or error conditions that may occur during the operation of the system. It provides functions to check the motor status and retrieve fault codes.

### **regulator.c/h**
The regulator module implements the PID control algorithm for stabilizing and swinging up the pendulum. It includes functions to compute the control signals based on the current position and velocity of the pendulum.

### **led.c/.h**
The led module implements a feedback system for the user, to differentiate between different status of the software. (error, warning, normal)

# Getting started
Copy the modules inside the STM32 project and specifically under stm32project/Src/ for the source files and stm32project/Inc/ for the header files. Then copy the content of the main.c of modules inside the main.c of the project and you're good to go.