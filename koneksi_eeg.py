import serial
import struct

from tinydb import TinyDB  
db = TinyDB("todo_db.json")
new_item = {"name": "Data", "value": 6}
ser = serial.Serial('COM9', 9600) # Replace 'COM3' with your port

def read_float_from_serial():
    try:
        if ser.in_waiting > 0:
            data = ser.readline() # Read a line of data

            # Attempt to decode as ASCII string
            try:
                string_data = data.decode('utf-8').strip()
                float_value = float(string_data)
                return float_value
            except ValueError:
                # Attempt to decode as binary float
                try:
                    float_value = struct.unpack('f', data)[0]
                    return float_value
                except struct.error:
                    print("Error: Could not decode data as a float.")
                    return None

    except serial.SerialException as e:
        print(f"Serial port error: {e}")
        return None
    except Exception as e:
        print(f"An error occurred: {e}")
        return None

    return None # No data received

while True:
    float_value = read_float_from_serial()
    if float_value is not None:
        print(f"Received float: {float_value}")
        x = int(float_value)
        #print(x)
        if x < 1 :
            print("k1")
            db.update({'value': 'a'})
            
        elif x >1 and x <=2 :
            print("k2")
            db.update({'value': 'b'})
        elif x >2 and x<8 :
            print("k2")
            db.update({'value': 'c'})