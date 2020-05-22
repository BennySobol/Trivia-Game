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

    signup1 = {"username": "user1", "password": "123abc", "email": "user1@gmail.com"}
    login1 = {"username": "user1", "password": "123abc"}
    signup2= {"username": "user2", "password": "123456", "email": "user2@gmail.com"}
    login2 = {"username": "user2", "password": "123456"}
    login_no_signup = {"username": "no_signup", "password": "123456"}


    signup_json1 = json.dumps(signup1)
    login_json1 = json.dumps(login1)
    signup_json2 = json.dumps(signup2)
    login_json2 = json.dumps(login2)
    login_no_signup_json = json.dumps(login_no_signup)
    for x in range(0,5):
        try:
            # Create a TCP/IP socket
            sock1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock3 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            # Connect the socket to the port where the server is listening
            sock1.connect((TCP_IP, TCP_PORT))
            time.sleep(0.05)

            # Send signup
            send_json(sock1, signup_json1, "S")
            # Look for the response
            print("sock1 (code, message) -", recv_json(sock1))

            # Send login                  
            send_json(sock1, login_json1, "L")
            # Look for the response
            print("sock1 (code, message) -", recv_json(sock1))

            # Send login                  
            send_json(sock1, login_json1, "L")
            # Look for the response
            print("sock1 (code, message) -", recv_json(sock1))

            sock2.connect((TCP_IP, TCP_PORT))
            time.sleep(0.05)
            sock3.connect((TCP_IP, TCP_PORT))

            # Send login                  
            send_json(sock2, login_json2, "L")
            # Look for the response
            print("sock2 (code, message) -", recv_json(sock2))

            # Send signup
            send_json(sock2, signup_json2, "S")
            # Look for the response
            print("sock2 (code, message) -", recv_json(sock2))

            # Send login                  
            send_json(sock2, login_json2, "L")
            # Look for the response
            print("sock2 (code, message) -", recv_json(sock2))

            # Send signup                  
            send_json(sock3, login_no_signup_json, "L")
            # Look for the response
            print("sock3 (code, message) -", recv_json(sock3))

            sock1.close()
            sock2.close()
            sock3.close()
        except:
            print("Some error occurred")


if __name__ == "__main__":
    main()