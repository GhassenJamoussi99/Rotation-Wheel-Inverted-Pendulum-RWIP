# Python GUI for RWIP

This Python application aims to establish an UART connection to the Stm32 MCU, facilitating efficient communication through a well-defined communication protocol.

## Files
- [`Master.py`](Master.py): Main entry point for the application
- [`GUI_Master.py`](GUI_Master.py): This script defines the GUI classes
- [`Serial_Com_ctrl.py`](Serial_Com_ctrl.py): This script is responsible for handling UART serial communication.
- [`Data_Com_ctrl.py`](Data_Com_ctrl.py): This script manages and processes data received over the serial port.

## Usage

1. Execute the following command to launch the app:

    ```bash
    python3 master.py
    ```

2. Choose the appropriate baud rate and COM port from the provided options in the GUI.
3. Click the "Connect" button to establish a connection between the Python application and the MCU.
4. Once connected, click on the "Start" button to initiate data streaming from the MCU.
5. To stop the data stream or disconnect from the MCU, use the respective buttons provided in the GUI.

## Acknowledgments

This project is based on the [Python-project](https://github.com/weewStack/Python-projects/tree/master/004-PySerial%20-%20MCU%20-%20Multi-Datareadings/010-DataDisplay%20Graphic%20display) provided by [WeeW Stack](https://github.com/weewStack). The initial code structure, especially the serial communication protocol, served as a foundation for the development of this project.
