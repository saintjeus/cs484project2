  CS 484 - Project 2
  server.c - server side impl.
  Jesus Barba, David de la Rosa, Devin Thaker

How to use program:
Run "make client" and "make server" to compile executables.

How it works:
The client and server run on localhost. They only handle one user at a time and from the client side prints all messages sent to the server using the UDP sockets API.
On one terminal, run the executable for client and on another terminal, run the executable for server. All messages sent from client will show activity on both terminals.
