import tkinter as tk
from tkinter import filedialog
import os
from PIL import Image, ImageTk


import serial
import glob
import struct
import time
import threading
import sys
import re



def resize_image(Copy_Image, Copy_Height, Copy_Weight):
    Loc_Size = (Copy_Height, Copy_Weight)
    Loc_ResizedImage = Copy_Image.resize(Loc_Size, Image.LANCZOS)
    return ImageTk.PhotoImage(Loc_ResizedImage)

############################################ UART PART #################################################3

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

############################################ End OF UART PART #################################################3


class ProjectWindow:
    def __init__(self, Copy_Root):

############################################ Set up The root Object ############################################################
        self.Copy_Root = Copy_Root
        self.Copy_Root.title("Hex to Code Generator")


        self.rx_isr_thread = threading.Thread(target=self.rx_isr, daemon=True)
        self.rx_isr_thread.start()

        ################## Second Window#################
        self.SecondScreen = tk.Text(Copy_Root, height=37, width=95)
        self.SecondScreen.place(x=620, y=60)

        #create Colors 
        self.SecondScreen.tag_configure("green", foreground="green",font=("Arial", 15))
        self.SecondScreen.tag_configure("red", foreground="red", font=("Arial", 13))
        self.SecondScreen.tag_configure("blue", foreground="blue",font=("Arial", 15))
        self.SecondScreen.tag_configure("black", foreground="black",font=("Arial", 15))

        self.Loc_DataFlagCheck = 0
        self.Loc_SectorFlagCheck = 0
        

         


############################################ Text ###########################################################################

        self.MadeBy = tk.Label(Copy_Root, text="By: Eng/ Muhammad (Ali) Ammar ", fg="blue", font=("Arial", 21, "bold")).place(x=100, y=650)
        self.SecondScreenWindow = tk.Label(Copy_Root, text="Screen Window ", fg="black", font=("Arial", 21, "bold")).place(x=900, y=20)

        # Image
        Loc_ImagePath = "HexToU8/Escanor.png"
        Loc_OrigrnalImage = Image.open(Loc_ImagePath)
        Loc_ResizedImage = resize_image(Loc_OrigrnalImage, 450, 300)
        self.Loc_ImageLabel = tk.Label(Copy_Root, image=Loc_ResizedImage)
        self.Loc_ImageLabel.image = Loc_ResizedImage
        self.Loc_ImageLabel.place(x=100, y=0)

        # # BaudRate Entry
        # self.BaudrateText = tk.Label(Copy_Root, text="Enter BaudRate:")
        # self.BaudrateText.place(x=10, y=320)
        # self.BaudrateDataEntry = tk.Text(Copy_Root, height=1, width=10)
        # self.BaudrateDataEntry.place(x=120, y=320)

        # # Input Hex File Entry
        # self.Lob_TextInputFile = tk.Label(Copy_Root, text="Input Hex File:")
        # self.Lob_TextInputFile.place(x=10, y=350)
        # self.Loc_WidgetInputFileEntry = tk.Entry(Copy_Root, width=40)
        # self.Loc_WidgetInputFileEntry.place(x=120, y=350)

        # # Generate Button
        # self.Loc_GenerateButton = tk.Button(Copy_Root, text="Generate Code", command=self.GenerateButton_ISR)
        # self.Loc_GenerateButton.place(x=190, y=420)

        # # Browse Button
        # self.Loc_BrowseButton = tk.Button(Copy_Root, text="Browse", command=self.BrowseButton_ISR)
        # self.Loc_BrowseButton.place(x=220, y=380)

        # # Result Label
        # self.Loc_ResultLabel = tk.Label(Copy_Root, text="")
        # self.Loc_ResultLabel.place(x=220, y=450)


        # # Ok Button
        # self.Loc_OkButton = tk.Button(Copy_Root, text="Ok", command=self.Ok_ISR)
        # self.Loc_OkButton.place(x=220, y=500)

################################################################################################################################################

        ### Transmit Button####
        self.Loc_TransmitButton = tk.Button(Copy_Root, text="Transmit Data", command=self.Data_Transmit)
        self.Loc_TransmitButton.place(x=60, y=400)
        
        self.TransmitManualWidget = tk.Text(Copy_Root, height=1, width=15)
        self.TransmitManualWidget.place(x=200, y=400)

        # Bind the <Return> key to the check_number function
        self.TransmitManualWidget.bind("<Return>", self.Data_Transmit)

        ##### End Transmit Button######


        ### Start Button####
        self.Loc_StartCommunicateButton = tk.Button(Copy_Root, text="Start", command=self.Start_Isr)
        self.Loc_StartCommunicateButton.place(x=230, y=350)
        

        ##### End Transmit Button######

################################################################################################################################################        



        # Variables to store fifth and sixth bytes
        self.fifth_byte = '00'


############################################ Static Method ############################################################
############################################ BootLoader ############################################################

    # def voidParseLine(self, line):
    #     try:
    #         fourth_byte = int(line[7:9], 16)
    #     except ValueError:
    #         print(f"Invalid hexadecimal value in line: {line}")
    #         return None, None

    #     if fourth_byte == 4:
    #         self.fifth_byte = line[9:13]
    #         return None, None
    #     elif fourth_byte == 5:
    #         return None, None
    #     elif fourth_byte == 1:
    #         print("End of the file")
    #         return None, None
    #     else:
    #         SecondPartOfAddress = line[3:7]
    #         first_part = self.fifth_byte[0:2]
    #         second_part = self.fifth_byte[2:4]
    #         first_part1, first_part2, first_part3, first_part4 = first_part[0], first_part[1], second_part[0], second_part[1]
    #         ThirdPart = SecondPartOfAddress[0:2]
    #         ForthPart = SecondPartOfAddress[2:4]
    #         first_part5, first_part6, first_part7, first_part8 = ThirdPart[0], ThirdPart[1], ForthPart[0], ForthPart[1]

    #         Loc_DataBytesNumber = int(line[1:3], 16)
    #         Loc_DataBytesValues = ', '.join(str(int(line[i:i+2], 16)) for i in range(9, len(line)-3, 2))
    #         Loc_CheckSum = int(line[-3:], 16)

    #         Loc_ScreenOuputData = f'Record {self.Loc_RecondNumberCounter}:\n'
    #         Loc_ScreenOuputData += f'Number of Data Bytes: {Loc_DataBytesNumber}\n'
    #         Loc_ScreenOuputData += f'Address: 0x{first_part1}{first_part2}{first_part3}{first_part4}{first_part5}{first_part6}{first_part7}{first_part8}\n'
    #         Loc_ScreenOuputData += f'Data Bytes: {Loc_DataBytesValues}\n'
    #         Loc_ScreenOuputData += f'Check Sum: {Loc_CheckSum}\n\n'

    #         Loc_OutputDataForFile = f'{Loc_DataBytesNumber}, {first_part1},{first_part2},{first_part3},{first_part4},{first_part5},{first_part6},{first_part7},{first_part8}, {Loc_DataBytesValues}, {Loc_CheckSum},OK?\n'

    #         return Loc_ScreenOuputData, Loc_OutputDataForFile

    # def voidWriting(self, input_file_path):
    #     Loc_OutputFilePath = os.path.join(os.path.dirname(input_file_path), "output.txt")

    #     with open(input_file_path, 'r') as file:
    #         Loc_AllRecordLines = file.readlines()

    #     self.SecondScreen.delete(1.0, tk.END) # remove the window on each generated code 

    #     with open(Loc_OutputFilePath, 'w') as Loc_OutputFile:
    #         Loc_OutputFile.write('unsigned char Converted_Code[]={\n')
    #         self.Loc_RecondNumberCounter = 1
    #         for Loc_Index, Loc_LineCounter in enumerate(Loc_AllRecordLines):
    #             processed_screen_line, processed_file_line = self.voidParseLine(Loc_LineCounter)
    #             if processed_screen_line is not None:
    #                 self.SecondScreen.insert(tk.END, processed_screen_line)
    #                 Loc_OutputFile.write(f'  {processed_file_line}')
    #                 self.Loc_RecondNumberCounter += 1

    #         if Loc_Index == len(Loc_AllRecordLines) - 1:
    #             Loc_OutputFile.seek(Loc_OutputFile.tell() - 2)
    #             Loc_OutputFile.truncate()

    #         Loc_OutputFile.write('?\n};\n')

    #     return Loc_OutputFilePath

    # def BrowseButton_ISR(self):
    #         file_path = filedialog.askopenfilename(filetypes=[('Hex Files', '*.hex')])
    #         self.Loc_WidgetInputFileEntry.delete(0, tk.END)
    #         self.Loc_WidgetInputFileEntry.insert(0, file_path)

    # def GenerateButton_ISR(self):
    #     Loc_InputFilePath = self.Loc_WidgetInputFileEntry.get()

    #     if Loc_InputFilePath:
    #         entered_data = self.BaudrateDataEntry.get("1.0", tk.END)
    #         print("BaudRate Is:", entered_data)

    #         output_file_path = self.voidWriting(Loc_InputFilePath)
    #         self.Loc_ResultLabel.config(text='Succeeded', fg='green')

##############################################################################################################


    def Data_Transmit(self, event=None):

        
            Loc_DataTransmit = (self.TransmitManualWidget.get("1.0", tk.END).strip())

            if Loc_DataTransmit.startswith("0x") == 0 and self.Loc_DataFlagCheck ==0 :
                Loc_DataTransmit= Loc_DataTransmit
                ser.write((Loc_DataTransmit+"\0\r").encode('utf-8'))
                print(f"\nData Sent is: {(Loc_DataTransmit)}")


                self.Loc_DataFlagCheck = 1 if Loc_DataTransmit == "3" else 0
                print()
                print(self.Loc_DataFlagCheck)

            
            elif Loc_DataTransmit.startswith("0x") :

                self.SecondScreen.insert(tk.END,Loc_DataTransmit , "red")
                self.SecondScreen.yview(tk.END)                 # Auto-scroll to the bottom


                Loc_DataTransmit = Loc_DataTransmit[2:]
                
                byte1 = Loc_DataTransmit[-2:]
                byte2 = Loc_DataTransmit[-4:-2]
                byte3 = Loc_DataTransmit[-6:-4]
                byte4 = Loc_DataTransmit[:-6]

                byte1 = int(byte1, 16)
                byte2 = int(byte2, 16)
                byte3 = int(byte3, 16)
                byte4 = int(byte4, 16)

                data_to_send = struct.pack('!B', byte1)
                ser.write(data_to_send)

                data_to_send = struct.pack('!B', byte2)
                ser.write(data_to_send)

                data_to_send = struct.pack('!B', byte3)
                ser.write(data_to_send)

                data_to_send = struct.pack('!B', byte4)
                ser.write(data_to_send)

                string_to_send = "\0\r" 
                 # Encode the string and send it
                ser.write(string_to_send.encode('utf-8'))



                print(f"Byte 1: {byte1}")
                print(f"Byte 2: {byte2}")
                print(f"Byte 3: {byte3}")

                print(f"Byte 4: {byte4}")
                

            elif self.Loc_DataFlagCheck == 1:
                
                self.Loc_DataFlagCheck =0
                Loc_DataTransmit = str(Loc_DataTransmit)

                self.SecondScreen.insert(tk.END,Loc_DataTransmit , "red")
                self.SecondScreen.yview(tk.END)                 # Auto-scroll to the bottom

                data_values = []

                # Extract individual characters in reverse order
                for char in (Loc_DataTransmit):
                    data_values.append(ord(char))

                # Assuming ser.write() is used to send the values to some serial device
                i=0
                for data_value in data_values:

                    data_to_send = struct.pack('!B', data_value)
                    print(f"Data{i} (ASCII): {data_value}")

                    ser.write(data_to_send)
                    i+=1
                string_to_send = "\0\r" 
                 # Encode the string and send it
                ser.write(string_to_send.encode('utf-8'))
            


            self.TransmitManualWidget.delete("1.0", 'end')


            


    def Start_Isr(self, event=None):
            self.SecondScreen.delete(1.0, tk.END) # remove the window on each generated code 

            string_to_send = "Start\0\r" #receives A M M A R 

            # Encode the string and send it
            ser.write(string_to_send.encode('utf-8'))
                




    def rx_isr(self):
        self.Loc_Check = 0
        self.Loc_Counter = 0
        loc_string_buffer = ""  # Buffer to accumulate characters
        while True:
            loc_received_char = ser.read(1).decode('utf-8')  # Read one character

            if loc_received_char == '\0':
                if "The Data Is" in loc_string_buffer:
                    self.Loc_Check = 1

                elif self.Loc_Check == 1 and self.Loc_Counter < 4 and loc_received_char != ' ' and loc_received_char !='\n' :
                    if loc_string_buffer:
                        loc_asciNumber = loc_string_buffer
                        ascii_value = chr(int(loc_string_buffer))
                        loc_string_buffer = ascii_value+" "
                        print(f"Received Ascii Number: {loc_asciNumber}, Char: {ascii_value}")

                       

                        self.Loc_Counter += 1

                if self.Loc_Counter == 4 :
                    self.Loc_Counter = 0
                    self.Loc_Check = 0
                self.SecondScreen.insert(tk.END, loc_string_buffer, "red")
                # Auto-scroll to the bottom
                self.SecondScreen.yview(tk.END)

                loc_string_buffer = ""
            else:
                # Accumulate characters until a null character is encountered
                loc_string_buffer += loc_received_char


# Welcome Message
print("Welcome To The Project")

# Create the main window
Loc_Root = tk.Tk()
Loc_Root.geometry("1400x700")

# Create an instance of the ProjectWindow class
app = ProjectWindow(Loc_Root)

# Start the GUI event loop
Loc_Root.mainloop()
