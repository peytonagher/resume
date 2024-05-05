#import socket module
from socket import *
import sys # In order to terminate the program
import threading

def client_handler(connectionSocket, addr):
    try:
        message = connectionSocket.recv(1024).decode()
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read()
        f.close()

        #Send HTTP header lines into socket
        connectionSocket.send("HTTP/1.1 200 OK\r\n\r\n".encode())

        #Send the content of the requested file to the client
        connectionSocket.send(outputdata.encode())
        connectionSocket.send("\r\n".encode())

        # Close the connection with this particular client
        connectionSocket.close()

    except IOError:
        #Send response message for file not found
        connectionSocket.send("HTTP/1.1 404 Not Found\r\n\r\n".encode())
        connectionSocket.send("<html><head></head><body><h1>404 Not Found</h1></body></html>\r\n".encode())
        
        #Close client socket
        connectionSocket.close()

def start_server():
    serverSocket = socket(AF_INET, SOCK_STREAM)
    #Prepare a sever socket
    serverSocket.bind(('', 6789))
    serverSocket.listen(1)
    #Establish the connection
    print ("Server ready")
    server_running = True
    threads = []

    try:
        while server_running:
            connectionSocket, addr = serverSocket.accept()
            client_thread = threading.Thread(target=client_handler, args=(connectionSocket, addr))
            client_thread.start()
            threads.append(client_thread)
            print("thread added")

    except KeyboardInterrupt:
        print("\nServer shutting down...")
        server_running = False
    
    for t in threads:
        t.join()

    serverSocket.close()
    sys.exit() # Terminate the program after sending the corresponding data

start_server()
