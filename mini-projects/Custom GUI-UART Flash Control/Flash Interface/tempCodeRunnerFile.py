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
