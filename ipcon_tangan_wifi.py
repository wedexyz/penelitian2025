import requests
import time
import subprocess
from tinydb import TinyDB   
from tinydb import Query  
db = TinyDB("todo_db.json")
Todo = Query()



def get_arp_table():
    """
    Mendapatkan tabel ARP menggunakan subprocess.run().
    """
    try:
        result = subprocess.run(['arp', '-a'], capture_output=True, text=True, check=True)
        return result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error saat menjalankan perintah: {e}")
        return None

def parse_arp_table(arp_output):
    """
    Menganalisis output tabel ARP.
    """
    if not arp_output:
        return []

    lines = arp_output.splitlines()
    arp_entries = []
    for line in lines:
        if "dynamic" in line.lower() or "static" in line.lower():
            parts = line.split()
            if len(parts) >= 2:
                ip_address = parts[0]
                mac_address = parts[1]
                arp_entries.append({"IP": ip_address, "MAC": mac_address})
    return arp_entries
arp_output = get_arp_table()

d = ''
if arp_output:
        arp_entries = parse_arp_table(arp_output)
        #print(arp_entries['IP'])
        #print(arp_entries['MAC'])
        if arp_entries:
            print("Tabel ARP:")
            for entry in arp_entries[0:1]:
                #(entry['IP']).tolist().append(d)
                print(f"  IP: {entry['IP']}, MAC: {entry['MAC']}")
                print( entry['IP'])
                d = entry['IP']



ESP32_IP = d   


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
