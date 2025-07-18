from socket import *
from time import *

class Http_Response:
    def __init__(self, entity_body = '', status_line = None, header_field = None):
        if header_field == None:
            header_field = []
        self._status_line = status_line
        self._header_field = header_field
        self._entity_body = entity_body

    def set_status_line(self, version, status_code, phrase):
        status_line = version + ' ' + status_code + ' ' + phrase + '\r\n'
        self._status_line =  status_line

    def set_entity_body(self, entity_body):
        self._entity_body = entity_body
    
    def add_header_line(self, header_field_name, header_value):
        header_line = header_field_name + ': ' + header_value + '\r\n'
        self._header_field.append(header_line)

    def add_date_header(self):
        time_info = gmtime()
        time_message = strftime("%a, %d %b %Y %X", time_info)
        time_message += ' GMT'
        self.add_header_line("Date", time_message)

    def add_content_type_header(self, content_type):
        self.add_header_line("Content-Type", content_type)

    def add_content_length_header(self):
        self.add_header_line("Content-Length", str(len(self._entity_body)))

    def add_server_header(self, server_type):
        self.add_header_line("Server", server_type)
    
    def add_connection_header(self, connection_state):
        self.add_header_line("Connection", connection_state)

    def send_response(self, socket):
        application_message = self._status_line
        for i in range(0, len(self._header_field)):
            application_message += self._header_field[i]
        application_message += '\r\n' + self._entity_body

        socket.send(application_message.encode())
    

#import socket module
serverSocket = socket(AF_INET, SOCK_STREAM)
#Prepare a sever socket
#Fill in start
serverSocket.bind(('localhost', 80))
serverSocket.listen(5)
#Fill in end
while True:
    #Establish the connection
    print('Ready to serve...')
    connectionSocket, addr = serverSocket.accept()
    print(addr)
    try:
        message = connectionSocket.recv(1024).decode()
        print(message)
        filename = message.split()[1]
        f = open(filename[1:].replace('%20', ' '))
        outputdata = f.read()
        #Send one HTTP header line into socket
        #Fill in start
        response = Http_Response()
        response.set_entity_body(outputdata)
        response.set_status_line("HTTP/1.1", "200", "OK")
        response.add_date_header()
        response.add_content_type_header("text/html")
        response.add_content_length_header()
        response.add_server_header("My Server (Windows)")
        response.add_connection_header("close")
        response.send_response(connectionSocket)

        #Fill in end
        #Send the content of the requested file to the client
        #for i in range(0, len(outputdata)):
        #    connectionSocket.send(outputdata[i].encode())
        #connectionSocket.send("\r\n".encode())

    except IOError:
        print("File not found")
        #Send response message for file not found
        #Fill in start
        response = Http_Response()
        response.set_status_line("HTTP/1.1", "404", "Not Found")
        response.add_date_header()
        response.add_server_header("My Server (Windows)")
        response.add_connection_header("close")
        response.send_response(connectionSocket)
        #Fill in end
        #Close client socket
        #Fill in start
        #Fill in end

    connectionSocket.close()