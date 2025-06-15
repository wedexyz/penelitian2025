import subprocess

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


if __name__ == "__main__":
    arp_output = get_arp_table()
    if arp_output:
        arp_entries = parse_arp_table(arp_output)
        #print(arp_entries['IP'])
        #print(arp_entries['MAC'])
        if arp_entries:
            print("Tabel ARP:")
            for entry in arp_entries[0:1]:
                print(f"  IP: {entry['IP']}, MAC: {entry['MAC']}")
                print( entry['IP'])
        