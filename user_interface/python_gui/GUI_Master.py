# Copyright 2021 <WeeW Stack >

# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files(the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify,
# merge, publish, distribute, sublicense, and/or sell copies of the
# Software, and to permit persons to whom the Software is furnished
# to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.

import tkinter as tk
from tkinter import *
from tkinter import messagebox
import threading
import customtkinter
from customtkinter import  CTkButton, CTkLabel, CTkFrame, CTkOptionMenu
from datetime import datetime

import numpy as np




class RootGUI():
    def __init__(self, serial,data):
        '''Initializing the root GUI and other comps of the program'''
        self.root = Tk()
        self.root.title("RWIP-GUI")
        self.root.geometry("210x80")
        self.root.configure(background='#333333')
        self.root.iconbitmap('htw.ico')
        
        self.serial =serial
        self.data=data
        self.root.protocol("WM_DELETE_WINDOW",self.close_window)
        self.root.resizable(False, False)


    def close_window(self):
        print("Closing window")
        self.root.destroy()
        self.serial.SerialClose(self)
        self.serial.threading=False


# Class to setup and create the communication manager with MCU
class ComGui():
    def __init__(self, root, serial,data):
        '''
        Initialize the connexion GUI and initialize the main widgets 
        '''
        self.root = root
        self.serial = serial
        self.data = data

        self.frame = CTkFrame(root)
        font = customtkinter.CTkFont("Cascadia Code", 14)


        self.label_com = CTkLabel(
            self.frame, text="Port: ",width=8,font=font, anchor="nw")
        self.label_bd = CTkLabel(
            self.frame, text="Speed: ",width=8,font=font, anchor="nw")

        self.baudOptionMenu()
        self.ComOptionMenu()

        self.btn_refresh = CTkButton(master=self.frame,font=font, text="⟳",
                                  width=10,  command=self.com_refresh)
        self.btn_connect = CTkButton(master=self.frame,font=font, text="✔",
                                  width=10,   command=self.serial_connect)
        self.btn_connect.configure(state=tk.DISABLED, fg_color="green")

        # Optional Graphic parameters
        self.padx = 5
        self.pady = 5

        # Put all the elements on the grid 
        self.publish()

    def publish(self):
        '''
         Method to display all the Widget of the main frame
        '''
        self.frame.grid(row=0, column=0,columnspan=3,padx=self.padx, pady=self.pady, sticky="nsw")
        self.label_com.grid(column=1, row=2,padx=self.padx, pady=self.pady)
        self.label_bd.grid(column=1, row=3,padx=self.padx, pady=self.pady)

        self.drop_baud.grid(column=2, row=3, padx=self.padx, pady=self.pady)
        self.drop_com.grid(column=2, row=2, padx=self.padx)

        self.btn_refresh.grid(column=3, row=2,padx=self.padx, pady=self.pady)
        self.btn_connect.grid(column=3, row=3,padx=self.padx, pady=self.pady)

    def ComOptionMenu(self):
        '''
         Method to Get the available COMs connected to the PC
         and list them into the drop menu
        '''
        # Generate the list of available coms

        self.serial.getCOMList()

        self.clicked_com = StringVar()
        self.clicked_com.set(self.serial.com_list[0])

        font = customtkinter.CTkFont("Cascadia Code", 12)

        self.drop_com = CTkOptionMenu(
            self.frame, variable=self.clicked_com,font=font, values=self.serial.com_list, command=self.connect_ctrl)

        self.drop_com.configure(width=10)

    def baudOptionMenu(self):
        '''
         Method to list all the baud rates in a drop menu
        '''
        self.clicked_bd = StringVar()
        bds = ["-",
               "300",
               "600",
               "1200",
               "2400",
               "4800",
               "9600",
               "14400",
               "19200",
               "28800",
               "38400",
               "56000",
               "57600",
               "115200",
               "128000",
               "256000"]
        self.clicked_bd .set(bds[0])

        font = customtkinter.CTkFont("Cascadia Code", 12)

        self.drop_baud = CTkOptionMenu(
        self.frame, variable=self.clicked_bd, values=bds, font=font, command=self.connect_ctrl)

        self.drop_baud.configure(width=10)


    def connect_ctrl(self, widget):
        '''
        Mehtod to keep the connect button disabled if all the 
        conditions are not cleared
        '''
        print("Connect ctrl")
        if "-" in self.clicked_bd.get() or "-" in self.clicked_com.get():
            self.btn_connect.configure(state=tk.DISABLED)

        else:
            self.btn_connect.configure(state=tk.ACTIVE)


    def com_refresh(self):
        print("Refresh")
        self.drop_com.destroy()

        # Refresh the list of available Coms
        self.ComOptionMenu()
        self.drop_com.grid(column=2, row=2, padx=self.padx)

        logic = []
        self.connect_ctrl(logic)

    def serial_connect(self):
        '''
        Method that Updates the GUI during connect / disconnect status
        Manage serials and data flows during connect / disconnect status
        '''
        if self.btn_connect._text in "✔":

            # Start the serial communication
            self.serial.SerialOpen(self)

            # If connection established move on
            if self.serial.ser.status:
                self.btn_connect.configure(text="✕")
                self.btn_connect.configure(state=tk.ACTIVE, fg_color="red")
                self.drop_baud.configure(state=tk.DISABLED)
                self.drop_com.configure(state=tk.DISABLED)
                
                self.dis = DisGUI(self.root, self.serial, self.data)
                self.conn = ConnGUI(self.root, self.serial, self.data)

                self.serial.t1 = threading.Thread(
                    target=self.serial.SerialSync, args=(self,),  daemon=True
                )
                self.serial.t1.start()
            else:
                ErrorMsg = f"Failure to estabish UART connection using {self.clicked_com.get()} "
                messagebox.showerror("showerror", ErrorMsg)

        else:
            self.serial.threading = False

            self.serial.SerialClose(self)
            self.conn.ConnGUIClose()
            self.dis.DisGUIClose()
            self.data.ClearData()

            self.btn_connect.configure(text="✔")
            self.btn_connect.configure(state=tk.ACTIVE, fg_color="green")
            self.drop_com.configure(state=tk.ACTIVE)
            self.drop_baud.configure(state=tk.ACTIVE)



class ConnGUI():
    def __init__(self, root, serial, data):
        '''
        Initialize main Widgets for communication GUI
        '''
        self.root = root
        self.serial = serial
        self.data = data
        self.dis_gui = DisGUI(self.root, self.serial, self.data)
        font = customtkinter.CTkFont("Cascadia Code", 12)

        #self.frame = CTkFrame(root)
        self.sync_frame = CTkFrame(root)
        self.start_frame = CTkFrame(root)

        self.sync_label = CTkLabel(
            self.sync_frame, text="Status: ",width=10,font=font, anchor="nw")
        self.sync_status = CTkLabel(
            self.sync_frame, text="..Sync..",width=10,font=font, anchor="nw")

        self.stream_label = CTkLabel(self.start_frame,font=font, text="Start/Stop:",
                                      anchor="nw")
        
        self.btn_start_stream = CTkButton(master=self.start_frame,font=font, text="➤",
                                    width=10,command=self.start_stream)
        self.btn_start_stream.configure(state=tk.DISABLED, fg_color="green")
        

        self.btn_stop_stream = CTkButton(master=self.start_frame,font=font, text="■",
                                    width=10,command=self.stop_stream)
        self.btn_stop_stream.configure(state=tk.DISABLED, fg_color="red")


        # Optional Graphic parameters
        self.padx = 5
        self.pady = 5

        # Extending the GUI
        self.ConnGUIOpen()


    def ConnGUIOpen(self):
        '''
        Method to display all the widgets 
        '''
        self.root.geometry("390x500")
        #self.frame.grid( column=3, row=0,padx=self.padx, pady=self.pady, sticky="nsw")
        self.sync_frame.grid( column=3, row=0,padx=self.padx, pady=self.pady, sticky="nsw")

        self.sync_label.grid(column=0, row=1,padx=self.padx, pady=self.pady)
        self.sync_status.grid(column=0, row=2,padx=self.padx, pady=self.pady)
  
        self.start_frame.grid( column=4, row=0,padx=self.padx, pady=self.pady, sticky="nsw")
        
        self.stream_label.grid(column=0, row=1,columnspan=2, padx=self.padx, pady=self.pady)

        self.btn_start_stream.grid(column=0, row=2, padx=self.padx, pady=self.pady)
        self.btn_stop_stream.grid(column=1, row=2, padx=self.padx, pady=self.pady)


    def ConnGUIClose(self):
        '''
        Method to close the connection GUI and destorys the widgets
        '''
        # Must destroy all the element so they are not kept in Memory
        for widget in self.sync_frame.winfo_children():
            widget.destroy()
        for widget in self.start_frame.winfo_children():
            widget.destroy()

        self.sync_frame.destroy()
        self.start_frame.destroy()
        self.root.geometry("210x80")

    def start_stream(self):
        self.btn_start_stream.configure(state=tk.DISABLED)
        self.btn_stop_stream.configure(state=tk.ACTIVE)
        self.serial.t1 = threading.Thread(target=self.serial.SerialDataStream, args=(self,),daemon=True)
        self.serial.t1.start()


    def stop_stream(self):
        self.btn_stop_stream.configure(state=tk.DISABLED)
        self.btn_start_stream.configure(state=tk.ACTIVE)
        self.serial.threading = False
        self.serial.SerialStop(self)


class DisGUI():
    def __init__(self, root, serial, data):
        self.root = root
        self.serial = serial
        self.data = data
        custom_font = customtkinter.CTkFont("Cascadia Code", 16)
        custom_font_values = customtkinter.CTkFont("Cascadia Code", 18,"bold")
        custom_font_user_infos = customtkinter.CTkFont("Courier", 14)

        self.frame = CTkFrame(root)
        
        self.pendulum_pos_frame = CTkFrame(self.frame)
        self.pendulum_pos_label = CTkLabel(self.pendulum_pos_frame,font=custom_font ,text="Pendulum Position:")
        self.pendulum_pos_value_frame = CTkFrame(self.frame)
        self.pendulum_pos_value = CTkLabel(self.pendulum_pos_value_frame,font=custom_font_values , text="0")
        self.pendulum_pos_unit_frame = CTkFrame(self.frame)
        self.pendulum_pos_unit = CTkLabel(self.pendulum_pos_unit_frame,font=custom_font , text="°")

        self.motor_speed_frame = CTkFrame(self.frame)
        self.motor_speed_label = CTkLabel(self.motor_speed_frame,font=custom_font , text="Motor Speed: ")
        self.motor_speed_value_frame = CTkFrame(self.frame)
        self.motor_speed_value = CTkLabel(self.motor_speed_value_frame,font=custom_font_values , text="0")
        self.motor_speed_unit_frame = CTkFrame(self.frame)
        self.motor_speed_unit = CTkLabel(self.motor_speed_unit_frame,font=custom_font , text="RPM")

        self.time_to_up_frame = CTkFrame(self.frame)
        self.time_to_up_label = CTkLabel(self.time_to_up_frame,font=custom_font , text="Time to Upright: ")
        self.time_to_up_value_frame = CTkFrame(self.frame)
        self.time_to_up_value = CTkLabel(self.time_to_up_value_frame,font=custom_font_values , text="0")
        self.time_to_up_unit_frame = CTkFrame(self.frame)
        self.time_to_up_unit = CTkLabel(self.time_to_up_unit_frame,font=custom_font , text="s")

        self.user_infos_frame = customtkinter.CTkScrollableFrame(self.frame,label_font=custom_font , label_text='User Infos: ')
        self.user_infos_value = CTkLabel(self.user_infos_frame,font=custom_font_user_infos , text='...')




        self.padx = 5
        self.pady = 5
        self.DisGUIOpen()

    def DisGUIOpen(self):
        '''
        Method to display all the widgets 
        '''
        self.root.geometry("390x500")  # Adjust the window size
        self.user_infos_msg=""
        
        # Add display frame
        self.frame.grid(row=4, column=1,columnspan=5, padx=self.padx, pady=self.pady,  sticky="nsw")

        # Add subframes to the display frame
        self.pendulum_pos_frame.grid(row=0, column=1,columnspan=2,  padx=self.padx, pady=self.pady, sticky="nsew")
        self.motor_speed_frame.grid(row=1, column=1,columnspan=2,  padx=self.padx, pady=self.pady, sticky="nsew")
        self.time_to_up_frame.grid(row=2, column=1,columnspan=2,  padx=self.padx, pady=self.pady, sticky="nsew")
        self.user_infos_frame.grid(row=3, column=1,columnspan=4,  padx=self.padx, pady=self.pady, sticky="nsew")

        self.pendulum_pos_label.grid(column=0, row=0, padx=self.padx, pady=self.pady)
        self.motor_speed_label.grid(column=0, row=1, padx=self.padx, pady=self.pady)
        self.time_to_up_label.grid(column=0, row=2, padx=self.padx, pady=self.pady)

        self.pendulum_pos_value_frame.grid(row=0, column=3,  padx=self.padx, pady=self.pady, sticky="nsew")
        self.motor_speed_value_frame.grid(row=1, column=3,  padx=self.padx, pady=self.pady, sticky="nsew")
        self.time_to_up_value_frame.grid(row=2, column=3,  padx=self.padx, pady=self.pady, sticky="nsew")

        self.pendulum_pos_value.grid(column=1, row=0, padx=self.padx, pady=self.pady)
        self.motor_speed_value.grid(column=1, row=1, padx=self.padx, pady=self.pady)
        self.time_to_up_value.grid(column=1, row=2, padx=self.padx, pady=self.pady)
        
        self.pendulum_pos_unit_frame.grid(row=0, column=4,  padx=self.padx, pady=self.pady, sticky="nsew")
        self.motor_speed_unit_frame.grid(row=1, column=4,  padx=self.padx, pady=self.pady, sticky="nsew")
        self.time_to_up_unit_frame.grid(row=2, column=4,  padx=self.padx, pady=self.pady, sticky="nsew")

        self.pendulum_pos_unit.grid(column=2, row=0, padx=self.padx, pady=self.pady)
        self.motor_speed_unit.grid(column=2, row=1, padx=self.padx, pady=self.pady)
        self.time_to_up_unit.grid(column=2, row=2, padx=self.padx, pady=self.pady)

        self.user_infos_value.grid(column=1, row=1, padx=self.padx, pady=self.pady)
 

    def UpdateValues(self, channel):
        if self.serial.threading and not getattr(self, 'update_in_progress', False):
            self.update_in_progress = True
            
            # Update values
            self.pendulum_pos_value.configure(text=f"{channel[0]}")
            self.motor_speed_value.configure(text=f"{channel[1]}")
            self.time_to_up_value.configure(text=f"{channel[2]}")
            update_info = self.UpdateUserInfo(channel[3])
            if update_info != "":
                timestamp = datetime.now().strftime("%H:%M:%S")
                self.user_infos_msg += f"{timestamp} - {update_info}\n"
                self.user_infos_value.configure(text=self.user_infos_msg)
            self.root.after(10, self.reset_update_flag)

    def UpdateUserInfo(self,value):
        if value == 1:
            return "Error 1"
        elif value == 345:
            return "Error 2"
        elif value == 346:
            return "Error 3"
        elif value == 347:
            return "Error 4"
        elif value == 348:
            return "Error 5"
        elif value == 349:
            return "Error 6"
        else:
            return ""
        
    def reset_update_flag(self):
        del self.update_in_progress

    def DisGUIClose(self):
        for widget in self.frame.winfo_children():
            widget.destroy()
        self.frame.destroy()
        self.root.geometry("210x80")
        

if __name__ == "__main__":
    RootGUI()
    ComGui()
    ConnGUI()
    DisGUI()