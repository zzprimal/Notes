""""
# ver 1
import os
from socket import *
from time import sleep

def child(sock):
    while True:
        sentence = sock.recv(1024).decode()
        if (sentence == ''):
            print("child exiting", flush = True)
            exit(0)
        print(sentence, flush = True)


serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(0)
#sleep(120)
print('The server is ready to receive')
connectionSocket, addr = serverSocket.accept()
print('accepted')
while True:
    sentence = connectionSocket.recv(1024).decode()
    if (sentence == ''):
        print("child exiting", flush = True)
        exit(0)
    print(sentence, flush = True)
"""

# ver 2
import os
from socket import *
#from time import sleep

def child(sock):
    while True:
        sentence = sock.recv(1024).decode()
        if (sentence == ''):
            print("child exiting", flush = True)
            exit(0)
        print(sentence, flush = True)


serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(0)
print('The server is ready to receive')
while True:
    connectionSocket, addr = serverSocket.accept()
    print('accepted')
    child_proc = os.fork()
    if (child_proc == 0):
        child(connectionSocket)
    #sleep(10)

