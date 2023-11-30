# """
# Author  	    			: Muhammad (Ali) Ammar                          
# Date 						: Nov 22, 2023       	 	         	
# Version 	 				: V01                                     
# Filename					: UDS_GUI.py                        

# """


# import tkinter as tk
# from tkinter import ttk  # Import the ttk module for Treeview
# from tkinter import filedialog
# import os
# from PIL import Image, ImageTk
# import platform



# ZERO_VALUE= 0
# ONE_VALUE = 1

# ############################# Public Functions #################################################################################

# def resize_image(Copy_Img, Copy_Height, Copy_Weight):
#     Loc_Size = (Copy_Height, Copy_Weight)
#     Loc_ResizedImg = Copy_Img.resize(Loc_Size, Image.LANCZOS)
#     return ImageTk.PhotoImage(Loc_ResizedImg)


# ##############################################################################################################


# class ProjectWindow:
#     def __init__(self, Copy_Root):
#         self.Copy_Root = Copy_Root
#         self.Copy_Root.title("UDS OVER CAN")
#         # self.Copy_Root.configure(bg="lightblue")
#         self.GroupText = tk.Label(Copy_Root, text="UDS Over CAN ", fg="blue", font=("Arial", 21, "bold")).place(x=300, y=0)
#         self.PrjectNameText = tk.Label(Copy_Root, text=" By Group 1-A ", fg="black", font=("Arial", 21, "bold")).place(x=300, y=40)

# ############################# Image Part #################################################################################
        
        
#         # Project Image 
#         self.Loc_ProjectImage = resize_image(Image.open("HexToU8/photo.png"),230,230)
#         self.Loc_ProjectImageLabel = tk.Label(Copy_Root, image=self.Loc_ProjectImage)
#         self.Loc_ProjectImageLabel.place(x=300, y=100)  # Adjust x and y as needed


#         # Led  Image 
#         self.Loc_LedOnImage = resize_image(Image.open("Project G1A/led_on.png"),150,150)

#         self.Loc_LedOffImage = resize_image(Image.open("Project G1A/led_off.png"),150,150)
#         self.Loc_LedImageLabel = tk.Label(Copy_Root, image=self.Loc_LedOnImage)
#         self.Loc_LedImageLabel.place(x=750, y=351)  # Adjust x and y as needed

# ############################## DRAW Lines #################################################################################

#         # Create a Canvas widget for drawing
#         self.HorzontalLine = tk.Canvas(Copy_Root, width=900, height=2, bg="black")
#         self.HorzontalLine.place(x=0, y=350)


# ############################## BUTTON PART ##################################################################################3

#         # Create an entry widget(White Space ) for user input
#         self.Loc_WhiteWdiget = tk.Entry(Copy_Root)
#         self.Loc_WhiteWdiget.place(x=300, y=800)  # Set x and y coordinates in pixels

 
#         # Create A Button
#         self.Loc_Button1 = tk.Button(Copy_Root, text="Enter Number", command=self.staticGetButtonNumber)
#         self.Loc_Button1.place(x=320, y=830)  # Set x and y coordinates in pixels


#         # Bind the <Return> key to the check_number function
#         self.Loc_WhiteWdiget.bind("<Return>", self.staticGetButtonNumber)

# ############################## Table PART ##################################################################################3
# # Create a custom style for the Treeview
#         self.TableStyleConfig = ttk.Style()
#         self.TableStyleConfig.configure("Treeview", background="lightblue")

#         # Create a Treeview widget for the table
#         self.Loc_Table = ttk.Treeview(Copy_Root, columns=("Column1", "Column2","Column3"), show="headings", height=3,style ="Treeview")
#         self.Loc_Table.place(x=250, y=355)
        
#         # Set the width of columns
#         Loc_ColumnWidthList = {"Column1": 100, "Column2": 120, "Column3": 150}
#         for Loc_ColumnCounter, Loc_WidthCounter in Loc_ColumnWidthList.items():
#             self.Loc_Table.column(Loc_ColumnCounter, width=Loc_WidthCounter)

#        # Set the column headings
#         Loc_ColumnHeadingist = {"Column1": "Service ID ", "Column2": "Service Name", "Column3": "Status"}
#         for Loc_ColumnCounter, Loc_HeadingCounter in Loc_ColumnHeadingist.items():
#             self.Loc_Table.heading(Loc_ColumnCounter, text=Loc_HeadingCounter)
        

#         # Set Rows 
#         self.Loc_Table.insert("", 0, values=("0x1", "LED","   ERROR" ))
#         self.Loc_Table.insert("", 1, values=("0x02", "Seat Belt","   FIXED"))
#         self.Loc_Table.insert("", 2, values=("0x03", "Future Serivce","" ))

#         self.staticSetRowBackgroundColor(0,  "red")
#         self.staticSetRowBackgroundColor(1,  "green")


# ############################## Static Function  For Class only  ##################################################################################


#     def staticSetRowBackgroundColor(self, row, color):
#         # Create a unique tag name based on the row
#         Loc_Tag = f"cell_{row}"

#         # Configure the tag with the specified background color
#         self.Loc_Table.tag_configure(Loc_Tag, background=color)

#         # Apply the tag to the specified cell in the third column
#         Loc_ItemId = self.Loc_Table.get_children()[row]
        
#         # Ensure that existing_tags is always a tuple
#         existing_tags = tuple(self.Loc_Table.item(Loc_ItemId, 'tags'))
        
#         # Concatenate the new tag with the existing tags and apply them to the item
#         self.Loc_Table.item(Loc_ItemId, tags=existing_tags + (Loc_Tag,))

#         # Force a redisplay of the table to update the tags
#         self.Loc_Table.update_idletasks()






#     def staticGetButtonNumber(self, event=None):
#         Loc_Number = int(self.Loc_WhiteWdiget.get())

#         print(f"Received number: {Loc_Number}")  # Display the number in the terminal

#         item_id = self.Loc_Table.get_children()[ZERO_VALUE]
        
#         if Loc_Number == 0:
#             self.Loc_LedImageLabel.configure(image=self.Loc_LedOffImage)
#             self.Loc_Table.set(item_id, column="Column3", value=f"   FIXED")
#             self.staticSetRowBackgroundColor(ZERO_VALUE, "green")
        
#         else :
#             self.Loc_LedImageLabel.configure(image=self.Loc_LedOnImage)
#             self.Loc_Table.set(item_id, column="Column3", value=f"   ERROR")
#             self.staticSetRowBackgroundColor(ZERO_VALUE, "red")


#         # Clear the entry widget
#         self.Loc_WhiteWdiget.delete(ZERO_VALUE, tk.END)



# ################################## Main Part #########################################################################################
# # Welcome Message
# print("Welcome To The Project")

# # Create the main window
# MainRoot = tk.Tk()
# MainRoot.geometry("900x900")  # Set the window size (width x height)

# # Create an instance of the ProjectWindow class
# ProjectWindow(MainRoot)

# # Start the GUI event loop
# MainRoot.mainloop()


##################################### UDS Version 2 #################################################################################


"""
Author  	    			: Muhammad (Ali) Ammar                          
Date 						: Nov 22, 2023       	 	         	
Version 	 				: V01                                     
Filename					: UDS_GUI.py                        

"""


import tkinter as tk
from tkinter import ttk  # Import the ttk module for Treeview
from tkinter import filedialog
import os
from PIL import Image, ImageTk
import platform

import serial
import glob
import struct
import time
import threading
import sys


ZERO_VALUE= 0
ONE_VALUE = 1




############################# Public Functions #################################################################################

def resize_image(Copy_Img, Copy_Height, Copy_Weight):
    Loc_Size = (Copy_Height, Copy_Weight)
    Loc_ResizedImg = Copy_Img.resize(Loc_Size, Image.LANCZOS)
    return ImageTk.PhotoImage(Loc_ResizedImg)



## uart Part 
def Get_SerialPort():
    Loc_PortsList = glob.glob('/dev/ttyUSB*')
    return Loc_PortsList[0] if Loc_PortsList else None

# Find the serial port
Global_SerialPort = Get_SerialPort()

if Global_SerialPort is None:
    print("No suitable serial port found.")
    sys.exit()


## Serial Configuration 

print(f"Serial port found: {Global_SerialPort}")
Global_BaudRate = 115200
ser = serial.Serial(Global_SerialPort, Global_BaudRate, stopbits=serial.STOPBITS_ONE, parity=serial.PARITY_NONE, bytesize=serial.EIGHTBITS, timeout=1)
ser.flush()
print(f"Serial communication established on {Global_SerialPort} at {Global_BaudRate} baud")




##############################################################################################################


class ProjectWindow:
    def __init__(self, Copy_Root):
        self.Copy_Root = Copy_Root
        self.Copy_Root.title("UDS OVER CAN")
        # self.Copy_Root.configure(bg="lightblue")
        self.GroupText = tk.Label(Copy_Root, text="UDS Over CAN ", fg="blue", font=("Arial", 21, "bold")).place(x=300, y=0)
        self.PrjectNameText = tk.Label(Copy_Root, text=" By Group 1-A ", fg="black", font=("Arial", 21, "bold")).place(x=300, y=40)

        self.rx_isr_thread = threading.Thread(target=self.rx_isr, daemon=True)
        self.rx_isr_thread.start()
############################# Image Part #################################################################################
        
        
        # Project Image 
        self.Loc_ProjectImage = resize_image(Image.open("HexToU8/photo.png"),230,230)
        self.Loc_ProjectImageLabel = tk.Label(Copy_Root, image=self.Loc_ProjectImage)
        self.Loc_ProjectImageLabel.place(x=300, y=100)  # Adjust x and y as needed


        # Led  Image 
        self.Loc_LedOnImage = resize_image(Image.open("Project G1A/led_on.png"),150,150)

        self.Loc_LedOffImage = resize_image(Image.open("Project G1A/led_off.png"),150,150)
        self.Loc_LedImageLabel = tk.Label(Copy_Root, image=self.Loc_LedOnImage)
        self.Loc_LedImageLabel.place(x=750, y=351)  # Adjust x and y as needed

############################## DRAW Lines #################################################################################

        # Create a Canvas widget for drawing
        self.HorzontalLine = tk.Canvas(Copy_Root, width=900, height=2, bg="black")
        self.HorzontalLine.place(x=0, y=350)


############################## BUTTON PART ##################################################################################3

        # Create an entry widget(White Space ) for user input
        self.Loc_WhiteWdiget = tk.Entry(Copy_Root)
        self.Loc_WhiteWdiget.place(x=300, y=800)  # Set x and y coordinates in pixels

 
        # Create A Button
        self.Loc_Button1 = tk.Button(Copy_Root, text="Enter Number", command=self.staticGetButtonNumber)
        self.Loc_Button1.place(x=320, y=830)  # Set x and y coordinates in pixels


        # Bind the <Return> key to the check_number function
        self.Loc_WhiteWdiget.bind("<Return>", self.staticGetButtonNumber)

############################## Table PART ##################################################################################3
# Create a custom style for the Treeview
        self.TableStyleConfig = ttk.Style()
        self.TableStyleConfig.configure("Treeview", background="lightblue")

        # Create a Treeview widget for the table
        self.Loc_Table = ttk.Treeview(Copy_Root, columns=("Column1", "Column2","Column3"), show="headings", height=3,style ="Treeview")
        self.Loc_Table.place(x=250, y=355)
        
        # Set the width of columns
        Loc_ColumnWidthList = {"Column1": 100, "Column2": 120, "Column3": 150}
        for Loc_ColumnCounter, Loc_WidthCounter in Loc_ColumnWidthList.items():
            self.Loc_Table.column(Loc_ColumnCounter, width=Loc_WidthCounter)

       # Set the column headings
        Loc_ColumnHeadingist = {"Column1": "Service ID ", "Column2": "Service Name", "Column3": "Status"}
        for Loc_ColumnCounter, Loc_HeadingCounter in Loc_ColumnHeadingist.items():
            self.Loc_Table.heading(Loc_ColumnCounter, text=Loc_HeadingCounter)
        

        # Set Rows 
        self.Loc_Table.insert("", 0, values=("0x1", "LED","   ERROR" ))
        self.Loc_Table.insert("", 1, values=("0x02", "Seat Belt","   FIXED"))
        self.Loc_Table.insert("", 2, values=("0x03", "Future Serivce","" ))

        self.staticSetRowBackgroundColor(0,  "red")
        self.staticSetRowBackgroundColor(1,  "green")


############################## Static Function  For Class only  ##################################################################################


    def staticSetRowBackgroundColor(self, row, color):
        # Create a unique tag name based on the row
        Loc_Tag = f"cell_{row}"

        # Configure the tag with the specified background color
        self.Loc_Table.tag_configure(Loc_Tag, background=color)

        # Apply the tag to the specified cell in the third column
        Loc_ItemId = self.Loc_Table.get_children()[row]
        
        # Ensure that existing_tags is always a tuple
        existing_tags = tuple(self.Loc_Table.item(Loc_ItemId, 'tags'))
        
        # Concatenate the new tag with the existing tags and apply them to the item
        self.Loc_Table.item(Loc_ItemId, tags=existing_tags + (Loc_Tag,))

        # Force a redisplay of the table to update the tags
        self.Loc_Table.update_idletasks()






    def staticGetButtonNumber(self, event=None):
        Loc_Number = int(self.Loc_WhiteWdiget.get())

        print(f"Received number: {Loc_Number}")  # Display the number in the terminal

        item_id = self.Loc_Table.get_children()[ZERO_VALUE]
        
        if Loc_Number == 0:
            self.Loc_LedImageLabel.configure(image=self.Loc_LedOffImage)
            self.Loc_Table.set(item_id, column="Column3", value=f"   FIXED")
            self.staticSetRowBackgroundColor(ZERO_VALUE, "green")
        
        else :
            self.Loc_LedImageLabel.configure(image=self.Loc_LedOnImage)
            self.Loc_Table.set(item_id, column="Column3", value=f"   ERROR")
            self.staticSetRowBackgroundColor(ZERO_VALUE, "red")


        # Clear the entry widget
        self.Loc_WhiteWdiget.delete(ZERO_VALUE, tk.END)

    def rx_isr(self):
        loc_string_buffer = ""  # Buffer to accumulate characters
        while True:
            loc_received_char = ser.read(1).decode('utf-8')  # Read one character
            if loc_received_char == '\0':
                # Process the accumulated characters
                if loc_string_buffer == "1":
                    item_id = self.Loc_Table.get_children()[ZERO_VALUE]
                    self.Loc_LedImageLabel.configure(image=self.Loc_LedOffImage)
                    self.Loc_Table.set(item_id, column="Column3", value=f"   FIXED")
                    self.staticSetRowBackgroundColor(ZERO_VALUE, "green")

                elif loc_string_buffer == "0":
                    item_id = self.Loc_Table.get_children()[ZERO_VALUE]
                    self.Loc_LedImageLabel.configure(image=self.Loc_LedOnImage)
                    self.Loc_Table.set(item_id, column="Column3", value=f"   ERROR")
                    self.staticSetRowBackgroundColor(ZERO_VALUE, "red")
                else:
                    print(f"Received unexpected data: {loc_string_buffer}.")

                loc_string_buffer = ""
            else:
                # Accumulate characters until a null character is encountered
                loc_string_buffer += loc_received_char


################################## Main Part #########################################################################################
# Welcome Message
print("Welcome To The Project")

# Create the main window
MainRoot = tk.Tk()
MainRoot.geometry("900x900")  # Set the window size (width x height)

# Create an instance of the ProjectWindow class
ProjectWindow(MainRoot)

# Start the GUI event loop
MainRoot.mainloop()
