# Importing Libraries 
import serial 
import time 
import pygame
import os

# Initialize pygame
pygame.init()

# Load the sound effect
sound_effect_path = os.path.join("/home/ricardo/Arduino/arduino_python", "fail.wav")
sound_effect = pygame.mixer.Sound(sound_effect_path)


arduino = serial.Serial(port='/dev/ttyACM0', baudrate=115200, timeout=.1) 
def write_read(x): 
	   arduino.write(bytes(x, 'utf-8')) 
	   time.sleep(0.05) 
	   data = arduino.readline() 
	   return data 
while True: 
	   num = input("Enter a number: ") # Taking input from user 
	   value = write_read(num) 
	   if int(value) == 5:
	   	 sound_effect.play()
	   print(value) # printing the value 

