import socket
import time

TCP_IP = '127.0.0.1'
TCP_PORT = 1234
BUFFER_SIZE = 5
MESSAGE = 'Hello'.encode()

for index in range(0, 5):
    try:
        # Create a TCP/IP socket
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # Connect the socket to the port where the server is listening
        s.connect((TCP_IP, TCP_PORT))
        # Look for the response
        data = s.recv(BUFFER_SIZE)
        if data == MESSAGE:
            print(index, " - received ", data.decode(), ", sending Hello")
            time.sleep(0.05)
            # Send data
            s.send(MESSAGE)
        s.close()
    except:
        print("Some error occurred")
