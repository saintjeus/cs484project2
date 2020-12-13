/* CS 484 - Project 2
*  server.c - server side impl.
*  Jesus Barba, David de la Rosa, Devin Thaker
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
/***************************/  
#define PORT     8007 
#define MAXLINE 1024 
/*****************************/

int main() { 
    int sockfd; 
    char recvbuffer[MAXLINE]; 
    char sendbuffer[MAXLINE]; //second buffer, size set to 1024 
    struct sockaddr_in     servaddr; 
  
    // udp socket definition
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("Opening socket"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
    
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len; 
    
    // loop here to get input, send to server, and receive from server
    while(1)
    {
    printf("\nClient: ");
    memset(&sendbuffer, 0, sizeof(sendbuffer));
    scanf("%s", sendbuffer);
    sendto(sockfd, (char *)sendbuffer, strlen(sendbuffer), 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr)); 
    printf("\nMessage sent.\n"); 
    
    // break loop if user wants to end session with "end"
    if(strcmp(sendbuffer,"end")==0)
    	break;
    
    //recieve messages from server
    memset(&recvbuffer, 0, sizeof(recvbuffer));	
    n = recvfrom(sockfd, (char *)recvbuffer, MAXLINE,  
                MSG_WAITALL, (struct sockaddr *) &servaddr, 
                &len); 
    recvbuffer[n] = '\0'; 
    printf("Server : %s\n", recvbuffer); 
    }
    
    close(sockfd); 
    return 0; 
} 
