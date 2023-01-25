#include"header.h"

void Select( int maxfd, fd_set *readset, fd_set *writeset, fd_set *exceptset, struct timeval *timeout){
    int n = select(maxfd,readset,writeset,exceptset,timeout);
    if(n < 0){
        fprintf( stderr,"[-]select() error with error number : %d\n",errno);
        perror("Error Description: ");
        exit(EXIT_FAILURE);
    }
}

void serverSelect(int maxfd,int listenfd,fd_set *readset,fd_set *writeset){
	int newSocketfd = 0;
	char sendBuff[MB];
	char recvBuff[MB];

	memset(sendBuff,0,sizeof(sendBuff));
	memset(recvBuff,0,sizeof(recvBuff));
	Select(maxfd+1,readset,writeset,NULL,NULL);
	
	//check the server listenfd
	if(FD_ISSET(listenfd,readset)){
		clientHandle(listenfd,&newSocketfd);
		printf("New Socket Created: %d\n",newSocketfd);
	}

/*	if(FD_ISSET(STDIN_FILENO,readset)){
		if(read(0,sendBuff,sizeof(sendBuff)) > 0){
			for(int i = 0; i < server.totalClient; i++){
				serverSend(server.clientList[i].fileDes,sendBuff);
			}
		}
	}*/
	
	for(int i = 0;i < server.totalClient;i++){
		if(FD_ISSET(server.clientList[i].fileDes,readset)){
			serverRecv(server.clientList[i].fileDes,recvBuff,0);
		}
	}
}
