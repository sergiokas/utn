#!/usr/bin/python

import sys
import signal
import random
import re
import SocketServer

class TCPHandler(SocketServer.BaseRequestHandler):

    def handle(self):
        # self.request is the TCP socket connected to the client
        self.buff = self.request.recv(1024).strip()
        self.data = re.split("\W+", self.buff)
        
        # just send back the same data, but upper-cased
        self.request.send(self.getResult())
        
        if(self.guess == SECRET):
            print "El ganador es ** {} **!".format(self.name)
            print "Vamos de nuevo..."
            restart()

    # Get result of user's guess
    def getResult(self):
        # Get name and number of the participant
        self.name = self.data[0]
        self.guess = 0
        if(self.data[1] and self.data[1].isdigit()):
            self.guess = int(self.data[1])

        # Check the guess against the secret number
        result = "IGUAL"
        if(self.guess < SECRET):
            result = "MAYOR"
        if(self.guess > SECRET):
            result = "MENOR"

        print SECRET
        print "Conectado desde {}, {} dice {}, el numero secreto es {}".format(self.client_address[0], self.name, self.guess, result)

        return result

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

# Get a secret number in a range
def restart():
    global SECRET
    SECRET = random.randint(1,99)

# Start the server
if __name__ == "__main__":

    # Capture the interruption signals
    signal.signal(signal.SIGINT, SignalHandler)
    signal.signal(signal.SIGTERM, SignalHandler)

    # Generate a secret random number
    SECRET = 0
    restart()

    # Create the server, binding to localhost to requested port
    HOST, PORT = "localhost", int(sys.argv[1])
    print "Running server on port", PORT
    server = SocketServer.TCPServer((HOST, PORT), TCPHandler)

    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server.serve_forever()

