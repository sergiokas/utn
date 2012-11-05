#!/usr/bin/python

import sys
import signal
import random
import re
import SocketServer

class DataServerHandler(SocketServer.BaseRequestHandler):
    def handle(self):
        # Get encryption key
        key = self.getKey()
        
        # Send the entire file, encrypted
        f = open("data.csv","r")
        for line in f:
            for c in line:
                #print self.encrypt(c,key)
                #self.request.send(c)
                self.request.send(self.encrypt(c,key))
        
        # Remember to close the file when done. 
        f.close
        print "Sent encrypted data to connected client from", self.client_address[0]
        
    # Get the XOR key based on the last IP octet 
    def getKey(self):
        return chr(int(re.split('\.',self.client_address[0])[3],10)) or 0xaa
    
    def encrypt(self, c, key):
        return chr(ord(c) ^ ord(key))
         

# This handler traps the SIGINT and SIGTERM signals
def SignalHandler(signum, frame):
    print "\nReceived signal, killing the server"
    quit()

# Cleanly kills the server
def quit():
	# For some reason it keeps waiting forever
    sys.exit(0)

# Start the servers
if __name__ == "__main__":
    # Capture the interruption signals
    signal.signal(signal.SIGINT, SignalHandler)
    signal.signal(signal.SIGTERM, SignalHandler)

    # Create the server, binding to localhost to requested port
    HOST, PORT = "", int(sys.argv[1])

    server = SocketServer.TCPServer((HOST, PORT), DataServerHandler)

    print "Running *DATA* server on port", PORT

    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server.serve_forever()
