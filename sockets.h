#ifndef _SOCKETS_H_
#define _SOCKETS_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <cstring>
#include <string>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>

namespace Core
{
    class Socket
    {

        public:

            /**
             * No default constructor. Socket can't be initialised empty!
             */
            Socket() = delete;

            /**
             * Construct Socket from socket file descriptor. File descriptor can be acquired 
             * for system other methods. This is okay for RAII because the socket file
             * descriptor cannot be acquired from another socket object.
             */
            Socket(const int &sock_fd);

            /**
             * Construct socket from hostname and portnumber/service
             */
            Socket(const char *host, const char *service);

            /**
             * Default destructor for the Socket class
             */
            ~Socket();

            /**
             * Binds socket to a given port number. Socket need not be bound for connecting
             * to remote host.
             */
            void bind();

            /**
             * Socket starts listening for incoming connections. Taks backlog as param.
             */
            void listen(int &backlog);
            void connect();
            Socket accept();
            int send(char *buff, int &len);
            int recv(char *buff, int &len);

        private:

            int socket_fd;
            struct addrinfo * sa;
    };
}

#endif
// Sockets.h
