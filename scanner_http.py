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
        s.settimeout(1)

        result = s.connect_ex((target, port))

        if result == 0:
            print("\n[+] Port {} is OPEN".format(port))

            # Try HTTP request ONLY for web ports
            if port in [80, 8080, 8000, 3000]:
                try:
                    request = "GET / HTTP/1.1\r\nHost: {}\r\n\r\n".format(target)
                    s.send(request.encode())

                    response = s.recv(4096)
                    print("    HTTP Response:")
                    print(response.decode(errors="ignore")[:300])

                except:
                    print("    HTTP: No response")

            else:
                print("    Service: Non-HTTP or unknown")

        s.close()

    except:
        pass

print("\nScan completed:", datetime.now())