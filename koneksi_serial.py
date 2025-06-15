import serial 
import time 
from tinydb import TinyDB   
from tinydb import Query   
#membuat database 
db = TinyDB("todo_db.json")
Todo = Query()

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1) 
def write_read(x): 
	arduino.write(bytes(x, 'utf-8')) 
	time.sleep(0.05) 
	data = arduino.readline() 
	return data 
	   
while True:
	#num = input("Enter a number: ") # Taking input from user 
	result = db.get(Todo.name == 'Data')
	print(result.get('value'))
	value = write_read(result.get('value')) 
	time.sleep(1)
	
	#print(value) # printing the value 
	   
