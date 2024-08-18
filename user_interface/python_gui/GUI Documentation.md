
# GUI Documentation

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Libraries](#libraries)
6. [Communication Protocol](#communication-protocol)
7. [Implementation](#implementation)
8. [Acknowledgments](#acknowledgments)

## Introduction

The RWIP-GUI is a Python application designed to establish a connection with an STM32 MCU and display relevant data to the motion of the pendulum through a well-defined communication protocol.

## Features

- **UART Communication:** Establishes a serial communication to the STM32 MCU, which is connected to the a specific USB-Port (COM).
- **Dynamic GUI:** The User can select a COM port, baud rate based on the Project configuration and initiate connections.
- **Start/Stop Stream:** Allows the user to start and stop data streaming from the MCU, using 2 different buttons.
- **Real-time Data Display:** Displays real-time data from the MCU, including pendulum position, motor speed, and time to upright.
- **Error/Infos Display:** Displays any occuring errors, warnings or relevant infos.


## Installation

To use the RWIP-GUI, follow these installation steps:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your_username/RWIP-GUI.git
   cd RWIP-GUI
   ```

2. **Install Dependencies:**
   ```bash
   pip install -r dependencies.txt
   ```

## Usage

Execute the following command to launch the application:

```bash
python3 Master.py
```

1. Choose the appropriate baud rate and COM port from the provided options in the GUI.
2. Click the "Connect" button to establish a connection between the Python application and the MCU.
3. Once connected, click on the "Start" button to initiate data streaming from the MCU.
4. To stop the data stream or disconnect from the MCU, use the respective buttons provided in the GUI.


## Libraries

The RWIP-GUI utilizes the following Python libraries:

- **Tkinter:** Used for creating the graphical user interface.
- **Customtkinter:** Used for creating modern UI widgets.
- **Serial:** Enables communication with the STM32 MCU via UART.
- **Numpy:** Facilitates handling and manipulation of numerical data.


## Communication Protocol

The communication protocol used by the RWIP-GUI involves sending specific command strings to the STM32 MCU over UART (this protocoll is based on the [Python-project](https://github.com/weewStack/Python-projects/tree/master/004-PySerial%20-%20MCU%20-%20Multi-Datareadings/010-DataDisplay%20Graphic%20display) provided by [WeeW Stack](https://github.com/weewStack)).<br>
 The key commands in the Python side are:

- `#?#`: Synchronization command to initiate communication.
- `#A#`: Start data streaming command.
- `#S#`: Stop data streaming command.

The GUI sends these commands to the MCU, and the MCU responds accordingly,using the following commands:

- `#!#4#`: Acknowledgment  of successful synchronization, and passing the number of channels (4).
- `#D#180#30#45#1#8#`: Stream Data for the 4 Channels. (the last argument is the total number of characters except '#' and 'D')
- `#E#`: Error (unknown received message).

## Implementation

### Master.py
- The main entry point of the application.
- Creates instances of classes from other modules to initiate the GUI and serial communication.

### GUI_Master.py
- Defines the `RootGUI`, `ComGui`, `ConnGui` and `DisGui` classes responsible for different aspects of the GUI.
- Tkinter and Customtkinter used for creating the main application window and GUI components.
- Threading used for managing the GUI concurrently with serial communication.

### Serial_Com_ctrl.py
- Implements the SerialCtrl class for managing serial communication with the STM32 microcontroller.
- Handles synchronization, data streaming, and connection management.
- Utilizes the serial module for establishing and managing UART communication.
- Threading used for handling synchronization and data streaming.

### Data_Com_ctrl.py
- Defines the DataMaster class responsible for handling and decoding data received from the microcontroller.
- Manages data channels and synchronization.
- Handles decoding and processing of data received over UART.
- Utilizes NumPy for array manipulation.


## Acknowledgments

This project is based on the Python project provided by WeeW Stack. The initial code structure, especially the serial communication protocol, served as a foundation for the development of this project.

