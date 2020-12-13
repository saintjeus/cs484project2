#  CS 484 - Project 2
#  Makefile
#  Jesus Barba, David de la Rosa, Devin Thaker


CC = gcc

# client executable is called "client"
# server executable is called "server"

all: client server

client: client.c
	gcc client.c -o client
	
server: server.c
	gcc server.c -o server

clean:
	rm -rf client server 
