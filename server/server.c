#include "../lib/header.h"

int main(void){
    int listenfd=0;
    int maxfd=0,newSocketfd = 0;
    fd_set readset;
    fd_set writeset;
    fd_set exceptset;
    char buff[MB];
    memset(&server,'\0',sizeof(struct serverData));
    // calling socket(), bind(), listen() with error handling
    createServerSocket( &listenfd);
    maxfd = listenfd;
    while(1){
        maxfd = serverBuildfdsets(listenfd,&readset,&writeset,&exceptset);
        serverSelect(maxfd,listenfd,&readset,&writeset);
    }
    close(listenfd);
    // cleanup();
    printf("\n...Terminating the session...\n");
    return (EXIT_SUCCESS);
}
