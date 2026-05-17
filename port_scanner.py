import socket

target = input("Enter IP or website (e.g. 127.0.0.1): ")

print("Scanning target:", target)

for port in range(1, 1025):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket.setdefaulttimeout(0.5)

    result = s.connect_ex((target, port))

    if result == 0:
        print("Port open:", port)

    s.close()