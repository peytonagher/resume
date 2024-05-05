from socket import *
import os
import sys
import struct
import time
import select
import binascii

ICMP_ECHO_REQUEST = 8



# In this function we make the checksum of our packet 
def icmp_checksum(str_):
    str_ = bytearray(str_)
    csum = 0
    countTo = (len(str_) // 2) * 2

    for count in range(0, countTo, 2):
        thisVal = str_[count+1] * 256 + str_[count]
        csum = csum + thisVal
        csum = csum & 0xffffffff

    if countTo < len(str_):
        csum = csum + str_[-1]
        csum = csum & 0xffffffff

    csum = (csum >> 16) + (csum & 0xffff)
    csum = csum + (csum >> 16)
    answer = ~csum
    answer = answer & 0xffff
    answer = answer >> 8 | (answer << 8 & 0xff00)
    return answer



def recvPingPacket(mySocket, ID, timeout, destAddr):
    timeLeft = timeout
    while 1:
        startedSelect = time.time()
        whatReady = select.select([mySocket], [], [], timeLeft)
        howLongInSelect = (time.time() - startedSelect)
        if whatReady[0] == []: # Timeout
            return "Request timed out."

        timeReceived = time.time()
        recPacket, addr = mySocket.recvfrom(1024)


        # Fill in start
        icmpHeader = recPacket[20:28]
        type, code, checksum, packetID, sequence = struct.unpack("bbHHh", icmpHeader)
        # Fill in end	

    
        if type != 8 and packetID == ID:
            bytesInDouble = struct.calcsize("d")
            timeSent = struct.unpack("d", recPacket[28:28 + bytesInDouble])[0]
            return timeReceived - timeSent

        timeLeft = timeLeft - howLongInSelect
        
        if timeLeft <= 0:
            return "Request timed out."

def sendPingPacket(mySocket, destAddr, ID):
    # Header is type (8), code (8), checksum (16), id (16), sequence (16)
    myChecksum = 0
    # Make a dummy header with a 0 checksum.
    # struct -- Interpret strings as packed binary data
    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
    data = struct.pack("d", time.time())
    
    # Fill in start
    myChecksum = icmp_checksum(header + data)
    # Fill in end	

    # Get the right checksum, and put in the header
    if sys.platform == 'darwin':
        myChecksum = htons(myChecksum) & 0xffff
    #Convert 16-bit integers from host to network byte order.
    else:
        myChecksum = htons(myChecksum)

    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
	
    # Fill in start
    packet = header + data
    mySocket.sendto(packet, (destAddr, 1))
    # Fill in end	


def oneTimePing(destAddr, timeout):         
    icmp = getprotobyname("icmp") 
    #Create Socket here
    mySocket = socket(AF_INET, SOCK_RAW, icmp) 

    myID = os.getpid() & 0xFFFF  #Return the current process i     
    sendPingPacket(mySocket, destAddr, myID) 
    delay = recvPingPacket(mySocket, myID, timeout, destAddr)          
    mySocket.close()         
    return delay  

def ping(host, timeout=1):
    i = 0

    min_rtt = float('inf')
    max_rtt = float('-inf')
    total_rtt = 0
    num_pings = 0
    num_timeouts = 0

    dest = gethostbyname(host)
    print ("\nPinging " + dest + " using Python:\n")
    #Send ping requests to a server separated by approximately one second
    while i < 10:
        delay = oneTimePing(dest, timeout)

        if isinstance(delay, str):  # Request timed out
            num_timeouts += 1
        else:
            delay_ms = delay * 1000
            print("delay: " + format(delay_ms, ".3f") + " (ms)")
            min_rtt = min(min_rtt, delay_ms)
            max_rtt = max(max_rtt, delay_ms)
            total_rtt += delay_ms
            num_pings += 1

        time.sleep(1) # one second
        i += 1

    avg_rtt = total_rtt / num_pings if num_pings > 0 else 0
    packet_loss_rate = (num_timeouts / (num_pings + num_timeouts)) * 100 if (num_pings + num_timeouts) > 0 else 0

    print("\n--- Statistics ---")
    print("Minimum RTT: " + format(min_rtt, ".3f") + " ms")
    print("Maximum RTT: " + format(max_rtt, ".3f") + " ms")
    print("Average RTT: " + format(avg_rtt, ".3f") + " ms")
    print("Packet Loss Rate: " + format(packet_loss_rate, ".2f") + "%\n")
    return delay

ping("127.0.0.1")
ping("google.com")
ping("ox.ac.uk")
ping("www.tsinghua.edu.cn")
ping("8.8.8.8")
ping("www.up.ac.za")
