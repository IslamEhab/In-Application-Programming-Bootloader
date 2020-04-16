In Application Programming Using USART1 Serial Communication Protocol.
Instead of ordinary way of burning an image into microcontroller using SWD.
here i used a custom bootloader which can burn the image into flash using USART Communication Protocol 
and the custom bootloader will make a jump to the address of the new image.
Burning Code using USART is done by a Python Script which is provided in the Project files as "flasher.py".
Microcontorller Used here was STM32F103C8 BluePill
the new image was only turn on a led
but for sure you can burn any application you want


Code Flashing Sequence 
1) Flash unlock
2) Erase Addresses
3) Use Python Script
4) Reset MC
5) Direct Jump to starting address 


UART UI          hex
1)Flash lock     01
2)Flash unlock   02
3)Write FLash    03 (address) (data 32bit)
4)Read FLash     04 (address)
5)FLash Erase    05 (address 32bit) (Num of pages)
6)Direct Jump    06 (address to jump)

Example to Burn an Image
You will Find it in debug folder as "blink_LED_0x0801D000.hex"
//Starting Address 0x0801D000
Starting Address 0x0801E400
HEX File Size 5k
Addresses to clear:
//0x0801D000
//0x0801D400
//0x0801D800
//0x0801DC00
//0x0801E000
or another image (also provided in Debug File)
0x0801E400
0x0801E800
0x0801EC00
0x0801F000
0x0801F400


Commands in Python
cd "Project file Path"  

python flasher.py "COM Number of USB TTL" Debug/"Hex_File_Name".hex
