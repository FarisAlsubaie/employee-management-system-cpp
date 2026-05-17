import socket
from datetime import datetime

target = input("Enter IP or website: ")
start_port = int(input("Start port: "))
end_port = int(input("End port: "))

print("\nScanning target:", target)
print("From port", start_port, "to", end_port)
print("Time started:", datetime.now())

open_ports = []

for port in range(start_port, end_port + 1):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket.setdefaulttimeout(0.3)

    result = s.connect_ex((target, port))

    if result == 0:
        print("Port open:", port)
        open_ports.append(port)

    s.close()

print("\nScan completed at:", datetime.now())

# Save results to file
with open("scan_results.txt", "w") as f:
    for port in open_ports:
        f.write("Port open: " + str(port) + "\n")

print("Results saved to scan_results.txt")