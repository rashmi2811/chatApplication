#include"header.h"

/* serverRecv */
int serverRecv( int listenfd, char *buff, int f){
    int readBytes = 0;
    memset(buff, '\0', sizeof(buff));
    if(f==0)
        readBytes = Recv( listenfd, buff,MB, 0);
    else{
        readBytes = Recv( listenfd, buff,MB, 0);
        if(readBytes == 0){
            serverExitClient(listenfd);
        }
        return 0;
    }
    if(readBytes == 0){
        serverExitClient(listenfd);
    }
    processRecvData( listenfd, buff);
}

/* serverSend */
void serverSend( int listenfd, char *buff){
    int writeBytes = 0;
    writeBytes = Send( listenfd, buff, strlen(buff), 0);
    printf("\n[CLIENT : %d] || Wrote [%d] number of bytes || BYTES = %s \n", listenfd, writeBytes, buff);
}
