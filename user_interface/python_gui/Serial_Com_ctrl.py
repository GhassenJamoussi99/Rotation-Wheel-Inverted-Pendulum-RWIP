# Copyright 2021 <WeeW Stack >

# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files(the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify,
# merge, publish, distribute, sublicense, and/or sell copies of the
# Software, and to permit persons to whom the Software is furnished


import serial.tools.list_ports  
import tkinter as tk

import time


class SerialCtrl():
    def __init__(self):
        '''
        Initializing the main varialbles for the serial data
        '''
        self.sync_cnt = 200


    def getCOMList(self):
        '''
        Method that get the lost of available coms in the system
        '''
        ports = serial.tools.list_ports.comports()
        self.com_list = [com[0] for com in ports]
        self.com_list.insert(0, "-")

    def SerialOpen(self, ComGUI):
        '''
        Method to setup the serial connection and make sure to go for the next only 
        if the connection is done properly
        '''

        try:
            self.ser.is_open
        except:
            PORT = ComGUI.clicked_com.get()
            BAUD = ComGUI.clicked_bd.get()

            self.ser = serial.Serial()
            self.ser.baudrate = BAUD
            self.ser.port = PORT
            self.ser.timeout = 0.1

        try:
            if self.ser.is_open:
                print("Already Open")
                self.ser.status = True
            else:
                PORT = ComGUI.clicked_com.get()
                BAUD = ComGUI.clicked_bd.get()
                self.ser = serial.Serial()
                self.ser.baudrate = BAUD
                self.ser.port = PORT
                self.ser.timeout = 0.01
                self.ser.open()
                self.ser.status = True
        except:
            self.ser.status = False
    

    def SerialClose(self, ComGUI):
        '''
        Method used to close the UART communication
        '''
        try:
            self.ser.is_open
            self.ser.close()
            self.ser.status = False
        except:
            self.ser.status = False

    def SerialStop(self, gui):
        self.ser.write(gui.data.StopStream.encode())

    def SerialSync(self, gui):
        self.threading = True
        cnt = 0
        while self.threading:
            try:
                self.ser.write(gui.data.sync.encode())
                gui.conn.sync_status.configure(text="..Sync..")
                gui.conn.sync_status.configure(text_color="orange")

                gui.data.RowMsg = self.ser.readline()
                # print(f"RowMsg: {gui.data.RowMsg}")
                gui.data.DecodeMsg()
                if gui.data.sync_ok in gui.data.msg[0]:
                    if int(gui.data.msg[1]) > 0:

                        gui.conn.btn_start_stream.configure(state=tk.ACTIVE)
                        gui.conn.sync_status.configure(text="Connected")
                        gui.conn.sync_status.configure(text_color="green")
                        gui.data.SynchChannel = int(gui.data.msg[1])
                        gui.data.GenChannels()
                        gui.data.buildYdata()
                        print(gui.data.Channels, gui.data.YData)
                        self.threading = False
                        break
                if self.threading == False:
                    break
            except Exception as e:
                print(e)
            cnt += 1
            if self.threading == False:
                break
            if cnt > self.sync_cnt:
                cnt = 0
                gui.conn.sync_status.configure(text="connection\n failed")
                gui.conn.sync_status.configure(text_color="red")

                time.sleep(0.5)
                if self.threading == False:
                    break
    
    def SerialDataStream(self, gui):
        self.threading = True
        cnt = 0
        while self.threading:
            try:
                self.ser.write(gui.data.StartStream.encode())
                gui.data.RowMsg = self.ser.readline()
                gui.data.DecodeMsg()
                gui.data.StreamDataCheck()
                if gui.data.StreamData:
                    gui.data.SetRefTime()
                    break
            except Exception as e:
                print(e)
        while self.threading:
            try:
                gui.data.RowMsg = self.ser.readline()
                gui.data.DecodeMsg()
                gui.data.StreamDataCheck()
                if gui.data.StreamData:
                    gui.data.UpdataXdata()
                    gui.data.UpdataYdata()
                    Ysam = [Ys[len(gui.data.XData)-1] for Ys in gui.data.YData]
                    
                    gui.dis_gui.UpdateValues(Ysam)

                    #gui.data.AdjustData()
                    

            except Exception as e:
                print(e)


                

