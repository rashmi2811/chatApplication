#include "header.h"

int clientBuildfdsets( int listenfd, fd_set *readset, fd_set *writeset, fd_set *exceptset){

    int maxfd = listenfd;
    FD_ZERO(readset);
    FD_SET(listenfd, readset);
    FD_SET(listenfd, writeset);
    FD_SET(STDIN_FILENO,readset);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    return maxfd;
}
