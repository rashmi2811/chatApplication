//Header
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <fcntl.h>

//Macros
#define MB 1024
#define MAXLINE 4096
#define MAXBUFF 8192
#define SERVER_PORT 9999
#define BACKLOG 10
#define MAX_NAME_SIZE 20
#define NO_OF_CLIENTS 10
#define CONNECTED "Connection Established...\n"

#define SA struct sockaddr

//Data Structure
struct client {
    char cname[MAX_NAME_SIZE];
    char chatWith[MAX_NAME_SIZE];
    int chatWithfd;
    int fileDes;
    int port;
    char ip[INET_ADDRSTRLEN];
};

struct serverData {
    int totalClient;
    struct client clientList[NO_OF_CLIENTS];
};

struct serverData server;

// Function Declarations

// Server Functions
void createServerSocket( int *listenfd);
int Socket( int family, int type, int protocol);
int Bind( int sockfd, SA *addr, socklen_t addrlen);
int Listen( int sockfd, int backlog);
int serverBuildfdsets( int listenfd,fd_set *readset, fd_set *writeset, fd_set *exceptset);
void serverSelect(int maxfd,int listenfd,fd_set *readset,fd_set *writeset);
void clientHandle( int listenfd, int *newSocketfd);
int Accept( int sockfd, SA *addr, socklen_t *addrlen);
void addNewClient(struct sockaddr_in clientInfo,int newSocketfd);
int serverRecv( int listenfd, char *buff, int f);
void serverSend( int listenfd, char *buff);
int processRecvData(int socket,char *buffer);
int findClientIndexName( char *name);
int findClientIndexList( int socket);
void serverExitClient( int socketfdDel);

// Common Functions
int Send( int sockfd,void *buff, size_t length, int flags);
int Recv( int sockfd, void *buff, size_t length, int flags);
void Select(int maxfd,fd_set *readset,fd_set *writeset,fd_set *exceptset,struct timeval *timeout);

// Client Functions
void createClientSocket( int *sockfd, char *IP);
int Connect( int sockfd, SA *addr, socklen_t addrlen);
int clientBuildfdsets( int listenfd,fd_set *readset, fd_set *writeset, fd_set *exceptset);
int clientSelect(int maxfd,int sockfd,fd_set *readset,fd_set *writeset);
void clientSend( int listenfd, char *buff);
void clientRecv( int listenfd, char *buff);

// ssize_t Write( int sockfd, sockaddr_invoid *buff, size_t count);
// ssize_t Read( int sockfd, void *buff, size_t count);
