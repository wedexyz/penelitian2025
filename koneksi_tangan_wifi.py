import requests
import time
from tinydb import TinyDB   
from tinydb import Query  
db = TinyDB("todo_db.json")
Todo = Query()
# ESP32 Base URL
ESP32_IP = "192.168.137.125"   

def fetch_esp32_command():
   try:
       url = f"{ESP32_IP}/command"
       response = requests.get(url)
       return response.text.strip()
   except Exception as e:
       print(f"Error fetching command from ESP32: {e}")
       return None
   



while True :
    result = db.get(Todo.name == 'Data').get('value')
    print (result)
    if result == 'a':
        ot = f"http://{ESP32_IP}/buka"
        print(ot)
        response = requests.get(ot)
        print(response)
        #time.sleep(0.25)
        fetch_esp32_command()

    elif result == 'b' :
        ot = f"http://{ESP32_IP}/jimpit"
        print(ot)
        response = requests.get(ot)
        print(response)
        #time.sleep(0.25)
        fetch_esp32_command()
    elif result == 'c':
        ot = f"http://{ESP32_IP}/gengam"
        print(ot)
        response = requests.get(ot)
        print(response)
        #time.sleep(0.25)
        fetch_esp32_command()
