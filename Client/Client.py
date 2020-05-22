import socket
import time
import json

TCP_IP = '127.0.0.1'
TCP_PORT = 1234
BUFFER_SIZE = 1024


def send_json(sock, json, code):
    """
    sock: a socket
    json: a json string
    code: a string code

    return: none
    """
    message = bytes(json,encoding="utf-8");
    sock.sendall(code.encode() + str(str(len(message)).zfill(5)).encode() + message)
    time.sleep(0.05)

def recv_json(sock):
    """
    sock: a socket

    return: tuple - (code, message)
    """
    data = sock.recv(BUFFER_SIZE).decode()
    return (data[0], data[5:])

def main():
    signup = {"username": "user1", "password": "123abc", "email": "user@gmail.com"}
    login = {"username": "user1", "password": "123abc"}

    signup_json = json.dumps(signup)
    login_json = json.dumps(login)

    for index in range(0, 5):
        try:
            # Create a TCP/IP socket
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            # Connect the socket to the port where the server is listening
            sock.connect((TCP_IP, TCP_PORT))

            # Send signup
            send_json(sock, signup_json, "S")
            # Look for the response
            print("(code, message) -", recv_json(sock))

            # Send login                  
            send_json(sock, login_json, "L")
            # Look for the response
            print("(code, message) -", recv_json(sock))

            sock.close()
        except:
            print("Some error occurred")


if __name__ == "__main__":
    main()