'''
Recieves an angle from the arduino and draws it
'''

import matplotlib.pyplot as plt
import numpy as np
from math import cos, sin, pi
import serial

ser = serial.Serial(input("Com port (ex. COM1)"), 9600)

while(true):
    read = ser.readline()
    numbers = read.split()
    plt.cla()
    plt.axis([-1, 1, -1, 1])

    iternums = iter(numbers)
    next(iternums)
    offset = 0;
    for num in iternums:
        plt.plot([0, float(num)*cos((offset*pi/180))], [0, float(num)*sin((offset*pi/180))], 'C0')
        offset += 45

    plt.plot([0, cos((float(numbers[0])*pi/180))], [0, sin((float(numbers[0])*pi/180))], 'C1')
    plt.pause(0.05)

plt.show()