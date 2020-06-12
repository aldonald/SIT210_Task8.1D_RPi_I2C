from smbus import SMBus
import RPi.GPIO as GPIO
import time
import sys

# i2c addreses
addr = 0x8 

bus = SMBus(1) 
running = True

try:
    while True:
        bus.write_byte(addr, 1)
        response = bus.read_byte(addr)
        if response < 2:
            print("Very dark")
        elif response < 4:
            print("A bit dark")
        elif response < 7:
            print("Moderately light")
        elif response < 7:
            print("Light")
        else:
            print("Super light!")
        time.sleep(1)
except KeyboardInterrupt:
    print("Interrupted")

