CC = gcc 
LIBPATH = ../lib/
LIB = createServerSocket.o send_recv.o clientHandle.o serverBuildfdsets.o processRecvData.o serverSelect.o\
      serverRecvSend.o serverExitClient.o
HEADER = $(LIBPATH)header.h

runS: server.o $(LIB)
	$(CC) -o runS server.o $(LIB)

server.o: server.c
	$(CC) -c server.c

createServerSocket.o: $(LIBPATH)createServerSocket.c $(HEADER)
	$(CC) -c $(LIBPATH)createServerSocket.c

send_recv.o: $(LIBPATH)send_recv.c $(HEADER)  
	$(CC) -c $(LIBPATH)send_recv.c

clientHandle.o: $(LIBPATH)clientHandle.c  $(HEADER)         
	$(CC) -c $(LIBPATH)clientHandle.c

serverBuildfdsets.o: $(LIBPATH)serverBuildfdsets.c $(HEADER)
	$(CC) -c $(LIBPATH)serverBuildfdsets.c

processRecvData.o: $(LIBPATH)processRecvData.c $(HEADER)
	$(CC) -c $(LIBPATH)processRecvData.c

serverSelect.o: $(LIBPATH)serverSelect.c $(HEADER)
	$(CC) -c $(LIBPATH)serverSelect.c

serverRecvSend.o: $(LIBPATH)serverRecvSend.c $(HEADER)
	$(CC) -c $(LIBPATH)serverRecvSend.c

serverExitClient.o: $(LIBPATH)serverExitClient.c $(HEADER)
	$(CC) -c $(LIBPATH)serverExitClient.c

clean: 
	rm $(LIB) server.o runS
