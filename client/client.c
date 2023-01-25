#include "../lib/header.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("[-]Usage: %s client_Name <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int sockfd=0;
    int maxfd=0;
    char buff[MAX_NAME_SIZE];
    fd_set readset;
    fd_set writeset;
    fd_set exceptset;
    strcpy(buff,argv[1]);
    
    createClientSocket( &sockfd, argv[2]);
    clientSend(sockfd,buff);

    while(1){
        maxfd = clientBuildfdsets(sockfd,&readset,&writeset,&exceptset);
        clientSelect(maxfd,sockfd,&readset,&writeset);
    }
    close(sockfd);
    return (EXIT_SUCCESS);
}
