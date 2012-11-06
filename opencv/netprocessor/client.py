#!/usr/bin/python
# -*- coding: utf-8 -*-

import socket
import sys

def client(filename):
    HOST, PORT = '127.0.0.1', int(sys.argv[1])
    # SOCK_STREAM == a TCP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    #sock.setblocking(0)  # optional non-blocking
    sock.connect((HOST, PORT))
    sock.send(filename)
    reply = sock.recv(10)  # limit reply to 10 bytes
    with file(filename) as f:
        content=f.read()
    sock.send(content)
    sock.close()
    return reply

print "Server replied %s" % client("tucan.jpg");