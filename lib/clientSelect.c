#include "header.h"

int clientSelect(int maxfd, int listenfd, fd_set *readset, fd_set *writeset){
    char sendBuff[MB];
    char recvBuff[MB];
    memset(sendBuff, '\0', MB);
    memset(recvBuff, '\0', MB);
    int action = select( maxfd+1, readset, writeset, NULL, NULL);
    if( action == -1 || action == 0) {
        perror("clientSelect() ERROR");
        exit(0);
    }
    if(FD_ISSET(listenfd, readset)){
        clientRecv( listenfd, recvBuff);
//	printf("%s\n",recvBuff);
    }
    if(FD_ISSET(STDIN_FILENO, readset)){
        if(read(0,sendBuff,MB) > 0){
            clientSend( listenfd, sendBuff);
        }
    }
    return 0;
}
