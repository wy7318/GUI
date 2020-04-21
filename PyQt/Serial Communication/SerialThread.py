import serial
import time
import binascii
import struct
import sys
import glob
import serial.tools.list_ports
from PyQt5.QtWidgets import QApplication, QDialog
import SerialGUI



def ParitySel(parity):
    switcher = {
        "None" : 'serial.PARITY_NONE',
        "Even" : "PARITY_EVEN",
        "Odd" : "PARITY_ODD",
        "Mark" : "PARITY_MARK",
        "Space" : "PARITY_SPACE",
    }
    return switcher.get(parity, 0)



c = ParitySel("None")

seriport1 = serial.Serial(port='COM26', baudrate=9600, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS, timeout=0.5)

def ToByte(command):
    c = str(command)
    last = '\n'
    comb = c + last
    bt = comb.encode('utf-8').decode('unicode-escape').encode('ISO-8859-1')
    return bt

print(ToByte('READ'))
print(type(ToByte(str('READ'))))


seriport1.write(ToByte('READ'))

s0 = seriport1.readall()
s1 = str(s0.decode('utf-8'))
print(s1)
print(type(s1))


seriport1.close()

