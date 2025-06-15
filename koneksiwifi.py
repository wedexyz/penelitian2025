import requests
import random
import time
# ESP32 Base URL
ESP32_IP = "192.168.137.67"   # Change this to your ESP32 IP address
#def control_led(endpoint):
   
# Function to fetch commands from ESP32
def fetch_esp32_command():
   try:
       url = f"{ESP32_IP}/command"
       response = requests.get(url)
       return response.text.strip()
   except Exception as e:
       print(f"Error fetching command from ESP32: {e}")
       return None
#control_led("index/on" if index_up else "index/off")
#url = ['http://192.168.137.200/buka','http://192.168.137.200/jimpit','http://192.168.137.200/gengam']
a = f"http://{ESP32_IP}/buka"
b = f"http://{ESP32_IP}/jimpit"
c = f"http://{ESP32_IP}/gengam"
url = [a,b,c]
while True :
    ot = random.choice(url)
    print(ot)
    response = requests.get(ot)
    print(response)
    #time.sleep(0.25)
    fetch_esp32_command()


