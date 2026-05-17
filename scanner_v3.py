import socket
from datetime import datetime

target = input("Enter IP or website: ")
start_port = int(input("Start port: "))
end_port = int(input("End port: "))

print("\nScanning target:", target)
print("Time started:", datetime.now())

for port in range(start_port, end_port + 1):
    try:
        s = socket.socket()
        s.settimeout(0.5)

        result = s.connect_ex((target, port))

        if result == 0:
            print("\n[+] Port {} is OPEN".format(port))

            try:
                s.send(b"Hello\r\n")
                banner = s.recv(1024)
                print("    Banner: {}".format(banner.decode().strip()))
            except:
                print("    Banner: Not available")

        s.close()

    except:
        pass

print("\nScan completed:", datetime.now())