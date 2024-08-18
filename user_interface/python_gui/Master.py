# Copyright 2021 <WeeW Stack >

# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files(the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify,
# merge, publish, distribute, sublicense, and/or sell copies of the
# Software, and to permit persons to whom the Software is furnished


from GUI_Master import RootGUI, ComGui
from Serial_Com_ctrl import SerialCtrl
from Data_Com_ctrl import DataMaster

MySerial = SerialCtrl()
MyData = DataMaster()
RootMaster = RootGUI(MySerial, MyData)
# Initiate the Communication Master class that will manage all the other GUI classes
ComMaster = ComGui(RootMaster.root, MySerial, MyData)

RootMaster.root.mainloop()