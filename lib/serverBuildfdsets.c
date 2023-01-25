#include "header.h"

int serverBuildfdsets( int listenfd, fd_set *readset, fd_set *writeset, fd_set *exceptset) {

    int maxfd = listenfd;
    FD_ZERO(readset);
    FD_SET(listenfd, readset);
   // FD_SET(STDIN_FILENO,readset);
    //fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    for(int i=0; i<=server.totalClient; i++) {
        FD_SET(server.clientList[i].fileDes, readset);
        if(maxfd<server.clientList[i].fileDes){
		maxfd = server.clientList[i].fileDes;
	}
    }
    return maxfd;
}
