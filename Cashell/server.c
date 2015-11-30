#include<stdio.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  
#include<stdlib.h>  
#include<string.h>  

void error_server(char *msg){  
	perror(msg);  
	exit(1);  
}  
			   
int turnOnServer(){  
	int sockfd,newsockfd,portno,clilen,k;  
	char buffer[256];  
	pid_t childpid;  
	struct sockaddr_in serv_addr,cli_addr;  
	int n;  
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);  
	if(sockfd<0){  
		error_server("error opening socket");  
	}  
	bzero((char *)&serv_addr,sizeof(serv_addr));  
	portno = 8888;  
	serv_addr.sin_family=AF_INET;  
	serv_addr.sin_addr.s_addr=INADDR_ANY;  
	serv_addr.sin_port=htons(portno);  
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) <0){  
		error_server("error on binding");  
	}  
	k=listen(sockfd,5);  
	for (;;) {  
		clilen=sizeof(cli_addr);  
		if(k<0) {  
			error_server("error on inding the network");  
			exit(1);  
		}  
		printf("server is running...........................\n         waiting for the client on the port number: %d\n",portno);   
		newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);  
		if(newsockfd<0){  
			error_server("error on accept");  
		}  
		printf("Connection accepted...\n");   
		if ((childpid = fork()) == 0) { //creating a child process   
		close(sockfd);    
		//stop listening for new connections by the main process.    
		//the child will continue to listen.    
		//the main process now handles the connected client.   
		for (;;) {   
			bzero(buffer,256);  
			n=read(newsockfd,buffer,255);  
			if(n<0){  
				error_server("error reading from socket");  
			} else{  
				printf("client: %s\n",buffer);  
			}  
			bzero(buffer,256);  
			printf("server->enter your message: %s",buffer);  
			fgets(buffer,256,stdin);  
			n=write(newsockfd,buffer,strlen(buffer));  
			if(n<0){  
				error_server("error writing socket");  
			}  
		}   
	}   
	close(newsockfd);   
	}   
}
