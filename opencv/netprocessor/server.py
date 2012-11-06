#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import signal
import random
import re
import SocketServer

class TCPHandler(SocketServer.BaseRequestHandler):

    def handle(self):
        # self.request is the TCP socket connected to the client
        print "Connection received from %s" % (self.client_address[0])
        self.filename = self.request.recv(255).strip()        

        # Acknowledge receiving the image name
        self.request.send("OK")
        print "Connection from %s accepted" % (self.client_address[0])

        # Limit image to 10MB
        self.content = self.request.recv(10*1024*1024)

        # Write file
        f=file("images/%s" % self.filename, "w")
        f.write(self.content)
        f.close()

        # Log success
        print "Saved file %s (%d bytes) from %s" % (self.filename, len(self.content), self.client_address[0])

# This handler traps the SIGINT and SIGTERM signals
def SignalHandler(signum, frame):
    print ""
    print "Received signal, killing the server"
    quit()

# Cleanly kills the server
def quit():
	# For some reason it keeps waiting forever
    # server.shutdown()
    sys.exit(0)

# Start the server
if __name__ == "__main__":

    # Capture the interruption signals
    signal.signal(signal.SIGINT, SignalHandler)
    signal.signal(signal.SIGTERM, SignalHandler)

    # Create the server, binding to localhost to requested port
    HOST, PORT = "127.0.0.1", int(sys.argv[1])
    print "Running server on port", PORT
    server = SocketServer.TCPServer((HOST, PORT), TCPHandler)

    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server.serve_forever()