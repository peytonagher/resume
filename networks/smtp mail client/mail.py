#import socket module
from socket import *

msg = "\r\n I love computer networks!"
endmsg = "\r\n.\r\n"

# Choose a mail server (e.g. Google mail server) and call it mailserver
mailserver = "mail.egr.msu.edu"
mailport = 25

# Create socket called clientSocket and establish a TCP
# connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, mailport))

recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != "220":
    print("220 reply not received from server.")

# Send HELO command and print server response.
helo_command = 'HELO mail.egr.msu.edu\r\n'
clientSocket.send(helo_command.encode())

recv1 = clientSocket.recv(1024).decode()
print(recv1)
if recv1[:3] != "250":
    print("250 reply not received from server.")

# Send MAIL FROM command and print server response.
mail_from = "MAIL FROM: <nagherpe@egr.msu.edu>\r\n"
clientSocket.send(mail_from.encode())

recv2 = clientSocket.recv(1024).decode()
print(recv2)

# Send RCPT TO command and print server
# response. [replace "xxxx" with a valid account]
rcptto = "RCPT TO: <nagherpe@egr.msu.edu>\r\n"
clientSocket.send(rcptto.encode())

recv3 = clientSocket.recv(1024).decode()
print(recv3)

# Send DATA command and print server response.
data = "DATA\r\n"
clientSocket.send(data.encode())

recv4 = clientSocket.recv(1024).decode()
print(recv4)

# Send message data.
print("Sending message data...")
clientSocket.send(msg.encode())
print("Message data sent.")

# Message ends with a single period.
clientSocket.send(endmsg.encode())

print("Receiving server response...")
recv5 = clientSocket.recv(1024).decode()
print("Server response received: " + recv5)

# Send QUIT command and get server response.
quit_command = "QUIT\r\n"
clientSocket.send(quit_command.encode())

recv7 = clientSocket.recv(1024).decode()
print("Server response received: " + recv7)
