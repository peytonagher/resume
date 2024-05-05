#import socket module
from socket import *
import sys # In order to terminate the program

# Take server host name, port number and filename command line arguments
server_host = sys.argv[1]
server_port = sys.argv[2]
filename = sys.argv[3]

# Create TCP client socket & connect to server
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((server_host, int(server_port)))

# Send & receive HTTP request to server
http_request = 'GET /' + filename + ' HTTP/1.1\r\n\r\n'
clientSocket.send(http_request.encode())

server_response = clientSocket.recv(1024)

while server_response:
    print(server_response.decode())
    server_response = clientSocket.recv(1024)

clientSocket.close()
sys.exit() #Terminate the program after receiving the corresponding data
