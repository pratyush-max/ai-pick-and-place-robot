import serial
import time

arduino = serial.Serial('COM5', 9600)
time.sleep(2)

while True:
    cmd = input("Enter command (L/R/P/S or Q to quit): ")

    if cmd.upper() == 'Q':
        break

    if cmd.upper() in ['L', 'R', 'P', 'S']:
        arduino.write(cmd.upper().encode())
        print("Sent:", cmd.upper())

arduino.close()
