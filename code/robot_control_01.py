# Martin Cerven 2019
# example program that controls Dustbot by sending commands to arduino by serial line

import serial
import random

from time import sleep

# ser = serial.Serial('/dev/tty.usbmodem1421', 115200)
ser = serial.Serial('/dev/ttyACM0', 115200)

#todo: after x seconds turn in radom direction and go random seconds forward, to infinity

forward_how_many_ms=0
forward_max_ms=1500;
forward_min_ms=500;

turning_how_many_ms=0
turning_max_ms=2000;
turning_min_ms=500;

while True:
    forward_how_many_ms= random.randint(forward_min_ms,forward_max_ms)
    ser.write(b'F')
    print("forward: "+str(forward_how_many_ms))
    sleep(forward_how_many_ms/1000)


    turning_how_many_ms= random.randint(turning_min_ms,turning_max_ms)
    ser.write(b'R')
    print("turning: "+str(turning_how_many_ms))
    sleep(turning_how_many_ms/1000)
