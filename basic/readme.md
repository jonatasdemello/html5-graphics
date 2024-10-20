
# Converting Programs from GW-Basic to QBasic

## Summary

 To run a GW-Basic program under QBasic, do the following:

    1. Convert the program in GW-Basic to ASCII format.
    2. Run QBasic with the /MBF switch.
    3. Load the program into QBasic.

## More Information

All QBasic programs must be in ASCII format. 
The GW-Basic program editor can save programs in the format QBasic requires. 
The file must be saved with the A option in GW-Basic. 
Otherwise, GW-Basic compresses the text of your program into a format that QBasic cannot read.


To convert the file to the QBasic format, do the following:

	1. Run GW-Basic.
	2. Use the LOAD command to load your GW-Basic program.
	3. Use the LIST command to verify your program's contents.
	4. Use the SAVE command with the A option to save the program. 
		The A switch causes the program to be saved in ASCII format. 
		For example: 
		save"<program name>",a
	5. Exit GW-Basic by typing SYSTEM at the GW-Basic prompt.

Once you have saved the program in ASCII format, 
you can then load the program in QBasic using the /MBF switch. 

MBF stands for Microsoft Binary Format, which is used for floating point numbers and calculations. 
It allows you to use your old programs and data without rewriting your programs or changing your files. 
For example, type the following command and press ENTER:

`qbasic /mbf`

You can determine if your program is in ASCII format by loading the program into QBasic. 
If it has strange characters or IBM extended character set characters, 
the program is probably not in ASCII format. 
End your QBasic session and save the file in ASCII format using the steps above.

To run the program in QBasic, from the Run menu, choose Start. 
If the program is converted to ASCII, it should run normally.

