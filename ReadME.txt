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


//Starting Address 0x0801D000
Starting Address 0x0801E400
HEX File Size 5k
Addresses to clear:
//0x0801D000
//0x0801D400
//0x0801D800
//0x0801DC00
//0x0801E000
or
0x0801E400
0x0801E800
0x0801EC00
0x0801F000
0x0801F400


Commands in Python
cd "Project file Path"  

python flasher.py "COM Number of USB TTL" Debug/"Hex_File_Name".hex